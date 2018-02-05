#ifndef ENGINE_PROFILING_H
#define ENGINE_PROFILING_H

namespace fdebug
{
	class __declspec(dllexport) Profiler
	{
	public:
		void addEntry(const char *category, float time);
		void newFrame();
		void initialize(const char* fileName);
		void shutdown();
	};
}
#endif