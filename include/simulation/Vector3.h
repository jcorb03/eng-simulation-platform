#pragma once

class Vector3
{
public:
  Vector3();
  Vector3(double x, double y, double z);

  double x() const;
  double y() const;
  double z() const;

  double dot(const Vector3& other) const;
  Vector3 operator+(const Vector3& other) const;
  Vector3 operator-(const Vector3& other) const;
  Vector3 operator*(double scalar) const;
  Vector3 operator/(double scalar) const;

  double magnitude() const;

private:
  double x_, y_, z_;
};

Vector3 operator*(double scalar, const Vector3& v);