//
//  SMAPPlugin.m
//  SMAP Plugin for Cordova
//
//  Created by Pullias, Jason M. (MSFC-IS60)[EAST] on 1/28/15.
//  Copyright (c) 2015 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import "SMAPPlugin.h"
#import "SmapPluginConfiguration.h"
#import <Cordova/CDVJSON.h>

@interface SmapObject : NSObject

@property (nonatomic, strong) NSString *callbackId;
@property (nonatomic) bool isJSON;

- (id) initWithCallbackId:(NSString*)callbackId isJSON:(BOOL)isJSON;
+ (SmapObject*) smapObjectWithCallbackId:(NSString*)callbackId isJSON:(BOOL)isJSON;

@end

@implementation SmapObject

- (id) initWithCallbackId:(NSString*)callbackId isJSON:(BOOL)isJSON
{
    if ((self = [super init]))
    {
        _callbackId = callbackId;
        _isJSON     = isJSON;
    }
    return self;
}

+ (SmapObject*) smapObjectWithCallbackId:(NSString*)callbackId isJSON:(BOOL)isJSON
{
    return [[SmapObject alloc] initWithCallbackId:callbackId isJSON:isJSON];
}

@end
//////////////////////////////////////////////////////////////////
@interface SMAPPlugin()
@property (nonatomic, strong) NSString *eventCallbackId;
@end

@implementation SMAPPlugin

- (void)pluginInitialize {
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotification:) name:CIMA_ReachabilityNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotification:) name:CIMA_LoginNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotification:) name:CIMA_CorrectPinNotification object:nil];
    // JMP note: usually these next lines would be in AppDelegate but that's not an option with Telerik
    [SmapPluginConfiguration configureSmap];
    [[CIMAService sharedInstance] loginUser];
}

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void) auid:(CDVInvokedUrlCommand*)command
{
    CIMAService *cimaService = [CIMAService sharedInstance];
    NSString *auid = [cimaService username];
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:auid];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)log:(CDVInvokedUrlCommand *)command {
    NSArray * arguments = command.arguments;
    NSString *errorStr = nil;
    
    CIMALogLevelType logLevel = CIMALogLevelDebug;
    if ([arguments count] >= 1)
    {
        NSString *level = [arguments objectAtIndex:0];
        
        if ([level caseInsensitiveCompare:@"ERROR"] == NSOrderedSame)
        {
            logLevel = CIMALogLevelError;
        }
        else if ([level caseInsensitiveCompare:@"WARN"] == NSOrderedSame)
        {
            logLevel = CIMALogLevelWarn;
        }
        else if ([level caseInsensitiveCompare:@"INFO"] == NSOrderedSame)
        {
            logLevel = CIMALogLevelInfo;
        }
        else if ([level caseInsensitiveCompare:@"DEBUG"] == NSOrderedSame)
        {
            logLevel = CIMALogLevelDebug;
        }
        else
        {
            errorStr = [NSString stringWithFormat:@"Unknown level '%@'", level];
        }
    }
    NSString *message = @"";
    if ([arguments count] >= 2)
    {
        message = [arguments objectAtIndex:1];
    }
    else
    {
        errorStr = @"No error message";
    }
    
    if (errorStr)
    {
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:[errorStr stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    }
    else
    {
        CIMAService *cimaService = [CIMAService sharedInstance];
        [cimaService logMessageWithLevel:logLevel timestamp:[NSDate date] message:message messageLocation:@""];
        
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    }
}

- (CIMATransportMethodType) transportMethod:(NSString *)transportMethodString {
    CIMATransportMethodType transportMethodType = CIMATransportMethodDefault;
    if ([transportMethodString caseInsensitiveCompare:@"GET"] == NSOrderedSame) {
        transportMethodType = CIMATransportMethodHttpGet;
    } else if ([transportMethodString caseInsensitiveCompare:@"POST"] == NSOrderedSame) {
        transportMethodType = CIMATransportMethodHttpPost;
    } else if ([transportMethodString caseInsensitiveCompare:@"PUT"] == NSOrderedSame) {
        transportMethodType = CIMATransportMethodHttpPut;
    } else if ([transportMethodString caseInsensitiveCompare:@"DELETE"] == NSOrderedSame) {
        transportMethodType = CIMATransportMethodHttpDelete;
    } else {
        CIMALogError(@"unsupported transport method: %@",transportMethodString);
    }
    return transportMethodType;
}

// convert dictionary where the values can be strings or arrays of strings
- (CIMAMap *)headerMap:(NSDictionary *)headerDict {
    CIMAMap *map = [[CIMAMap alloc] init];
    if ([headerDict isKindOfClass:[NSDictionary class]]) {
        for (NSString *key in headerDict.allKeys) {
            id valueStringOrArray = [headerDict valueForKey:key];
            if ([valueStringOrArray isKindOfClass:[NSString class]]) {
                [map addValue:valueStringOrArray forKey:key];
            } else if ([valueStringOrArray isKindOfClass:[NSArray class]]) {
                for (NSString *value in (NSArray*)valueStringOrArray) {
                    [map addValue:value forKey:key];
                }
            }
        }
    }
    return map.count > 0 ? map : nil;
}

- (void)sendRequest:(CDVInvokedUrlCommand *)command {
    if ((command.arguments.count > 0) && [command.arguments.firstObject isKindOfClass:[NSDictionary class]]) {
        NSDictionary *requestParams = command.arguments.firstObject;
        NSString *requestPath = [requestParams valueForKey:@"url"];
        CIMATransportMethodType requestMethod = [self transportMethod:[requestParams valueForKey:@"method"]];
        BOOL isJson = NO;
        CIMAMap *headers = [self headerMap:[requestParams valueForKey:@"headers"]];
        NSData *requestBody = nil;
        id requestBodyData = [requestParams valueForKey:@"data"]; // NSString or NSObject or NSNull
        if ([requestBodyData isKindOfClass:[NSString class]]) {
            // string data
            requestBody = [(NSString*)requestBodyData dataUsingEncoding:NSUTF8StringEncoding];
        } else if (![requestBodyData isEqual:[NSNull null]]) {
            // JSON data
            isJson = YES;
            NSError* error = nil;
            requestBody = [NSJSONSerialization dataWithJSONObject:requestBodyData
                                                   options:0
                                                     error:&error];
            if (error)
            {
                CIMALogError(@"NSDictionary dataWithJSONObject error: %@", [error localizedDescription]);
                requestBody = nil;
            }
        }
        
        SmapObject *smapObject = [SmapObject smapObjectWithCallbackId:command.callbackId isJSON:isJson];
        CIMAService *cimaService = [CIMAService sharedInstance];
        CIMARequest *request = [CIMARequest requestWithUrl:requestPath method:requestMethod headers:headers data:requestBody];
        [cimaService sendRequest:request delegate:self object:smapObject];
    }
}

- (void)signout:(CDVInvokedUrlCommand *)command {
    CIMAService *cimaService = [CIMAService sharedInstance];

    [cimaService logoutUser];
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)isReachable:(CDVInvokedUrlCommand *)command {
    CIMAService *cimaService = [CIMAService sharedInstance];
    
    BOOL isReachable = [cimaService isServerReachable];
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsBool:isReachable];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)isSessionStarted:(CDVInvokedUrlCommand *)command {
    CIMAService *cimaService = [CIMAService sharedInstance];
    
    BOOL isSessionStarted = [cimaService isSessionStarted];
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsBool:isSessionStarted];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)registerEventListener:(CDVInvokedUrlCommand *)command {
    self.eventCallbackId = command.callbackId;
}

