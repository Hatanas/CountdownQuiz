#include "HintDrawer.h"


using RC = util::ResolutionConverter;

const double HintDrawer::m_FONT_SIZE = 3.0;
//const Vec2 HintDrawer::m_TEXT_AREA_SIZE = {60.0, 8.0};

HintDrawer::HintDrawer(String hintText, double positionY)
	: m_hintTextFont(RC::toY(m_FONT_SIZE))
	, m_hintText(hintText)
	, m_centerPosition({50.0, positionY})
{
	m_timer.start();
}

HintDrawer& HintDrawer::operator=(HintDrawer& obj)
{
	obj;
	return *this;
}


void HintDrawer::update()
{
	if(m_timer.elapsed() > 1000) {
		m_timer.pause();
	}
}

void HintDrawer::draw() const
{
	const auto kineticFunction = [this](KineticTypography& k) {
		const double intercept = EaseInOut(0.0, 512.0, Easing::Linear, util::Math::norm(m_timer.elapsed(), 0, 1000));
		k.col = Color(34, 34, 34, Clamp(static_cast<int>(-255.0 / (k.textLength - 1) * k.index + intercept), 0, 255));
	};
	m_hintTextFont.drawKinetic(m_hintText, m_hintTextFont(m_hintText).regionCenter(RC::toVec2(m_centerPosition)).pos, kineticFunction);
}