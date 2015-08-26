//
//  CIMASmapDemoApplicationServer.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 10/4/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CIMA/CIMASmapDemoApplicationServerInterface.h>

/** A demo application server for testing, development, and demo purposes */
@interface CIMASmapDemoApplicationServer : NSObject<CIMASmapDemoApplicationServerInterface>

/** when the server is not active, it will not respond to requests */
@property (nonatomic, assign) BOOL           isActive;

/** minimum response time in seconds */
@property (nonatomic, assign) NSTimeInterval minResponseTime;

/** maximum response time in seconds */
@property (nonatomic, assign) NSTimeInterval maxResponseTime;

/** counter of messages received */
@property (readonly, nonatomic, assign) NSUInteger messageCount;

/** initialize application server with specified response time:
 @param minResponseTime minimum response time in seconds
 @param maxResponseTime maximum response time in seconds */
- (id) initWithMinResponseTime:(NSTimeInterval)minResponseTime maxResponseTime:(NSTimeInterval)maxResponseTime;

/** create and initialize application server with default response times:
 isActive = YES
 minResponseTime = 1.0 seconds
 maxResponseTime = 1.1 seconds */
+ (CIMASmapDemoApplicationServer*) defaultApplicationServer;

/** create and initialize application server with specified response time:
 @param minResponseTime minimum response time in seconds
 @param maxResponseTime maximum response time in seconds */
+ (CIMASmapDemoApplicationServer*) serverWithMinResponseTime:(NSTimeInterval)minResponseTime maxResponseTime:(NSTimeInterval)maxResponseTime;

/** return the custom HTTP header field name for the AUID */
+ (NSString*) auidHeaderField;

@end
