//
//  CIMASmapDemoAuthenication.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 10/3/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

/** Authentication state for the SMAP demo server */
typedef NS_ENUM(NSUInteger, CIMASmapDemoAuthenicationState)
{
    /** OK */
    CIMASmapDemoAuthenicationStateOk,
    /** OK, but password about to expire */
    CIMASmapDemoAuthenicationStateOkButPasswordAboutToExpire,
    /** Account disabled */
    CIMASmapDemoAuthenicationStateAccountDisabled,
    /** Account expired */
    CIMASmapDemoAuthenicationStateAccountExpired,
    /** Token expired */
    CIMASmapDemoAuthenicationStateTokenExpired,
    /** Invalid credentials */
    CIMASmapDemoAuthenicationStateInvalidCredentials
};

/** Represents the user authentication parameters for a SMAP demo server */
@interface CIMASmapDemoAuthenication : NSObject

/** A dictionary of authorized users, in which the keys are AUID strings and the values are password strings
 default: {adam, a}, {anna, a}, {dawn, d}, {doug, d}, {emma, e}, {eric, e}, {fred, f}, {jane, j}, {john, j}, {randy, r}*/
@property (nonatomic, strong) NSMutableDictionary *users;

/** A set of AUID strings for disabled users
 default: dawn, doug */
@property (nonatomic, strong) NSMutableSet *disabledUsers;

/** A set of AUID strings for expired users
 default: emma, eric */
@property (nonatomic, strong) NSMutableSet *expiredUsers;

/** A set of AUID strings for users about to expire
 default: adam, anna */
@property (nonatomic, strong) NSMutableSet *aboutToExpireUsers;

/** Maximum login token duration in seconds
 default: 10 minutes */
@property (nonatomic, assign) NSTimeInterval maxTokenDuration;

/** Maximum login token idle duration in seconds
 default: 5 minutes */
@property (nonatomic, assign) NSTimeInterval maxIdleTokenDuration;

/** initialize object with a dictionary of users and default token duration values
 @param users dictionary of users, in which the keys are AUID strings and values are password strings */
- (id) initWithUsers:(NSDictionary*)users;

/** initialize object with a dictionary of users and token durations
 @param users dictionary of users, in which the keys are AUID strings and values are password strings
 @param maxTokenDuration maximum login token duration in seconds
 @param maxIdleTokenDuration maximum login token idle duration in seconds */
- (id) initWithUsers:(NSDictionary*)users
    maxTokenDuration:(NSTimeInterval)maxTokenDuration
maxIdleTokenDuration:(NSTimeInterval)maxIdleTokenDuration;

/** initialize object
 @param users dictionary of users, in which the keys are AUID strings and values are password strings
 @param disabledUsers set of AUID strings of disabled users
 @param expiredUsers set of AUID strings of expired users
 @param aboutToExpireUsers set of AUID strings of about to expire users
 @param maxTokenDuration maximum login token duration in seconds
 @param maxIdleTokenDuration maximum login token idle duration in seconds */
- (id) initWithUsers:(NSDictionary*)users
       disabledUsers:(NSSet*)disabledUsers
        expiredUsers:(NSSet*)expiredUsers
  aboutToExpireUsers:(NSSet*)aboutToExpireUsers
    maxTokenDuration:(NSTimeInterval)maxTokenDuration
maxIdleTokenDuration:(NSTimeInterval)maxIdleTokenDuration;

/** get SSO token if the AUID and password are valid
 @param auid username
 @param password password
 @param ssoToken (out) pointer to token if user is authorized */
- (CIMASmapDemoAuthenicationState) ssoTokenForAuid:(NSString*)auid password:(NSString*)password ssoToken:(NSString**)ssoToken;

/** get AUID if the SSO token is valid
 @param ssoToken token
 @param auid (out) pointer to auid string if token is valid */
- (CIMASmapDemoAuthenicationState) auidFromSsoToken:(NSString*)ssoToken auid:(NSString**)auid;

/** create and initialize object with default values:
 Users{auid,password}: {adam, a}, {anna, a}, {dawn, d}, {doug, d}, {emma, e}, {eric, e}, {fred, f}, {jane, j}, {john, j}, {randy, r}
 DisabledUsers: dawn, doug
 ExpiredUsers: emma, eric
 AboutToExpireUsers: adam, anna
 MaxTokenDuration: 10 minutes
 MaxIdleTokenDuration: 5 minutes */
+ (CIMASmapDemoAuthenication*) defaultAuthentication;

/** create and initialize object with a dictionary of users and default token duration values
 @param users dictionary of users, in which the keys are AUID strings and values are password strings */
+ (CIMASmapDemoAuthenication*) authenicationWithUsers:(NSDictionary*)users;

/** create and initialize object with a dictionary of users and token durations
 @param users dictionary of users, in which the keys are AUID strings and values are password strings
 @param maxTokenDuration maximum login token duration in seconds
 @param maxIdleTokenDuration maximum login token idle duration in seconds */
+ (CIMASmapDemoAuthenication*) authenicationWithUsers:(NSDictionary*)users
                                     maxTokenDuration:(NSTimeInterval)maxTokenDuration
                                 maxIdleTokenDuration:(NSTimeInterval)maxIdleTokenDuration;

/** get the string description for the authentication state
 @param state authentication state */
+ (NSString*) descriptionForState:(CIMASmapDemoAuthenicationState)state;

@end
