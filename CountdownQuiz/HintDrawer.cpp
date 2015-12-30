#include "HintDrawer.h"


using RC = util::ResolutionConverter;

HintDrawer::HintDrawer(String hintText)
	: m_hintTextFont(20)
	, m_hintText(hintText)
	, m_y(20.0)
{
}

HintDrawer& HintDrawer::operator=(HintDrawer& obj)
{
	return *this;
}


void HintDrawer::update()
{
}

void HintDrawer::draw() const
{
	//RoundRect(RectF(RC::toX(80.0), RC::toY(10.0)), 6.0).setCenter(RC::toVec2({50.0, m_y}).asPoint()).draw(Palette::Orange).drawFrame(1.0, 0.0, Palette::Red);
	m_hintTextFont(m_hintText).drawCenter(Rect(RC::toX(80.0), RC::toY(10.0)).setCenter(RC::toVec2({50.0, m_y}).asPoint()).draw(Palette::Orange).drawFrame(1.0, 0.0, Palette::Red).center);
}