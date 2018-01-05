#include <GL\glew.h>
#include "GlWindow.h"
#include <cassert>

#include <Math\Vector2D.h>

namespace
{
	using gameMath::Vector2D;

	Vector2D verts[] =
	{
		Vector2D(+0.0f, +0.1f),
		Vector2D(-0.1f, -0.1f),
		Vector2D(+0.1f, -0.1f)
	};

	const unsigned int NUM_VERTS = sizeof(verts) / sizeof(*verts);
	Vector2D shipPosition(-0.5f, -0.0f);
}

void GlWindow::initializeGL()
{
	GLenum err = glewInit();
	assert(err == 0);

	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), NULL, GL_DYNAMIC_DRAW);

	connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
	timer.start(0);
}

void GlWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	
	Vector2D translatedVerts[NUM_VERTS];

	for (unsigned int i = 0; i < NUM_VERTS; i++)
		translatedVerts[i] = verts[i] + shipPosition;

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(translatedVerts), translatedVerts);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void GlWindow::update()
{
	Vector2D velocity(0.001f, 0.001f);
	shipPosition = shipPosition + velocity;
	repaint();
}
