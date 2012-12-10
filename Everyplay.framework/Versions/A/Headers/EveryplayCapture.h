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

@property (nonatomic, assign) NSUInteger targetFPS;
@property (nonatomic, assign) NSUInteger motionFactor;

@property (nonatomic, readonly) BOOL isRecording;
@property (nonatomic, readonly) BOOL isPaused;

#pragma mark - screen (OpenGL) capturing
- (id)initWithView:(UIView *)glview eaglContext:(EAGLContext *)context layer:(CAEAGLLayer *)layer;

- (void)createFramebuffer;
- (void)createFramebuffer:(GLuint)framebufferRef;
- (void)createFramebuffer:(GLuint)framebufferRef withMSAA:(GLuint)msaaFramebufferRef;
- (void)deleteFramebuffer;

- (void)setActiveFramebufferCallback:(void (^)(GLuint activeFramebuffer))callback;

- (GLuint)msaaFramebuffer:(GLuint)msaaFramebufferRef;

- (BOOL)beforePresentRenderbuffer:(GLuint)framebufferRef;

- (BOOL)afterPresentRenderbuffer;
- (BOOL)afterPresentRenderbuffer:(GLuint)msaaFramebufferRef;

#pragma mark - Helpers
- (void)startRecording;
- (void)stopRecording;

- (void)pauseRecording;
- (void)resumeRecording;

- (void)autoRecordForSeconds:(NSUInteger)seconds withDelay:(NSUInteger)delay;

@end
