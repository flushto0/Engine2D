#include <QtWidgets\qapplication.h>
#include <QtWidgets\qwidget.h>
#include "GlWindow.h"

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);
	GlWindow window;

	QWidget widg;
	widg.show();

	return application.exec();
}