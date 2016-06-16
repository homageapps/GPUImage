#import "GLProgram.h"

// Base classes
#import "GPUImageContext.h"
#import "GPUImageOutput.h"
#import "GPUImageView.h"
#import "GPUImageVideoCamera.h"
#import "GPUImageStillCamera.h"
#import "GPUImageMovie.h"
#import "GPUImagePicture.h"
#import "GPUImageRawDataInput.h"
#import "GPUImageRawDataOutput.h"
#import "GPUImageMovieWriter.h"
#import "GPUImageFilterPipeline.h"
#import "GPUImageTextureOutput.h"
#import "GPUImageFilterGroup.h"
#import "GPUImageTextureInput.h"
#import "GPUImageUIElement.h"
#import "GPUImageBuffer.h"
#import "GPUImageFramebuffer.h"
#import "GPUImageFramebufferCache.h"

// Filters
#import "GPUImageFilter.h"
#import "GPUImageTwoInputFilter.h"
#import "GPUImagePixellateFilter.h"
#import "GPUImagePixellatePositionFilter.h"
#import "GPUImageSepiaFilter.h"
#import "GPUImageColorInvertFilter.h"
#import "GPUImageSaturationFilter.h"
#import "GPUImageContrastFilter.h"
#import "GPUImageExposureFilter.h"
#import "GPUImageBrightnessFilter.h"
#import "GPUImageLevelsFilter.h"
#import "GPUImageSharpenFilter.h"
#import "GPUImageGammaFilter.h"
#import "GPUImageSobelEdgeDetectionFilter.h"
#import "GPUImageSketchFilter.h"
#import "GPUImageToonFilter.h"
#import "GPUImageSmoothToonFilter.h"
#import "GPUImageMultiplyBlendFilter.h"
#import "GPUImageDissolveBlendFilter.h"
#import "GPUImageKuwaharaFilter.h"
#import "GPUImageKuwaharaRadius3Filter.h"
#import "GPUImageVignetteFilter.h"
#import "GPUImageGaussianBlurFilter.h"
#import "GPUImageGaussianBlurPositionFilter.h"
#import "GPUImageGaussianSelectiveBlurFilter.h"
#import "GPUImageOverlayBlendFilter.h"
#import "GPUImageDarkenBlendFilter.h"
#import "GPUImageLightenBlendFilter.h"
#import "GPUImageSwirlFilter.h"
#import "GPUImageSourceOverBlendFilter.h"
#import "GPUImageColorBurnBlendFilter.h"
#import "GPUImageColorDodgeBlendFilter.h"
#import "GPUImageScreenBlendFilter.h"
#import "GPUImageExclusionBlendFilter.h"
#import "GPUImageDifferenceBlendFilter.h"
#import "GPUImageSubtractBlendFilter.h"
#import "GPUImageHardLightBlendFilter.h"
#import "GPUImageSoftLightBlendFilter.h"
#import "GPUImageColorBlendFilter.h"
#import "GPUImageHueBlendFilter.h"
#import "GPUImageSaturationBlendFilter.h"
#import "GPUImageLuminosityBlendFilter.h"
#import "GPUImageCropFilter.h"
#import "GPUImageGrayscaleFilter.h"
#import "GPUImageTransformFilter.h"
#import "GPUImageChromaKeyBlendFilter.h"
#import "GPUImageHazeFilter.h"
#import "GPUImageLuminanceThresholdFilter.h"
#import "GPUImagePosterizeFilter.h"
#import "GPUImageBoxBlurFilter.h"
#import "GPUImageAdaptiveThresholdFilter.h"
#import "GPUImageUnsharpMaskFilter.h"
#import "GPUImageBulgeDistortionFilter.h"
#import "GPUImagePinchDistortionFilter.h"
#import "GPUImageCrosshatchFilter.h"
#import "GPUImageCGAColorspaceFilter.h"
#import "GPUImagePolarPixellateFilter.h"
#import "GPUImageStretchDistortionFilter.h"
#import "GPUImagePerlinNoiseFilter.h"
#import "GPUImageJFAVoronoiFilter.h"
#import "GPUImageVoronoiConsumerFilter.h"
#import "GPUImageMosaicFilter.h"
#import "GPUImageTiltShiftFilter.h"
#import "GPUImage3x3ConvolutionFilter.h"
#import "GPUImageEmbossFilter.h"
#import "GPUImageCannyEdgeDetectionFilter.h"
#import "GPUImageThresholdEdgeDetectionFilter.h"
#import "GPUImageMaskFilter.h"
#import "GPUImageMask3CFilter.h"
#import "GPUImageHistogramFilter.h"
#import "GPUImageHistogramGenerator.h"
#import "GPUImageHistogramEqualizationFilter.h"
#import "GPUImagePrewittEdgeDetectionFilter.h"
#import "GPUImageXYDerivativeFilter.h"
#import "GPUImageHarrisCornerDetectionFilter.h"
#import "GPUImageAlphaBlendFilter.h"
#import "GPUImageNormalBlendFilter.h"
#import "GPUImageNonMaximumSuppressionFilter.h"
#import "GPUImageRGBFilter.h"
#import "GPUImageAlphaFilter.h"
#import "GPUImageMedianFilter.h"
#import "GPUImageBilateralFilter.h"
#import "GPUImageCrosshairGenerator.h"
#import "GPUImageToneCurveFilter.h"
#import "GPUImageNobleCornerDetectionFilter.h"
#import "GPUImageShiTomasiFeatureDetectionFilter.h"
#import "GPUImageErosionFilter.h"
#import "GPUImageRGBErosionFilter.h"
#import "GPUImageDilationFilter.h"
#import "GPUImageRGBDilationFilter.h"
#import "GPUImageOpeningFilter.h"
#import "GPUImageRGBOpeningFilter.h"
#import "GPUImageClosingFilter.h"
#import "GPUImageRGBClosingFilter.h"
#import "GPUImageColorPackingFilter.h"
#import "GPUImageSphereRefractionFilter.h"
#import "GPUImageMonochromeFilter.h"
#import "GPUImageOpacityFilter.h"
#import "GPUImageHighlightShadowFilter.h"
#import "GPUImageFalseColorFilter.h"
#import "GPUImageHSBFilter.h"
#import "GPUImageHueFilter.h"
#import "GPUImageGlassSphereFilter.h"
#import "GPUImageLookupFilter.h"
#import "GPUImageAmatorkaFilter.h"
#import "GPUImageMissEtikateFilter.h"
#import "GPUImageSoftEleganceFilter.h"
#import "GPUImageAddBlendFilter.h"
#import "GPUImageDivideBlendFilter.h"
#import "GPUImagePolkaDotFilter.h"
#import "GPUImageLocalBinaryPatternFilter.h"
#import "GPUImageLanczosResamplingFilter.h"
#import "GPUImageAverageColor.h"
#import "GPUImageSolidColorGenerator.h"
#import "GPUImageLuminosity.h"
#import "GPUImageAverageLuminanceThresholdFilter.h"
#import "GPUImageWhiteBalanceFilter.h"
#import "GPUImageChromaKeyFilter.h"
#import "GPUImageLowPassFilter.h"
#import "GPUImageHighPassFilter.h"
#import "GPUImageMotionDetector.h"
#import "GPUImageHalftoneFilter.h"
#import "GPUImageThresholdedNonMaximumSuppressionFilter.h"
#import "GPUImageHoughTransformLineDetector.h"
#import "GPUImageParallelCoordinateLineTransformFilter.h"
#import "GPUImageThresholdSketchFilter.h"
#import "GPUImageLineGenerator.h"
#import "GPUImageLinearBurnBlendFilter.h"
#import "GPUImageGaussianBlurPositionFilter.h"
#import "GPUImagePixellatePositionFilter.h"
#import "GPUImageTwoInputCrossTextureSamplingFilter.h"
#import "GPUImagePoissonBlendFilter.h"
#import "GPUImageMotionBlurFilter.h"
#import "GPUImageZoomBlurFilter.h"
#import "GPUImageLaplacianFilter.h"
#import "GPUImageiOSBlurFilter.h"
#import "GPUImageLuminanceRangeFilter.h"
#import "GPUImageDirectionalNonMaximumSuppressionFilter.h"
#import "GPUImageDirectionalSobelEdgeDetectionFilter.h"
#import "GPUImageSingleComponentGaussianBlurFilter.h"
#import "GPUImageThreeInputFilter.h"
#import "GPUImageWeakPixelInclusionFilter.h"

