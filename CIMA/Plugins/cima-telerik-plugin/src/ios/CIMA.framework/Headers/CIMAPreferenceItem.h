//
//  CIMAPreferenceItem.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 11/21/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <UIKit/UIKit.h>

@class CIMAPreferenceItem;

/** A collection of methods allowing the preference item to be stored */
@protocol CIMAPreferenceStorageDelegate

/** Encode (store) the value of the preference item
 @param preferenceItem item to store
 @param coder NSCoder subclass to encode the value of the preference item */
- (void) preferenceItem:(CIMAPreferenceItem*)preferenceItem encodeValue:(NSCoder*)coder;

/** Decode (read) the value of the preference item
 @param preferenceItem item to read
 @param coder NSCoder subclass to decode the value of the preference item */
- (void) preferenceItem:(CIMAPreferenceItem*)preferenceItem decodeValue:(NSCoder*)coder;

/** Set the value of the preference item to the default value
 @param preferenceItem item to reset to default value */
- (void) setPreferenceItemToDefaultValue:(CIMAPreferenceItem*)preferenceItem;

@end

/** A collection of methods allowing the preference item to be stored */
@protocol CIMAPreferenceProtocol

/** Return the preference item object for the specified save tag. This would normally be the object itself, unless the object is a group of preference items
 @param saveTag string representing the key for saving the preference item */
- (CIMAPreferenceItem*) preferenceItemForSaveTag:(NSString*)saveTag;

@optional
/** Return the row height for a UITableViewCell representing the preference item */
- (CGFloat) rowHeight;

/** Return a reuseIdentifier for a UITableViewCell representing the preference item */
- (NSString*) reuseIdentifier;

/** Return a UITableViewCell representing the preference item
 @param cell optional cell for reuse, if cell is nil, create new UITableViewCell */
- (UITableViewCell*) cellForRow:(UITableViewCell*)cell;

/** Return a UIViewController to be pushed when the preference item is selected, or nil */
- (UIViewController*) didSelectRow;

/** Return a UIViewController to be pushed when the preference item accessory button is tapped, or nil */
- (UIViewController*) accessoryButtonTappedForRow;

@end

/** Abstract base class for a preference item
 The child class must override the methods in CIMAPreferenceStorageDelegate */
@interface CIMAPreferenceItem : NSObject <CIMAPreferenceStorageDelegate, CIMAPreferenceProtocol>

/** Name of the preference to display on screen */
@property (nonatomic, strong) NSString *name;

/** Key string for saving the preference */
@property (nonatomic, strong) NSString *saveTag;

/** Storage delegate object, defaults to self */
@property (nonatomic, weak) id<CIMAPreferenceStorageDelegate> storageDelegate;

/** Initialize preference item
 @param name name of the preference to display on screen */
- (id) initWithName:(NSString*)name;

/** Initialize preference item
 @param name name of the preference to display on screen
 @param saveTag key string for saving the preference */
- (id) initWithName:(NSString*)name saveTag:(NSString*)saveTag;

@end
