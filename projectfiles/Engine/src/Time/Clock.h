#ifndef ENGINE_CLOCK_H
#define ENGINE_CLOCK_H

#include <Windows.h>

namespace gameTime
{
	class __declspec(dllexport) Clock
	{
		float deltaTime;
		LARGE_INTEGER timeFrequency;
		LARGE_INTEGER timeLastFrame;
		LARGE_INTEGER deltaLastFrame;

	public:
		bool initialize();
		bool shutdown();
		void newFrame();
		float timeElapsedLastFrame() const;
	};
}


#endif
