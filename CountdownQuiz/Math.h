#pragma once

namespace util
{
class Math
{
private:
	Math() = default;
	~Math() = default;
public:
	static double norm(double x, double minX, double maxX);
	static double reverseNorm(double x, double minX, double maxX);
	static double inverseNorm(double normX, double minX, double maxX);
};
}