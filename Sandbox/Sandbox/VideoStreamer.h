#pragma once
#include "SandboxCore.h"
#include "Video.h"

class VideoStreamer
{
public:
	void CalculateFPS();
	void CalcuateFrameSize();
	void OpenVideoWriter();
	void ManageFrame();
	void Display(const std::string& windowName, const cv::Mat& frame);


	VideoStreamer(Video& video, const std::string& outputFilename = "");

	/// <summary>
	///Allows the streaming from one video source to another
	///	</summary>
	/// <param name="readFrom">the video that is to be read from</param>
	/// <param name="writeTo">the object that the video is to written to</param>
	VideoStreamer(const cv::VideoCapture& readFrom, const std::string& outputFilename = "");

	/// <summary>
	/// Read directly from a camera
	/// </summary>
	/// <param name="cameraID">the ID of the camera</param>
	/// <returns></returns>
	VideoStreamer(int32_t cameraID, const std::string& outputFilename = "");

private:
	Video capture;
	float_t fps;
	cv::VideoWriter writer;
	std::string outputFilename;
};

