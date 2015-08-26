//
//  SmapPluginConfiguration
//  SMAP Plugin for Cordova
//
//  Created by Pullias, Jason M. (MSFC-IS60)[EAST] on 1/28/15.
//  Copyright (c) 2015 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import "SmapPluginConfiguration.h"
#import <CIMA/CIMA.h>

@implementation SmapPluginConfiguration

// End user should modify this function as appropriate for the application
+ (void)configureSmap {
    NSString *appId = @"Test"; // test appId supports /echo & /info endpoints for the sample app
    CIMAService *cimaService = [CIMAService initializeServiceWithApplicationId:appId];
    // Optional
    cimaService.buildType = CIMABuildAlpha;
    cimaService.environment = CIMAEnvironmentTest;
    
    cimaService.environmentPassword = @"cima";
    cimaService.logLevel = CIMALogLevelInfo;
    cimaService.logToConsole = YES;
    
    cimaService.requiresAuthentication = YES;
    cimaService.allowsSavedPassword    = YES;
    
    cimaService.doesShowProgressDialog = NO;
}

@end
