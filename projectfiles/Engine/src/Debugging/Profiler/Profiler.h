#ifndef ENGINE_PROFILING_H
#define ENGINE_PROFILING_H

namespace fdebug
{
	class __declspec(dllexport) Profiler
	{
		const char* fileName;
		int frameIndex;
		int categoryIndex;

		static const unsigned int MAX_FRAME_SAMPLES = 500;
		static const unsigned int MAX_PROFILE_CATEGORIES = 5;
		struct ProfileCategory
		{
			const char* name;
			float samples[MAX_FRAME_SAMPLES];
		} categories[MAX_PROFILE_CATEGORIES];
	public:
		void initialize(const char* fileName);
		void shutdown();
		void newFrame();
		void addEntry(const char *category, float time);

	};
}
#endif