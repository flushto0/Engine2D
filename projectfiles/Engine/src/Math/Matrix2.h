#ifndef ENGINE_MATRIX2_H
#define ENGINE_MATRIX2_H

#include "Vector2.h"
#include <cmath>

namespace fmath
{
	
	struct Matrix2
	{
		float r0c0, r0c1;
		float r1c0, r1c1;

		inline explicit Matrix2(
			float r0c0 = 1, float r0c1 = 0, 
			float r1c0 = 0, float r1c1 = 1);
		inline static Matrix2 rotate(float angleInRadians);
	};
	inline Vector2 operator*(const Matrix2 &left, const Vector2 &right);

	#include "Matrix2.inl"
}
#endif