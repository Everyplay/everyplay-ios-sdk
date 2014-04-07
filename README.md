Welcome to Everyplay. To get started, make sure you have an account registered, and that you have a unique client ID
for your game. You can get these along with the latest integration instructions at https://developers.everyplay.com/

You can always download the latest SDK upgrades directly from https://github.com/everyplay/everyplay-ios-sdk

Looking for Android version? See https://github.com/everyplay/everyplay-android-sdk

Everyplay SDK is licensed under the Apache License, Version 2.0 (http://www.apache.org/licenses/LICENSE-2.0.html)

For now, each SDK release has an expiration date. After expiring, there's a warning dialog on launch
that recommends to upgrade the SDK. Apps downloaded from the App Store won't have this behaviour.

Current and previous expiration dates:

- 2014-05-31 (releases from 1.7.4 to CURRENT)
- 2014-02-28 (releases from 1.7.1 to 1.7.3)
- 2013-11-25 (releases from 1.6 to 1.7)
- 2013-08-31 (releases from 1.4.1 to 1.5.1)
- 2013-05-31 (releases from 1.0.13 to 1.4)
- 2013-03-31 (releases from 1.0.10 to 1.0.12)
- 2013-02-28 (releases from 1.0 to 1.0.9)

Everyplay SDK/iOS - Release Notes
=================================

### v1.7.6 - April 7th 2014 (build 1760)

- Generic:
    - Fixed a regression from 1.7.5 SDK with using disableSingleCoreDevices
      property, in some non-Unity cases it could have caused screen rendering
      to halt entirely

    - Fixed Twitter sharing for iOS 7.1 devices, a workaround required for
      previous releases was now causing a crash

    - Fixed some rare OpenGL graphics state issues

    - Fixed potential ES3 linking errors for some engine build environments

    - Improved SpriteKit support

    - Generic Live FaceCam stability and performance improvements

    - Fixed Live Facecam from showing preview border in audio only mode,
      previously it was required to disable preview box manually

    - Improved startRecording internal behaviour so there's less need for handling
      everyplayReadyForRecording: delegate in some early initialization scenarios

- Unity plugin:
    - New graphics integration support for iOS

### v1.7.5 - March 11th 2014 (build 1751)

- Generic:
    - Custom engines: OpenGL pipeline changes for recording support
      are now entirely optional (for advanced use cases), following
      the behaviour from the Android version

    - OpenGL performance and state handling improvements, including
      OpenGL ES3 support

    - Improved support for GLKit and SpriteKit, new upgraded
      examples available at:

      https://github.com/Everyplay/everyplay-ios-examples

    - UI localization support for Simplified Chinese

    - Full OpenAL spatial audio support

    - OpenAL/CocosDenshion: Muting sound effects volume would also
      mute background music, fixed

    - Fixed a merging issue of videos with no audio track

    - 64bit support: Apps downloaded from the App Store didn't
      remove the sandbox status, fixed

    - Fixed a regression that prevented apps from launching on iOS 4.x,
      giving error related to "Symbol not found: _objc_storeWeak"

- UE3:
    - Potential fix for audio processing on certain older generation devices

- Unity plugin:
    - Now supports changing the Live FaceCam preview border color

### v1.7.4 - February 11th 2014 (build 1741)

- Generic:
    - Build 1741: Fixed localization related bundle lookup error
      in some cases (NSInvalidArgumentException error with
      [NSPlaceholderString initWithFormat:locale:arguments:])

    - Initial spatial audio support with OpenAL

    - Fixed rare video merging issues and video player UI behaviour

    - New internal notification manager functionality that improves
      handling of certain scenarios for better Live FaceCam support

    - New EveryplayFaceCam class option to set Live FaceCam preview
      box border color, defaults to white

    - Fixed certain rare audio issues on developer triggered pause/resume
      handling while entering background and coming back

    - Fixed OpenAL audio resource leak that happens in some scenarios,
      potentially leading to no sound

    - Added EveryplayFeatures.disableOpenALMessages toggle to turn off
      logging for non-implemented OpenAL methods or parameters used

### v1.7.3 - January 29th 2014 (build 1730)

- Generic:
    - Breaking API change for Live FaceCam support: Due to new iOS7
      user permission additions, it's now required to ask for a grant
      before starting sessions through [[Everyplay sharedInstance] faceCam]

      If the permission hasn't been yet asked, calling
      [[[Everyplay sharedInstance] faceCam] requestRecordingPermission];
      will bring up standard iOS permission dialog, following calls
      give the state the user previously answered

      You can later check the granted state either by using the delegate handler
      or asking from the [[Everyplay sharedInstance] faceCam].isRecordingPermissionGranted
      property

    - New delegate for Live FaceCam permission grant:
      (void)everyplayFaceCamRecordingPermission:(NSNumber *)granted

    - Following the changes in 1.7.2, more improvements and bugfixes for
      developer triggered pause/resume handler while entering background
      and coming back

    - Improved redirectURI validation

    - UI localization support, starting with Japanese and Korean

- Unity plugin:
    - Compatibility fixes against Unity 4.3.3 WWW class

    - New methods for asking Live FaceCam permission grant from the
      user before allowed to call FaceCamStartSession:
      - public bool FaceCamIsRecordingPermissionGranted();
      - public void FaceCamRequestRecordingPermission();

    - New delegate for Live FaceCam permission grant, FaceCamRecordingPermission

    - Improved test scripts in Everyplay.prefab with new features

### v1.7.2 - November 25th 2013 (build 1720)

- Generic:
    - 64bit support: Fixed broken video editor UI and other
      internal compatibility fixes

    - Improved notification handling on certain cases that involves
      pause/resume of recording or continuing recording, giving back
      more control to developer

    - Fixed a bug from handling multiple AVAudioPlayer instances
      with separate delegate handlers

    - Initial AVAudioPlayer level metering support

- Cocos2d:
    - Added support for Cocos2d-x 3.0 alpha

- Unity plugin:
    - Fixed an issue with MSAA support being broken for
      Unity 4.1 and later releases

### v1.7.1 - November 12th 2013 (build 1710)

- Generic:
    - Video editor on iOS 7 now properly checks for user permissions before
      adding buttons for doing audio and/or video FaceCam commentary

    - Video editor now allows to trim shorter videos from longer recordings

- Unity plugin:
    - Added support for Unity 4.3

### v1.7 - November 4th 2013 (build 1700)

- Generic:
    - Main focus on improving thread-safety and stability, iOS 7 compatibility,
      ARC memory management behaviour and fixing known, hard to reproduce issues
      that we've seen from developer submitted crash logs

    - Everyplay.bundle graphics have been updated towards more iOS 7
      look and feel

    - Everyplay sidebar population and handling has been rewritten
      with better reliability and showing icon graphics

    - Internal changes for upcoming landscape view support on iPhone

    - Fixes to keyboard layout behaviour in some views and iOS versions

    - Video player view now shows more info about the video

    - Improved video editor trimming behaviour and touch area size

    - Improved network reachability logic

    - AVAudioPlayer support improvements

    - Fixed certain iOS 7 related orientation handling issues

    - Fixed a potential crash situation with everyplayUpload* delegate
      and passing NSNumber values

    - Fixed a rare crash from saving gameplay metadata

    - Fixed a rare crash from internal analytics code sending events

    - Fixed a rare crash with everyplayThumbnailReadyAtFilePath: delegate
      and Unity3d

    - Fixed a rare crash from CoreAudio and CFRelease usage

    - Added workaroundLegacyOrientations property to EveryplayCapture

### v1.6.3 - September 23rd 2013 (build 1630)

- Generic:
    - More tweaks against final iOS 7 GM, now built against Xcode 5 GM with
      initial 64bit support

    - Fixed status bar appearance on iOS 7

    - AVAudioPlayer now supports audioPlayerDidFinishPlaying:successfully: delegate

    - Fixed an issue with GameCenter matchmaking API

    - Fixed potential memory leaks

    - Fixed a regression with iPod background music support

    - A/B testing framework improvements

- Cocos2d:
    - Fixed an issue with OpenGL viewport handling

### v1.6.2 - August 30th 2013 (build 1620)

- Generic:
    - New features based on improved thumbnail code in 1.6 SDK series

    - You can now control when the thumbnail(s) are taken by calling
      [[[Everyplay sharedInstance] capture] takeThumbnail]; as many
      times you like and use them within your game UI or provide means
      for sharing to social networks

    - You can now control the resolution of the file based thumbnail
      through thumbnailWidth property in EveryplayCapture

    - Instead of loading a thumbnail from a file based resource, you can
      now pass in your own texture ID and render the thumbnail there directly,
      by using thumbnailTargetTexture* properties in EveryplayCapture

    - New delegate for texture ID based thumbnailing

    - Fixed a regression in 1.6 SDK series that could have resulted to a brief
      black screen while the initialization is in progress

- Unity plugin:
    - Support for new thumbnail features

    - New EveryplayAnimatedThumbnail helper

- EveryplaySoundEngine:
    - Now supports querying AL_SEC_OFFSET with OpenAL

### v1.6.1 - August 22nd 2013 (build 1610)

- Generic:
    - Changed some code that could have led to a false positive
      result from App Store review process, claiming non-public
      API usage in 1.6 SDK

    - Improved closing the new modal share dialog on iOS 5

    - Fixes to audio handling bugs that may have resulted to a muted
      audio in certain situations

    - A/B testing framework improvements while the app is in
      development mode

    - Fix to blurry Everyplay logo on iPad

- EveryplaySoundEngine:
    - Fixed clicking sound issues in OpenAL

### v1.6 - August 14th 2013 (build 1600)

- Generic:
    - New feature: Everyplay sharing can now be triggered as modal dialogue
      while the game is visible on the background. Players can now immediately
      share replay without going through the video player flow

      For suitable scenarios, call [[Everyplay sharedInstance] showEveryplaySharingModal];

    - All around generic recording optimizations and fixes, including
      improved iPad 3 video framerate, video tearing fixes for certain
      random devices, pause/resume handling, fixes for rare avsync issues
      and video framerate on single-core devices

    - Optimized audio recording performance for some extreme cases

    - Fixes to audio handling bugs that may have resulted to a muted
      audio in certain situations

    - AVFoundation AVAudioPlayer support now out of private beta

    - Thumbnail performance and memory optimizations, orientation
      handling and alpha channel fixes

    - Improved video resolution for Retina iPad in some cases

    - CocosDenshion background music support now enabled for older
      single-core devices

    - New built-in A/B testing functionality for certain UX functionality

    - Few potential UI crashes fixed

    - Improved iOS7 support

- UE3:
    - Performance optimizations for Unreal Engine 3

- Unity plugin:
    - Added support for Unity 4.2

    - New method for bringing up modal share dialog, public void ShowSharingModal();

### v1.5.1 - June 27th 2013 (build 1510)

- Generic:
    - Fixed a few OpenGL regressions from 1.5 release, including the
      dreaded OpenGL 0x502 error on certain Unity apps while launching

### v1.5 - June 26th 2013 (build 1501)

- Generic:
    - New feature: Record FaceCam commentary live while playing! FaceCam now
      features recording of video and/or audio from the front facing camera
      while simultaneously recording the gameplay

      Users can now record and share Let's Play style replays, walkthroughs
      and reaction videos. Depending on needs, developers can choose to not
      show live preview video of a camera feed, position built-in preview window
      functionality or use live preview video feed as a texture within the game

      For more info, please read
      https://developers.everyplay.com/doc/Everyplay-Live-FaceCam-integration-to-iOS-game

    - New delegates for FaceCam session and video upload states, so now you can
      thank your players after sharing the video

    - iOS 7 beta workarounds for changed behaviour or regressions

- Unity plugin:
    - Live FaceCam support with new helper methods. For more info, please read
      https://developers.everyplay.com/doc/Everyplay-Live-FaceCam-integration-to-Unity3d-game

    - Merged prefab and helper script for HUD-less recording that was
      previously distributed as a separate package

    - New delegates for FaceCam session and video upload states

    - Added two new methods:
      - public bool IsRecordingSupported();
      - public bool IsSingleCoreDevice();

### v1.4.2 - May 21st 2013 (build 1420)

- Generic:
    - Fixed an issue with MSAA performance while not recording. The issue got
      triggered in certain OpenGL pipeline integrations, such as Unity

    - Fixed an issue with FaceCam mirrored image handling on iOS 5

    - Some bug fixes for the new audio recording core introduced in 1.4 SDK,
      including sample rate handling with iOS 5 on some Unity scenarios

- Unity plugin:
    - Setting a null clientId, secret or redirectURI now triggers an assert,
      to workaround some Unity project situations where the game object
      settings get cleared

- EveryplaySoundEngine:
    - Thread-safety fixes for streaming background music

### v1.4.1 - May 8th 2013 (build 1412)

- Generic:
    - The editor mode in the new video player now launches and shows controls
      faster when loading the replay

    - Minor FaceCam related video editor bug fixes

    - Fixed a regression with OpenGL graphics and use of a stencil buffer

    - Fixed an issue with releasing EveryplayCapture instance and
      re-initializing it, ie. games using native views outside the gameplay
      and initializing OpenGL view several times

    - New expiration date for the SDK build

    - Fixed a 1.4 SDK regression of running against iOS 4 target and a rare
      analytics crash from build 1410

- Everyplay OpenAL:
    - Fixed a clicking sound that could happen with certain type of audio loops

### v1.4 - April 29th 2013 (build 1400)

- Generic:
    - New feature: FaceCam turns replays into stories. Users can now add audio
      and video commentary easily to their replays to talk about their gaming
      moments, share funny commentary and liven it up!

    - Many enhancements and bug fixes to the video player, including better
      touch area handling. The video player also doesn't use EveryplayVideoPlayer.xib
      from Everyplay.bundle anymore, leading to faster memory management in
      some cases

    - Improved PNG size optimizations for Everyplay.bundle, taking less space for
      .IPA packages even after including new assets for the video editor / FaceCam
      functionality

    - New audio recording core

    - There was a potential video framerate issue with 1.2 SDK and later when
      triggering pause/resume recording, fixed

    - Possible bug fixes to some rare crash logs that we've received, but
      haven't managed to reproduce

- EveryplaySoundEngine:

    - Fixed a rare crash when the app wakes up from the background
      and continues playing streaming background music

### v1.3.1 - April 20th 2013 (build 1310)

- Everyplay OpenAL:
    - Improved state handling, there was an issue that got triggered with
      CocosDenshion pauseAllEffects/resumeAllEffects calls

### v1.3 - April 18th 2013 (build 1300)

- Generic:
    - OpenAL and CocosDenshion background music support

    - Added EveryplaySoundEngine class for simple audio playing needs without
      using OpenAL or CocosDenshion

    - The build version used is now printed to the console on app launch, to help
      figuring out if Xcode incorrectly links against wrong Everyplay.framework
      version on some upgrade cases. The build version can also be checked from
      Everyplay views Settings tab on older releases

    - Calling showEveryplay method from a non-main/web thread could result to
      a crash, fixed

    - Fixed a minor video framerate regression on single-core devices after the
      recent UE3 optimization

    - Some videoplayer state handling and return from background fixes

- Everyplay OpenAL:

    - Introducing Everyplay OpenAL (beta), supporting the basic OpenAL use cases
      of a common iOS game or 3rdparty audio libraries such as CocosDenshion.
      Please contact us if you use a feature that's currently not implemented!
      If you encounter implementation bugs, please provide a working test case
      if possible

    - Known issues:

        - alBufferDataStatic behaves the same as alBufferData, so it'll allocate
          sound buffers internally

        - Spatial audio support is partly implemented for the first release

        - No support for setting the output sample rate through
          alcMacOSXMixerOutputRate extension yet

        - When used with CocosDenshion, the background audio music is streamed
          but no hardware decoding support yet for MP3/AAC

- Unity plugin:
      - New method to set target FPS, public void SetTargetFPS(int fps)

### v1.2 - April 3rd 2013 (build 1200)

- Generic:
    - Fixed a rare crash after the uploading has begun

    - Optimized framerate consistency and timing for the recorded video
      on some edge cases, such as..

- UE3:
    - Early support for Unreal Engine 3! For registered Unreal Engine 3 Developers
      only (excluding UDK), please contact us. Demo videos available at
      https://everyplay.com/epic-citadel

- Cocos2d:
    - Fixed a rare view handling issue where the graphics could be left
      in a wrong state after bringing in another view and returning from it

- Unity plugin:
      - New method to increase video quality, public void SetMotionFactor(int factor)

### v1.0.14 - March 19th 2013 (build 15)

- Generic:
    - Repeated pauseRecording/resumeRecording calls could lead to audio and
      video being out of sync or result to video being unplayable, fixed

### v1.0.13 - March 16th 2013 (build 14)

- Generic:
    - Fixed an issue with single-core retina devices (iPhone 4) and Unity 4
      target resolution mode that led to video resolution being too small,
      doesn't affect native resolution usage

- Unity plugin:
    - Now supports Unity 3.5, 4.0 and 4.1 series! To upgrade, re-import
      Everyplay.unitypackage into your project and rebuild Xcode project
      from scratch

    - Spotlight search for locating Everyplay.framework failed from
      folders with spaces, fixed

### v1.0.12 - March 10th 2013 (build 13)

- Generic:
    - GPU optimizations in SDK v1.0.11 broke 16bit MSAA recording support and
      Unity 4 Target Resolution support for non-native resolutions, fixed

    - In some cases the video player showed the wrong icon in Get from
      App Store button, fixed

    - Fixed a rare bug in video trimming that resulted to trimming
      operation not finishing in time

### v1.0.11 - March 4th 2013 (build 12)

- Generic:
    - Faster sharing: It's now possible to directly share gameplays without
      creating an Everyplay account by using iOS 5+ Twitter and iOS 6+ Social
      frameworks. Sharing by mail has been extended to work from the first
      share dialog, previously it was limited to re-sharing

    - Improved framerate for the recorded video when the GPU is heavily
      utilized, also helping some older generation single-core devices
      like iPhone 4 and iPad 1

    - Added disableSingleCoreDevices boolean property to EveryplayCapture,
      to disable recording on devices with A4 chip or older

    - Added lowMemoryDevice boolean property to EveryplayCapture,
      to optimize memory usage at the cost of performance

    - Memory optimization fixes after leaving Everyplay view

    - Added [[Everyplay sharedInstance] showEveryplayWithPath:] method for
      navigating directly to a certain view, such as game id specific feeds

- Unity plugin:
    - Post-processing script now also tries to locate Everyplay.framework
      and bundle from your Unity project directory without using Spotlight,
      improving usability on constant integration / build machines

    - Post-processing script now weak links Twitter (iOS5+) and Social (iOS6+)
      frameworks to your project

    - Additional fixes to skewed graphics buffer if the orientation has changed
      between portrait and landscape modes when coming back from Everyplay view
      to the game

    - Added three new methods:
      - public void SetDisableSingleCoreDevices(bool state);
      - public void SetLowMemoryDevice(bool state);
      - public void ShowWithPath(string path);

### v1.0.10 - February 15th 2013 (build 10)

- Generic:
    - Fixed a rare audio encoder related crash when stopping the recording

    - OpenGL fix for multiple camera viewport usage

### v1.0.9 - February 11th 2013 (build 9)

- Generic:
    - New login flow for faster sharing: New users now immediately gain an Everyplay
      account when sharing their first replay. No email is required and the username
      is optional

    - HUD-less recording support: Now you can record gameplay without UI elements

      Call [[[Everyplay sharedInstance] capture] snapshotRenderbuffer]; after
      you've drawn the core elements of your game, done

    - Continuous recording support, especially suitable for longer online gaming
      sessions. If the recording session goes over the maximum length set,
      the resulting video will have the content recorded within last N minutes

      Set [[Everyplay sharedInstance] capture].maxRecordingMinutesLength property
      to your preferred value, done

    - More improvements to framerate consistency on recorded video

    - Free disk space monitoring and related error handling

    - Fixed audio related crash with multiple audio sources

- Unity plugin:
    - Added two new methods:
      - public bool SnapshotRenderbuffer();
      - public void SetMaxRecordingMinutesLength(int minutes);

### v1.0.8 - February 4th 2013 (build 8)

- Generic:
    - Optimized framerate consistency and timing for the recorded video

    - Improved audio and video synchronization for the recorded video

    - Everyplay.bundle: Removed device specific splash screens,
      reducing the space required for the graphics by 50%

    - Some games triggered screen tearing to the recorded movie files
      on iPad retina resolution, fixed

    - Video player: Fixed replay button behaviour on iOS 5 and
      touch area handling after changing the orientation

    - Optimized loading of Everyplay view via data prefetch

    - Improved analytics

- Cocos2d:
    - Now supports cocos2d-iphone v2.1-rc0

- Unity plugin:
    - Changing orientation between landscape and portrait mode resulted to skewed
      graphics buffer when returning back from Everyplay view to the game, Everyplay
      plugin now triggers a forced orientation check. For apps supporting all
      orientations for gameplay, it's recommended to lock orientation using
      RecordingStarted/RecordingStopped delegates when recording.

    - Added WasClosed delegate that triggers when returning back to the game

    - EveryplayTest script now warns when trying to trigger functionality on editor

### v1.0.7 - January 21st 2013 (build 7)

- Generic:
    - Background upload support
    - Video player shows related videos after the current video ends
    - New initialization method initWithDelegate:andAddRootViewControllerForView:
      for apps without existing view controller

- Cocos2d:
    - More throughly tested support for Cocos2d 1.x, 2.x and Cocos2d-x!
      See online integration walkthrough at https://developers.everyplay.com/doc

- Examples:
    - See Cocos2d examples at our forked cocos2d repositories at
        - https://github.com/Everyplay/cocos2d-iphone/tree/master-v2
        - https://github.com/Everyplay/cocos2d-iphone/tree/master
        - https://github.com/Everyplay/cocos2d-x

### v1.0.6 - January 7th 2013 (build 6)

- Generic:
    - Two video playback related methods added, playVideoWithURL: and playVideoWithDictionary:
    - Fixed audio related crash on iOS simulator
    - Fixed OAuth2/login flow related view handling and crashes
    - Fixed off-by-one bug related to resumed uploads.
      There's a server-side workaround for older builds

- Examples:
    - Examples for using Everyplay server API and native OpenGL/audio released!
      Check out https://github.com/Everyplay/everyplay-ios-examples

### v1.0.5 - December 24th 2012 (build 5)

- Generic:
    - Good things come in small packages and this release focuses on
      optimizing OpenGL memory usage. Depending on device and resolution,
      you'll likely save at least 13*(width*height)/1024/1024 megabytes
      for other needs. Happy holidays!

    - Fixed generic tiny memory leaks that ARC didn't handle

### v1.0.4 - December 18th 2012 (build 5)

- Generic:
    - Some games triggered screen tearing to the recorded movie files
      on iPad retina resolution, fixed

    - Some streamed video files resulted to a black frame at the end of video, fixed

    - Entering Everyplay view could cause a crash while updating sidebar contents, fixed

### v1.0.3 - December 17th 2012 (build 4)

- Generic:
    - iPod background music no longer goes muted when the application starts,
      however it won't be recorded to gameplay video

    - Using OpenGL ES1 with multitexturing caused some screen flickering
      while recording, fixed

    - If the developer manually pauses recording before the application goes to
      background, recording no longer automatically resumes when coming back.
      Instead, it's up to developer to resume it

    - Touching trimmer controls in the video player work better

    - Ability for webview to trigger fullscreen mode (wo/ native topbar or sidebar),
      for future features

    - User canceling authentication now triggers better events for internal use

### v1.0.2 - December 10th 2012 (build 3)

- Generic:
    - Fixes related to 16bit MSAA framebuffer handling

    - Fixed video player for showing loading spinner for no reason

    - Video player controls fade away more reliably

    - Video player play/pause button changed location after certain internal
      state changes, fixed

- Unity plugin:
    - Improved graphics pipeline integration. Now works for both Unity 3.5 and 4.0 in
      16/32bit mode, with MSAA anti-aliased rendering and supports Unity4's new target
      resolution capability

    - Fixed small memory leak with EveryplayThumbnailReadyAtFilePath

- Cocos2d:
    - Early support for integrating into Cocos2d 1.x, 2.x and Cocos2d-x graphics pipelines
      with no source code changes required. You'll only need to initialize Everyplay and
      set client id and secret as with any other engine using Objective-C API

### v1.0.1 - December 4th 2012 (build 2)

- First public release

- Generic:
    - Optimized media handling especially for longer gameplays, video recordings now
      close considerably faster and load faster to video player

    - Optimized thumbnail snapshot processing while recording and changed the file format
      from PNG to JPEG

    - If there's multiple video files to merge/post-process, the video player shows a
      progress bar indicator and you can cancel merging at any point

    - Resumed uploads failed to send video title and other metadata to server, fixed

    - Resumed uploads updated progress bar info with incorrect completed bytes, fixed

    - Fixed OpenGL ES1 related crash while recording

    - Fixed everyplayShown delegate getting called too often in some situtations

    - Added menu flow control option, now you can decide if returning from Everyplay
      view goes back to game as usual, or back to video editor

- Unity plugin:
    - Fixed compatibility with project folders having spaces

    - Plugin now correctly retains in memory while scene is changed

    - All unsubscribed event handlers are now automatically cleaned on plugin dealloc

    - public void SetMetadata(Dictionary<string,object> dict) was added. It allows user
      to set metadata as a dictionary object

    - public bool IsSupported() was added. It allows user to check if Everyplay recording
      is supported by the device

- Known issues:
  - MSAA/anti-aliased rendering support broken for Unity 3.5 / 4.0,
    fixed in the next release

### v1.0 - November 26th 2012 (build 1)
- Initial release, sent to private beta developers
