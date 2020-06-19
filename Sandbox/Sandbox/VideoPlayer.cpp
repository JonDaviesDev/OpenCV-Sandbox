#include "VideoPlayer.h"

VideoPlayer::VideoPlayer(const std::string& videoLocation, Window& window) : video(videoLocation), window(window) 
{
	PlayVideo();
}

void VideoPlayer::OnTrackbarSlide(int position, void* userData)
{
	// This is to get around the limitations of a static method not being able to access nonstatic members
	// This callback needs to be static as 'cv::createTrackbar' requires it to be
	VideoPlayer* vp = (VideoPlayer*)userData;

	vp->NonStaticAccesser(position);
}

void VideoPlayer::NonStaticAccesser(int position)
{
	// READ ACCESS VIOLATION
	video.VideoCapture().set(cv::CAP_PROP_POS_FRAMES, position);

	if (!dontSet)
		run = 1;
	else dontSet = 0;
}

void VideoPlayer::OpenVideo()
{
	video.VideoCapture().open(video.GetFilename());

	video.SetFrameCount(video.VideoCapture().get(cv::CAP_PROP_FRAME_COUNT));
	video.SetWidth(video.VideoCapture().get(cv::CAP_PROP_FRAME_WIDTH));
	video.SetHeight(video.VideoCapture().get(cv::CAP_PROP_FRAME_HEIGHT));
}

void VideoPlayer::CreateTrackbar(const std::string& trackbarLabel)
{
	trackbarName = trackbarLabel;

	cv::createTrackbar(trackbarName, window.GetWindowName(), (int*)&sliderPosition, video.GetFrameCount(), OnTrackbarSlide, this);
}

void VideoPlayer::PrintInformation()
{
	std::cout << "Video details: " << std::endl;
	std::cout << video.GetFrameCount() << " frames" << std::endl;
	std::cout << video.GetWidth() << " - width" << std::endl;
	std::cout << video.GetHeight() << " - height" << std::endl;
}

void VideoPlayer::Play()
{
	cv::Mat frame;

	while (true)
	{
		if (run != 0)
		{
			video.VideoCapture() >> frame;

			if (frame.empty())
				break;

			int currentPosition = (int)video.VideoCapture().get(cv::CAP_PROP_POS_FRAMES);
			
			dontSet = 1;

			cv::setTrackbarPos(trackbarName, window.GetWindowName(), currentPosition);

			cv::imshow(window.GetWindowName(), frame);

			run -= 1;
		}

		EventController(window.KeyPress());

	}
}

void VideoPlayer::EventController(char key)
{
	switch (key)
	{
	case 's':
		run = 1;
		std::cout << "Single step, run = " << run << std::endl;
		break;
	case 'r':
		run = -1;
		std::cout << "Run mode, run = " << run << std::endl;
		break;
	case 27:
		cv::destroyWindow(window.GetWindowName());
		break;
	}
}

void VideoPlayer::PlayVideo()
{
	OpenVideo();
	CreateTrackbar("Frame");
	Play();
}

