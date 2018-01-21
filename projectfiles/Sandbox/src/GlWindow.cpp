#include <GL\glew.h>
#include "GlWindow.h"
#include <cassert>
#include <QtGui\QKeyEvent>

#include <Math\Matrix2D.h>
#include <Math\Vector2D.h>
#include <Time\Clock.h>

namespace
{
	using gameMath::Vector2D;
	using gameMath::Matrix2D;
	using gameTime::Clock;

	Vector2D verts[] =
	{
		Vector2D(+0.0f, 0.14142135623f),
		Vector2D(-0.1f, -0.1f),
		Vector2D(+0.1f, -0.1f)
	};

	const unsigned int NUM_VERTS = sizeof(verts) / sizeof(*verts);
	Vector2D shipPosition;
	Vector2D shipVelocity;
	Clock gameClock;

	float shipOrientation = 0.0f;
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
	int minSize = std::min(width(), height());
	Vector2D viewLoc;
	viewLoc.x = width() / 2 - minSize / 2;
	viewLoc.y = height() / 2 - minSize / 2;
	glViewport(viewLoc.x, viewLoc.y, minSize, minSize);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	Vector2D transformedVerts[NUM_VERTS];
	Matrix2D oper = Matrix2D::rotate(shipOrientation);

	for (unsigned int i = 0; i < NUM_VERTS; i++)
		transformedVerts[i] = shipPosition + (oper * verts[i]);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(transformedVerts), transformedVerts);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void GlWindow::update()
{
	gameClock.newFrame();
	rotateShip();
	shipPosition += shipVelocity * gameClock.timeElapsedLastFrame();
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
	const float ANGULAR_MOVEMENT = 10.0f * gameClock.timeElapsedLastFrame();
	
	if (GetAsyncKeyState(VK_LEFT))
	{
		shipOrientation -= ANGULAR_MOVEMENT;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		shipOrientation += ANGULAR_MOVEMENT;
	}
}

void GlWindow::updateVelocity()
{
	const float ACCELERATION = 0.6f * gameClock.timeElapsedLastFrame();

	if (GetAsyncKeyState(VK_UP))
	{
		shipVelocity.y += ACCELERATION;
	}
}