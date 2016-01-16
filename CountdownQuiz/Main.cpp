#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Source/Utility/ResolutionConverter.h"
#include "Source/Game/Game.h"

void Main()
{
	// Window::SetVirtualFullscreen(Window::GetState().screenSize);
	Window::Resize(960, 540);
	util::ResolutionConverter::setWindowResolution(Window::Width(), Window::Height());
	Graphics::SetBackground(Color(L"#EEEEEE"));

	FontAsset::Register(L"HintFont", util::ResolutionConverter::toY(3.0));

	SceneManager<String, GameData> manager;
	manager.add<Game>(L"Game");

	while(System::Update()) {
		manager.updateAndDraw();
	}
}
