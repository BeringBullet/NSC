//
//  CIMAXmlParser.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 9/29/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CIMA/CIMAXmlParsing.h>

@class CIMAXmlTraits;

/** XML parsing object */
@interface CIMAXmlParser : NSObject<NSXMLParserDelegate>

/** XML Traits object specifies settings for parsing and writing XML */
@property (readonly, nonatomic, strong) CIMAXmlTraits* xmlTraits;

/** initialize the XML parser with default traits
 @param data data to parse as XML */
- (id) initWithData:(NSData*)data;

/** initialize the XML parser with specified traits
 @param data data to parse
 @param xmlTraits parsing setting */
- (id) initWithData:(NSData*)data
          xmlTraits:(CIMAXmlTraits*)xmlTraits;

/** parse the XML data into an object
 @param root root element object
 @param error (out) indicate error in XML parsing */
- (id<CIMAXmlParsing>) parseRoot:(NSObject<CIMAXmlParsing>*)root error:(NSError**)error;

/** parse the XML data into an object
 @param possbileRoots dictionary of possible root elements, where the key is the element name and value is the corresponding class object
 @param error (out) indicate error in XML parsing */
- (id<CIMAXmlParsing>) findAndParseRoot:(NSDictionary*)possbileRoots error:(NSError **)error;

/** parse the XML data into an object
 @param data XML data to parse
 @param root root element object
 @param error (out) indicate error in XML parsing */
+ (id<CIMAXmlParsing>) parseData:(NSData*)data root:(NSObject<CIMAXmlParsing>*)root error:(NSError **)error;

/** parse the XML data into an object
 @param data XML data to parse
 @param possbileRoots dictionary of possible root elements, where the key is the element name and value is the corresponding class object
 @param error (out) indicate error in XML parsing */
+ (id<CIMAXmlParsing>) parseData:(NSData*)data possibleRoots:(NSDictionary*)possbileRoots error:(NSError **)error;

@end
