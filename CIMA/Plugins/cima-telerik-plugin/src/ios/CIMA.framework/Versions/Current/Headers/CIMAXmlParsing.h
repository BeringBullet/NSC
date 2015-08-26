//
//  CIMAXmlParsing.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 9/29/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

@class CIMAXmlParser;

/** A collection of methods to allow CIMAXmlParser to parse XML data into an object */
@protocol CIMAXmlParsing

@required
/** Begin parsing an XML element by creating the corresponding object
 @param xmlParser parser
 @param elementName XML element name
 @param attributeDict XML attributes */
- (id<CIMAXmlParsing>) xmlParser:(CIMAXmlParser*)xmlParser
                 didStartElement:(NSString*)elementName
                      attributes:(NSDictionary*)attributeDict;

/** Finish parsing an XML element
 @param xmlParser parser
 @param elementName XML element name
 @param attributeDict XML attributes
 @param value XML element value
 @param children array of XML child objects, id<CIMAXmlParsing> */
- (void) xmlParser:(CIMAXmlParser*)xmlParser
     didEndElement:(NSString*)elementName
        attributes:(NSDictionary*)attributeDict
             value:(NSString*)value
          children:(NSArray*)children;

@end
