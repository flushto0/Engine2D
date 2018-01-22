#include <gtest\gtest.h>
#include <Math\Matrix3.h>
#include <Math\Vector3.h>

using fmath::Matrix3;
using fmath::Vector3;

TEST(Matrix3, Ctor)
{
	Matrix3 identity;
	EXPECT_FLOAT_EQ(identity.r0c0, 1);
	EXPECT_FLOAT_EQ(identity.r0c1, 0);
	EXPECT_FLOAT_EQ(identity.r0c2, 0);
	EXPECT_FLOAT_EQ(identity.r1c0, 0);
	EXPECT_FLOAT_EQ(identity.r1c1, 1);
	EXPECT_FLOAT_EQ(identity.r1c2, 0);
	EXPECT_FLOAT_EQ(identity.r2c0, 0);
	EXPECT_FLOAT_EQ(identity.r2c1, 0);
	EXPECT_FLOAT_EQ(identity.r2c2, 1);

	Matrix3 random(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	);
	EXPECT_FLOAT_EQ(random.r0c0, 1);
	EXPECT_FLOAT_EQ(random.r0c1, 2);
	EXPECT_FLOAT_EQ(random.r0c2, 3);
	EXPECT_FLOAT_EQ(random.r1c0, 4);
	EXPECT_FLOAT_EQ(random.r1c1, 5);
	EXPECT_FLOAT_EQ(random.r1c2, 6);
	EXPECT_FLOAT_EQ(random.r2c0, 7);
	EXPECT_FLOAT_EQ(random.r2c1, 8);
	EXPECT_FLOAT_EQ(random.r2c2, 9);


}

TEST(Matrix3, MatrixVectorMultiply)
{

}