#pragma once
#include "Effect.h"
class Canny : public Effect
{
public:
	void Activate();

	void ConvertRGBToGrayScale();
	void ConvertGrayScaleToCanny();

	Canny();
	Canny(Window& outputWindow, Image& image);

private:
	cv::Mat grayScale;
};

