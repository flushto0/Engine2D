#include <GL\glew.h>
#include "GlWindow.h"
#include <cassert>
#include <QtGui\QKeyEvent>

#include <Math\Vector2D.h>
#include <Time\Clock.h>

namespace
{
	using gameMath::Vector2D;
	using gameTime::Clock;

	Vector2D verts[] =
	{
		Vector2D(+0.0f, +0.1f),
		Vector2D(-0.1f, -0.1f),
		Vector2D(+0.1f, -0.1f)
	};

	const unsigned int NUM_VERTS = sizeof(verts) / sizeof(*verts);
	Vector2D shipPosition;
	Vector2D shipVelocity;
	Clock gameClock;
}

void GlWindow::initializeGL()
{
	glViewport(0, 0, width(), height());
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
	gameClock.newFrame();
	rotateShip();
	shipPosition = shipPosition + shipVelocity * gameClock.timeElapsedLastFrame();
	repaint();
}


bool GlWindow::shutdown()
{
	return gameClock.shutdown();
}

bool GlWindow::initialize()
{
	
	return gameClock.initialize();
}

void GlWindow::rotateShip()
{
	const float ACCELERATION = 0.6f * gameClock.timeElapsedLastFrame();
	if (GetAsyncKeyState(VK_UP))
	{
		shipVelocity.y += ACCELERATION;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		shipVelocity.y -= ACCELERATION;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		shipVelocity.x -= ACCELERATION;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		shipVelocity.x += ACCELERATION;
	}
}

void GlWindow::updateVelocity()
{

}