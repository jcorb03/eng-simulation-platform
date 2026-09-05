#include "simulation/Vector3.h"
#include <cmath>

Vector3::Vector3() : x_(0.0), y_(0.0), z_(0.0) {}

Vector3::Vector3(double x, double y, double z) : x_(x), y_(y), z_(z) {}

double Vector3::x() const
{
  return x_;
}

double Vector3::y() const
{
  return y_;
}

double Vector3::z() const
{
  return z_;
}

double Vector3::dot(const Vector3& other) const 
{
  return x_ * other.x() + y_ * other.y() + z_ * other.z();
}

Vector3 Vector3::operator+(const Vector3& other) const
{
  return Vector3(x_ + other.x_, y_ + other.y_, z_ + other.z_);
}

Vector3 Vector3::operator-(const Vector3& other) const
{
  return Vector3(x_ - other.x_, y_ - other.y_, z_ - other.z_);
}

Vector3 Vector3::operator*(double scalar) const
{
  return Vector3(x_ * scalar, y_ * scalar, z_ * scalar);
}

Vector3 operator*(const double scalar, const Vector3& v)
{
  return Vector3(v.x() * scalar, v.y() * scalar, v.z() * scalar);
}

double Vector3::magnitude() const
{
  return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}