//
//  CIMASmapDemoConnection.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 10/4/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CIMA/CIMALogLevel.h>
#import <CIMA/CIMASmapDemoApplicationServerInterface.h>

@class CIMAMap, CIMASmapDemoAuthenication, CIMASmapDemoAuthorization, CIMASmapDemoApplicationServer;

/** Represents a connection to the SMAP server, for demo and testing purposes */
@interface CIMASmapDemoConnection : NSObject

/** User authentication object */
@property (nonatomic,strong) CIMASmapDemoAuthenication     *authenication;

/** User/Device/App Version authorization blacklist/whitelist object */
@property (nonatomic,strong) CIMASmapDemoAuthorization     *authorization;

/** Demo Server Object */
@property (nonatomic,strong) id<CIMASmapDemoApplicationServerInterface> applicationServer;

/** Application log level */
@property (nonatomic,assign) CIMALogLevelType              logLevel;

/** Report user's GPS location to server */
@property (nonatomic,assign) BOOL                          recordLocation;

/** Map of configuration key/value pairs for application specific use */
@property (nonatomic,strong) CIMAMap                       *configurationMap;

/** Maximum session duration in seconds */
@property (nonatomic,assign) NSTimeInterval                maxSessionDuration;

/** Maximum session idle duration in seconds */
@property (nonatomic,assign) NSTimeInterval                maxIdleSessionDuration;

/** Initialize the object
 @param authenication user authentication object
 @param applicationServer demo server object
 defaults:
 LogLevel: CIMALogLevelInfo
 ConfigurationMap: (none)
 MaxSessionDuration: 20 minutes
 MaxIdleSessionDuration: 3 minutes */
- (id) initWithAuthenication:(CIMASmapDemoAuthenication*)authenication
           applicationServer:(id<CIMASmapDemoApplicationServerInterface>)applicationServer;

/** Initialize the object
 @param authenication user authentication object
 @param authorization authorization whitelist/blacklist object
 @param applicationServer demo server object
 @param logLevel application log level
 @param recordLocation flag for recording user location
 @param configurationMap optional map of configuration key/value pairs for application specific use
 @param maxSessionDuration maximum session duration in seconds
 @param maxIdleSessionDuration maximum session idle duration in seconds */
- (id) initWithAuthenication:(CIMASmapDemoAuthenication*)authenication
               authorization:(CIMASmapDemoAuthorization*)authorization
           applicationServer:(id<CIMASmapDemoApplicationServerInterface>)applicationServer
                    logLevel:(CIMALogLevelType)logLevel
              recordLocation:(BOOL)recordLocation
            configurationMap:(CIMAMap*)configurationMap
          maxSessionDuration:(NSTimeInterval)maxSessionDuration
      maxIdleSessionDuration:(NSTimeInterval)maxIdleSessionDuration;

/** Create and initialize the object with default values:
 Authenication: [CIMASmapDemoAuthenication defaultAuthentication]
 Authorization: [CIMASmapDemoAuthorization defaultAuthorization]
 ApplicationServer: [CIMASmapDemoApplicationServer defaultApplicationServer]
 LogLevel: CIMALogLevelInfo
 ConfigurationMap: (none)
 MaxSessionDuration: 20 minutes
 MaxIdleSessionDuration: 3 minutes */
+ (CIMASmapDemoConnection*) defaultConnection;


/** Create and initialize the object
 @param authenication user authentication object
 @param applicationServer demo server object
 defaults:
 LogLevel: CIMALogLevelInfo
 ConfigurationMap: (none)
 MaxSessionDuration: 20 minutes
 MaxIdleSessionDuration: 3 minutes */
+ (CIMASmapDemoConnection*) connectionWithAuthenication:(CIMASmapDemoAuthenication*)authenication
                                      applicationServer:(id<CIMASmapDemoApplicationServerInterface>)applicationServer;

@end
