#include "Window.h"

Window::Window() {}

Window::Window(const std::string& windowName) : windowName(windowName)
{
	if (windowName != "")
		Create(windowName, cv::WINDOW_AUTOSIZE);
}

Window::~Window() {}


void Window::Create(const std::string& windowName, uint32_t flags) 
{
	cv::namedWindow(windowName, flags);
}

void Window::Destroy()
{
	cv::destroyWindow(windowName);
}

void Window::Pause(uint32_t pauseLength)
{
	cv::waitKey(pauseLength);
}

std::string Window::GetWindowName() { return windowName; }

char Window::KeyPress()
{
	return (char)cv::waitKey(10);
}