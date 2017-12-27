#include <QtWidgets\qapplication.h>
#include "GlWindow.h"
#include <QtCore\qtimer.h>

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);
	
	GlWindow window;
	window.show();

	return application.exec();
}