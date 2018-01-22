#include <GL\glew.h>
#include "GlWindow.h"
#include <cassert>
#include <QtGui\QKeyEvent>

#include <Math\Matrix3.h>
#include <Math\Vector3.h>
#include <Time\Clock.h>

namespace
{
	using fmath::Vector3;
	using fmath::Matrix3;
	using ftime::Clock;

	Vector3 verts[] =
	{
		Vector3(+0.0f, 0.14142135623f, 1),
		Vector3(-0.1f, -0.1f, 1),
		Vector3(+0.1f, -0.1f, 1)
	};

	const unsigned int NUM_VERTS = sizeof(verts) / sizeof(*verts);
	Vector3 shipPosition;
	Vector3 shipVelocity;
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
	Vector3 viewLoc;
	viewLoc.x = width() / 2 - minSize / 2;
	viewLoc.y = height() / 2 - minSize / 2;
	glViewport(viewLoc.x, viewLoc.y, minSize, minSize);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	Vector3 transformedVerts[NUM_VERTS];
	Matrix3 oper = Matrix3::translate(shipPosition.x, shipPosition.y) * Matrix3::rotateZ(shipOrientation);

	for (unsigned int i = 0; i < NUM_VERTS; i++)
		transformedVerts[i] = oper * verts[i];

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(transformedVerts), transformedVerts);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void GlWindow::update()
{
	gameClock.newFrame();
	rotateShip();
	updateVelocity();
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
	const float ANGULAR_MOVEMENT = 2.0f * gameClock.timeElapsedLastFrame();
	
	if (GetAsyncKeyState(VK_LEFT))
	{
		shipOrientation += ANGULAR_MOVEMENT;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		shipOrientation -= ANGULAR_MOVEMENT;
	}
}

void GlWindow::updateVelocity()
{
	const float ACCELERATION = 1.0f * gameClock.timeElapsedLastFrame();

	Vector3 accelerationDirection(-sin(shipOrientation), cos(shipOrientation));

	if (GetAsyncKeyState(VK_UP))
	{
		shipVelocity += (accelerationDirection * ACCELERATION);
	}
}