/*
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership.  The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License.  You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing,
 software distributed under the License is distributed on an
 "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied.  See the License for the
 specific language governing permissions and limitations
 under the License.
 */

#import "CDVPlugin.h"
#import "CDVInvokedUrlCommand.h"
#import "CDVScreenOrientationDelegate.h"

@class CDVInAppBrowserViewController;

@interface CDVInAppBrowser : CDVPlugin {}

@property (nonatomic, retain) CDVInAppBrowserViewController* inAppBrowserViewController;

- (void)open:(CDVInvokedUrlCommand*)command;
- (void)close:(CDVInvokedUrlCommand*)command;

@end

@interface CDVInAppBrowserViewController : UIViewController <UIWebViewDelegate>{}

@property (nonatomic, strong) IBOutlet UIWebView* webView;
@property (nonatomic, strong) IBOutlet UIBarButtonItem* closeButton;
@property (nonatomic, strong) IBOutlet UILabel* addressLabel;
@property (nonatomic, strong) IBOutlet UIBarButtonItem* backButton;
@property (nonatomic, strong) IBOutlet UIBarButtonItem* forwardButton;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView* spinner;
@property (nonatomic, strong) IBOutlet UIToolbar* toolbar;

@property (nonatomic, weak) id <CDVScreenOrientationDelegate> orientationDelegate;
@property (nonatomic, strong) NSString* userAgent;

- (void)close;
- (void)navigateTo:(NSString*)url;
- (void)showLocationBar:(BOOL)show;

- (id)initWithUserAgent:(NSString*)userAgent;

@end

@interface CDVInAppBrowserOptions : NSObject {}

@property (nonatomic, assign) BOOL location;

+ (CDVInAppBrowserOptions*)parseOptions:(NSString*)options;

@end
