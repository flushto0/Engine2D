#include <gtest\gtest.h>
#include <Math\Matrix3.h>
#include <Math\Vector3.h>
#include <Math\Constants.h>
#include "HelpFunctions.h"

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
	Matrix3 oper(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	);
	Vector3 vec(1, 2, 3);

	Vector3 result = oper * vec;

	EXPECT_FLOAT_EQ(result.x, 14);
	EXPECT_FLOAT_EQ(result.y, 32);
	EXPECT_FLOAT_EQ(result.z, 50);

}

TEST(Matrix3, MatrixRotation)
{
	Matrix3 oper = Matrix3::rotateZ(0);
	EXPECT_FLOAT_EQ(oper.r0c0, 1);
	EXPECT_FLOAT_EQ(oper.r0c1, 0);
	EXPECT_FLOAT_EQ(oper.r0c2, 0);
	EXPECT_FLOAT_EQ(oper.r1c0, 0);
	EXPECT_FLOAT_EQ(oper.r1c1, 1);
	EXPECT_FLOAT_EQ(oper.r1c2, 0);
	EXPECT_FLOAT_EQ(oper.r2c0, 0);
	EXPECT_FLOAT_EQ(oper.r2c1, 0);
	EXPECT_FLOAT_EQ(oper.r2c2, 1);

	oper = Matrix3::rotateZ((float)fmath::PI / 2);
	EXPECT_TRUE(checkThreshold(oper.r0c0, 0.0f));
	EXPECT_FLOAT_EQ(oper.r0c1, -1.0f);
	EXPECT_FLOAT_EQ(oper.r0c2, 0);
	EXPECT_FLOAT_EQ(oper.r1c0, 1.0f);
	EXPECT_TRUE(checkThreshold(oper.r1c1, 0.0f));
	EXPECT_FLOAT_EQ(oper.r1c2, 0);
	EXPECT_FLOAT_EQ(oper.r2c0, 0);
	EXPECT_FLOAT_EQ(oper.r2c1, 0);
	EXPECT_FLOAT_EQ(oper.r2c2, 1);

	oper = Matrix3::rotateZ((float)fmath::PI / 4);
	EXPECT_FLOAT_EQ(oper.r0c0, 1.0f / sqrt(2.0f));
	EXPECT_FLOAT_EQ(oper.r0c1, -1.0f / sqrt(2.0f));
	EXPECT_FLOAT_EQ(oper.r0c2, 0);
	EXPECT_FLOAT_EQ(oper.r1c0, 1.0f / sqrt(2.0f));
	EXPECT_FLOAT_EQ(oper.r1c1, 1.0f / sqrt(2.0f));
	EXPECT_FLOAT_EQ(oper.r1c2, 0);
	EXPECT_FLOAT_EQ(oper.r2c0, 0);
	EXPECT_FLOAT_EQ(oper.r2c1, 0);
	EXPECT_FLOAT_EQ(oper.r2c2, 1);

	oper = Matrix3::rotateZ((float)-fmath::PI / 4);
	EXPECT_FLOAT_EQ(oper.r0c0, 1.0f / sqrt(2.0f));
	EXPECT_FLOAT_EQ(oper.r0c1, 1.0f / sqrt(2.0f));
	EXPECT_FLOAT_EQ(oper.r0c2, 0);
	EXPECT_FLOAT_EQ(oper.r1c0, -1.0f / sqrt(2.0f));
	EXPECT_FLOAT_EQ(oper.r1c1, 1.0f / sqrt(2.0f));
	EXPECT_FLOAT_EQ(oper.r1c2, 0);
	EXPECT_FLOAT_EQ(oper.r2c0, 0);
	EXPECT_FLOAT_EQ(oper.r2c1, 0);
	EXPECT_FLOAT_EQ(oper.r2c2, 1);

	oper = Matrix3::rotateZ((float)fmath::PI / 6);
	EXPECT_FLOAT_EQ(oper.r0c0, sqrt(3.0f) / 2);
	EXPECT_FLOAT_EQ(oper.r0c1, -1.0f / 2);
	EXPECT_FLOAT_EQ(oper.r0c2, 0);
	EXPECT_FLOAT_EQ(oper.r1c0, 1.0f / 2);
	EXPECT_FLOAT_EQ(oper.r1c1, sqrt(3.0f) / 2.0f);
	EXPECT_FLOAT_EQ(oper.r1c2, 0);
	EXPECT_FLOAT_EQ(oper.r2c0, 0);
	EXPECT_FLOAT_EQ(oper.r2c1, 0);
	EXPECT_FLOAT_EQ(oper.r2c2, 1);

}