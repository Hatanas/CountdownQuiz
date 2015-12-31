#pragma once

namespace util
{
/// <summary>
/// ���쐔�w�n�֐��Q
/// </summary>
class Math
{
private:
	Math() = default;
	~Math() = default;
public:
	/// <summary>
	/// ���l��0.0~1.0�͈̔͂ɐ��K������
	/// </summary>
	/// <param name="x"> ���K������l </param>
	/// <param name="minX"> �ŏ��l </param>
	/// <param name="maxX"> �ő�l </param>
	/// <returns> ���K�����ꂽ�l </returns>
	static double norm(double x, double minX, double maxX);
	// static double reverseNorm(double x, double minX, double maxX);
	// static double inverseNorm(double normX, double minX, double maxX);
};
}