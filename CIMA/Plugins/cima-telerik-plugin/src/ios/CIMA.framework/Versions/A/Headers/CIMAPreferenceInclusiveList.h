//
//  CIMAPreferenceInclusiveList.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 11/22/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CIMA/CIMAPreferenceItem.h>

/** Represents a preference screen for selecting multiple items from a list of items */
@interface CIMAPreferenceInclusiveList : CIMAPreferenceItem

/** Array of NSString objects to display on screen in order as possible selections */
@property (nonatomic, strong) NSArray *selectionNames;

/** Set of NSString objects to display on screen as disabled. The disabled names should also be in selectionNames */
@property (nonatomic, strong) NSSet *disabledNames;

/** Set of NSNumber objects representing currently selected indexes, which equals defaultIndexes if the user has never made a selection */
@property (nonatomic, strong) NSMutableSet *selectedIndexes;

/** Set of NSNumber objects representing the indexes of default selections */
@property (nonatomic, strong) NSSet *defaultIndexes;

/** initialize CIMAPreferenceInclusiveList
 @param name name of the preference setting to display on screen in the title bar and the parent preference list
 @param saveTag unique key string for use saving and reading the preference value
 @param selectionNames array of NSString objects to display on screen as possible selections
 @param disabledNames set of NSString objects in selectionNames to disable
 @param defaultIndexes set of NSNumber objects representing indexes of default selections if the user has never made a selection */
- (id) initWithName:(NSString*)name
            saveTag:(NSString*)saveTag
     selectionNames:(NSArray*)selectionNames
      disabledNames:(NSSet*)disabledNames
     defaultIndexes:(NSSet*)defaultIndexes;

/** Set the selected preferences by name. If a name is not in selectionNames, then selectedIndex is unchanged and the method returns NO
 @param names array of NSString objects representing names of preference items to select */
- (BOOL) setSelectedIndexesWithNames:(NSArray*)names;

/** Get an array of NSString objects representing the names of the selected preference item in the list */
- (NSArray*) selectedNames;

/** Create and initialize CIMAPreferenceInclusiveList
 @param name name of the preference setting to display on screen in the title bar and the parent preference list
 @param saveTag unique key string for use saving and reading the preference value
 @param selectionNames array of NSString objects to display on screen as possible selections
 @param disabledNames set of NSString objects in selectionNames to disable
 @param defaultIndexes set of NSNumber objects representing indexes of default selections if the user has never made a selection */
+ (CIMAPreferenceInclusiveList*) inclusiveListWithName:(NSString*)name
                                               saveTag:(NSString*)saveTag
                                        selectionNames:(NSArray*)selectionNames
                                         disabledNames:(NSSet*)disabledNames
                                        defaultIndexes:(NSSet*)defaultIndexes;

@end

