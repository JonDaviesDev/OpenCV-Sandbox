#pragma once
#include "SandboxCore.h"
#include "Image.h"

class Effect : public Image
{
public:
	virtual void Activate() = 0;

	cv::Mat GetOutput();
	std::string GetEffectName();

	Effect();
	Effect(const cv::Mat& inputImage);
protected:
	cv::Mat output;
	std::string effectName;
};

