#include "HintDrawer.h"


using RC = util::ResolutionConverter;

const double HintDrawer::m_FONT_SIZE = 3.0;
const Vec2 HintDrawer::m_TEXT_AREA_SIZE = {60.0, 8.0};

HintDrawer::HintDrawer(String hintText, double positionY)
	: m_hintTextFont(RC::toY(m_FONT_SIZE))
	, m_hintText(hintText)
	, m_centerPosition_px(m_hintTextFont(m_hintText).regionCenter(RC::toVec2({50.0, positionY})).center)
{
}

HintDrawer& HintDrawer::operator=(HintDrawer& obj)
{
	obj;
	return *this;
}


void HintDrawer::update()
{
}

void HintDrawer::draw() const
{
	RoundRect(RectF(RC::toVec2(m_TEXT_AREA_SIZE)), 7.0).setCenter(m_centerPosition_px).draw(Palette::Orange).drawFrame(2.0, 0.0, Palette::Red);
	m_hintTextFont(m_hintText).drawCenter(m_centerPosition_px);
}