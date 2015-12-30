#pragma once

#include <Siv3D.hpp>


namespace util
{
class ResolutionConverter
{
private:
	static int windowWidth_;
	static int windowHeight_;
private:
	ResolutionConverter() = default;
	~ResolutionConverter() = default;
public:
	static void setWindowResolution(int width, int height);
	static int toX(double percentageX);
	static int toY(double percentageY);
	static Vec2 toVec2(double percentageX, double percentageY);
	static Vec2 toVec2(Vec2 percentageV);
};
}
