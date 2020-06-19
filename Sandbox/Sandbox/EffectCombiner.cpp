#include "EffectCombiner.h"

EffectCombiner::EffectCombiner(Image& originalImage, const std::initializer_list<std::shared_ptr<Effect>>& effects)
{
	windowName = "OpenCV Application - ";

	cv::Mat image = originalImage.GetImage();

	int i = 0;

	for (auto effect : effects)
	{
		if (i < effects.size() - 1)
			windowName += std::string(effect->GetEffectName() + ", ");
		else windowName += effect->GetEffectName();

		effect->SetImage(image);

		effect->Activate();

		image = effect->GetOutput();
		output = effect->GetOutput();

		i++;
	}
		
	Window window(windowName);

	Display(window, output);
}

void EffectCombiner::Activate(){}