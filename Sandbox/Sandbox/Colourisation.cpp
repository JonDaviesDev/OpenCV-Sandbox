#include "Colourisation.h"

void Colourisation::ReadImage(const std::filesystem::path& imagePath)
{
	image = cv::imread(imagePath.string());
}

void Colourisation::Exit(const std::string& exitMessage)
{
	std::cout << exitMessage << std::endl;

	exit(-1);
}

void Colourisation::RetrieveResources()
{
	bool protoFound = false;
	bool weightFound = false;

	std::filesystem::path path = std::filesystem::current_path().parent_path();

	for (auto& directory : std::filesystem::recursive_directory_iterator(path))
	{
		if (directory.path().filename() == "colorization_deploy_v2.prototxt")
		{
			protoFileLocation = directory.path();
			protoFound = true;
		}
		
		if (directory.path().filename() == "colorization_release_v2.caffemodel")
		{
			weightsFileLocation = directory.path();
			weightFound = true;
		}

		if (protoFound && weightFound)
			break;
	}
}

void Colourisation::Run()
{
	ReadImage(imagePath);
}

// the 313 ab cluster centers from pts_in_hull.npy (already transposed)
static float hull_pts[] = {
    -90., -90., -90., -90., -90., -80., -80., -80., -80., -80., -80., -80., -80., -70., -70., -70., -70., -70., -70., -70., -70.,
    -70., -70., -60., -60., -60., -60., -60., -60., -60., -60., -60., -60., -60., -60., -50., -50., -50., -50., -50., -50., -50., -50.,
    -50., -50., -50., -50., -50., -50., -40., -40., -40., -40., -40., -40., -40., -40., -40., -40., -40., -40., -40., -40., -40., -30.,
    -30., -30., -30., -30., -30., -30., -30., -30., -30., -30., -30., -30., -30., -30., -30., -20., -20., -20., -20., -20., -20., -20.,
    -20., -20., -20., -20., -20., -20., -20., -20., -20., -10., -10., -10., -10., -10., -10., -10., -10., -10., -10., -10., -10., -10.,
    -10., -10., -10., -10., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 10., 10., 10., 10., 10., 10., 10.,
    10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 20., 20., 20., 20., 20., 20., 20., 20., 20., 20., 20., 20., 20., 20., 20.,
    20., 20., 20., 30., 30., 30., 30., 30., 30., 30., 30., 30., 30., 30., 30., 30., 30., 30., 30., 30., 30., 30., 40., 40., 40., 40.,
    40., 40., 40., 40., 40., 40., 40., 40., 40., 40., 40., 40., 40., 40., 40., 40., 50., 50., 50., 50., 50., 50., 50., 50., 50., 50.,
    50., 50., 50., 50., 50., 50., 50., 50., 50., 60., 60., 60., 60., 60., 60., 60., 60., 60., 60., 60., 60., 60., 60., 60., 60., 60.,
    60., 60., 60., 70., 70., 70., 70., 70., 70., 70., 70., 70., 70., 70., 70., 70., 70., 70., 70., 70., 70., 70., 70., 80., 80., 80.,
    80., 80., 80., 80., 80., 80., 80., 80., 80., 80., 80., 80., 80., 80., 80., 80., 90., 90., 90., 90., 90., 90., 90., 90., 90., 90.,
    90., 90., 90., 90., 90., 90., 90., 90., 90., 100., 100., 100., 100., 100., 100., 100., 100., 100., 100., 50., 60., 70., 80., 90.,
    20., 30., 40., 50., 60., 70., 80., 90., 0., 10., 20., 30., 40., 50., 60., 70., 80., 90., -20., -10., 0., 10., 20., 30., 40., 50.,
    60., 70., 80., 90., -30., -20., -10., 0., 10., 20., 30., 40., 50., 60., 70., 80., 90., 100., -40., -30., -20., -10., 0., 10., 20.,
    30., 40., 50., 60., 70., 80., 90., 100., -50., -40., -30., -20., -10., 0., 10., 20., 30., 40., 50., 60., 70., 80., 90., 100., -50.,
    -40., -30., -20., -10., 0., 10., 20., 30., 40., 50., 60., 70., 80., 90., 100., -60., -50., -40., -30., -20., -10., 0., 10., 20.,
    30., 40., 50., 60., 70., 80., 90., 100., -70., -60., -50., -40., -30., -20., -10., 0., 10., 20., 30., 40., 50., 60., 70., 80., 90.,
    100., -80., -70., -60., -50., -40., -30., -20., -10., 0., 10., 20., 30., 40., 50., 60., 70., 80., 90., -80., -70., -60., -50.,
    -40., -30., -20., -10., 0., 10., 20., 30., 40., 50., 60., 70., 80., 90., -90., -80., -70., -60., -50., -40., -30., -20., -10.,
    0., 10., 20., 30., 40., 50., 60., 70., 80., 90., -100., -90., -80., -70., -60., -50., -40., -30., -20., -10., 0., 10., 20., 30.,
    40., 50., 60., 70., 80., 90., -100., -90., -80., -70., -60., -50., -40., -30., -20., -10., 0., 10., 20., 30., 40., 50., 60., 70.,
    80., -110., -100., -90., -80., -70., -60., -50., -40., -30., -20., -10., 0., 10., 20., 30., 40., 50., 60., 70., 80., -110., -100.,
    -90., -80., -70., -60., -50., -40., -30., -20., -10., 0., 10., 20., 30., 40., 50., 60., 70., 80., -110., -100., -90., -80., -70.,
    -60., -50., -40., -30., -20., -10., 0., 10., 20., 30., 40., 50., 60., 70., -110., -100., -90., -80., -70., -60., -50., -40., -30.,
    -20., -10., 0., 10., 20., 30., 40., 50., 60., 70., -90., -80., -70., -60., -50., -40., -30., -20., -10., 0.
};

