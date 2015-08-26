//
//  SMAPPlugin.h
//  SMAP Plugin for Cordova
//
//  Created by Pullias, Jason M. (MSFC-IS60)[EAST] on 1/28/15.
//  Copyright (c) 2015 Center for Internal Mobile Applications (CIMA). All rights reserved.
//


#import <Foundation/Foundation.h>
#import <Cordova/CDVPlugin.h>
#import <CIMA/CIMA.h>

@interface SMAPPlugin : CDVPlugin <CIMASmapServiceDelegate>

- (void)auid:(CDVInvokedUrlCommand*)command;
- (void)log:(CDVInvokedUrlCommand*)command;
- (void)sendRequest:(CDVInvokedUrlCommand*)command;
- (void)signout:(CDVInvokedUrlCommand*)command;

@end