//
//  CIMAPreferenceExclusiveList.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 11/22/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CIMA/CIMAPreferenceItem.h>

/** Represents a preference screen for selecting one item from a list of multiple items */
@interface CIMAPreferenceExclusiveList : CIMAPreferenceItem

/** Array of NSString objects to display on screen in order as possible selections */
@property (nonatomic, strong) NSArray *selectionNames;

/** Set of NSString objects to display on screen as disabled. The disabled names should also be in selectionNames */
@property (nonatomic, strong) NSSet *disabledNames;

/** Currently selected index, which equals defaultIndex if the user has never made a selection */
@property (nonatomic, assign) NSUInteger selectedIndex;

/** Default index */
@property (nonatomic, assign) NSUInteger defaultIndex;

/** initialize CIMAPreferenceExclusiveList
 @param name name of the preference setting to display on screen in the title bar and the parent preference list
 @param saveTag unique key string for use saving and reading the preference value
 @param selectionNames array of NSString objects to display on screen as possible selections
 @param disabledNames set of NSString objects in selectionNames to disable
 @param defaultIndex default selection if the user has never made a selection */
- (id) initWithName:(NSString*)name
            saveTag:(NSString*)saveTag
     selectionNames:(NSArray*)selectionNames
      disabledNames:(NSSet*)disabledNames
       defaultIndex:(NSUInteger)defaultIndex;

/** Set the selected preference by name. If the name is not in selectionNames, then selectedIndex is unchanged and the method returns NO
 @param selectionName name of preference item to select */
- (BOOL) setSelectedIndexWithName:(NSString*)selectionName;

/** Get the name of the selected preference item in the list */
- (NSString*) selectedName;

/** Create and initialize CIMAPreferenceExclusiveList
 @param name name of the preference setting to display on screen in the title bar and the parent preference list
 @param saveTag unique key string for use saving and reading the preference value
 @param selectionNames array of NSString objects to display on screen as possible selections
 @param disabledNames set of NSString objects in selectionNames to disable
 @param defaultIndex default selection if the user has never made a selection */
+ (CIMAPreferenceExclusiveList*) exclusiveListWithName:(NSString*)name
                                               saveTag:(NSString*)saveTag
                                        selectionNames:(NSArray*)selectionNames
                                         disabledNames:(NSSet*)disabledNames
                                          defaultIndex:(NSUInteger)defaultIndex;

@end
