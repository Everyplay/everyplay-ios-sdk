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

#import <CoreFoundation/CoreFoundation.h>
#import <UIKit/UIKit.h>

#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

#import <AVFoundation/AVFoundation.h>
#import <QuartzCore/QuartzCore.h>

@interface EveryplayCapture : NSObject<AVCaptureVideoDataOutputSampleBufferDelegate, AVCaptureAudioDataOutputSampleBufferDelegate>;

/* Set target framerate for the video, defaults to 30fps. (Valid values: 30, 20, 15) */
@property (nonatomic, assign) NSUInteger targetFPS;
/* Set video quality, defaults to 2. (Valid values: 1-4) */
@property (nonatomic, assign) NSUInteger motionFactor;
/*
 * Set maximum recording length in minutes, defaults to unlimited.
 *
 * If the recording session goes over the maximum length set, the resulting
 * video will have the content recorded within last N minutes, which is suitable
 * especially for online games.
 */
@property (nonatomic, assign) NSUInteger maxRecordingMinutesLength;

/* Optimize for low memory devices, disabled by default. */
@property (nonatomic, assign) BOOL lowMemoryDevice;

/*
 * If the recorded video frames show jerky behavior,
 * enable this to workaround.
 */
@property (nonatomic, assign) BOOL workaroundFrameJerking;

/*
 * Disable recording support for single-core CPU devices
 *
 * Depending on a game and the device, recording a gameplay
 * may be too heavy on CPU/memory resources left.
 */
@property (nonatomic, assign) BOOL disableSingleCoreDevices;

@property (nonatomic, readonly) BOOL isSingleCoreDevice;

@property (nonatomic, readonly) BOOL isRecordingSupported;
@property (nonatomic, readonly) BOOL isRecording;
@property (nonatomic, readonly) BOOL isPaused;

// Filebased thumbnail target
@property (nonatomic, assign) int thumbnailWidth;

// Thumbnail target texture
@property (nonatomic, assign) int thumbnailTargetTextureId;
@property (nonatomic, assign) int thumbnailTargetTextureWidth;
@property (nonatomic, assign) int thumbnailTargetTextureHeight;

#pragma mark - screen (OpenGL) capturing
- (id)initWithView:(UIView *)glview eaglContext:(EAGLContext *)context layer:(CAEAGLLayer *)layer;

- (void)createFramebuffer;
- (void)createFramebuffer:(GLuint)framebufferRef;
- (void)createFramebuffer:(GLuint)framebufferRef withMSAA:(GLuint)msaaFramebufferRef;
- (void)deleteFramebuffer;

- (void)setActiveFramebufferCallback:(void (^)(GLuint activeFramebuffer))callback;

- (GLuint)msaaFramebuffer:(GLuint)msaaFramebufferRef;

- (BOOL)snapshotRenderbuffer;

- (BOOL)beforePresentRenderbuffer:(GLuint)framebufferRef;

- (BOOL)afterPresentRenderbuffer;
- (BOOL)afterPresentRenderbuffer:(GLuint)msaaFramebufferRef;

#pragma mark - Helpers
- (void)startRecording;
- (void)stopRecording;

- (void)pauseRecording;
- (void)resumeRecording;

- (void)takeThumbnail;

- (void)autoRecordForSeconds:(NSUInteger)seconds withDelay:(NSUInteger)delay;

@end
