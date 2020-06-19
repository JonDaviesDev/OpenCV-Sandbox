#include "SandboxCore.h"

#include "Window.h"
#include "Image.h"
#include "VideoPlayer.h"
#include "GaussianBlur.h"
#include "ImageScalar.h"
#include "Canny.h"
#include "EffectCombiner.h"
#include "Camera.h"
#include "VideoStreamer.h"
#include "Colourisation.h"


int main()
{
	std::string solutionDirectory(std::filesystem::current_path().parent_path().string());
	std::string imageSampleDirectory(solutionDirectory + "\\ImageSamples\\");

	std::string fileLocation(imageSampleDirectory + "FreeDiving.jpg");
	std::string windowMainName("OpenCV-Sandbox Application");
	
	Window windowMain(windowMainName);
	Image image(fileLocation, windowMain);


	std::shared_ptr<Effect> scaleDown = std::make_unique<ImageScalar>(-2);
	std::shared_ptr<Effect> canny = std::make_unique<Canny>();
	std::shared_ptr<Effect> blur = std::make_unique<GaussianBlur>(10, 3, 3);



	EffectCombiner ec(image, { canny, blur });

	//Camera camera;


	//Colourisation converter(fileLocation);



	cv::waitKey(0);




	return 0;
}