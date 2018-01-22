Matrix2::Matrix2(
	float r0c0, float r0c1,
	float r1c0, float r1c1) : r0c0(r0c0), r0c1(r0c1), r1c0(r1c0), r1c1(r1c1)
{

}

Matrix2 fmath::Matrix2::rotate(float angleInRadians)
{
	float cosResult = cos(angleInRadians);
	float sinResult = sin(angleInRadians);
	return Matrix2(
		cosResult, -sinResult,
		sinResult, cosResult);
}

Vector2 operator*(const Matrix2 &left, const Vector2 &right)
{
	// This is multiplied in row-major format to adhere to opengl.
	// | x  y | x | a  b |
	//            | c  d |
	return Vector2(
		left.r0c0 * right.x + left.r0c1 * right.y,
		left.r1c0 * right.x + left.r1c1 * right.y
	);
}
