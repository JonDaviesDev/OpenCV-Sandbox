#include "Video.h"

void Video::SetFrameCount(double_t frame) { frameCount = frame; }
void Video::SetWidth(double_t width) { frameWidth = width; }
void Video::SetHeight(double_t height) { frameHeight = height; }
void Video::SetDimensions(int32_t width, int32_t height) { frameWidth = width; frameHeight = height; }
void Video::SetVideoCapture(const cv::VideoCapture& capture) { this->capture = capture; }


double_t Video::GetFrameCount() { return frameCount; }
double_t Video::GetWidth() { return frameWidth; }
double_t Video::GetHeight() { return frameHeight; }
cv::Size2i Video::GetDimensions() { return cv::Size2i(frameWidth, frameHeight); }
std::string Video::GetFilename() { return filename; }

cv::VideoCapture& Video::VideoCapture() { return capture; }

Video::Video(){}
Video::Video(const std::string& filename) : filename(filename)
{
	capture.open(filename);
}
