//
//  CIMASmapDemoAuthorization.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 10/4/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

/** Represents the the authorization black/white lists for a SMAP demo server */
@interface CIMASmapDemoAuthorization : NSObject

/** When non-nil, only users with AUID strings in the white list set will be authorized */
@property (nonatomic, strong) NSMutableSet *auidWhitelist;

/** When non-nil, users with AUID strings in the black list set will not be authorized */
@property (nonatomic, strong) NSMutableSet *auidBlacklist;

/** When non-nil, only devices with device ID strings in the white list set will be authorized */
@property (nonatomic, strong) NSMutableSet *deviceIdWhitelist;

/** When non-nil, devices with device ID strings in the black list set will not be authorized */
@property (nonatomic, strong) NSMutableSet *deviceIdBlacklist;

/** When non-nil, only app versions with matching strings in the white list set will be authorized */
@property (nonatomic, strong) NSMutableSet *appVersionWhitelist;

/** When non-nil, app versions with matching strings in the black list set will not be authorized */
@property (nonatomic, strong) NSMutableSet *appVersionBlacklist;

/** initialize and object with specified black lists and white lists
 @param auidWhitelist optional set of the complete set of AUIDs authorized
 @param auidBlacklist optional set of AUIDs not authorized
 @param deviceIdWhitelist optional set of the complete set of device IDs authorized
 @param deviceIdBlacklist optional set of device IDs not authorized
 @param appVersionWhitelist optional set of the complete set of app version strings authorized
 @param appVersionBlacklist optional set of app version strings not authorized */
- (id) initWithAuidWhitelist:(NSSet*)auidWhitelist
               auidBlacklist:(NSSet*)auidBlacklist
           deviceIdWhitelist:(NSSet*)deviceIdWhitelist
           deviceIdBlacklist:(NSSet*)deviceIdBlacklist
         appVersionWhitelist:(NSSet*)appVersionWhitelist
         appVersionBlacklist:(NSSet*)appVersionBlacklist;

/** return true if the AUID is not blacklisted and is on the white list if applicable
 @param auid AUID string */
- (BOOL) isAuthorizedForAuid:(NSString*)auid;

/** return true if the app version string is not blacklisted and is on the white list if applicable
 @param version app version string */
- (BOOL) isAuthorizedForAppVersion:(NSString*)version;

/** return true if the device id string is not blacklisted and is on the white list if applicable
 @param deviceId device ID string */
- (BOOL) isAuthorizedForDeviceId:(NSString*)deviceId;

/** Create and initialize an object with no black lists and no white lists */
+ (CIMASmapDemoAuthorization*) defaultAuthorization;

@end
