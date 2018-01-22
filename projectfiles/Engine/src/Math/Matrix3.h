#ifndef ENGINE_MATRIX3_H
#define ENGINE_MATRIX3_H

#include "Vector3.h"
#include <cmath>

namespace fmath
{
	struct Matrix3
	{
		float r0c0, r0c1, r0c2;
		float r1c0, r1c1, r1c2;
		float r2c0, r2c1, r2c2;

		Matrix3(
			float r0c0 = 1, float r0c1 = 0, float r0c2 = 0,
			float r1c0 = 0, float r1c1 = 1, float r1c2 = 0,
			float r2c0 = 0, float r2c1 = 0, float r2c2 = 1);
		inline static Matrix3 rotateZ(float angleInRadians);
		inline static Matrix3 translate(float x, float y);
	};

	inline Vector3 operator*(Matrix3 &matrix, Vector3 &vector);

#include "Matrix3.inl"
}
#endif