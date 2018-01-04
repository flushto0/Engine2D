#include <GL\glew.h>
#include <cassert>
#include "GlWindow.h"

namespace
{
	float verts[] =
	{
		+0.0f, +0.1f,
		-0.1f, -0.1f,
		+0.1f, -0.1f
	};
}


void GlWindow::initializeGL()
{
	GLenum err = glewInit();
	assert(err == 0);

	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
	timer.start(0);
}

void GlWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void GlWindow::update()
{

}
