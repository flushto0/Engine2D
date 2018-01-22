#include <gtest\gtest.h>
#include <Math\Vector2.h>

using namespace fmath;

TEST(Vector2, CtorDefault)
{
	Vector2 first(1, 2);

	EXPECT_FLOAT_EQ(1, first.x);
	EXPECT_FLOAT_EQ(2, first.y);

}

TEST(Vector2, VectorAddition)
{
	Vector2 first(2, 3);
	Vector2 second(3, 4);

	Vector2 result1 = first + second;
	Vector2 result2 = second + first;

	EXPECT_FLOAT_EQ(5, result1.x);
	EXPECT_FLOAT_EQ(7, result1.y);

	EXPECT_FLOAT_EQ(result1.x, result2.x);
	EXPECT_FLOAT_EQ(result1.y, result2.y);

}
TEST(Vector2, ScalarMultiplication)
{
	Vector2 vector(1, 2);
	float scalar = 3;

	Vector2 result1 = vector * scalar;
	Vector2 result2 = scalar * vector;

	EXPECT_FLOAT_EQ(3, result1.x);
	EXPECT_FLOAT_EQ(6, result1.y);

	EXPECT_FLOAT_EQ(result1.x, result2.x);
	EXPECT_FLOAT_EQ(result1.y, result2.y);
}

TEST(Vector2, OperatorPlusEq)
{
	Vector2 left(123.4f, 567.8f);
	Vector2 right(10, 10);

	left += right;

	EXPECT_FLOAT_EQ(left.x, 133.4f);
	EXPECT_FLOAT_EQ(left.y, 577.8f);
}

TEST(Vector2, OperatorMinusEq)
{
	Vector2 left(123.4f, 567.8f);
	Vector2 right(10, 10);

	left -= right;

	EXPECT_FLOAT_EQ(left.x, 113.4f);
	EXPECT_FLOAT_EQ(left.y, 557.8f);
}