#include "ResolutionConverter.h"


int util::ResolutionConverter::windowWidth_ = 640;
int util::ResolutionConverter::windowHeight_ = 480;

void util::ResolutionConverter::setWindowResolution(int width, int height)
{
	windowWidth_ = width;
	windowHeight_ = height;
}

int util::ResolutionConverter::toX(double percentageX)
{
	return int(percentageX / 100.0 * windowWidth_);
}

int util::ResolutionConverter::toY(double percentageY)
{
	return int(percentageY / 100.0 * windowHeight_);
}

Vec2 util::ResolutionConverter::toVec2(double percentageX, double percentageY)
{
	return Vec2(percentageX / 100.0 * windowWidth_, percentageY / 100.0 * windowHeight_);
}