#include <cmath>
#include <gtest\gtest.h>
#include <Math\Matrix2.h>
#include <Math\Constants.h>
#include "HelpFunctions.h"

using fmath::Matrix2;
using fmath::Vector2;

TEST(Matrix2, CtorDefault)
{
	Matrix2 identity;
	EXPECT_FLOAT_EQ(identity.r0c0, 1.0f);
	EXPECT_FLOAT_EQ(identity.r0c1, 0.0f);
	EXPECT_FLOAT_EQ(identity.r1c0, 0.0f);
	EXPECT_FLOAT_EQ(identity.r1c1, 1.0f);

}

TEST(Matrix2, MatrixVectorMultiply)
{
	Matrix2 oper(
		2, -3,
		-2, 5);
	Vector2 vec(3, 6);

	Vector2 result = oper * vec;
	EXPECT_FLOAT_EQ(result.x, -12);
	EXPECT_FLOAT_EQ(result.y, 24);

}
TEST(Matrix2, MatrixRotation)
{
	Matrix2 oper = Matrix2::rotate(0);
	EXPECT_FLOAT_EQ(oper.r0c0, 1.0f);
	EXPECT_FLOAT_EQ(oper.r0c1, 0.0f);
	EXPECT_FLOAT_EQ(oper.r1c0, 0.0f);
	EXPECT_FLOAT_EQ(oper.r1c1, 1.0f);

	oper = Matrix2::rotate((float)fmath::PI / 2);
	EXPECT_TRUE(checkThreshold(oper.r0c0, 0.0f));
	EXPECT_FLOAT_EQ(oper.r0c1, -1.0f);
	EXPECT_FLOAT_EQ(oper.r1c0, 1.0f);
	EXPECT_TRUE(checkThreshold(oper.r1c1, 0.0f));

	oper = Matrix2::rotate((float)fmath::PI / 4);
	EXPECT_FLOAT_EQ(oper.r0c0, 1.0f / sqrt(2.0f));
	EXPECT_FLOAT_EQ(oper.r0c1, -1.0f / sqrt(2.0f));
	EXPECT_FLOAT_EQ(oper.r1c0, 1.0f / sqrt(2.0f));
	EXPECT_FLOAT_EQ(oper.r1c1, 1.0f / sqrt(2.0f));

	oper = Matrix2::rotate((float)-fmath::PI / 4);
	EXPECT_FLOAT_EQ(oper.r0c0, 1.0f / sqrt(2.0f));
	EXPECT_FLOAT_EQ(oper.r0c1, 1.0f / sqrt(2.0f));
	EXPECT_FLOAT_EQ(oper.r1c0, -1.0f / sqrt(2.0f));
	EXPECT_FLOAT_EQ(oper.r1c1, 1.0f / sqrt(2.0f));

	oper = Matrix2::rotate((float)fmath::PI / 6);
	EXPECT_FLOAT_EQ(oper.r0c0, sqrt(3.0f) / 2);
	EXPECT_FLOAT_EQ(oper.r0c1, -1.0f / 2);
	EXPECT_FLOAT_EQ(oper.r1c0, 1.0f / 2);
	EXPECT_FLOAT_EQ(oper.r1c1, sqrt(3.0f) / 2.0f);

}