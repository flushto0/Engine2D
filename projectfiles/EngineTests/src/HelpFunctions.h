#ifndef TEST_HELPFUNCTIONS_H
#define TEST_HELPFUNCTIONS_H

#include <cmath>

inline bool checkThreshold(float left, float right, float threshold = 0.0000001f)
{
	return abs(left - right) < threshold;
}
#endif