#ifndef ENGINE_VECTOR2D_H
#define ENGINE_VECTOR2D_H


namespace gameMath
{
	struct Vector2D
	{
		float x;
		float y;

		Vector2D(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
	};

	Vector2D operator+(const Vector2D &left, const Vector2D &right)
	{
		return Vector2D(left.x + right.x, left.y + right.y);
	}

	Vector2D operator*(float scalar, const Vector2D &vector)
	{
		return Vector2D(vector.x * scalar, vector.y * scalar);
	}

	Vector2D operator*(const Vector2D &vector, float scalar)
	{
		return Vector2D(vector.x * scalar, vector.y * scalar);
	}
}


#endif