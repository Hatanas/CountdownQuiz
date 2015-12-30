#pragma once

#include <Siv3D.hpp>


namespace util
{
/// <summary>
/// 解像度によって座標値を変換するためのクラス
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
	/// ウィンドウの解像度を設定する
	/// </summary>
	/// <param name="width"> ウィンドウの幅(px) </param>
	/// <param name="height"> ウィンドウの高さ(px) </param>
	static void setWindowResolution(int width, int height);
	
	/// <summary>
	/// %単位の座標値をpx単位の座標値に変換(x座標)
	/// </summary>
	/// <param name="percentageX"> x座標(%) </param>
	/// <returns> x座標(px) </returns>
	static int toX(double percentageX);
	
	/// <summary>
	/// %単位の座標値をpx単位の座標値に変換(y座標)
	/// </summary>
	/// <param name="percentageX"> y座標(%) </param>
	/// <returns> y座標(px) </returns>
	static int toY(double percentageY);
	
	/// <summary>
	/// %単位の座標値をpx単位の座標値に変換(x座標，y座標)
	/// </summary>
	/// <param name="percentageX"> x座標(%) </param>
	/// <param name="percentageY"> y座標(%) </param>
	/// <returns> 座標値(px) </returns>
	static Vec2 toVec2(double percentageX, double percentageY);
	
	/// <summary>
	/// %単位の座標値をpx単位の座標値に変換(x座標，y座標)
	/// </summary>
	/// <param name="percentageV"> Vec2型の座標値(%) </param>
	/// <returns> 座標値(px) </returns>
	static Vec2 toVec2(Vec2 percentageV);
};
}
