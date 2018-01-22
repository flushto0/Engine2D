#ifndef ENGINE_VECTOR2D_H
#define ENGINE_VECTOR2D_H


namespace fmath
{
	struct Vector2
	{
		float x;
		float y;

		explicit Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

		inline Vector2& operator+=(const Vector2& right);
		inline Vector2& operator-=(const Vector2& right);
	};

	inline Vector2 operator+(const Vector2 &left, const Vector2 &right);
	inline Vector2 operator*(float scalar, const Vector2 &vector);
	inline Vector2 operator*(const Vector2 &vector, float scalar);

	#include "Math/Vector2.inl"

}


#endif