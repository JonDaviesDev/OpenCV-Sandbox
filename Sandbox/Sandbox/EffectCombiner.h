#pragma once
#include "Effect.h"
#include "EffectsCore.h"
#include <vector>

enum class EffectType
{
	GaussianBlur, Scale, CannyEdgeDetection
};

class EffectCombiner : public Effect
{
public:
	EffectCombiner(Image& originalImage, const std::initializer_list<std::shared_ptr<Effect>>& effects);

	void Activate();

private:
	std::string windowName;
};

