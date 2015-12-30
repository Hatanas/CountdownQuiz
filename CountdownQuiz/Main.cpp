#include <Siv3D.hpp>
#include "CountdownBar.h"
#include "CountdownNumber.h"
#include "HintDrawer.h"

void Main()
{
	TimerMillisec timer;
	timer.start();

	CountdownBar bar(10000);
	CountdownNumber number(10000);
	HintDrawer hint(L"てすとてきすと");

	while(System::Update()) {
		int elapsed = timer.elapsed();
		if(elapsed > 10000) {
			timer.pause();
		}
		bar.update(elapsed);
		number.update(elapsed);
		bar.draw();
		number.draw();
		hint.draw();
	}
}
