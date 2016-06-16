#import "GPUImageMask3CFilter.h"

#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
NSString *const kGPUImageMask3CShaderString = SHADER_STRING
(
 varying highp vec2 textureCoordinate;
 varying highp vec2 textureCoordinate2;
 
 uniform sampler2D inputImageTexture;
 uniform sampler2D inputImageTexture2;
 
 void main()
 {
	 lowp vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);
	 lowp vec4 textureColor2 = texture2D(inputImageTexture2, textureCoordinate2);
	 
	 //Averages mask's the RGB values, and uses the value as the new alpha channel.
	 //Typical/ideal case, R,G, and B will be the same (mask is in grayscale).
	 lowp float newAlpha = dot(textureColor2.rgb, vec3(.33333334, .33333334, .33333334)) * textureColor.a;
	 gl_FragColor = vec4(textureColor.xyz, newAlpha);
 }
);
#else
NSString *const kGPUImageMask3CShaderString = SHADER_STRING
(
 varying vec2 textureCoordinate;
 varying vec2 textureCoordinate2;
 
 uniform sampler2D inputImageTexture;
 uniform sampler2D inputImageTexture2;
 
 void main()
 {
	 vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);
	 vec4 textureColor2 = texture2D(inputImageTexture2, textureCoordinate2);
	 
     //Averages mask's the RGB values, and uses the value as the new alpha channel.
     //Typical/ideal case, R,G, and B will be the same (mask is in grayscale).
	 float newAlpha = dot(textureColor2.rgb, vec3(.33333334, .33333334, .33333334));
	 gl_FragColor = vec4(textureColor.xyz, newAlpha);
 }
);
#endif

@implementation GPUImageMask3CFilter

- (id)init;
{
    if (!(self = [super initWithFragmentShaderFromString:kGPUImageMask3CShaderString]))
    {
		return nil;
    }
    
    return self;
}

- (void)renderToTextureWithVertices:(const GLfloat *)vertices textureCoordinates:(const GLfloat *)textureCoordinates;
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    [super renderToTextureWithVertices:vertices textureCoordinates:textureCoordinates];
    glDisable(GL_BLEND);
}

@end

