#import "GPUImageTwoInputFilter.h"

extern NSString *const kGPUImageThreeInputTextureVertexShaderString;

@interface GPUImageThreeInputFilter : GPUImageTwoInputFilter
{
    GPUImageFramebuffer *thirdInputFramebuffer;

    GLint filterThirdTextureCoordinateAttribute;
    GLint filterInputTextureUniform3;
    GPUImageRotationMode inputRotation3;
    GLuint filterSourceTexture3;
    CMTime thirdFrameTime;
    
    BOOL hasSetSecondTexture, hasReceivedThirdFrame, thirdFrameWasVideo;
    BOOL thirdFrameCheckDisabled;
}

// For now, just redefine this on the Mac
typedef NS_ENUM(NSInteger, kTimeStampsUsed) {
    kTimeStampsUsedNormal,            // default GPUImage lib behaviour. Will passthrough any received timestamp.
    kTimeStampsUsedFirstIndex,        // Will pass through timestamps of only the first index frames.
    kTimeStampsUsedSecondIndex,       // Will pass through timestamps of only the first index frames.
    kTimeStampsUsedThirdIndex         // Will pass through timestamps of only the first index frames.
};

@property (nonatomic) kTimeStampsUsed timeStampsPassedThrough;

- (void)disableThirdFrameCheck;

@end
