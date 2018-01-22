#include <gtest\gtest.h>
#include <Math\Vector3.h>

using fmath::Vector3;

TEST(Vector3, Ctor)
{
	Vector3 instance(-2.4f, 5.0f, 3.1f);
	EXPECT_FLOAT_EQ(instance.x, -2.4f);
	EXPECT_FLOAT_EQ(instance.y, 5.0f);
	EXPECT_FLOAT_EQ(instance.z, 3.1f);

	Vector3 defaultCtor;
	EXPECT_FLOAT_EQ(defaultCtor.x, 0);
	EXPECT_FLOAT_EQ(defaultCtor.y, 0);
	EXPECT_FLOAT_EQ(defaultCtor.z, 0);
}

TEST(Vector3, VectorAddition)
{
	Vector3 left(1, 2, 3);
	Vector3 right(4, 5, 6);
	Vector3 result = left + right;
	Vector3 result2 = right + left;

	EXPECT_FLOAT_EQ(result.x, 5);
	EXPECT_FLOAT_EQ(result.y, 7);
	EXPECT_FLOAT_EQ(result.z, 9);

	EXPECT_FLOAT_EQ(result2.x, result.x);
	EXPECT_FLOAT_EQ(result2.y, result.y);
	EXPECT_FLOAT_EQ(result2.z, result.z);

}

TEST(Vector3, ScalarMultiplication)
{
	Vector3 instance(3, 2, 5);
	Vector3 multiple = instance * 3;
	Vector3 multiple2 = 3 * instance;


	EXPECT_FLOAT_EQ(multiple.x, 9);
	EXPECT_FLOAT_EQ(multiple.y, 6);
	EXPECT_FLOAT_EQ(multiple.z, 15);

	EXPECT_FLOAT_EQ(multiple2.x, multiple.x);
	EXPECT_FLOAT_EQ(multiple2.y, multiple.y);
	EXPECT_FLOAT_EQ(multiple2.z, multiple.z);

}