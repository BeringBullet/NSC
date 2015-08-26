//
//  CIMAAesKeyAndIv.h
//  CIMA Framework
//
//  Created by Randall Johnson on 10/22/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

#define CIMA_AES_128_KEY_LENGTH 16
#define CIMA_AES_192_KEY_LENGTH 24
#define CIMA_AES_256_KEY_LENGTH 32
#define CIMA_AES_IV_LENGTH      16

/** This class represents an AES key and IV */
@interface CIMAAesKeyAndIv : NSObject

/** The AES key */
@property (readonly, nonatomic, strong) NSData *key;

/** The IV */
@property (readonly, nonatomic, strong) NSData *iv;

/** Initialize object with specified key and IV
 @param key key object
 @param iv iv object */
- (id) initWithKey:(NSData*)key iv:(NSData*)iv;

/** Initialize object with specified key and IV
 @param key key pointer
 @param keyLength key length in bytes
 @param iv iv pointer, should be standard length */
- (id) initWithKey:(const void*)key keyLength:(NSUInteger)keyLength iv:(const void*)iv;

/** Initialize object with random key and IV
 @param keyLength key length in bytes */
- (id) initWithKeyLength:(NSUInteger)keyLength;

/** Get key length */
- (NSUInteger) keyLength;

/** Get key bytes */
- (const void*) keyBytes;

/** Get IV bytes */
- (const void*) ivBytes;

/** Create and initialize object with specified key and IV
 @param key key object
 @param iv iv object */
+ (CIMAAesKeyAndIv*) keyAndIvWithKey:(NSData*)key iv:(NSData*)iv;

/** Create and initialize object with specified key and IV
 @param key key pointer
 @param keyLength key length in bytes
 @param iv iv pointer, should be standard length */
+ (CIMAAesKeyAndIv*) keyAndIvWithKey:(const void*)key keyLength:(NSUInteger)keyLength iv:(const void*)iv;

/** Create and initialize object with random key and IV
 @param keyLength key length in bytes */
+ (CIMAAesKeyAndIv*) keyAndIvWithKeyLength:(NSUInteger)keyLength;


@end
