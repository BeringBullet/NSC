//
//  CIMATransportMethod.h
//  CIMA Framework
//
//  Created by Johnson, Randall L. (MSFC-IS80)[UNITeS] on 9/28/11.
//  Copyright 2011 Center for Internal Mobile Applications (CIMA). All rights reserved.
//

/** HTTP method */
typedef NS_ENUM(NSUInteger, CIMATransportMethodType) {
    /** Default - GET */
    CIMATransportMethodDefault,
    /** GET */
    CIMATransportMethodHttpGet,
    /** POST */
    CIMATransportMethodHttpPost,
    /** PUT */
    CIMATransportMethodHttpPut,
    /** DELETE */
    CIMATransportMethodHttpDelete
};
