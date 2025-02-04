//
//  GameSDK.h
//  GameSDK
//
//  Created by Nero-Macbook on 10/29/21.
//

#import <Foundation/Foundation.h>
#import "GameInfo.h"
#import "IAPDataRequest.h"
#import "FirebaseManager.h"
#import "LoginDelegate.h"
#import "IdAppTracking.h"
#import "FacebookManager.h"
#import "AppleIAP.h"
#import <UIKit/UIKit.h>
#import <FBSDKCoreKit/FBSDKCoreKit.h>
#import <FBSDKLoginKit/FBSDKLoginKit.h>
#import "GTrackingManager.h"

@interface GameSDK : NSObject<UIApplicationDelegate, FIRMessagingDelegate>
{
    
}

+ (GameSDK *) sharedInstance;
+ (IdAppTracking *) ServerIdTracking;
+ (FacebookManager *) Facebook;
+ (AppleIAP *) AppleIAP;
+ (GTrackingManager *) GTracking;
+ (FirebaseManager *) Firebase;
@property (nonatomic, strong) GameInfo *gameInfo;

- (void) initSdk;
- (void) initSdk:(void(^)(NSDictionary *))loadCallback;

- (void) showSignInView:(UIViewController *)viewParent andResultDelegate:(id<LoginDelegate>) loginResultDelegate;
- (void) IDSignOut:(id<LogoutDelegate>) logoutDelegate;
//IAP
- (void) showIAP:(IAPDataRequest *) iapData andMainView:(UIViewController *) mainView andIAPDelegate:(id) iAPDelegate;
//tracking
- (void)applicationDidBecomeActive:(UIApplication *)application;
- (BOOL)application:(UIApplication *)app
            openURL:(NSURL *)url
            options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;
- (BOOL)application:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

- (BOOL) deleteAccountAllow;
- (void) deleteAcount:(UIViewController *) mainView andCallback:(void(^)(NSDictionary *))callback;
- (void) deleteAcount:(void(^)(NSString *))callback;
- (NSString *) getSdkVersion;
- (void) showFloatingButton:(UIViewController *)mainView;
@end
