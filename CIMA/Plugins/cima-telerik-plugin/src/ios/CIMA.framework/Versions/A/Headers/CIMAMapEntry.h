//
//  CIMAMapEntry.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 9/27/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

/** Represents a key/value pair in a CIMAMap object */
@interface CIMAMapEntry : NSObject

/** key string */
@property (readonly, nonatomic, strong) NSString* key;

/** value string */
@property (readonly, nonatomic, strong) NSString* value;

/** initialize CIMAMap with a key and value
 @param key key string
 @param value value string */
- (id) initWithKey:(NSString *)key value:(NSString *)value;

/** create and initialize CIMAMap with a key and value
 @param key key string
 @param value value string */
+ (CIMAMapEntry*) entryWithKey:(NSString *)key value:(NSString *)value;

@end
