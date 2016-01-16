#include "HintDrawer.h"


using RC = util::ResolutionConverter;

const double HintDrawer::m_FONT_SIZE = 3.0;

HintDrawer::HintDrawer(String hintText, double positionY)
	: m_hintTextFont(RC::toY(m_FONT_SIZE))
	, m_hintText(hintText)
	, m_centerPosition({50.0, positionY})
{
	m_timer.start();
}

HintDrawer& HintDrawer::operator=(const HintDrawer& obj)
{
	this->m_timer = obj.m_timer;
	return *this;
}


void HintDrawer::update()
{
	if(m_timer.ms() > 1000) {
		m_timer.pause();
	}
}

void HintDrawer::draw() const
{
	const auto kineticFunction = [this](KineticTypography& k) {
		const double intercept = EaseInOut(0.0, 1.0 + (k.textLength - 1) / 3.0, Easing::Linear, util::Math::norm(m_timer.ms(), 0, 1000));
		k.col = ColorF(Color(L"#222222"), Clamp(- 1.0 / 3.0 * k.index + intercept, 0.0, 1.0));
	};
	FontAsset(L"HintFont").drawKinetic(m_hintText, m_hintTextFont(m_hintText).regionCenter(RC::toVec2(m_centerPosition)).pos, kineticFunction);
	//m_hintTextFont.drawKinetic(m_hintText, m_hintTextFont(m_hintText).regionCenter(RC::toVec2(m_centerPosition)).pos, kineticFunction);
}