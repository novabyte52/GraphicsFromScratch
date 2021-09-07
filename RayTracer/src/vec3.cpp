#include "vec3.hpp"

double Vec3::dot(const Vec3& rhs)
{
    return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
}

double Vec3::length()
{
    return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

bool Vec3::equals(Vec3 other)
{
    return Vec3::x == other.x && Vec3::y == other.y && Vec3::z == other.z;
}

Vec3& Vec3::operator+=(const Vec3& rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    return *this;
}

Vec3& Vec3::operator+=(double rhs)
{
    this->x += rhs;
    this->y += rhs;
    this->z += rhs;
    return *this;
}

Vec3 operator+(Vec3 lhs, const Vec3& rhs)
{
    lhs += rhs;
    return lhs;
}

Vec3 operator+(Vec3& lhs, double rhs)
{
    lhs+=rhs;
    return lhs;
}

Vec3& Vec3::operator-=(const Vec3& rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
    return *this;
}

Vec3& Vec3::operator-=(double rhs)
{
    this->x -= rhs;
    this->y -= rhs;
    this->z -= rhs;
    return *this;
}

Vec3 operator-(Vec3 lhs, const Vec3& rhs)
{
    lhs -= rhs;
    return lhs;
}

Vec3 operator-(Vec3& lhs, double rhs)
{
    lhs -= rhs;
    return lhs;
}

Vec3& Vec3::operator*=(const Vec3& rhs)
{
    this->x *= rhs.x;
    this->y *= rhs.y;
    this->z *= rhs.z;
    return *this;
}

Vec3& Vec3::operator*=(double rhs)
{
    this->x *= rhs;
    this->y *= rhs;
    this->z *= rhs;
    return *this;
}

Vec3 operator*(Vec3 lhs, const Vec3& rhs)
{
    lhs *= rhs;
    return lhs;
}

Vec3 operator*(Vec3& lhs, double rhs)
{
    lhs *= rhs;
    return lhs;
}

Vec3& Vec3::operator/=(const Vec3& rhs)
{
    this->x /= rhs.x;
    this->y /= rhs.y;
    this->z /= rhs.z;
    return *this;
}

Vec3& Vec3::operator/=(double rhs)
{
    this->x /= rhs;
    this->y /= rhs;
    this->z /= rhs;
    return *this;
}

Vec3 operator/(Vec3 lhs, const Vec3& rhs)
{
    lhs /= rhs;
    return lhs;
}

Vec3 operator/(Vec3& lhs, double rhs)
{
    lhs /= rhs;
    return lhs;
}
