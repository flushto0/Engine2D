#ifndef GL_WINDOW
#define GL_WINDOW
#include <QtOpenGL\qgl.h>
#include <QtCore\qtimer.h>

class GlWindow : public QGLWidget
{
	Q_OBJECT

	GLuint vertexBufferID;
	QTimer timer;
protected:
	void initializeGL();
	void paintGL();
private slots:
	void update();
};

#endif