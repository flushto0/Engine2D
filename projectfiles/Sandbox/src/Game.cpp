#include <QtWidgets\qapplication.h>
#include "GlWindow.h"
#include <Windows.h>

int main(int argc, char* argv[])
{
	LARGE_INTEGER clockFreq;
	LARGE_INTEGER startTime;
	LARGE_INTEGER endTime;
	QueryPerformanceFrequency(&clockFreq);

	QApplication application(argc, argv);
	
	GlWindow window;
	window.show();

	return application.exec();
}