//
//  CIMAMap.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 9/30/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

@class CIMAMapEntry;

/** Represents a map of keys (NSString) to values (Objects), like a NSDictionary except keys need not be unique */
@interface CIMAMap : NSObject

/** Array of CIMAMapEntry objects */
@property (readonly, nonatomic, strong) NSMutableArray* keyValues;

/** Initialize empty CIMAMap */
- (id) init;

/** Initialize CIMAMap with a key and value
 @param key key string
 @param value string value */
- (id) initWithKey:(NSString*)key value:(NSString*)value;

/** Initialize CIMAMap with an array of CIMAMapEntry objects
 @param keyValues array of CIMAMapEntry objects */
- (id) initWithKeyValues:(NSArray*)keyValues;

/** Initialize CIMAMap with a dictionary of objects that can be represented as strings using the description method
 @param dict dictionary of objects which can be represented as strings using the description method, and keys which are NSString objects */
- (id) initWithDictionary:(NSDictionary*)dict;

/** Initialize CIMAMap with the specified values and keys
 @param firstValue the first value to add to the CIMAMap, the object must implement the description method
 @param ... first the NSString key for firstValue, then a null-terminated list of alternating values and keys */
- (id) initWithValuesAndKeys:(id)firstValue, ... NS_REQUIRES_NIL_TERMINATION;

/** Get the number of key/value pairs */
- (NSUInteger) count;

/** Add a key/value pair
 @param value string value
 @param key key string */
- (void) addValue:(NSString*)value forKey:(NSString*)key;

/** Add a key/value pair
 @param mapEntry a key/value pair */
- (void) addKeyValue:(CIMAMapEntry*)mapEntry;

/** Get the value for the specified key. If the key has multiple values, the first value will be returned
 @param key key string */
- (NSString*) valueForKey:(NSString *)key;

/** Get all keys and values. If a key has multiple values, the last value will be in the dictionary */
- (NSDictionary*) dictionary;

/** Create and initialize empty CIMAMap */
+ (CIMAMap*) map;

/** Create and initialize CIMAMap with a key and value
 @param key key string
 @param value string value */
+ (CIMAMap*) mapWithKey:(NSString*)key value:(NSString*)value;

/** Create and initialize CIMAMap with an array of CIMAMapEntry objects
 @param keyValues array of CIMAMapEntry objects */
+ (CIMAMap*) mapWithKeyValues:(NSArray*)keyValues;

/** Create and initialize CIMAMap with a dictionary of objects that can be represented as strings using the description method
 @param dict dictionary of objects which can be represented as strings using the description method, and keys which are NSString objects */
+ (CIMAMap*) mapWithDictionary:(NSDictionary*)dict;

/** Create and initialize CIMAMap with the specified values and keys
 @param firstValue the first value to add to the CIMAMap, the object must implement the description method
 @param ... first the NSString key for firstValue, then a null-terminated list of alternating values and keys */
+ (CIMAMap*) mapWithValuesAndKeys:(id)firstValue, ... NS_REQUIRES_NIL_TERMINATION;

@end
