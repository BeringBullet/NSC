//
//  CIMALogLevel.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 9/28/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

/** Represents the log level for the application and framework */
typedef NS_ENUM(NSUInteger, CIMALogLevelType) {
    /** All logs disabled */
    CIMALogLevelNone,
    /** Log Debug, Info, Warnings, and Errors */
    CIMALogLevelDebug,
    /** Log Info, Warnings, and Errors */
    CIMALogLevelInfo,
    /** Log Warnings, and Errors */
    CIMALogLevelWarn,
    /** Log Errors */
    CIMALogLevelError
} ;

