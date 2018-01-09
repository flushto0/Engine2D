#include "Matrix2D.h"
Matrix2D::Matrix2D(
	float r0c0, float r0c1,
	float r1c0, float r1c1) : r0c0(r0c0), r0c1(r0c1), r1c0(r1c0), r1c1(r1c1)
{

}

Matrix2D gameMath::Matrix2D::rotate(float angleInRadians)
{
	return Matrix2D();
}

Vector2D operator*(const Matrix2D &left, const Vector2D &right)
{
	// This is multiplied in row-major format to adhere to opengl.
	// | x  y | x | a  b |
	//            | c  d |
	return Vector2D(
		left.r0c0 * right.x + left.r1c0 * right.y,
		left.r0c1 * right.x + left.r1c1 * right.y
	);
}
