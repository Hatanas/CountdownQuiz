#pragma once


/// <summary>
/// サブシーンを定義するためのインターフェース．
/// </summary>
/// <remarks>
/// 抽象クラスなのでインスタンスは生成できません．
/// </remarks>
class SubScene
{
public:
	virtual ~SubScene() = default;
public:
	/// <summary>
	/// シーンを開始する．初期化とは別物．
	/// </summary>
	virtual void start() = 0;

	/// <summary>
	/// シーンを更新する．
	/// </summary>
	virtual void update() = 0;

	/// <summary>
	/// シーンを描画する．
	/// </summary>
	virtual void draw() const = 0;
};

