#pragma once

namespace util
{
/// <summary>
/// 自作数学系関数群
/// </summary>
class Math
{
private:
	Math() = default;
	~Math() = default;
public:
	/// <summary>
	/// 数値を0.0~1.0の範囲に正規化する
	/// </summary>
	/// <param name="x"> 正規化する値 </param>
	/// <param name="minX"> 最小値 </param>
	/// <param name="maxX"> 最大値 </param>
	/// <returns> 正規化された値 </returns>
	static double norm(double x, double minX, double maxX);
	// static double reverseNorm(double x, double minX, double maxX);
	static double inverseNorm(double normX, double minX, double maxX);
};
}