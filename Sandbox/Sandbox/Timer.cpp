#include "Timer.h"

// Start timing on Construction
Timer::Timer(const std::string& owner) 
	: start(std::chrono::high_resolution_clock::now()), end(), duration(), owner(owner) {}

// Stop timing on destruction and print results
Timer::~Timer()
{
	// get the clock time again
	end = std::chrono::high_resolution_clock::now();

	// calculate difference
	duration = end - start;

	// if no name has been provided
	if (owner == "")
	{
		float milliseconds = duration.count() * 1000.0f;
		//std::cout << milliseconds << "ms" << std::endl;
	}
	else
	{
		float milliseconds = duration.count() * 1000.0f;
		//std::cout << owner << " took - " << milliseconds << "ms" << " to run" << std::endl;
	}

}

// if the time is needed before destruction, this can be called
float Timer::GetTime()
{
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;

	return duration.count();
}
