//
//  CIMASmapDemoApplicationServerInterface.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 10/4/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

@class CIMARequest, CIMAResponse;

/** A collection of methods implementing a SMAP Demo server */
@protocol CIMASmapDemoApplicationServerInterface

/** Return whether the server is active */
- (BOOL) isActive;

/** Respond to the request
 @param request CIMA request object */
- (CIMAResponse*) respondToRequest:(CIMARequest*)request;

@end
