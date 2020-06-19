#include "Effect.h"

cv::Mat Effect::GetOutput() { return output; }

std::string Effect::GetEffectName() { return effectName; }

Effect::Effect() {}
Effect::Effect(const cv::Mat& inputImage) : Image(inputImage), output() {}
