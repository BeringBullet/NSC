//
//  CIMADeviceUtilities.h
//  CIMA Framework
//
//  Created by Randall Johnson on 10/20/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

/** Screen size of a device in portrait mode, width < height */
typedef NS_ENUM(NSUInteger, CIMADeviceScreenSize) {
    /** 320x480 iPhone 4, 4s */
    CIMAScreen320x480,
    /** 320x568 iPhone 5, 5s (includes 6 and 6 Plus when there is no launchscreen xib) */
    CIMAScreen320x568,
    /** 375x667 iPhone 6 */
    CIMAScreen375x667,
    /** 414x736 iPhone 6 Plus */
    CIMAScreen414x736,
    /** 768x1024 iPad */
    CIMAScreen768x1024,
    /** Other screen size */
    CIMAScreenSizeOther
};

/** This class provides device utility methods */
@interface CIMADeviceUtilities : NSObject

/**----------
 @name Unique ID
 ------------*/

/** Get a string that is unique and consistent to this device and application combination */
+ (NSString*) uniqueDeviceApplicationIdentifier;

/** Get a data object that is unique and consistent to this device and application combination */
+ (NSData*)   uniqueDeviceApplicationIdentifierAsData;

/** Get a data object that is unique and consistent to this device 
    The device ID is stored in the shared keychain so it's consistent across all apps using CIMA framework on a device */
+ (NSData*) uniqueDeviceIdentifierAsData;

/** Get a string that is unique and consistent to this device
 The device ID is stored in the shared keychain so it's consistent across all apps using CIMA framework on a device */
+ (NSString*) uniqueDeviceIdentifier;

/** Get a data object that is unique and not consistent */
+ (NSData*) uniqueIdentifierAsData;

/** Get a string that is unique and not consistent */
+ (NSString*) uniqueIdentifier;

/**----------
 @name Device Features
 ------------*/

/** Determine whether the device can make phone calls */
+ (BOOL) canMakePhoneCalls;

/** Determine whether the device is a simulator */
+ (BOOL) isSimulator;

/** Determine whether the device is an iPad */
+ (BOOL) isPad;

/** Determine whether the device is an iPhone with 320x568 resolution (iPhone 5, 5s) 
    also includes iPhone 6 and 6 Plus when the app does not have a launch screen xib 
    or launch screen image for iPhone 6 and 6 Plus */
+ (BOOL) isPhoneWS;

/** Determine whether the device has a retina display */
+ (BOOL) isRetinaDisplay;

/** Determine whether the device OS is greater than or equal to the specified version
 @param minimumVersion version string such as 7.0 */
+ (BOOL) isSystemVersionGreaterThanEqualTo:(NSString*)minimumVersion;

/** Get the orientation independent screen size of the device */
+ (CIMADeviceScreenSize)screenSize;

@end
