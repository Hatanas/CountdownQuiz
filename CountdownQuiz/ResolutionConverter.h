#pragma once

#include <Siv3D.hpp>


namespace util
{
/// <summary>
/// �𑜓x�ɂ���č��W�l��ϊ����邽�߂̃N���X
/// </summary>
class ResolutionConverter
{
private:
	static int windowWidth_;
	static int windowHeight_;
private:
	ResolutionConverter() = default;
	~ResolutionConverter() = default;
public:
	/// <summary>
	/// �E�B���h�E�̉𑜓x��ݒ肷��
	/// </summary>
	/// <param name="width"> �E�B���h�E�̕�(px) </param>
	/// <param name="height"> �E�B���h�E�̍���(px) </param>
	static void setWindowResolution(int width, int height);
	
	/// <summary>
	/// %�P�ʂ̍��W�l��px�P�ʂ̍��W�l�ɕϊ�(x���W)
	/// </summary>
	/// <param name="percentageX"> x���W(%) </param>
	/// <returns> x���W(px) </returns>
	static int toX(double percentageX);
	
	/// <summary>
	/// %�P�ʂ̍��W�l��px�P�ʂ̍��W�l�ɕϊ�(y���W)
	/// </summary>
	/// <param name="percentageX"> y���W(%) </param>
	/// <returns> y���W(px) </returns>
	static int toY(double percentageY);
	
	/// <summary>
	/// %�P�ʂ̍��W�l��px�P�ʂ̍��W�l�ɕϊ�(x���W�Cy���W)
	/// </summary>
	/// <param name="percentageX"> x���W(%) </param>
	/// <param name="percentageY"> y���W(%) </param>
	/// <returns> ���W�l(px) </returns>
	static Vec2 toVec2(double percentageX, double percentageY);
	
	/// <summary>
	/// %�P�ʂ̍��W�l��px�P�ʂ̍��W�l�ɕϊ�(x���W�Cy���W)
	/// </summary>
	/// <param name="percentageV"> Vec2�^�̍��W�l(%) </param>
	/// <returns> ���W�l(px) </returns>
	static Vec2 toVec2(Vec2 percentageV);
};
}
