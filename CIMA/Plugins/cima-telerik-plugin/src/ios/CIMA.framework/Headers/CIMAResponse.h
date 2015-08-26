//
//  CIMAResponse.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 10/6/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

@class CIMAMap;

/** Represents a HTTP response from the SMAP server */
@interface CIMAResponse : NSObject

/** HTTP status code from the server */
@property (readonly, nonatomic, assign) NSInteger code;

/** HTTP headers from the server */
@property (readonly, nonatomic, strong) CIMAMap*  headers;

/** HTTP message body from the server */
@property (readonly, nonatomic, strong) NSData*   data;

/** initialize HTTP response with data as message body
 @param code HTTP status code
 @param headers HTTP headers
 @param data HTTP message body */
- (id) initWithCode:(NSInteger)code
            headers:(CIMAMap*)headers
               data:(NSData*)data;

/** initialize HTTP response with string as message body
 @param code HTTP status code
 @param headers HTTP headers
 @param stringData HTTP message body to be UTF-8 encoded */
- (id) initWithCode:(NSInteger)code
            headers:(CIMAMap*)headers
         stringData:(NSString*)stringData;

/** get HTTP body as UTF-8 string */
- (NSString*) dataAsString;

/** create and initialize HTTP response with data as message body
 @param code HTTP status code
 @param headers HTTP headers
 @param data HTTP message body */
+ (CIMAResponse*) responseWithCode:(NSInteger)code
                           headers:(CIMAMap*)headers
                              data:(NSData*)data;

/** create and initialize HTTP response with string as message body
 @param code HTTP status code
 @param headers HTTP headers
 @param stringData HTTP message body to be UTF-8 encoded */
+ (CIMAResponse*) responseWithCode:(NSInteger)code
                           headers:(CIMAMap*)headers
                        stringData:(NSString*)stringData;

@end
