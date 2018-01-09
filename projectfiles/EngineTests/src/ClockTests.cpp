#include <gtest\gtest.h>
#include <Time/Clock.h>
#include <Windows.h>
#include <iostream>


using gameTime::Clock;

TEST(Clock, ClockInitializeFns)
{
	Clock clock;

	EXPECT_TRUE(clock.initialize());
	EXPECT_TRUE(clock.shutdown());
}
#ifdef OVERNIGHT_TESTS

TEST(Clock, FrameTimeDeltas)
{
	Clock clock;
	EXPECT_TRUE(clock.initialize());
	Sleep(1000);
	clock.newFrame();
	float timedTime = clock.timeElapsedLastFrame();
	EXPECT_TRUE(0.9f < timedTime);
	EXPECT_TRUE(timedTime < 1.1f);
	clock.newFrame();

	Sleep(500);
	clock.newFrame();
	timedTime = clock.timeElapsedLastFrame();
	EXPECT_TRUE(0.4f < timedTime);
	EXPECT_TRUE(timedTime < 0.6f);

	const int NUM_TESTS = 10 + rand() % 100;
	const float EPSILON = 0.006f;
	for (int i = 0; i < NUM_TESTS; i++)
	{
		std::cout << ".";
		int thisTestms = rand() % 10000;
		float thisTestsec = thisTestms / 1000.0f;
		
		clock.newFrame();
		Sleep(thisTestms);
		clock.newFrame();

		float elapsedsec = clock.timeElapsedLastFrame();
		EXPECT_TRUE((thisTestsec - EPSILON) < elapsedsec);
		EXPECT_TRUE(elapsedsec < (thisTestsec + EPSILON));

	}

	clock.newFrame();
	clock.timeElapsedLastFrame();
	EXPECT_TRUE(clock.shutdown());
}

#endif