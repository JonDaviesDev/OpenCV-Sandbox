#pragma once
#include "SandboxCore.h"

class Video
{
public:
	// Methods
	void SetFrameCount(double_t frameCount);
	void SetWidth(double_t frameWidth);
	void SetHeight(double_t frameHeight);
	void SetDimensions(int32_t width, int32_t height);
	void SetVideoCapture(const cv::VideoCapture& capture);

	double_t GetFrameCount();
	double_t GetWidth();
	double_t GetHeight();
	cv::Size2i GetDimensions();
	std::string GetFilename();

	// Properties
	cv::VideoCapture& VideoCapture();

	//Constructors
	Video();
	Video(const std::string& filename);

private:
	double_t frameCount, frameWidth, frameHeight;
	cv::VideoCapture capture;
	std::string filename;
};

