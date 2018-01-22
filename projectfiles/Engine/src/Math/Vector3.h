#ifndef ENGINE_VECTOR3_H
#define ENGINE_VECTOR3_H

namespace fmath
{
	struct Vector3
	{
		float x;
		float y;
		float z;

		explicit Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}

		inline Vector3& operator+=(const Vector3& right);
		inline Vector3& operator-=(const Vector3& right);
	};

	inline Vector3 operator+(const Vector3 &left, const Vector3 &right);
	inline Vector3 operator*(float scalar, const Vector3 &vector);
	inline Vector3 operator*(const Vector3 &vector, float scalar);

	#include "Vector3.inl"
}

#endif