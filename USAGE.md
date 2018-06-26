# Usage

## Initializing
Call **[Everyplay initWithDelegate:<EveryplayDelegate> andParentViewController:<UIViewController>]** to initialize Everyplay.

## Recording
* Call **[[[Everyplay sharedInstance] capture] startRecording]** to start recording.
* Call **[[[Everyplay sharedInstance] capture] stopRecording]** to stop recording.
* Call **[[[Everyplay sharedInstance] capture] pauseRecording]** to pause recording.
* Call **[[[Everyplay sharedInstance] capture] resumeRecording]** to resume recording after pause. 
---
* Call **[[[Everyplay sharedInstance] capture] isRecording]** to check whether recording is active.
* Call **[[[Everyplay sharedInstance] capture] isPaused]** to check whether recording is currently paused.
* Call **[Everyplay isSupported]** to check whether Everyplay is supported on device.
* Call **[[[Everyplay sharedInstance] capture] isRecordingSupported]** to check whether Everyplay recording is supported on device.

## Additional functionality
* Call **[[[Everyplay sharedInstance] capture] takeThumbnail]** to take a thumbnail of the recording. This will cause everyplayThumbnailReadyAtTextureId:(NSNumber *)textureId portraitMode:(NSNumber *)portrait or everyplayMetalThumbnailReadyAtTexture:(id)texture portraitMode:(NSNumber *)portrait to fire after the thumbnail has been prepared. Which one fires depends on the graphics backend.
* Call **[[[Everyplay sharedInstance] capture] setThumbnailTargetTextureId:int]** to set a target texture for the thumbnail. Once a thumbnail is taken, it will be applied to this target texture. This applies when renderer is OpenGL.
* Call **[[[Everyplay sharedInstance] capture] setThumbnailTargetTextureMetal:id]** to set a target texture for the thumbnail. Once a thumbnail is taken, it will be applied to this target texture. This applies when renderer is Metal.
* Call **[[[Everyplay sharedInstance] capture] setMotionFactor:NSUInteger]** to affect the quality of the recording. The function clamps the value given between 1 and 4. Default quality is 2. Higher value produces better quality video at cost of file size.
* Call **[[[Everyplay sharedInstance] capture] setTargetFPS:NSUInteger]** to affect the frame rate the video is being captured. Higher capture frame rate produces smoother video at cost of file size.
* Call **[[[Everyplay sharedInstance] capture] setLowMemoryDevice:BOOL]** to lower the memory cost of the plugin. This will increase CPU usage slightly.
* Call **[[[Everyplay sharedInstance] capture] setMaxRecordingMinutesLength:NSUInteger]** to set maximum length for a recording. The length is counted from the end of the recording. If you set this to 1 and record for 2 minutes, the recording will contain the LAST 1 minute. 
* Call **[[[Everyplay sharedInstance] capture] setMaxRecordingSecondsLength:NSUInteger]** to set maximum length for a recording. The length is counted from the end of the recording. If you set this to 15 and record for 30 seconds, the recording will contain the LAST 15 seconds.

## Accessing video
* Call **[[Everyplay sharedInstance] playLastRecording]** to play back last recording and allow user to trim it.
* Call **[[Everyplay sharedInstance] showEveryplaySharingModal]** to share the video using the device's share modal.
* Call **[[Everyplay sharedInstance] getEveryplayFilepath]** to get the path to the video file. This will cause everyplayFileReady(NSString *) to fire after the video has been prepared. 

## Delegate Functions
All delegate functions are available via EveryplayDelegate.

### Mandatory
* (void)**everyplayShown** - This will fire when the Everyplay video player has been opened.
* (void)**everyplayHidden** - This will fire when the Everyplay video player has been closed.

### Optional
* (void)**everyplayReadyForRecording:(NSNumber \*)enabled** - This tells whether the device is currently ready to start a recording session. This will fire multiple times during the lifetime of the app.
    * If the parameter is true, the device is ready to start a recording. Otherwise it is not.
* (void)**everyplayRecordingStarted** - This will fire when a recording has been started.
* (void)**everyplayRecordingStopped** - This will fire when a recording has been stopped.
* (void)**everyplayFileReady(NSString \*)** - This will fire when [[Everyplay sharedInstance] getEveryplayFilepath] has been called and the video has successfully been prepared.
    * The parameter contains the path to the recorded file.
* (void)**everyplayThumbnailReadyAtTextureId:(NSNumber \*)textureId portraitMode:(NSNumber \*)portrait** - This function will fire when [[[Everyplay sharedInstance]capture] takeThumbnail] has been called and the thumbnail has successfully been prepared. This applies when renderer is OpenGL.
* (void)**everyplayMetalThumbnailReadyAtTexture:(id)texture portraitMode:(NSNumber \*)portrait** - This function will fire when [[[Everyplay sharedInstance]capture] takeThumbnail] has been called and the thumbnail has successfully been prepared. This applies when renderer is Metal.
    * First parameter identifies the texture, second parameter indicates whether the thumbnail was taken in portrait orientation.
