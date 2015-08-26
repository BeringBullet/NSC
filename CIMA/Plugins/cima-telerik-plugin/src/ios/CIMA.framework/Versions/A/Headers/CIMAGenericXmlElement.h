//
//  CIMAGenericXmlElement.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 9/29/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CIMA/CIMAXmlParsing.h>
#import <CIMA/CIMAXmlWriting.h>

/** This class represents an XML element */
@interface CIMAGenericXmlElement : NSObject<CIMAXmlParsing, CIMAXmlWriting>

/** Element name */
@property (readonly, nonatomic, strong) NSString *elementName;

/** Element value */
@property (readonly, nonatomic, strong) NSString *value;

/** Element attributes, a dictionary of NSString keys and NSString values */
@property (readonly, nonatomic, strong) NSDictionary *attributes;

/** Element children, an array of objects that must implement CIMAXmlParsing and CIMAXmlWriting protocols */
@property (readonly, nonatomic, strong) NSMutableArray *children;

/**------------------
 @name Initialization
 ------------------*/

/** Initialize a new XML element with the specified name and attributes
 @param elementName required element name
 @param attributeDict optional element attributes, a dictionary of NSString keys and NSString values */
- (id) initWithName:(NSString *)elementName attributes:(NSDictionary*)attributeDict;

/** Create and initialize a new XML element with the specified name and attributes
 @param elementName required element name
 @param attributeDict optional element attributes, a dictionary of NSString keys and NSString values */
+ (CIMAGenericXmlElement*) elementWithName:(NSString *)elementName attributes:(NSDictionary*)attributeDict;

/**------------------
 @name Misc
 ------------------*/

/** Return true if the element name matches the argument
 @param name string to check against the XML element name */
- (BOOL) isNamed:(NSString*)name;

/** Add a child to the XML element after any existing children
 @param child an object that implements the CIMAXmlParsing and CIMAXmlWriting protocols */
- (void) addChild:(id<CIMAXmlParsing,CIMAXmlWriting>)child;

/**------------------
 @name Value as Date
 ------------------*/

/** Get the XML element value as a date object, assuming a format like yyyy-MM-dd */
- (NSDate *) dateValue;

/** Get the XML element value as an array of NSDate objects, assuming a format like yyyy-MM-dd */
- (NSArray *) dateArray;

/** Get the XML element value as a date object, when the value is the number of milliseconds since Jan 1, 1970 */
- (NSDate *) dateFromMillisecondsValue;

/** Get the XML element value as an array of NSDate objects, when the value is number of milliseconds since Jan 1, 1970 */
- (NSArray *) dateFromMillisecondsArray;

/** Get the XML element value as a NSDate, assuming a format like yyyy-MM-dd HH:mm:ss.SSS ZZ */
- (NSDate *) timestampValue;

/**------------------
 @name Value as Number
 ------------------*/

/** Get the XML element value as a BOOL, interpreting values like True, T, Yes, Y, 1 as true */
- (BOOL) boolValue;

/** Get the XML element value as an array of NSNumbers representing BOOL values*/
- (NSArray*) boolArray;

/** Get the XML element value as a double */
- (double) doubleValue;

/** Get the XML element value as an array of NSNumbers representing doubles */
- (NSArray*) doubleArray;

/** Get the XML element value as an int */
- (NSInteger) intValue;

/** Get the XML element value as an array of NSNumbers representing ints */
- (NSArray *) intArray;

/** Get the XML element value as a long long */
- (long long) longValue;

/** Get the XML element value as an array of NSNumbers representing long long */
- (NSArray *) longArray;

/**------------------
 @name Value as String/Data/Enum
 ------------------*/

/** Get the XML element value as a string */
- (NSString *) stringValue;

/** Get the XML element value as an array of strings split by whitespace */
- (NSArray *) stringArray;

/** Get the XML element value as a data object, using base64 decoding on the XML value string */
- (NSData*) dataValue;

/** Get the XML element value as an enum value
 @param enumStrings array of NSString enum names to match against the XML element value
 enum value corresponds to the array index of each enum name string */
- (int) enumValue:(NSArray*)enumStrings;



@end
