#include "Image.h"

Image::Image() {}

Image::Image(const std::string& filename) : filename(filename) 
{
	if (filename != "")
		ReadFile(filename);

	if (image.empty())
		Exit();
	
	std::cout << "Image opened successfully" << std::endl;
}

Image::Image(const std::string& filename, Window& outputWindow)
{
	if (filename.empty())
		Exit();

	ReadFile(filename);

	Display(outputWindow, image);
}

Image::Image(const cv::Mat& image) : image(image)
{
	if (image.empty())
		Exit();
	else std::cout << "Image opened successfully" << std::endl;
}

Image::Image(const cv::Mat& image, Window& outputWindow) : image(image)
{
	if (image.empty())
		Exit();
	else std::cout << "Image opened successfully" << std::endl;

	Display(outputWindow, this->image);
}

Image::~Image() {}

void Image::SetImage(const cv::Mat& image) { this->image = image; }

cv::Mat Image::GetImage() { return image; }

void Image::ReadFile(const std::string& filename)
{
	image = cv::imread(filename, -1);
}

void Image::ReadImage(const cv::Mat& image)
{
	this->image = image;
}

void Image::Display(Window& displayWindow, Image& image)
{
	cv::imshow(displayWindow.GetWindowName(), image.GetImage());
}

void Image::Display(Window& displayWindow, const cv::Mat& image)
{
	cv::imshow(displayWindow.GetWindowName(), image);
}

void Image::Exit()
{
	std::cout << "No image data has been found" << std::endl;
	std::cout << "Exiting program..." << std::endl;

	exit(-1);
}