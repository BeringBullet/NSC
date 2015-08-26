//
//  CIMADateUtilities.h
//  CIMA Framework
//
//  Created by Randall Johnson on 10/20/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

/** This class provides date utility methods */
@interface CIMADateUtilities : NSObject

/** Create NSDate at midnight on the specified date
 @param year year in the gregorian calendar
 @param month 1 based
 @param day 1 based */
+ (NSDate *) dateWithYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day;

/** Create NSDate at the specified date and time
 @param year year in the gregorian calendar
 @param month 1 based
 @param day 1 based
 @param hour hour
 @param minute minute
 @param second second */
+ (NSDate *) dateWithYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day
                     hour:(NSInteger)hour minute:(NSInteger)minute second:(NSInteger)second;

/** Create NSDate from string
 @param string date string
 @param format format of date string for use with NSDateFormatter */
+ (NSDate *) dateFromString:(NSString*)string withFormat:(NSString*)format;

/** Create string from NSDate
 @param date date
 @param format format of date string for use with NSDateFormatter */
+ (NSString *) stringFromDate:(NSDate*)date withFormat:(NSString*)format;

@end
