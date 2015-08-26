//
//  CIMAPreferenceChildPane.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 11/21/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CIMA/CIMAPreferenceItem.h>

/** Represents a child pane in the preferences screen */
@interface CIMAPreferenceChildPane : CIMAPreferenceItem

/** Array of CIMAPreferenceItem objects */
@property (readonly, nonatomic, strong) NSArray *items;

/** Initialize a CIMAPreferenceItem with multiple items
 @param name name of the preference child pane
 @param items array of CIMAPreferenceItem objects to include in the child pane */
- (id) initWithName:(NSString*)name
          itemArray:(NSArray*)items;

/** Initialize a CIMAPreferenceItem with a single item
 @param name name of the preference child pane
 @param item CIMAPreferenceItem to include in the child pane */
- (id) initWithName:(NSString *)name
               item:(CIMAPreferenceItem*)item;

/** Initialize a CIMAPreferenceItem with multiple items
 @param name name of the preference child pane
 @param firstItem the first CIMAPreferenceItem to include in the child pane
 @param ... a null termitated list of CIMAPreferenceItems to include in the child pane */
- (id) initWithName:(NSString *)name
              items:(CIMAPreferenceItem*)firstItem, ... NS_REQUIRES_NIL_TERMINATION;

/** Create and initialize a CIMAPreferenceItem with multiple items
 @param name name of the preference child pane
 @param items array of CIMAPreferenceItem objects to include in the child pane */
+ (CIMAPreferenceChildPane*) childPaneWithName:(NSString*)name
                                     itemArray:(NSArray*)items;

/** Create and initialize a CIMAPreferenceItem with a single item
 @param name name of the preference child pane
 @param item CIMAPreferenceItem to include in the child pane */
+ (CIMAPreferenceChildPane*) childPaneWithName:(NSString *)name
                                          item:(CIMAPreferenceItem*)item;

/** Create and initialize a CIMAPreferenceItem with multiple items
 @param name name of the preference child pane
 @param firstItem the first CIMAPreferenceItem to include in the child pane
 @param ... a null termitated list of CIMAPreferenceItems to include in the child pane */
+ (CIMAPreferenceChildPane*) childPaneWithName:(NSString *)name
                                         items:(CIMAPreferenceItem*)firstItem, ... NS_REQUIRES_NIL_TERMINATION;

@end