- (void)handleNotification:(NSNotification *)notification {
    NSString *name = nil;
    id value = [NSNull null];
    if ([notification.name isEqualToString:CIMA_ReachabilityNotification]) {
        NSNumber *isReachable = [notification object];
        name = @"cimaReachabilityChanged";
        value = isReachable;
    }
    else if ([notification.name isEqualToString:CIMA_LoginNotification]) {
        name = @"cimaSessionStarted";
    } else if ([notification.name isEqualToString:CIMA_CorrectPinNotification]) {
        name = @"cimaPinCorrect";
    }
    if (name && self.eventCallbackId) {
        CDVPluginResult *result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:@{@"name":name, @"value": value}];
        [result setKeepCallbackAsBool:YES];
        [self.commandDelegate sendPluginResult:result callbackId:self.eventCallbackId];
    }
}

#pragma mark CIMASmapServiceDelegate Methods

- (void) smapServiceDidFinish:(CIMASmapMessageData*)smapMessageData
{
    SmapObject *smapObject = (SmapObject*) smapMessageData.object;
    
    CDVPluginResult* pluginResult = nil;
    if (smapObject.isJSON)
    {
        NSDictionary *jsonDict;
        if ([smapMessageData.response.data length])
        {
            NSError* error = nil;
            jsonDict = [NSJSONSerialization JSONObjectWithData:smapMessageData.response.data
                                                        options:NSJSONReadingMutableContainers
                                                          error:&error];
            
            if (error != nil)
            {
                NSLog(@"NSString JSONObjectWithData error: %@", [error localizedDescription]);
                jsonDict = nil;
            }
        }
        else
        {
            jsonDict = [NSDictionary dictionary];
        }
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:jsonDict];
    }
    else
    {
        NSString *responseString = [smapMessageData.response dataAsString];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:responseString];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:smapObject.callbackId];

}

- (void) smapServiceDidFail:(CIMASmapMessageData*)smapMessageData
{
    SmapObject *smapObject = (SmapObject*) smapMessageData.object;
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:[@"CIMA messaging error" stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:smapObject.callbackId];
}



@end