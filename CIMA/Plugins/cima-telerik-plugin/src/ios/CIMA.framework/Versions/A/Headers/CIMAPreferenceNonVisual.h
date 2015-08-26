//
//  CIMAPreferenceNonVisual.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 12/7/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>


#import <CIMA/CIMAPreferenceItem.h>

/** Represents a preference item that is stored but not displayed in a preference menu */
@interface CIMAPreferenceNonVisual : CIMAPreferenceItem

/** Value of the preference */
@property (nonatomic, strong) id<NSObject> value;

/** Default value of the preference */
@property (nonatomic, strong) id<NSObject> defaultValue;

/** initialize preference
 @param name name is not relevant since this preference is not displayed on screen
 @param saveTag key for saving the preference
 @param defaultValue default value */
- (id) initWithName:(NSString*)name
            saveTag:(NSString*)saveTag
       defaultValue:(id<NSObject>)defaultValue;

/** create and initialize preference
 @param name name is not relevant since this preference is not displayed on screen
 @param saveTag key for saving the preference
 @param defaultValue default value */
+ (CIMAPreferenceNonVisual*) nonVisualWithName:(NSString*)name
                                       saveTag:(NSString*)saveTag
                                  defaultValue:(id<NSObject>)defaultValue;

@end
