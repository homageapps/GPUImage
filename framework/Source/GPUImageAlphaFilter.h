#import "GPUImageFilter.h"

@interface GPUImageAlphaFilter : GPUImageFilter
{
    GLint alphaUniform;
}

// Normalized values by which the alpha channel is multiplied. The range is from 0.0 up.
// 1.0 is the default value (by default the alpha channel will be untouched).
@property (readwrite, nonatomic) CGFloat alpha;

@end
