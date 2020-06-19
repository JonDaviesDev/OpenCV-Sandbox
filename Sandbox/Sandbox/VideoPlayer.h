#pragma once
#include "SandboxCore.h"

#include <functional>
#include "Window.h"
#include "Video.h"

class VideoPlayer
{
public:
	static void OnTrackbarSlide(int position, void* userData);
	void NonStaticAccesser(int position);
	void OpenVideo();
	void CreateTrackbar(const std::string& trackbarLabel);
	void PrintInformation();
	void Play();
	void EventController(char key);
	void PlayVideo();

	VideoPlayer(const std::string& videoLocation, Window& window);
	
private:
	uint32_t sliderPosition, dontSet, run;
	Video video;
	std::string trackbarName;
	Window window;
};

