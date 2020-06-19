#pragma once
#include "SandboxCore.h"
#include "Timer.h"
#include <filesystem>

class Colourisation
{
public:
	void ReadImage(const std::filesystem::path& imageFileLocation);
	void RetrieveResources();
	void Run();
	void Exit(const std::string& exitMessage);


	Colourisation(const std::filesystem::path& imagePath);

private:
	std::filesystem::path imagePath;
	std::string imageName;
	std::filesystem::path protoFileLocation;
	std::filesystem::path weightsFileLocation;
	cv::Mat image;
};

