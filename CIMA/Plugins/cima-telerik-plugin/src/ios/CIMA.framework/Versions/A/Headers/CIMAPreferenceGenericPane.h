//
//  CIMAPreferenceGenericPane.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 11/21/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CIMA/CIMAPreferenceItem.h>

/** Represents an item in the preferences menu that uses a custom view controller */
@interface CIMAPreferenceGenericPane : CIMAPreferenceItem

/** View controller to present when the user selects this preference item in a preference list */
@property (readonly, nonatomic, strong) UIViewController *viewController;

/** Initialize the object
 @param name name to display in preference list, and use as view controller title
 @param viewController controller to present when the user selects this preference item */
- (id) initWithName:(NSString*)name
     viewController:(UIViewController*)viewController;

/** Create and initialize the object
 @param name name to display in preference list, and use as view controller title
 @param viewController controller to present when the user selects this preference item */
+ (CIMAPreferenceGenericPane*) genericPaneWithName:(NSString*)name
                                    viewController:(UIViewController*)viewController;

@end
