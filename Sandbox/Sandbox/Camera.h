#pragma once
#include "SandboxCore.h"

class Camera
{
public:
	/// <summary>
	/// Searches for the desired phyical camera and opens it
	/// </summary>
	/// <param name="cameraID">The ID of the phyisical camera ('0' will open the first camera found)</param>
	void OpenCamera(int32_t cameraID); 
	bool CheckCameraOpened();
	void ManageFrame(Window& window);
	void DisplayFrame(Window& window, const cv::Mat frame);
	int32_t Wait(uint32_t time);

	Camera(int32_t cameraID = 0);
	~Camera();

private:
	cv::VideoCapture capture;
};

