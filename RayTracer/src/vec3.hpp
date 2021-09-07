#pragma once

#include <math.h>

class Vec3 {
public:
    double x;
    double y;
    double z;

    Vec3() = default;
    Vec3(double x, double y, double z): x(x), y(y), z(z) {};

    double dot(const Vec3& rhs);

    double length();

    bool equals(Vec3 other);

    Vec3& operator+=(const Vec3& rhs);
    Vec3& operator+=(double rhs);
    friend Vec3 operator+(Vec3 lhs, const Vec3& rhs);
    friend Vec3 operator+(Vec3& lhs, double rhs);
    
    Vec3& operator-=(const Vec3& rhs);
    Vec3& operator-=(double rhs);
    friend Vec3 operator-(Vec3 lhs, const Vec3& rhs);
    friend Vec3 operator-(Vec3& lhs, double rhs);
    
    Vec3& operator*=(const Vec3& rhs);
    Vec3& operator*=(double rhs);
    friend Vec3 operator*(Vec3 lhs, const Vec3& rhs);
    friend Vec3 operator*(Vec3& lhs, double rhs);
    
    Vec3& operator/=(const Vec3& rhs);
    Vec3& operator/=(double rhs);
    friend Vec3 operator/(Vec3 lhs, const Vec3& rhs);
    friend Vec3 operator/(Vec3& lhs, double rhs);
};
