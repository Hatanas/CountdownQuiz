#include "NextDummy.h"

using RC = util::ResolutionConverter;


NextDummy::NextDummy(std::shared_ptr<SubSceneManager> sceneChanger)
	: m_sceneChanger(sceneChanger)
{
}


void NextDummy::start() {}

void NextDummy::update() {}

void NextDummy::draw() const
{
	Rect(RC::toVec2({100.0, 100.0}).asPoint()).setCenter(RC::toVec2({50.0, 50.0}).asPoint()).draw(Color(L"#EEEEEE"));
}