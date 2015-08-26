//
//  CIMAXmlWriter.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 9/29/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CIMA/CIMAXmlWriting.h>

@class CIMAXmlTraits;

/** XML writing object */
@interface CIMAXmlWriter : NSObject

/** XML Traits object specifies settings for parsing and writing XML */
@property (readonly, nonatomic, strong) CIMAXmlTraits *xmlTraits;

/** initialize the XML writer with specified traits
 @param outputStream output stream
 @param xmlTraits XML writing traits */
- (id) initWithStream:(NSOutputStream*)outputStream
            xmlTraits:(CIMAXmlTraits*)xmlTraits;

/** initialize the XML writer with default traits
 @param outputStream output stream */
- (id) initWithStream:(NSOutputStream*)outputStream;

/** initialize the XML writer with compact traits
 @param outputStream output stream */
- (id) initCompactWithStream:(NSOutputStream*)outputStream;

/** start XML element with no attributes
 @param elementName XML element name */
- (void) startElement:(NSString*)elementName;

/** start XML element with specified attributes
 @param elementName XML element name
 @param attributeDict XML attributes */
- (void) startElement:(NSString*)elementName attributes:(NSDictionary*)attributeDict;

/** start XML element with specified namespace
 @param elementName XML element name
 @param namespace XML namespace */
- (void) startElement:(NSString*)elementName withNamespace:(NSString*)namespace;

/** start XML element with specified parameters
 @param elementName XML element name
 @param attributeDict optional XML attributes
 @param namespaceName optional XML namespace name
 @param namespace optional XML namespace */
- (void) startElement:(NSString*)elementName
           attributes:(NSDictionary*)attributeDict
    withNamespaceName:(NSString*)namespaceName
        withNamespace:(NSString*)namespace;

/** end XML element */
- (void) endElement;

/** increment indent according to xmlTraits */
- (void) indentIncrement;

/** decrement indent according to xmlTraits */
- (void) indentDecrement;

/** write empty XML element with specified name
 @param elementName XML element name */
- (void) writeEmptyWithName:(NSString*)elementName;

/** write XML element with a string value which will be escaped
 @param value XML string value to be escaped
 @param elementName XML element name */
- (void) writeString:(NSString*)value withName:(NSString*)elementName;

/** write XML element with a string value which will be escaped
 @param value XML string value to be escaped
 @param attributeDict optional XML attributes
 @param elementName XML element name */
- (void) writeString:(NSString*)value attributes:(NSDictionary *)attributeDict withName:(NSString*)elementName;

/** write XML element with an array of strings
 @param values array of XML strings to be escaped and combined into a single string separated by spaces
 @param elementName XML element name */
- (void) writeStrings:(NSArray*)values withName:(NSString*)elementName;

/** write XML element with a bool value
 @param value XML bool value
 @param elementName XML element name */
- (void) writeBoolean:(BOOL)value withName:(NSString*)elementName;

/** write XML element with a C array of bool values
 @param values C array of bool values
 @param count number of elements in the array of bool values
 @param elementName XML element name */
- (void) writeBooleans:(BOOL*)values count:(int)count withName:(NSString*)elementName;

/** write XML element with a CDATA value
 @param value string to enclose in CDATA tag
 @param elementName XML element name */
- (void) writeCdata:(NSString*)value withName:(NSString*)elementName;

/** write XML element with a CDATA value
 @param value string to enclose in CDATA tag
 @param attributeDict XML element attributes
 @param elementName XML element name */
- (void) writeCdata:(NSString*)value attributes:(NSDictionary *)attributeDict withName:(NSString*)elementName;

/** write XML element with Base64 encoded data
 @param data data for Base64 encoding
 @param elementName XML element name */
- (void) writeData:(NSData*)data withName:(NSString*)elementName;

/** write XML element with date value, according to date format in xmlTraits
 @param value date object
 @param elementName XML element name */
- (void) writeDate:(NSDate*)value withName:(NSString*)elementName;

/** write XML element with date values, according to date format in xmlTraits
 @param values array of NSDate objects
 @param elementName XML element name */
- (void) writeDates:(NSArray*)values withName:(NSString*)elementName;

/** write XML element with timestamp value in milliseconds since Jan 1, 1970
 @param value date object
 @param elementName XML element name */
- (void) writeDateAsMilliseconds:(NSDate*)value withName:(NSString*)elementName;

/** write XML element with timestamp values in milliseconds since Jan 1, 1970
 @param values array of NSDate objects
 @param elementName XML element name */
- (void) writeDatesAsMilliseconds:(NSArray*)values withName:(NSString*)elementName;

/** write XML element with double value
 @param value XML element value
 @param elementName XML element name */
- (void) writeDouble:(double)value withName:(NSString*)elementName;

/** write XML element with double values
 @param values C array of doubles
 @param count number of entries in array
 @param elementName XML element name */
- (void) writeDoubles:(double*)values count:(int)count withName:(NSString*)elementName;

/** write XML element with int value
 @param value XML element value
 @param elementName XML element name */
- (void) writeInt:(int)value withName:(NSString*)elementName;

/** write XML element with int values
 @param values C array of int
 @param count number of entries in array
 @param elementName XML element name */
- (void) writeInts:(int*)values count:(int)count withName:(NSString*)elementName;

/** write XML element with long long value
 @param value XML element value
 @param elementName XML element name */
- (void) writeLong:(long long)value withName:(NSString*)elementName;

/** write XML element with long long values
 @param values C array of long long
 @param count number of entries in array
 @param elementName XML element name */
- (void) writeLongs:(long long*)values count:(int)count withName:(NSString*)elementName;

/** write XML element with timestamp value, according to timestamp format in xmlTraits
 @param value date object
 @param elementName XML element name */
- (void) writeTimestamp:(NSDate*)value withName:(NSString*)elementName;

/** escape XML string
 @param string unescaped string */
- (NSString*) escapeXml:(NSString*)string;

/** create XML data from an object
 @param xmlWritingObject an XML object
 @param xmlTraits XML writing settings */
+ (NSData *) toXmlData:(id <CIMAXmlWriting>)xmlWritingObject withXmlTraits:(CIMAXmlTraits*)xmlTraits;

/** create XML data from an object with default XML traits
 @param xmlWritingObject an XML object */
+ (NSData *) toXmlData:(id <CIMAXmlWriting>)xmlWritingObject;

/** create XML data from an object with compact XML traits
 @param xmlWritingObject an XML object */
+ (NSData *) toCompactXmlData:(id <CIMAXmlWriting>)xmlWritingObject;

/** create XML string from an object
 @param xmlWritingObject an XML object
 @param xmlTraits XML writing settings */
+ (NSString *) toXmlString:(id <CIMAXmlWriting>)xmlWritingObject withXmlTraits:(CIMAXmlTraits*)xmlTraits;

/** create XML string from an object with default XML traits
 @param xmlWritingObject an XML object */
+ (NSString *) toXmlString:(id <CIMAXmlWriting>)xmlWritingObject;

/** create XML string from an object with compact XML traits
 @param xmlWritingObject an XML object */
+ (NSString *) toCompactXmlString:(id <CIMAXmlWriting>)xmlWritingObject;
@end
