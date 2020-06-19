#pragma once
#include "SandboxCore.h"
#include "Effect.h"

class GaussianBlur : public Effect
{
public:
	void Activate();

	GaussianBlur(uint32_t degreeOfBlurEffect, uint32_t xAxisLevelOfBlur, uint32_t yAxisLevelOfBlur);

	/// <summary>
	/// Accepts an image as a parameter and performs a Gaussian Blur on it
	/// </summary>
	/// <param name="outputwindow">Target window for displaying result</param>
	/// <param name="image">Original cv::Mat object to perform the blur on</param>
	/// <param name="degreeOfBlurEffect">Overall degree of blur</param>
	/// <param name="xAxisLevelOfBlur">Additional blur on X axis</param>
	/// <param name="yAxisLevelOfBlur">Additional blur on Y axis</param>
	/// <returns></returns>
	GaussianBlur(Window& outputwindow, const cv::Mat& image, uint32_t degreeOfBlurEffect, uint32_t xAxisLevelOfBlur, uint32_t yAxisLevelOfBlur);
	
	/// <summary>
	/// Accepts an image as a parameter and performs a Gaussian Blur on it
	/// </summary>
	/// <param name="outputwindow">Target window for displaying result</param>
	/// <param name="image">Original image to perform the blur on</param>
	/// <param name="degreeOfBlurEffect">Overall degree of blur</param>
	/// <param name="xAxisLevelOfBlur">Additional blur on X axis</param>
	/// <param name="yAxisLevelOfBlur">Additional blur on Y axis</param>
	/// <returns></returns>
	GaussianBlur(Window& window, Image& image, uint32_t degreeOfBlurEffect, uint32_t xAxisLevelOfBlur, uint32_t yAxisLevelOfBlur);

	/// <summary>
	/// Accepts an image as a parameter and performs a Gaussian Blur on it
	/// </summary>
	/// <param name="outputwindow">Target window for displaying result</param>
	/// <param name="filename">Original file to perform the blur on</param>
	/// <param name="degreeOfBlurEffect">Overall degree of blur</param>
	/// <param name="xAxisLevelOfBlur">Additional blur on X axis</param>
	/// <param name="yAxisLevelOfBlur">Additional blur on Y axis</param>
	/// <returns></returns>
	GaussianBlur(Window& outputwindow, const std::string& filename, uint32_t degreeOfBlurEffect, uint32_t xAxisLevelOfBlur, uint32_t yAxisLevelOfBlur);

private:
	// In order - The level of effect of the blur as a whole, then the weighting of the x axis, followed by the weighting of the y axis
	uint32_t degree, xAxis, yAxis;
};

