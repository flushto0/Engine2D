#include <gtest\gtest.h>
#include <Math\Matrix2D.h>

using gameMath::Matrix2D;
using gameMath::Vector2D;

TEST(Matrix2D, CtorDefault)
{
	Matrix2D identity;
	EXPECT_FLOAT_EQ(identity.r0c0, 1.0f);
	EXPECT_FLOAT_EQ(identity.r0c1, 0.0f);
	EXPECT_FLOAT_EQ(identity.r1c0, 0.0f);
	EXPECT_FLOAT_EQ(identity.r1c1, 1.0f);

}

TEST(Matrix2D, MatrixVectorMultiply)
{
	Matrix2D oper(
		2, -3,
		-2, 5);
	Vector2D vec(3, 6);

	Vector2D result = oper * vec;
	EXPECT_FLOAT_EQ(result.x, -6);
	EXPECT_FLOAT_EQ(result.y, 21);

}
TEST(Matrix2D, MatrixRotation)
{
	Matrix2D oper = Matrix2D::rotate(0);
	EXPECT_FLOAT_EQ(oper.r0c0, 1.0f);
	EXPECT_FLOAT_EQ(oper.r0c1, 0.0f);
	EXPECT_FLOAT_EQ(oper.r1c0, 0.0f);
	EXPECT_FLOAT_EQ(oper.r1c1, 1.0f);

	oper = Matrix2D::rotate(PI / 2);
	EXPECT_FLOAT_EQ(oper.r0c0, 0.0f);
	EXPECT_FLOAT_EQ(oper.r0c1, -1.0f);
	EXPECT_FLOAT_EQ(oper.r1c0, 1.0f);
	EXPECT_FLOAT_EQ(oper.r1c1, 0.0f);

	oper = Matrix2D::rotate(PI / 4);
	float sqrt2over2 = 0.70710678118;
	EXPECT_FLOAT_EQ(oper.r0c0, 1 / sqrt(2));
	EXPECT_FLOAT_EQ(oper.r0c1, -1 / sqrt(2));
	EXPECT_FLOAT_EQ(oper.r1c0, 1 / sqrt(2));
	EXPECT_FLOAT_EQ(oper.r1c1, 1 / sqrt(2));

	oper = Matrix2D::rotate(-PI / 4);
	EXPECT_FLOAT_EQ(oper.r0c0, 1 / sqrt(2));
	EXPECT_FLOAT_EQ(oper.r0c1, 1 / sqrt(2));
	EXPECT_FLOAT_EQ(oper.r1c0, -1 / sqrt(2));
	EXPECT_FLOAT_EQ(oper.r1c1, 1 / sqrt(2));

	oper = Matrix2D::rotate(PI / 6);
	EXPECT_FLOAT_EQ(oper.r0c0, sqrt(3) / 2);
	EXPECT_FLOAT_EQ(oper.r0c1, -1 / 2);
	EXPECT_FLOAT_EQ(oper.r1c0, 1 / 2);
	EXPECT_FLOAT_EQ(oper.r1c1, sqrt(3) / 2);

}