/*
 * Copyright 2012 Applifier
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#import <Foundation/Foundation.h>

typedef void(^EveryplayRequestResponseHandler)(NSURLResponse *response, NSData *responseData, NSError *error);
typedef void(^EveryplayRequestSendingProgressHandler)(unsigned long long bytesSend, unsigned long long bytesTotal);

enum EveryplayRequestMethod {
    EveryplayRequestMethodGET = 0,
    EveryplayRequestMethodPOST,
    EveryplayRequestMethodPUT,
    EveryplayRequestMethodDELETE,
    EveryplayRequestMethodHEAD
};
typedef enum EveryplayRequestMethod EveryplayRequestMethod;

@class NXOAuth2Request;
@class EveryplayAccount;

@interface EveryplayRequest : NSObject {
@private
    NXOAuth2Request *oauthRequest;
}


#pragma mark Class Methods

+ (id)   performMethod:(EveryplayRequestMethod)aMethod
            onResource:(NSURL *)resource
       usingParameters:(NSDictionary *)parameters
           withAccount:(EveryplayAccount *)account
sendingProgressHandler:(EveryplayRequestSendingProgressHandler)progressHandler
       responseHandler:(EveryplayRequestResponseHandler)responseHandler;

+ (id)   performMethod:(EveryplayRequestMethod)aMethod
            onResource:(NSURL *)resource
       usingParameters:(NSDictionary *)parameters
           withClientId:(NSString *)clientId
sendingProgressHandler:(EveryplayRequestSendingProgressHandler)progressHandler
       responseHandler:(EveryplayRequestResponseHandler)responseHandler;

+ (id)   performMethod:(EveryplayRequestMethod)aMethod
            onResource:(NSURL *)resource
       usingParameters:(NSDictionary *)parameters
sendingProgressHandler:(EveryplayRequestSendingProgressHandler)progressHandler
       responseHandler:(EveryplayRequestResponseHandler)responseHandler;

+ (id)   createRequestWithMethod:(EveryplayRequestMethod)aMethod
                      onResource:(NSURL *)aResource
                 usingParameters:(NSDictionary *)someParameters;

+ (void)cancelRequest:(id)request;

+ (EveryplayRequestMethod) requestMethodWithString:(NSString *)method;
+ (NSString *) stringFromMethod:(EveryplayRequestMethod)method;

#pragma mark Initializer
- (id)initWithMethod:(EveryplayRequestMethod)aMethod resource:(NSURL *)aResource;

#pragma mark Accessors

@property (nonatomic, readwrite, retain) EveryplayAccount *account;
@property (nonatomic, assign) EveryplayRequestMethod requestMethod;
@property (nonatomic, readwrite, retain) NSURL *resource;
@property (nonatomic, readwrite, retain) NSDictionary *parameters;


#pragma mark Signed NSURLRequest

- (NSURLRequest *)signedURLRequest;

#pragma mark Perform Request

- (void)performRequestWithSendingProgressHandler:(EveryplayRequestSendingProgressHandler)progressHandler
                                 responseHandler:(EveryplayRequestResponseHandler)responseHandler;

#pragma Cancel Request

- (void)cancel;

@end