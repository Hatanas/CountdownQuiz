#pragma once


/// <summary>
/// �T�u�V�[�����`���邽�߂̃C���^�[�t�F�[�X�D
/// </summary>
/// <remarks>
/// ���ۃN���X�Ȃ̂ŃC���X�^���X�͐����ł��܂���D
/// </remarks>
class SubScene
{
public:
	virtual ~SubScene() = default;
public:
	/// <summary>
	/// �V�[�����J�n����D�������Ƃ͕ʕ��D
	/// </summary>
	virtual void start() = 0;

	/// <summary>
	/// �V�[�����X�V����D
	/// </summary>
	virtual void update() = 0;

	/// <summary>
	/// �V�[����`�悷��D
	/// </summary>
	virtual void draw() const = 0;
};

