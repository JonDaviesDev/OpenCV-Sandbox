#include "Canny.h"

void Canny::Activate()
{
	ConvertRGBToGrayScale();

	ConvertGrayScaleToCanny();
}

void Canny::ConvertRGBToGrayScale()
{
	cv::cvtColor(image, grayScale, cv::COLOR_BGR2GRAY);
}

void Canny::ConvertGrayScaleToCanny()
{
	cv::Canny(grayScale, output, 100, 150, 3, false);
}

Canny::Canny()
{
	effectName = "Canny";
}

Canny::Canny(Window& outputWindow, Image& image)
{
	this->image = image.GetImage();

	Activate();

	Display(outputWindow, output);
}
