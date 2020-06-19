#pragma once
#include "SandboxCore.h"

class Window
{
public:
	void Create(const std::string& windowName, uint32_t flags);
	void Destroy();
	void Pause(uint32_t pauseLength);
	char KeyPress();

	std::string GetWindowName();

	Window();
	Window(const std::string& windowName = "");
	~Window();

private:
	std::string windowName;
};

