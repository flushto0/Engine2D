#ifndef GL_WINDOW
#define GL_WINDOW
#include <QtOpenGL\qgl.h>
#include <QtCore\qtimer.h>

class GlWindow : public QGLWidget
{
	Q_OBJECT

	GLuint vertexBufferID;
	QTimer timer;
public:
	bool shutdown();
	bool initialize();
protected:
	void initializeGL();
	void paintGL();
private slots:
	void update();
	void rotateShip();
	void updateVelocity();
};

#endif