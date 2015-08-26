'use strict';
var cordova = require('cordova');

/** interface to logging function in CIMA framework
    @param {string} level log level string "DEBUG", "INFO", "WARN", "ERROR"
    @param {string} message string to log 
    @private */
var cimaLog = function (level, message) {
    cordova.exec(null, null, 'SMAP', 'log', [level, message]);
};

/** function to create CIMA request object
    @param {string} url URL path component
    @param {string} method HTTP method (GET, POST, PUT, DELETE)
    @param {object} data body of HTTP request, string or JSON object 
    @param {object} httpHeaders http headers, {'Header-key:':'header-value','Set-Cookie:':'[Cookie 1, Cookie 2]'} 
    @private */
var makeRequestObject = function (url, method, data, headers) {
    return {
        url: url || null,
        method: method || 'GET',
        data: data || null,
        headers: headers || null
    };
};

// register event handler to send CIMA events to JS world
(function () {
    function onSuccessHandler(info) {
        if (info && info.name) {
            cordova.fireWindowEvent(info.name, info);
        }
    }
    cordova.exec(onSuccessHandler, null, 'SMAP', 'registerEventListener', []);
}());

/**
 * Smap object provides an interface to the native CIMA framework and is exported to window.smap
 * @module Smap
 */
module.exports = {
    /** 
     * Get the AUID (username) of the logged in user
       @param {function} onSuccessHandler the function to call with the AUID string
     */
    getAuid : function (onSuccessHandler) {
        cordova.exec(onSuccessHandler, null, 'SMAP', 'auid', []);
    },
    /** 
     * Determine if the SMAP server is currently reachable, due to the device being offline or online
       @param {function} onSuccessHandler the function to call with the bool result
     */
    isReachable: function (onSuccessHandler) {
        cordova.exec(onSuccessHandler, null, 'SMAP', 'isReachable', []);
    },
    /** 
     * Determine if a session has been started
       @param {function} onSuccessHandler the function to call with the bool result
     */
    isSessionStarted: function (onSuccessHandler) {
        cordova.exec(onSuccessHandler, null, 'SMAP', 'isSessionStarted', []);
    },
    /** 
     * Log to the server and the mobile device debug console (apple console or android logcat)
       @param {string} message log message
     */
    logDebug : function (message) {
        cimaLog("DEBUG", message);
    },
    /** 
     * Log to the server and the mobile device debug console (apple console or android logcat)
       @param {string} message log message
     */
    logInfo : function (message) {
        cimaLog("INFO", message);
    },
    /** 
     * Log to the server and the mobile device debug console (apple console or android logcat)
       @param {string} message log message
     */
    logWarn : function (message) {
        cimaLog("WARN", message);
    },
    /** 
     * Log to the server and the mobile device debug console (apple console or android logcat)
       @param {string} message log message
     */
    logError : function (message) {
        cimaLog("ERROR", message);
    },
    /** 
     * Send an HTTP request with string data to the server
       @param {string} url URL path component
       @param {function} onSuccessHandler the function to call with the HTTP response body string
       @param {function} onErrorHandler the function to call with an error string
       @param {string} method HTTP method (GET, POST, PUT, DELETE)
       @param {string} data body of HTTP request
       @param {object} httpHeaders http headers, {'Header-key:':'header-value','Set-Cookie:':'[Cookie 1, Cookie 2]'}      
     */
    sendRequest : function (url, onSuccessHandler, onErrorHandler, method, data, httpHeaders) {
        cordova.exec(onSuccessHandler, onErrorHandler, 'SMAP', 'sendRequest', [makeRequestObject(url, method, data, httpHeaders)]);
    },
    /** 
     * Send an HTTP request with a JSON object to the server
       @param {string} url URL path component
       @param {function} onSuccessHandler the function to call with the HTTP response body as a JSON object
       @param {function} onErrorHandler the function to call with an error string
       @param {string} method HTTP method (GET, POST, PUT, DELETE)
       @param {object} jsonObject body of HTTP request       
       @param {object} httpHeaders headers, {'Header-key:':'header-value','Set-Cookie:':'[Cookie 1, Cookie 2]'}   
     */
    sendJSON : function (url, onSuccessHandler, onErrorHandler, method, jsonObject, httpHeaders) {
        cordova.exec(onSuccessHandler, onErrorHandler, 'SMAP', 'sendRequest', [makeRequestObject(url, method, jsonObject, httpHeaders)]);
    },
    /** 
     * Sign out and display the login screen
     */
    signOut : function () {
        cordova.exec(null, null, 'SMAP', 'signout', []);
    }
};