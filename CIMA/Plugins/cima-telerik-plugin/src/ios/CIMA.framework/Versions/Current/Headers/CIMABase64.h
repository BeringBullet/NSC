//
//  CIMABase64.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 9/24/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

/** This class encodes and decodes Base64 data */
@interface CIMABase64 : NSObject

/** Encode data to Base64 string
 @param input input data
 @param length data length in bytes */
+ (NSString*) encode:(const uint8_t*)input length:(NSUInteger)length;

/** Encode data to Base64 string
 @param data data to encode */
+ (NSString*) encode:(NSData*)data;

/** Decode a Base64 string
 @param string base64 string
 @param inputLength string length in bytes */
+ (NSData*) decode:(const char*)string length:(NSUInteger)inputLength;

/** Decode a Base64 string
 @param string base64 string */
+ (NSData*) decode:(NSString*)string;

@end
