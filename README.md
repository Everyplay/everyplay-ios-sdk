Welcome to Everyplay. To get started, make sure you have an account registered, and that you have a unique client ID
for your game. You can get these along with the latest integration instructions at https://developers.everyplay.com/

You can always download the latest SDK upgrades directly from https://github.com/everyplay/everyplay-ios-sdk

Everyplay SDK is licensed under the Apache License, Version 2.0 (http://www.apache.org/licenses/LICENSE-2.0.html)


Everyplay SDK - Release Notes
=============================


### v1.0.3 - December 17th 2012

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

### v1.0.2 - December 10th 2012

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

### v1.0.1 - December 4th 2012

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

### v1.0 - November 26th 2012
- Initial release, sent to private beta developers
