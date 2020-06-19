#include "ImageScalar.h"


void ImageScalar::Activate()
{
	if (scaleFactor >= 0)
		PyramidUp(scaleFactor);
	else PyramidDown(std::abs(scaleFactor));
}

void ImageScalar::PyramidDown(int32_t timesSmaller)
{
	cv::pyrDown(image, output, cv::Size(image.cols / (int)timesSmaller, image.rows / (int)timesSmaller));
}

void ImageScalar::PyramidUp(int32_t timesLarger)
{
	cv::pyrUp(image, output, cv::Size(image.cols * (int)timesLarger, image.rows * (int)timesLarger));
}

ImageScalar::ImageScalar(int32_t scaleFactor) : scaleFactor(scaleFactor)
{
	effectName = "Scaled";
}

ImageScalar::ImageScalar(Window& window, const std::string& filename, int32_t scaleFactor)
	: scaleFactor(scaleFactor)
{
	ReadFile(filename);

	Activate();

	Display(window, output);
}

ImageScalar::ImageScalar(Window& window, const cv::Mat& image, int32_t scaleFactor) : scaleFactor(scaleFactor)
{
	ReadImage(image);

	Activate();

	Display(window, output);
}

ImageScalar::ImageScalar(Window& window, Image& image, int32_t scaleFactor) : Effect(image.GetImage()), scaleFactor(scaleFactor)
{
	ReadImage(image.GetImage());

	Activate();

	Display(window, output);
}

