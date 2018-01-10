#include <gtest\gtest.h>
#include <Math/Vector2D.h>

using namespace gameMath;

TEST(Vector2D, CtorDefault)
{
	Vector2D first(1, 2);

	EXPECT_FLOAT_EQ(1, first.x);
	EXPECT_FLOAT_EQ(2, first.y);

}

TEST(Vector2D, VectorAddition)
{
	Vector2D first(2, 3);
	Vector2D second(3, 4);

	Vector2D result1 = first + second;
	Vector2D result2 = second + first;

	EXPECT_FLOAT_EQ(5, result1.x);
	EXPECT_FLOAT_EQ(7, result1.y);

	EXPECT_FLOAT_EQ(result1.x, result2.x);
	EXPECT_FLOAT_EQ(result1.y, result2.y);

}
TEST(Vector2D, ScalarMultiplication)
{
	Vector2D vector(1, 2);
	float scalar = 3;

	Vector2D result1 = vector * scalar;
	Vector2D result2 = scalar * vector;

	EXPECT_FLOAT_EQ(3, result1.x);
	EXPECT_FLOAT_EQ(6, result1.y);

	EXPECT_FLOAT_EQ(result1.x, result2.x);
	EXPECT_FLOAT_EQ(result1.y, result2.y);
}

TEST(Vector2D, OperatorPlusEq)
{
	Vector2D left(123.4f, 567.8f);
	Vector2D right(10, 10);

	left += right;

	EXPECT_FLOAT_EQ(left.x, 133.4f);
	EXPECT_FLOAT_EQ(left.y, 577.8f);
}

TEST(Vector2D, OperatorMinusEq)
{
	Vector2D left(123.4f, 567.8f);
	Vector2D right(10, 10);

	left -= right;

	EXPECT_FLOAT_EQ(left.x, 113.4f);
	EXPECT_FLOAT_EQ(left.y, 557.8f);
}