#include "GaussianBlur.h"

GaussianBlur::GaussianBlur(uint32_t degreeOfBlurEffect, uint32_t xAxisLevelOfBlur, uint32_t yAxisLevelOfBlur)
	: degree(degreeOfBlurEffect), xAxis(xAxisLevelOfBlur), yAxis(yAxisLevelOfBlur) 
{
	effectName = "Blurred";
}

GaussianBlur::GaussianBlur(Window& window, const cv::Mat& image, uint32_t degreeOfBlurEffect, uint32_t xAxisLevelOfBlur, uint32_t yAxisLevelOfBlur)
	:  degree(degreeOfBlurEffect), xAxis(xAxisLevelOfBlur), yAxis(yAxisLevelOfBlur)
{
	ReadImage(image);

	Activate();

	Display(window, output);
}

GaussianBlur::GaussianBlur(Window& window, Image& image, uint32_t degreeOfBlurEffect, uint32_t xAxisLevelOfBlur, uint32_t yAxisLevelOfBlur)
	: degree(degreeOfBlurEffect), xAxis(xAxisLevelOfBlur), yAxis(yAxisLevelOfBlur)
{
	ReadImage(image.GetImage());

	Activate();

	Display(window, output);
}

GaussianBlur::GaussianBlur(Window& window, const std::string& filename, uint32_t degreeOfBlurEffect, uint32_t xAxisLevelOfBlur, uint32_t yAxisLevelOfBlur)
	: degree(degreeOfBlurEffect), xAxis(xAxisLevelOfBlur), yAxis(yAxisLevelOfBlur)
{
	ReadFile(filename);

	Activate();

	Display(window, output);
}

void GaussianBlur::Activate()
{
	if (degree < 0)
		degree = 1;

	if (degree % 2 == 0)
		degree += 1;

	cv::GaussianBlur(image, output, cv::Size(degree, degree), xAxis, yAxis);
}

