#include <Siv3D.hpp>
#include "CountdownBar.h"

void Main()
{
	TimerMillisec timer;
	timer.start();

	CountdownBar bar(10000);

	while(System::Update()) {
		int elapsed = timer.elapsed();
		if(elapsed > 10000) {
			timer.pause();
		}
		bar.update(elapsed);
		bar.draw();
	}
}
