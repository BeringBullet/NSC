//
//  CIMASmapMessageData.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 10/3/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

/** SMAP result */
typedef NS_ENUM(NSUInteger, CIMASmapResultType) {
    /** Success */
    CIMASmapResultSuccess,
    /** User cancelled request */
    CIMASmapResultUserCancelled,
    /** Request failed */
    CIMASmapResultFailure
};

@class CIMAMap, CIMAResponse;

/** Represents a message from the SMAP server containing the response to a request */
@interface CIMASmapMessageData : NSObject

/** The path of the HTTP request URL */
@property (readonly, nonatomic, strong) NSString*          requestUrl;

/** The result type */
@property (readonly, nonatomic, assign) CIMASmapResultType result;

/** A string from the SMAP server indicating the reason for a failure */
@property (readonly, nonatomic, strong) NSString*          resultMessage;

/** Response object representing the HTTP response the SMAP server received from the application server */
@property (readonly, nonatomic, strong) CIMAResponse*      response;

/** Optional passthrough object specified in call to CIMAService::sendRequest or equivalent */
@property (readonly, nonatomic, strong) id                 object;

/** initialize object
 @param requestUrl path of the HTTP request URL
 @param result result type
 @param message string from SMAP server indicating the reason for a failure
 @param response response object representing the HTTP response the SMAP server received from the application server
 @param object optional passthrough object specified in call to CIMAService::sendRequest or equivalent */
- (id) initWithRequestUrl:(NSString*)requestUrl
                   result:(CIMASmapResultType)result
                  message:(NSString*)message
                 response:(CIMAResponse*)response
                   object:(id)object;

/** get the CIMA result property as a string */
- (NSString*) resultAsString;

@end
