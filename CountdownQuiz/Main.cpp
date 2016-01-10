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

	SceneManager<String> manager;
	manager.add<Game>(L"Game");

	while(System::Update()) {
		manager.updateAndDraw();
	}
}
