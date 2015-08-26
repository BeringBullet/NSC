//
//  CIMAPreferenceToggle.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 11/21/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CIMA/CIMAPreferenceItem.h>

/** Represents a preference item which the user can turn on or off with a UISwitch */
@interface CIMAPreferenceToggle : CIMAPreferenceItem

/** value of the preference */
@property (nonatomic, assign) BOOL value;

/** default value of the preference */
@property (nonatomic, assign) BOOL defaultValue;

/** initialize preference item
 @param name name to display on screen
 @param saveTag key to use for saving the preference
 @param defaultValue default value */
- (id) initWithName:(NSString*)name
            saveTag:(NSString*)saveTag
       defaultValue:(BOOL)defaultValue;

/** create and initialize preference item
 @param name name to display on screen
 @param saveTag key to use for saving the preference
 @param defaultValue default value */
+ (CIMAPreferenceToggle*) toggleWithName:(NSString*)name
                                 saveTag:(NSString*)saveTag
                            defaultValue:(BOOL)defaultValue;

@end
