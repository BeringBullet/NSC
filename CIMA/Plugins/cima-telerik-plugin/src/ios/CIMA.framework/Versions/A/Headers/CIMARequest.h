//
//  CIMARequest.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 10/6/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CIMA/CIMATransportMethod.h>


@class CIMAMap;

/** Represents a HTTP request to the SMAP server */
@interface CIMARequest : NSObject

/** path of the URI, e.g. @"/info" */
@property (readonly, nonatomic, strong) NSString*               url;

/** HTTP method */
@property (readonly, nonatomic, assign) CIMATransportMethodType method;

/** HTTP headers */
@property (readonly, nonatomic, strong) CIMAMap*                headers;

/** HTTP body */
@property (readonly, nonatomic, strong) NSData*                 data;

/** initialize HTTP request object with data as body
 @param url path of the URI, e.g. @"/info"
 @param method HTTP method
 @param headers optional HTTP headers
 @param data optional HTTP body */
- (id) initWithUrl:(NSString*)url
            method:(CIMATransportMethodType)method
           headers:(CIMAMap*)headers
              data:(NSData*)data;

/** initialize HTTP request object with string as body
 @param url path of the URI, e.g. @"/info"
 @param method HTTP method
 @param headers optional HTTP headers
 @param stringData optional HTTP body to be UTF-8 encoded */
- (id) initWithUrl:(NSString*)url
            method:(CIMATransportMethodType)method
           headers:(CIMAMap*)headers
        stringData:(NSString*)stringData;

/** get HTTP body as UTF-8 string */
- (NSString*) dataAsString;

/** create and initialize HTTP request object with data as body
 @param url path of the URI, e.g. @"/info"
 @param method HTTP method
 @param headers optional HTTP headers
 @param data optional HTTP body */
+ (CIMARequest*) requestWithUrl:(NSString*)url
                         method:(CIMATransportMethodType)method
                        headers:(CIMAMap*)headers
                           data:(NSData*)data;

/** create and initialize HTTP request object with string as body
 @param url path of the URI, e.g. @"/info"
 @param method HTTP method
 @param headers optional HTTP headers
 @param stringData optional HTTP body to be UTF-8 encoded */
+ (CIMARequest*) requestWithUrl:(NSString*)url
                         method:(CIMATransportMethodType)method
                        headers:(CIMAMap*)headers
                     stringData:(NSString*)stringData;

@end
