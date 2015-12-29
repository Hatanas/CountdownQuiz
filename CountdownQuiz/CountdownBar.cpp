#include "CountdownBar.h"


using RC = util::ResolutionConverter;

const int CountdownBar::BAR_LENGTH_ = 520;
const int CountdownBar::BAR_HEIGHT_ = 20;
const double CountdownBar::HSV_BEGIN_ANGLE_ = 135.0;
const double CountdownBar::HSV_END_ANGLE_ = 0.0;

CountdownBar::CountdownBar(int limitTime_ms)
	: limitTime_ms_(limitTime_ms)
	, fontOfCountNumber_(30)
{
}

CountdownBar& CountdownBar::operator=(CountdownBar& obj)
{
	this->nowBarLength_ = obj.nowBarLength_;
	this->nowLimitTime_s_ = obj.nowLimitTime_s_;
	return *this;
}

void CountdownBar::update(int elapsedTime_ms)
{
	double normTime = util::Math::reverseNorm(elapsedTime_ms, 0.0, limitTime_ms_);
	nowBarLength_ = int(520 * normTime);
	nowLimitTime_s_ = int(util::Time::millisecToSec(limitTime_ms_) * normTime);
	nowHSVAngle_ = util::Math::inverseNorm(normTime, HSV_END_ANGLE_, HSV_BEGIN_ANGLE_);
}

void CountdownBar::draw() const
{
	Rect(nowBarLength_, BAR_HEIGHT_).setPos(100, 20).draw(HSV(nowHSVAngle_, 1.0, 1.0));
	fontOfCountNumber_(nowLimitTime_s_).drawCenter(RC::toVec2(6.5, 6.5));
}