#include <QtWidgets\qapplication.h>
#include <QtCore\qdebug.h>
#include "GlWindow.h"
#include <Windows.h>

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);
	
	GlWindow window;
	if (!window.initialize()) return -1;
	window.show();
	unsigned int errCode = application.exec();
	if(!window.shutdown()) errCode |= 1;
	return errCode;
}