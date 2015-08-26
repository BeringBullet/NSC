//
//  CIMAPreferenceTextField.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 12/2/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <UIKit/UIKit.h>

#import <CIMA/CIMAPreferenceItem.h>

/** Represents a preference item in which the user can enter text with the keyboard */
@interface CIMAPreferenceTextField : CIMAPreferenceItem

/** String value of the preference */
@property (nonatomic, strong) NSString* value;

/** Default value of the preference */
@property (nonatomic, strong) NSString* defaultValue;

/** Optional placeholder text for the UITextField */
@property (nonatomic, strong) NSString* placeholderText;

/** Whether the text field should hide the text being entered. Default is NO */
@property (nonatomic, assign) BOOL isSecure;

/** The keyboard style associated with the text field. Default is UIKeyboardTypeDefault */
@property (nonatomic, assign) UIKeyboardType keyboardType;

/** The auto-capitalization style for the text field. Default is UITextAutocapitalizationTypeSentences */
@property (nonatomic, assign) UITextAutocapitalizationType autocapitalizationType;

/** The auto-correction style for the text field. Default is UITextAutocorrectionTypeDefault */
@property (nonatomic, assign) UITextAutocorrectionType autoCorrectionType;

/** initialize preference item
 @param name name to display on screen
 @param saveTag key string for saving the preference
 @param defaultValue default preference value */
- (id) initWithName:(NSString*)name
            saveTag:(NSString*)saveTag
       defaultValue:(NSString*)defaultValue;

/** create and initialize preference item
 @param name name to display on screen
 @param saveTag key string for saving the preference
 @param defaultValue default preference value */
+ (CIMAPreferenceTextField*) textFieldWithName:(NSString*)name
                                       saveTag:(NSString*)saveTag
                                  defaultValue:(NSString*)defaultValue;


@end
