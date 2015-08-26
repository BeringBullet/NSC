//
//  CIMAService.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 9/24/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <CIMA/CIMALogLevel.h>
#import <CIMA/CIMAPreferenceItem.h>
#import <CIMA/CIMASmapService.h>


#define CIMALog(level, format, ...) \
  { \
    CIMAService *_x_cimaService = [CIMAService sharedInstance]; \
    if ([_x_cimaService willLogAtLevel:level]) \
    { \
      [_x_cimaService logMessageWithLevel:level \
                                timestamp:[NSDate date] \
                                  message:[NSString stringWithFormat:format, ##__VA_ARGS__] \
                          messageLocation:[NSString stringWithFormat:@"%s:%d", __PRETTY_FUNCTION__, __LINE__]]; \
    } \
  }

#define CIMALogException(level, ex, format, ...) \
  { \
    CIMAService *_x_cimaService = [CIMAService sharedInstance]; \
    if ([_x_cimaService willLogAtLevel:level]) \
    { \
      [_x_cimaService logExceptionWithLevel:level \
                                  timestamp:[NSDate date] \
                                    message:[NSString stringWithFormat:format, ##__VA_ARGS__] \
                            messageLocation:[NSString stringWithFormat:@"%s:%d", __PRETTY_FUNCTION__, __LINE__] \
                                  exception:ex]; \
    } \
  }

#define CIMALogDebug(format, ...) CIMALog(CIMALogLevelDebug, format, ##__VA_ARGS__)
#define CIMALogInfo(format, ...)  CIMALog(CIMALogLevelInfo, format, ##__VA_ARGS__)
#define CIMALogWarn(format, ...)  CIMALog(CIMALogLevelWarn, format, ##__VA_ARGS__)
#define CIMALogError(format, ...) CIMALog(CIMALogLevelError, format, ##__VA_ARGS__)

#define CIMALogExceptionDebug(exception, format, ...) CIMALogException(CIMALogLevelDebug, exception, format, ##__VA_ARGS__)
#define CIMALogExceptionInfo(exception, format, ...)  CIMALogException(CIMALogLevelInfo, exception, format, ##__VA_ARGS__)
#define CIMALogExceptionWarn(exception, format, ...)  CIMALogException(CIMALogLevelWarn, exception, format, ##__VA_ARGS__)
#define CIMALogExceptionError(exception, format, ...) CIMALogException(CIMALogLevelError, exception, format, ##__VA_ARGS__)

/** Server environment */
typedef NS_OPTIONS(NSUInteger, CIMAEnvironmentType) {
    /** Internal demo server */
    CIMAEnvironmentDemo = 1 << 0,
    /** Dev server */
    CIMAEnvironmentDev  = 1 << 1,
    /** Test server */
    CIMAEnvironmentTest = 1 << 2,
    /** Prod server */
    CIMAEnvironmentProd = 1 << 3
};

/** Build type */
typedef NS_ENUM(NSUInteger, CIMABuildType) {
    /** Alpha */
    CIMABuildAlpha,
    /** Beta */
    CIMABuildBeta,
    /** Release */
    CIMABuildRelease
};

/** NSNotification with this name is sent on successful login with the server */
#define CIMA_LoginNotification @"CIMA_LoginNotification"

/** NSNotification with this name is sent when the user enters the correct PIN (for offline login) */
#define CIMA_CorrectPinNotification @"gov.nasa.neacc.cima.pinEntry.correct"

/** NSNotification with this name is sent when server reachability changes (device transitions online/offline) 
    The object associated with the notification is a NSNumber(BOOL) indicating whether the server is reachable */
#define CIMA_ReachabilityNotification @"gov.nasa.neacc.cima.reachability"

@class CIMAMap, CIMARequest, CIMAService, CIMASmapDemoConnection;

/** A collection of methods to inform an object of changes in the CIMAService */
@protocol CIMAServiceDelegate

@optional
/** When the framework received a configuration map change from the server, this method is called.
 Not typically used.
 @param cimaService cimaService singleton
 @param configurationMap configuration map */
- (void) service:(CIMAService*)cimaService configurationMapDidChange:(CIMAMap*)configurationMap;
@end

/** This class is the main interface to the CIMA framework */
@interface CIMAService : NSObject

/** This is the CIMA assigned app ID string specified in the initialization method */
@property (readonly, nonatomic, strong) NSString *applicationId;

/** Specify the server environment (Prod, Test, Dev, Demo). Default: CIMAEnvironmentProd */
@property (nonatomic, assign) CIMAEnvironmentType environment;

/** Specify the supported server environments, for the hidden debug screen. Default: all */
@property (nonatomic, assign) NSUInteger          supportedEnvironments;

/** Specify an optional password to access the server environment selection in conjunction with username: env */
@property (nonatomic, strong) NSString           *environmentPassword;

/** Specify the build type (Alpha, Beta, Release). Default: CIMABuildRelease */
@property (nonatomic, assign) CIMABuildType       buildType;

/** Specify an expiration date for this app. Default: nil */
@property (nonatomic, strong) NSDate             *expirationDate;

/** Specify an optional password to access a hidden view controller for debugging in conjunction with username: debug */
@property (nonatomic, strong) NSString            *debugPassword;

/** Specify an optional debug view controller accessed by using username: debug and password specified with property debugPassword */
@property (nonatomic, strong) UIViewController    *debugViewController;

/** Specify an optional demo connection for use when the server environment is CIMAEnvironmentDemo */
@property (nonatomic, strong) CIMASmapDemoConnection *smapDemoConnection;

/** Specify whether the application requires authentication. Default: YES */
@property (nonatomic, assign) BOOL requiresAuthentication;

/** Specify whether the application allows login by AUID and password. Default: YES */
@property (nonatomic, assign) BOOL allowsLaunchpadLogin;

/** Specify whether the application allows login by derived credential. Default: YES */
@property (nonatomic, assign) BOOL allowsDerivedCredentialLogin;

/** Specify whether the application allows saving launchpad password with a PIN. Default: YES */
@property (nonatomic, assign) BOOL allowsSavedPassword;

/** Specify whether the application supports offline login with derived credentials. Default: NO */
@property (nonatomic, assign) BOOL allowsOfflineLogin;

/** Specify whether the framework should display alertViews while communicating with the server. Default: YES */
@property (nonatomic, assign) BOOL doesShowProgressDialog;

/** Specify whether the framework should display alertViews to indicate errors communicating with the server. Default: YES */
@property (nonatomic, assign) BOOL doesShowCommunicationAlerts;

/** Specify whether the framework should use data compression. Default: YES */
@property (nonatomic, assign) BOOL doesUseCompression;

/** Optional 320x60 banner that appears at the top of the login screens
 When this is nil and backgroundImage property is nil, the application name is used (CFBundleDisplayName) */
@property (nonatomic, strong) UIImage *logo;

/** Optional background image that appears behind login screens.
 When this is nil, a NASA logo is used.
 320x480 (for iPhone 4S and earlier) */
@property (nonatomic, strong) UIImage *backgroundImage;

/** Optional background image that appears behind login screens.
 When this is nil, a NASA logo is used.
 320x568 (for iPhone 5, 5S) */
@property (nonatomic, strong) UIImage *backgroundImage_iPhoneWS;

/** Optional background image that appears behind login screens.
 When this is nil, backgroundImage_iPhoneWS is used and stretched to fill the screen.
 375x667 (for iPhone 6) */
@property (nonatomic, strong) UIImage *backgroundImage_iPhone6;

/** Optional background image that appears behind login screens.
 When this is nil, backgroundImage_iPhone6 or _iPhone_WS is used and stretched to fill the screen.
 414x736 (for iPhone 6+) */
@property (nonatomic, strong) UIImage *backgroundImage_iPhone6Plus;

/** Optional background image that appears behind login screens.
 When this is nil, a NASA logo is used.
 540x620 (for iPad UIModalPresentationFormSheet) */
@property (nonatomic, strong) UIImage *backgroundImage_iPad;

/** Optional image to display at the bottom of the info screen.
 Recommended about 90 px tall and no wider than 320px
 Default is CIMA logo */
@property (nonatomic, strong) UIImage* infoLogo;

/** Optional map of title/value pairs <NSString> to display in the info screen */
@property (nonatomic, strong) CIMAMap* infoItems;

/** Specify log level that applies to console and server logs. Default: CIMALogLevelWarn */
@property (nonatomic, assign) CIMALogLevelType logLevel;

/** Specify whether to log to console. Default: YES */
@property (nonatomic, assign) BOOL logToConsole;

/** Selectively enable logs from the application. Default: YES */
@property (nonatomic, assign) BOOL logApplicationLogs;

/** Selectively enable logs from within the framework. Default: YES */
@property (nonatomic, assign) BOOL logSystemLogs;

/** Selectively enable server response time logs within the framework. Default: YES */
@property (nonatomic, assign) BOOL logResponseTimes;

/** Selectively enable screen view logs within the framework. Default: YES */
@property (nonatomic, assign) BOOL logScreenViews;

/** Selectively enable event (app lifecycle, network status) logs within the framework. Default: YES */
@property (nonatomic, assign) BOOL logEvents;

/** Selectively enable orientation change logs. Default: YES */
@property (nonatomic, assign) BOOL logOrientationChanges;

/** DEPRECATED - GPS location reporting is not supported.
 However, user location is tracked on the server using geolocation by IP address */
@property (nonatomic, assign) BOOL recordLocation;

/** Key/value pairs that can be sent from the SMAP server for application specific use */
@property (nonatomic, strong) CIMAMap* configurationMap;

/** Optional array of <CIMAPreferenceItem> to be added in the preference menu */
@property (nonatomic, strong) NSArray *applicationPreferenceItems;

/** Optional array of <CIMAPreferenceItem> to be added in the preference menu */
@property (nonatomic, strong) NSArray *userPreferenceItems;

/** Delegate object, refer to CIMAServiceDelegate protocol */
@property (nonatomic, weak) id<CIMAServiceDelegate> delegate;

/** Initialize CIMAService singleton
 @param cimaApplicationId CIMA Assigned Application ID string */
+ (CIMAService *) initializeServiceWithApplicationId:(NSString*)cimaApplicationId;

/** Initialize CIMAService singleton
 @param cimaApplicationId CIMA Assigned Application ID string
 @param iosAppIdentifier currently ignored, the framework will determine the bundle ID programatically at runtime */
+ (CIMAService *) initializeServiceWithApplicationId:(NSString*)cimaApplicationId
                                    iosAppIdentifier:(NSString*)iosAppIdentifier;

/** Returns the singleton CIMAService if initializeServiceWithApplicationId has been called, otherwise nil */
+ (CIMAService *) sharedInstance;

/** Returns the username of the logged in user */
- (NSString *) username;

/** Returns TRUE when the server is reachable by WiFi or cellular, FALSE if the device is offline */
- (BOOL)isServerReachable;

/** Returns TRUE if the app has successfully started a session with the server. Note that the session may have timed out, 
    in which case the user will be asked for the PIN to start a new session on the next outgoing request */
- (BOOL)isSessionStarted;

/** Returns the application version string (CFBundleVersion) */
- (NSString *) applicationVersion;

/** Returns the framework version string (CFBundleVersion) */
- (NSString *) frameworkVersion;

/** Returns the build type string (Alpha/Beta/Release), corresponding to buildType property */
- (NSString *) buildMessage;

/** Returns the server environment string (Prod, Test, Dev, Demo, Local), corresponding to environment property */
- (NSString *) environmentMessage;

/** Return whether the application has expired, according to expirationDate property */
- (BOOL) hasApplicationExpired;

/** Display alert and exit if the application has expired, according to expirationDate property */
- (void) alertAndExitIfApplicationExpired;

/** Return whether the session has timed out. The timeout is determined internal to the CIMA framework and server */
- (BOOL) hasBackgroundTimeoutExpired;

/** Start a session that is not associated with a user.
 Use loginUser to start a session with user login */
- (void) startSession;

/** Start a session that is not associated with a user.
 Use loginUser to start a session with user login
 @param request request to pass through SMAP gateway to application server
 @param delegate object to call with the result of the request
 @param object optional passthrough to the delegate call */
- (void) startSessionWithRequest:(CIMARequest*)request
                        delegate:(id<CIMASmapServiceDelegate>)delegate
                          object:(id<NSObject>)object;

/** Send a request (can only succeed if a session is already established)
 @param request request to pass through SMAP gateway to application server
 @param delegate object to call with the result of the request
 @param object optional passthrough to the delegate call */
- (void) sendRequest:(CIMARequest*)request
            delegate:(id<CIMASmapServiceDelegate>)delegate
              object:(id<NSObject>)object;

/** End a session, but do not show login UI */
- (void) endSession;

/** End a session, but do not show login UI
 @param request request to pass through SMAP gateway to application server
 @param delegate object to call with the result of the request
 @param object optional passthrough to the delegate call */
- (void) endSessionWithRequest:(CIMARequest*)request
                      delegate:(id<CIMASmapServiceDelegate>)delegate
                        object:(id<NSObject>)object;

/** Start a session by displaying the Login UI
 The framework will send CIMA_LoginNotification after login is successful */
- (void) loginUser;

/** Start a session by displaying the Login UI
 The framework will send CIMA_LoginNotification after login is successful
 @param request request to pass through SMAP gateway to application server
 @param delegate object to call with the result of the request
 @param object optional passthrough to the delegate call */
- (void) loginUserWithRequest:(CIMARequest*)request
                     delegate:(id<CIMASmapServiceDelegate>)delegate
                       object:(id<NSObject>)object;

/** DEPRECATED
 @param mainViewController deprecated */
- (void) loginUserWithViewController:(UIViewController*)mainViewController;

/** DEPRECATED
 @param mainViewController deprecated
 @param request deprecated
 @param delegate deprecated
 @param object deprecated */
- (void) loginUserWithViewController:(UIViewController*)mainViewController
                             request:(CIMARequest*)request
                            delegate:(id<CIMASmapServiceDelegate>)delegate
                              object:(id<NSObject>)object;

/** End a session and display the login UI */
- (void) logoutUser;

/** Send device token to the CIMA push notification server to register this device for push notifications
 @param deviceToken Apple Push Notification device token */
- (void) registerForPushNotifications:(NSData*)deviceToken;


#pragma mark - Info
///--------------------------
/// @name Info Screen
///--------------------------

/** Return a new instance of the CIMAInfoViewController class */
- (UIViewController*) infoViewController;

/** Present a new instance of the CIMAInfoViewController within a navigation controller with a Done button
 @param parentViewController the controller which should present the info view controller */
- (void) showInfo:(UIViewController*)parentViewController;

#pragma mark - Preferences
///--------------------------
/// @name Preferences Screen
///--------------------------

/** Return a new instance of the CIMAPreferencesViewController class */
- (UIViewController*) preferenceViewController;

/** Save user/app preferences to the device */
- (void) savePreferences;

/** Present a new instance of the CIMAPreferencesViewController within a navigation controller with a Done button
 @param parentViewController the controller which should present the preferences view controller */
- (void) showPreferences:(UIViewController*)parentViewController;

/** Read an application level preference
 @param saveTag corresponds to the <CIMAPreferenceItem> in the property applicationPreferenceItems */
- (CIMAPreferenceItem*) applicationPreferenceItemForSaveTag:(NSString*)saveTag;

/** Read a user level preference
 @param saveTag corresponds to the <CIMAPreferenceItem> in the property userPreferenceItems */
- (CIMAPreferenceItem*) userPreferenceItemForSaveTag:(NSString*)saveTag;

#pragma mark - LogMesssage

/** Use macros CIMALogDebug, CIMALogInfo, CIMALogWarn, CIMALogError rather than calling this method directly.
 Return YES if the specified log level should print, according to the property logLevel
 @param level log level */
- (BOOL) willLogAtLevel:(CIMALogLevelType)level;

/** Use macros CIMALogDebug, CIMALogInfo, CIMALogWarn, CIMALogError rather than calling this method directly.
 Log a message to the console and/or server, depending on CIMAService properties
 @param level log level
 @param timestamp timestamp
 @param message log message
 @param messageLocation location information such as method name and line number */
- (void) logMessageWithLevel:(CIMALogLevelType)level
                   timestamp:(NSDate*)timestamp
                     message:(NSString*)message
             messageLocation:(NSString*)messageLocation;

/** Use macros CIMALogExceptionDebug, CIMALogExceptionInfo, CIMALogExceptionWarn, CIMALogExceptionError rather than calling this method directly.
 Log a message to the console and/or server, depending on CIMAService properties
 @param level log level
 @param timestamp timestamp
 @param message log message
 @param messageLocation location information such as method name and line number
 @param exception exception */
- (void) logExceptionWithLevel:(CIMALogLevelType)level
                     timestamp:(NSDate*)timestamp
                       message:(NSString*)message
               messageLocation:(NSString*)messageLocation
                     exception:(NSException*)exception;


#pragma mark - ResponseTime

/** Log a response time to the console and/or server, depending on CIMAService properties
 typically called from within the framework
 @param transactionId transaction id string
 @param sentAt timestamp to log
 @param receivedAt timestamp to log */
- (void) addResponseTimeWithTransactionId:(NSString*)transactionId
                                   sentAt:(NSDate*)sentAt
                               receivedAt:(NSDate*)receivedAt;

/** Log a response time to the console and/or server, depending on CIMAService properties
 @param url url to log
 @param sentAt timestamp to log
 @param receivedAt timestamp to log */
- (void) addResponseTimeWithUrl:(NSString*)url
                         sentAt:(NSDate*)sentAt
                     receivedAt:(NSDate*)receivedAt;


#pragma mark - ScreenView

/** Log a screen view to the console and/or server, depending on CIMAService properties
 @param controller controller being presented. The title property of controller will be used to log the screenview */
- (void) startScreenView:(UIViewController*)controller;

/** Log a screen view to the console and/or server, depending on CIMAService properties
 @param controller being presented
 @param name string to log for this screenview */
- (void) startScreenView:(UIViewController*)controller name:(NSString*)name;

/** Log a screen view to the console and/or server, depending on CIMAService properties
 @param controller being dismissed */
- (void) endScreenView:(UIViewController*)controller;

/** Log a screen view to the console and/or server, depending on CIMAService properties
 Typically startScreenView / endScreenView are preferable to this method
 @param name name to log
 @param start timestamp to log
 @param end timestamp to log */
- (void) addScreenViewWithName:(NSString*)name
                         start:(NSDate*)start
                           end:(NSDate*)end;


#pragma mark - Events
/** Log an event to the console and/or server, depending on CIMAService properties
 @param name name to log
 @param key key to log
 @param value value to log */
- (void) addEventWithName:(NSString*)name
                      key:(NSString*)key
                    value:(NSString*)value;

/** Log an event to the console and/or server, depending on CIMAService properties
 @param name name to log
 @param timestamp timestamp to log
 @param key key to log
 @param value value to log */
- (void) addEventWithName:(NSString*)name
                timestamp:(NSDate*)timestamp
                      key:(NSString*)key
                    value:(NSString*)value;

/** Log an event to the console and/or server, depending on CIMAService properties
 @param name name to log
 @param dict dictionary of properties to log */
- (void) addEventWithName:(NSString*)name
               properties:(NSDictionary*)dict;

/** Log an event to the console and/or server, depending on CIMAService properties
 @param name name to log
 @param timestamp timestamp to log
 @param dict dictionary of properties to log */
- (void) addEventWithName:(NSString*)name
                timestamp:(NSDate*)timestamp
               properties:(NSDictionary*)dict;


#pragma mark - Window orientation

/** Return the supported interface orientation mask (UIInterfaceOrientationMask)
 based first on whether the topmost view controller implements the restrictedRotation method of the CIMARotationCheck protocol
 otherwise based on the application level UI orientation mask (Info.plist)
 @param window window
 @return UIInterfaceOrientationMask */
- (NSUInteger) supportedInterfaceOrientationsForWindow:(UIWindow *)window;


@end
