#include <QtWidgets\qapplication.h>
#include <QtCore\qdebug.h>
#include "GlWindow.h"
#include <Windows.h>

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);
	
	GlWindow window;
	window.show();

	return application.exec();
}