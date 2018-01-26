Matrix3::Matrix3(
	float r0c0, float r0c1, float r0c2,
	float r1c0, float r1c1, float r1c2,
	float r2c0, float r2c1, float r2c2) :
	r0c0(r0c0), r0c1(r0c1), r0c2(r0c2),
	r1c0(r1c0), r1c1(r1c1), r1c2(r1c2),
	r2c0(r2c0), r2c1(r2c1), r2c2(r2c2) {}

Matrix3 fmath::Matrix3::rotateZ(float angleInRadians)
{
	float cosPart = cos(angleInRadians);
	float sinPart = sin(angleInRadians);

	return Matrix3(
		cosPart, -sinPart, 0,
		sinPart, cosPart, 0,
		0, 0, 1);
}

Matrix3 fmath::Matrix3::translate(float x, float y)
{
	return Matrix3(
		1, 0, x,
		0, 1, y,
		0, 0, 1);
}

Vector3 operator*(Matrix3 &matrix, Vector3 &vector)
{
	return Vector3(
		matrix.r0c0 * vector.x + matrix.r0c1 * vector.y + matrix.r0c2 * vector.z,
		matrix.r1c0 * vector.x + matrix.r1c1 * vector.y + matrix.r1c2 * vector.z,
		matrix.r2c0 * vector.x + matrix.r2c1 * vector.y + matrix.r2c2 * vector.z);
}
Matrix3 operator*(Matrix3 &left, Matrix3 &right)
{
	return Matrix3(
		left.r0c0 * right.r0c0 + left.r0c1 * right.r1c0 + left.r0c2 * right.r2c0, 
		left.r0c0 * right.r0c1 + left.r0c1 * right.r1c1 + left.r0c2 * right.r2c1,
		left.r0c0 * right.r0c2 + left.r0c1 * right.r1c2 + left.r0c2 * right.r2c2,

		left.r1c0 * right.r0c0 + left.r1c1 * right.r1c0 + left.r1c2 * right.r2c0,
		left.r1c0 * right.r0c1 + left.r1c1 * right.r1c1 + left.r1c2 * right.r2c1,
		left.r1c0 * right.r0c2 + left.r1c1 * right.r1c2 + left.r1c2 * right.r2c2,

		left.r2c0 * right.r0c0 + left.r2c1 * right.r1c0 + left.r2c2 * right.r2c0,
		left.r2c0 * right.r0c1 + left.r2c1 * right.r1c1 + left.r2c2 * right.r2c1,
		left.r2c0 * right.r0c2 + left.r2c1 * right.r1c2 + left.r2c2 * right.r2c2);
}