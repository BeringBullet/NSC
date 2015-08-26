//
//  CIMASmapService.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 10/3/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

#import <Foundation/Foundation.h>

@class CIMASmapMessageData;

/** Collection of methods that will be called to inform an object the result of SMAP requests */
@protocol CIMASmapServiceDelegate

/** SMAP request finished successfully
 @param smapMessageData SMAP message data */
- (void) smapServiceDidFinish:(CIMASmapMessageData*)smapMessageData;

@optional
/** SMAP request failed
 @param smapMessageData SMAP message data */
- (void) smapServiceDidFail:(CIMASmapMessageData*)smapMessageData;

@end
