#include "Camera.h"

void Camera::OpenCamera(int32_t cameraID)
{
	capture.open(cameraID);
}

bool Camera::CheckCameraOpened()
{
	if (!capture.isOpened())
		return false;
	else return true;
}

void Camera::ManageFrame(Window& outputWindow)
{
	cv::Mat frame;

	// This will run until there are no more frames to display or the application is closed
	while(true)
	{	
		capture >> frame;

		if (frame.empty()) break; // Ran out of frames
		DisplayFrame(outputWindow, frame);
		if (Wait(33) >= 0) break;
	}
}

void Camera::DisplayFrame(Window& window, const cv::Mat frame)
{
	cv::imshow(window.GetWindowName(), frame);
}

int32_t Camera::Wait(uint32_t time)
{
	return cv::waitKey(time);
}

Camera::Camera(int32_t cameraID)
{
	OpenCamera(cameraID);

	if (!CheckCameraOpened())
	{
		std::cerr << "No camera can be found" << std::endl;
		this->~Camera();
	}
	else
	{
		Window outputWindow("Camera Feed");

		ManageFrame(outputWindow);
	}
}

Camera::~Camera() {}