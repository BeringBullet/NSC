//
//  CIMAXmlWriting.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 9/29/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

@class CIMAXmlWriter;

/** A collection of methods to allow CIMAXmlParser to represent an object in XML */
@protocol CIMAXmlWriting

@required
/** Write the object as an XML element with the specified name
 @param xmlWriter XML writer object
 @param elementName XML element name */
- (void) writeToXmlWriter:(CIMAXmlWriter*)xmlWriter withName:(NSString*)elementName;

/** Write the object as an XML element
 @param xmlWriter XML writer object */
- (void) writeToXmlWriter:(CIMAXmlWriter*)xmlWriter;

@end
