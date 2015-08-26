//
//  CIMAPreferenceGroup.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 11/21/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CIMA/CIMAPreferenceItem.h>

/** Represents a group of preferences */
@interface CIMAPreferenceGroup : CIMAPreferenceItem

/** Array of CIMAPreferenceItem objects */
@property (readonly, nonatomic, strong) NSArray *items;

/** Initialize object with an array of CIMAPreferenceItem objects
 @param name name of the preference group, to display on screen
 @param items array of CIMAPreferenceItem objects */
- (id) initWithName:(NSString*)name itemArray:(NSArray*)items;

/** Initialize object with a single CIMAPreferenceItem
 @param name name of the preference group, to display on screen
 @param item CIMAPreferenceItem object */
- (id) initWithName:(NSString*)name item:(CIMAPreferenceItem*)item;

/** Initialize object with an list of CIMAPreferenceItem objects
 @param name name of the preference group, to display on screen
 @param firstItem first CIMAPreferenceItem
 @param ... nil terminated list of CIMAPreferenceItem objects */
- (id) initWithName:(NSString*)name items:(CIMAPreferenceItem*)firstItem, ... NS_REQUIRES_NIL_TERMINATION;

/** Create and initialize object with an array of CIMAPreferenceItem objects
 @param name name of the preference group, to display on screen
 @param items array of CIMAPreferenceItem objects */
+ (CIMAPreferenceGroup*) groupWithName:(NSString*)name itemArray:(NSArray*)items;

/** Create and initialize object with a single CIMAPreferenceItem
 @param name name of the preference group, to display on screen
 @param item CIMAPreferenceItem object */
+ (CIMAPreferenceGroup*) groupWithName:(NSString*)name item:(CIMAPreferenceItem*)item;

/** Create and initialize object with an list of CIMAPreferenceItem objects
 @param name name of the preference group, to display on screen
 @param firstItem first CIMAPreferenceItem
 @param ... nil terminated list of CIMAPreferenceItem objects */
+ (CIMAPreferenceGroup*) groupWithName:(NSString*)name items:(CIMAPreferenceItem*)firstItem, ... NS_REQUIRES_NIL_TERMINATION;

@end
