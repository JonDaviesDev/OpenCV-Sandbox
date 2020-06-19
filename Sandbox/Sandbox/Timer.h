#pragma once
#include "SandboxCore.h"

#include <chrono>

class Timer
{
public:
	// Start time on construction
	Timer(const std:: string& owner = "");

	// Display time on destruction
	~Timer();

	// If the time is needed before destruction
	float GetTime();

private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> interuptedDuration;
	std::chrono::duration<float> duration;
	std::string owner;
};

