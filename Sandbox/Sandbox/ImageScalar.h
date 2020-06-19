#pragma once
#include "SandboxCore.h"
#include "Effect.h"

class ImageScalar : public Effect
{
public:
	void Activate();

	void PyramidDown(int32_t timesSmaller);
	void PyramidUp(int32_t timesLarger);

	ImageScalar(int32_t scaleFactor);

	/// <summary>
	/// Scales the size of the image either up or down.
	/// </summary>
	/// <param name="window">Enter the window object that the image will be displayed to.</param>
	/// <param name="filename">Enter the file path of the desired file.</param>
	/// <param name="scaleFactor">Scale the image size by a factor of this value.  Positive values result in a scale increase,
	/// while negative numbers result in a scale decrease.</param>
	ImageScalar(Window& window, const std::string& filename, int32_t scaleFactor);

	/// <summary>
	/// Scales the size of the image either up or down.
	/// </summary>
	/// <param name="window">Enter the window object that the image will be displayed to.</param>
	/// <param name="image">Enter the 'cv::Mat' image object.</param>
	/// <param name="scaleFactor">Scale the image size by a factor of this value.  Positive values result in a scale increase,
	/// while negative numbers result in a scale decrease.</param>
	ImageScalar(Window& window, const cv::Mat& image, int32_t scaleFactor);

	/// <summary>
	/// Scales the size of the image either up or down.
	/// </summary>
	/// <param name="window">Enter the window object that the image will be displayed to.</param>
	/// <param name="image">Enter the image object that will be edited</param>
	/// <param name="scaleFactor">Scale the image size by a factor of this value.  Positive values result in a scale increase,
	/// while negative numbers result in a scale decrease.</param>
	/// <returns></returns>
	ImageScalar(Window& window, Image& image, int32_t scaleFactor);

private:
	int32_t scaleFactor;
};

