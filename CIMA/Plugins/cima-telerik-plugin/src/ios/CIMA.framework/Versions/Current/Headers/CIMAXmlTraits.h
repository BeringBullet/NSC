//
//  CIMAXmlTraits.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 11/1/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

@class CIMAAesKeyAndIv;

/** Represents settings for parsing and writing XML */
@interface CIMAXmlTraits : NSObject

/** initial indent string for CIMAXmlWriter */
@property (readonly, nonatomic, strong) NSString *initialIndent;

/** incremental indent string for CIMAXmlWriter */
@property (readonly, nonatomic, strong) NSString *indentIncrement;

/** end of line string for CIMAXmlWriter */
@property (readonly, nonatomic, strong) NSString *endOfLine;

/** flag for redacting protected elements for CIMAXmlWriter */
@property (readonly, nonatomic, assign) BOOL sanitizeProtectedElements;

/** date format for parsing and writing */
@property (readonly, nonatomic, strong) NSString *dateFormat;

/** timestamp format for parsing and writing */
@property (readonly, nonatomic, strong) NSString *timestampFormat;

/** key and iv for data encryption/decryption */
@property (readonly, nonatomic, strong) CIMAAesKeyAndIv *keyAndIv;

/** Initialize the XML traits object
 @param initialIndent initial indent string for CIMAXmlWriter
 @param indentIncrement incremental indent string for CIMAXmlWriter
 @param endofLine end of line string for CIMAXmlWriter
 @param sanitizeProtectedElements flag for redacting protected elements for CIMAXmlWriter
 @param dateFormat date format for parsing and writing
 @param timestampFormat timestamp format for parsing and writing
 @param keyAndIv key and iv for data encryption/decryption */
- (id) initWithInitialIndent:(NSString*)initialIndent
             indentIncrement:(NSString*)indentIncrement
                   endOfLine:(NSString*)endofLine
   sanitizeProtectedElements:(BOOL)sanitizeProtectedElements
                  dateFormat:(NSString*)dateFormat
             timestampFormat:(NSString*)timestampFormat
                    keyAndIv:(CIMAAesKeyAndIv*)keyAndIv;

/** Create and initialize the XML traits object
 @param initialIndent initial indent string for CIMAXmlWriter
 @param indentIncrement incremental indent string for CIMAXmlWriter
 @param endOfLine end of line string for CIMAXmlWriter
 @param sanitizeProtectedElements flag for redacting protected elements for CIMAXmlWriter
 @param dateFormat date format for parsing and writing
 @param timestampFormat timestamp format for parsing and writing
 @param keyAndIv key and iv for data encryption/decryption */
+ (CIMAXmlTraits*) traitsWithInitialIndent:(NSString*)initialIndent
                           indentIncrement:(NSString*)indentIncrement
                                 endOfLine:(NSString*)endOfLine
                 sanitizeProtectedElements:(BOOL)sanitizeProtectedElements
                                dateFormat:(NSString*)dateFormat
                           timestampFormat:(NSString*)timestampFormat
                                  keyAndIv:(CIMAAesKeyAndIv*)keyAndIv;

/** Create and initialize the XML traits object with default settings:
 4 space indentation, newline eol, not sanitized,  Date(yyyy-MM-dd), Timestamp(yyyy-MM-dd HH:mm:ss.SSS ZZ),  no key & IV */
+ (CIMAXmlTraits*) defaultTraits;

/** Create and initialize the XML traits object with compact settings:
 No indention, eol, not sanitized,  Date(yyyy-MM-dd), Timestamp(yyyy-MM-dd HH:mm:ss.SSS ZZ),  no key & IV */
+ (CIMAXmlTraits*) compactTraits;

@end
