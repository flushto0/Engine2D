#include <gtest\gtest.h>
#include <Math/Vector2D.h>

using namespace gameMath;

TEST(Vector2D, VectorInitialization)
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
TEST(Vector2D, CopyCtor)
{
	Vector2D source(123.4, 567.8);
	Vector2D copied(source);
	EXPECT_FLOAT_EQ(copied.x, source.x);
	EXPECT_FLOAT_EQ(copied.y, source.y);


}

TEST(Vector2D, AssignmentOperators)
{

}