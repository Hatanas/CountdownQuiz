#pragma once

namespace util
{
/// <summary>
/// ©ì”ŠwŒnŠÖ”ŒQ
/// </summary>
class Math
{
private:
	Math() = default;
	~Math() = default;
public:
	/// <summary>
	/// ”’l‚ğ0.0~1.0‚Ì”ÍˆÍ‚É³‹K‰»‚·‚é
	/// </summary>
	/// <param name="x"> ³‹K‰»‚·‚é’l </param>
	/// <param name="minX"> Å¬’l </param>
	/// <param name="maxX"> Å‘å’l </param>
	/// <returns> ³‹K‰»‚³‚ê‚½’l </returns>
	static double norm(double x, double minX, double maxX);
	// static double reverseNorm(double x, double minX, double maxX);
	static double inverseNorm(double normX, double minX, double maxX);
};
}