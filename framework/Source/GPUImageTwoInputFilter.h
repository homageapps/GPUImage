#import "GPUImageFilter.h"

extern NSString *const kGPUImageTwoInputTextureVertexShaderString;

@interface GPUImageTwoInputFilter : GPUImageFilter
{
    GPUImageFramebuffer *secondInputFramebuffer;

    GLint filterSecondTextureCoordinateAttribute;
    GLint filterInputTextureUniform2;
    GPUImageRotationMode inputRotation2;
    CMTime firstFrameTime, secondFrameTime, previousFrameTime;
    
    BOOL hasSetFirstTexture, hasReceivedFirstFrame, hasReceivedSecondFrame, firstFrameWasVideo, secondFrameWasVideo;
    BOOL firstFrameCheckDisabled, secondFrameCheckDisabled;
}

typedef NS_ENUM(NSInteger, kTimeStampsUsed) {
    kTimeStampsUsedNormal,            // default GPUImage lib behaviour. Will passthrough any received timestamp.
    kTimeStampsUsedFirstIndex,        // Will pass through timestamps of only the first index frames.
    kTimeStampsUsedSecondIndex,       // Will pass through timestamps of only the first index frames.
    kTimeStampsUsedThirdIndex         // Will pass through timestamps of only the first index frames.
};

@property (nonatomic) kTimeStampsUsed timeStampsPassedThrough;

- (void)disableFirstFrameCheck;
- (void)disableSecondFrameCheck;

@end
