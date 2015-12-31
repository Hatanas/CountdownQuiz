#include <Siv3D.hpp>
#include "Source/CountdownBar.h"
#include "Source/CountdownNumber.h"
#include "Source/HintDrawer.h"
#include "Source/AnswerButton.h"
#include "Source/Utility/ResolutionConverter.h"

void Main()
{
	Window::SetVirtualFullscreen(Window::GetState().screenSize);
	util::ResolutionConverter::setWindowResolution(Window::Width(), Window::Height());

	Graphics::SetBackground(Color(L"#EEEEEE"));

	TimerMillisec timer;
	timer.start();

	CountdownBar bar(10000);
	CountdownNumber number(10000);
	HintDrawer hint(L"ヒント1", 29.0);
	AnswerButton answer(L"選択肢1", {17.0, 85.0});

	while(System::Update()) {
		int elapsed = timer.elapsed();
		if(elapsed > 10000) {
			timer.pause();
		}
		bar.update(elapsed);
		number.update(elapsed);
		answer.update();
		bar.draw();
		number.draw();
		hint.draw();
		answer.draw();
	}
}
