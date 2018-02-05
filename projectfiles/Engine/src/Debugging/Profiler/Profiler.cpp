#include "Profiler.h"

void fdebug::Profiler::initialize(const char* fileName)
{
	this->fileName = fileName;
	frameIndex = -1;
	categoryIndex = 0;
}

void fdebug::Profiler::shutdown()
{
}

void fdebug::Profiler::newFrame()
{
	frameIndex++;
	categoryIndex = 0;
}

void fdebug::Profiler::addEntry(const char* category, float time)
{

}