Colourisation::Colourisation(const std::filesystem::path& imagePath)
{
	ReadImage(imagePath);

	imageName = imagePath.filename().string();

	RetrieveResources();

	std::filesystem::path protoFile = protoFileLocation;
	std::filesystem::path weightsFile = weightsFileLocation;

	const int32_t networkInputWidth = 224;
	const int32_t networkInputHeight = 244;
	
	cv::dnn::Net net = cv::dnn::readNetFromCaffe(protoFile.string(), weightsFile.string());

	Timer timer;

	int sz[] = { 2, 313, 1, 1 };
	const cv::Mat pts_in_hull(4, sz, CV_32F, hull_pts);
	cv::Ptr<cv::dnn::Layer> class8_ab = net.getLayer("class8_ab");
	class8_ab->blobs.push_back(pts_in_hull);
	cv::Ptr<cv::dnn::Layer> conv8_313_rh = net.getLayer("conv8_313_rh");
	conv8_313_rh->blobs.push_back(cv::Mat(1, 313, CV_32F, cv::Scalar(2.606)));

	cv::Mat lab, L, input;
	image.convertTo(image, CV_32F, 1.0 / 255);
	cvtColor(image, lab, cv::COLOR_BGR2Lab);
	extractChannel(lab, L, 0);
	resize(L, input, cv::Size(networkInputWidth, networkInputHeight));
	input -= 50;

	// run the L channel through the network
	cv::Mat inputBlob = cv::dnn::blobFromImage(input);
	net.setInput(inputBlob);
	cv::Mat result = net.forward();

	// retrieve the calculated a,b channels from the network output
	cv::Size siz(result.size[2], result.size[3]);
	cv::Mat a = cv::Mat(siz, CV_32F, result.ptr(0, 0));
	cv::Mat b = cv::Mat(siz, CV_32F, result.ptr(0, 1));
	cv::resize(a, a, image.size());
	cv::resize(b, b, image.size());

	cv::Mat color, chn[] = { L, a, b };
	cv::merge(chn, 3, lab);
	cv::cvtColor(lab, color, cv::COLOR_Lab2BGR);

	std::cout << "Time taken : " << (timer.GetTime()) << " secs" << std::endl;

	imageName.replace(imageName.end() - 4, imageName.end(), "");
	imageName += "_colorized.png";

	color = color * 255;
	color.convertTo(color, CV_8U);
	imwrite(imageName, color);

	std::cout << "Colorized image saved as " << imageName << std::endl;
}