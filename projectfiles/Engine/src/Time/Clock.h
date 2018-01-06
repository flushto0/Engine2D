#ifndef ENGINE_CLOCK_H
#define ENGINE_CLOCK_H

namespace gameTime
{
	class Clock
	{
	public:
		bool initialize();
		bool shutdown();
		void newFrame();
		float timeElapsedLastFrame() const;
	};
}


#endif
