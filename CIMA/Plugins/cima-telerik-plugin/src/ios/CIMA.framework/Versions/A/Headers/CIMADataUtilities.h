//
//  CIMADataUtilities.h
//  CIMA Framework
//
//  Created by Randall Johnson on 10/20/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

@class CIMAAesKeyAndIv;

/** Message digest type */
typedef NS_ENUM(NSUInteger, CIMAMessageDigestType)
{
    /** MD5 */
    CIMAMessageDigestMD5,
    /** SHA1 */
    CIMAMessageDigestSHA1,
    /** SHA224 */
    CIMAMessageDigestSHA224,
    /** SHA256 */
    CIMAMessageDigestSHA256,
    /** SHA384 */
    CIMAMessageDigestSHA384,
    /** SHA512 */
    CIMAMessageDigestSHA512
};

/** This class provides encryption/signing/encoding/compression type utility methods */
@interface CIMADataUtilities : NSObject

/** Decode Base64 string
 @param string Base64 string to decode */
+ (NSData *) dataFromBase64String:(NSString *)string;

/** Calculate the hash/digest of a message
 @param type of hash function, MD5/SHA
 @param data message data */
+ (NSData*) digestOfType:(CIMAMessageDigestType)type fromData:(NSData*)data;

/** Calculate the HMAC of a message with key
 @param type type of hash function
 @param message message data
 @param key key */
+ (NSData*) hmacOfType:(CIMAMessageDigestType)type withMessage:(NSData*)message forKey:(NSData*)key;

/** Calculate a key using PBKDF2
 @param type type of hash function
 @param password password from which to derive the key
 @param salt cryptographic salt
 @param rounds number of iterations for the algorithm
 @param derivedKeyLength length of the key to generate */
+ (NSData*) pbkdf2OfType:(CIMAMessageDigestType)type
            withPassword:(NSData*)password
                    salt:(NSData*)salt
                  rounds:(NSUInteger)rounds
        derivedKeyLength:(NSUInteger)derivedKeyLength;

///-----------------
/// @name Encryption
///-----------------

/** Encrypt data
 @param data data to encrypt
 @param keyAndIv key and IV to use in encryption */
+ (NSData*) aesEncryptData:(NSData*)data withKeyAndIv:(CIMAAesKeyAndIv*)keyAndIv;

/** Decrypt data
 @param data data to decrypt
 @param keyAndIv key and IV to use in decryption */
+ (NSData*) aesDecryptData:(NSData*)data withKeyAndIv:(CIMAAesKeyAndIv*)keyAndIv;

///-----------------
/// @name Compression
///-----------------

/** Compress data
 @param data data to compress */
+ (NSData*) compressData:(NSData*)data;

/** Uncompress data
 @param data data to uncompress */
+ (NSData*) uncompressData:(NSData*)data;

@end
