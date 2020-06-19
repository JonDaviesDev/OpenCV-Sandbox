#pragma once
#include "SandboxCore.h"

class Image
{
public:
	void Display(Window& displayWindow, Image& image);
	void Display(Window& displayWindow, const cv::Mat& image);

	void Exit();
	void ReadFile(const std::string& filename);
	void ReadImage(const cv::Mat& image);

	void SetImage(const cv::Mat& image);
	cv::Mat GetImage();

	Image();
	Image(const std::string& filename);
	Image(const std::string& filename, Window& outputWindow);
	Image(const cv::Mat& image);
	Image(const cv::Mat& image, Window& outputWindow);
	~Image();

protected:
	std::string filename;
	cv::Mat image;
};

