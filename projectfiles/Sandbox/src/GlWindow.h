#ifndef GL_WINDOW
#define GL_WINDOW
#include <QtOpenGL\qgl.h>

class GlWindow : public QGLWidget
{
	GLuint vertexBufferID;

protected:
	void initializeGL();
	void paintGL();
};

#endif