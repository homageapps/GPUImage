#import "GPUImageAlphaFilter.h"

#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
NSString *const kGPUImageAlphaFragmentShaderString = SHADER_STRING
(
 varying highp vec2 textureCoordinate;
 uniform sampler2D inputImageTexture;
 uniform highp float alphaAdjustment;
 
 void main()
 {
     highp vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);
     lowp float newAlpha = textureColor.a * alphaAdjustment;
     gl_FragColor = vec4(textureColor.xyz, newAlpha);
 }
);
#else
NSString *const kGPUImageRGBFragmentShaderString = SHADER_STRING
(
 varying highp vec2 textureCoordinate;
 uniform sampler2D inputImageTexture;
 uniform highp float alphaAdjustment;
 
 void main()
 {
     vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);
     lowp float newAlpha = textureColor.a * alphaAdjustment;
     gl_FragColor = vec4(textureColor.xyz, newAlpha);
 }
 );
#endif

@implementation GPUImageAlphaFilter

@synthesize alpha = _alpha;

#pragma mark -
#pragma mark Initialization and teardown

- (id)init;
{
    if (!(self = [super initWithFragmentShaderFromString:kGPUImageAlphaFragmentShaderString]))
    {
		return nil;
    }
    
    alphaUniform = [filterProgram uniformIndex:@"alphaAdjustment"];
    self.alpha = 1.0;
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (void)setAlpha:(CGFloat)newValue;
{
    _alpha = newValue;
    [self setFloat:_alpha forUniform:alphaUniform program:filterProgram];
}

@end