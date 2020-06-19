#include "VideoStreamer.h"

void VideoStreamer::CalculateFPS()
{
	fps = capture.VideoCapture().get(cv::CAP_PROP_FPS);
}

void VideoStreamer::CalcuateFrameSize()
{
	capture.SetDimensions((int32_t)capture.VideoCapture().get(cv::CAP_PROP_FRAME_WIDTH),
		(int32_t)capture.VideoCapture().get(cv::CAP_PROP_FRAME_HEIGHT));
}

void VideoStreamer::OpenVideoWriter()
{
	writer.open(outputFilename, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, capture.GetDimensions());
}

void VideoStreamer::ManageFrame()
{
	cv::Mat logPolarFrame, RGBFrame;

	while (true)
	{
		capture.VideoCapture() >> RGBFrame;
		if (RGBFrame.empty()) break;

		cv::logPolar(RGBFrame, logPolarFrame, cv::Point2f(RGBFrame.cols / 2, RGBFrame.rows / 2), 40, cv::WARP_FILL_OUTLIERS);

		Display("Log Polar", logPolarFrame);
		writer << logPolarFrame;

		char c = cv::waitKey(10);
		if (c == 27) break;
	}
}

void VideoStreamer::Display(const std::string& windowName, const cv::Mat& frame)
{
	Window window(windowName);

	cv::imshow(window.GetWindowName(), frame);
}

VideoStreamer::VideoStreamer(Video& video, const std::string& outputFilename)
{
	capture = video;

	this->outputFilename = outputFilename;

	CalculateFPS();

	CalcuateFrameSize();

	OpenVideoWriter();

	ManageFrame();
}

VideoStreamer::VideoStreamer(const cv::VideoCapture& readFrom, const std::string& outputFilename)
{
	capture.SetVideoCapture(readFrom);

	if (outputFilename == "") this->outputFilename = "LogPolar";
	else this->outputFilename = outputFilename;
}

VideoStreamer::VideoStreamer(int32_t cameraID, const std::string& outputFilename)
{
	capture.SetVideoCapture(cameraID);

	if (outputFilename == "") this->outputFilename = "LogPolar";
	else this->outputFilename = outputFilename;

	CalculateFPS();

	CalcuateFrameSize();

	OpenVideoWriter();

	ManageFrame();
}
