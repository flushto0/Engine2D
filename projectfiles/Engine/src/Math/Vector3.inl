Vector3& Vector3::operator+=(const Vector3& right)
{
	this->x += right.x;
	this->y += right.y;
	this->z += right.z;
	return *this;
}
Vector3& Vector3::operator-=(const Vector3& right)
{
	this->x -= right.x;
	this->y -= right.y;
	this->z -= right.z;
	return *this;
}

Vector3 operator+(const Vector3 &left, const Vector3 &right)
{
	return Vector3(left.x +	right.x, left.y + right.y, left.z + right.z);
}
Vector3 operator*(float scalar, const Vector3 &vector)
{
	return Vector3(
		vector.x * scalar, 
		vector.y * scalar,
		vector.z * scalar);
}
Vector3 operator*(const Vector3 &vector, float scalar)
{
	return Vector3(
		vector.x * scalar, 
		vector.y * scalar,
		vector.z * scalar);
}