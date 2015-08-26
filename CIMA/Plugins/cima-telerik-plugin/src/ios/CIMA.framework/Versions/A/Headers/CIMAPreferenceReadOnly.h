//
//  CIMAPreferenceReadOnly.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 12/2/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CIMA/CIMAPreferenceItem.h>

/** Represents a preference item that is displayed in a preference menu but cannot be modified in the UI or stored */
@interface CIMAPreferenceReadOnly : CIMAPreferenceItem

/** String value of the preference to display on screen */
@property (nonatomic, strong) NSString *value;

/** initialize the preference item
 @param name name to display on screen
 @param value string value of the preference item to display on screen */
- (id) initWithName:(NSString*)name value:(NSString*)value;

/** create and initialize the preference item
 @param name name to display on screen
 @param value string value of the preference item to display on screen */
+ (CIMAPreferenceReadOnly*) readOnlyWithName:(NSString*)name value:(NSString*)value;

@end
