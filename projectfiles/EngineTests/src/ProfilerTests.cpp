#include <gtest\gtest.h>
#include <Debugging\Profiler\Profiler.h>
#include <fstream>

using std::ifstream;
using std::string;
using fdebug::Profiler;

string getNextToken(ifstream& theFile)
{
	char c;
	string ret;

	while (theFile.good())
	{
		theFile >> c;
		if (c == ',' || c == '\n')
			break;
		ret += c;
	}
	return ret;
}

TEST(Profiler, SampleFunctionality)
{
	const char* profileFileName = "profiles.txt";
	Profiler profiler;
	profiler.initialize(profileFileName);

	const int NUM_ENTRIES = 15;

	for (int i = 0; i < NUM_ENTRIES; i++)
	{
		profiler.newFrame();
		profiler.addEntry("Category1", i);
		profiler.addEntry("Category2", ++i);
		profiler.addEntry("Category3", ++i);
	}

	profiler.shutdown();

	ifstream input(profileFileName);

	EXPECT_EQ(getNextToken(input), "Category1");
	EXPECT_EQ(getNextToken(input), "Category2");
	EXPECT_EQ(getNextToken(input), "Category3");

	for (int i = 0; i < NUM_ENTRIES; i++)
	{
		string buf = getNextToken(input);
		EXPECT_EQ(atoi(buf.c_str()), i);
	}
}
