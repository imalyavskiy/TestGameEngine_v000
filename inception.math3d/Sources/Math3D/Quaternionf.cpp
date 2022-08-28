#include "pch.hpp"
#include "Math3D.hpp"

namespace Math3D
{
  Quaternion::Quaternion(const float s, const float x, const float y, const float z)
    : s_(s)
    , x_(x)
    , y_(y)
    , z_(z)
  {
  }

  Quaternion::Quaternion(const float _w, const Vector3f& v)
  {
   throw std::logic_error("not implemented");
  }

  auto Quaternion::s() const -> float
  {
    return s_;
  }
  void Quaternion::s(const float s)
  {
    s_ = s;
  }

  auto Quaternion::x() const -> float
  {
    return x_;
  }
  void Quaternion::x(const float x)
  {
    x_ = x;
  }

  auto Quaternion::y() const -> float
  {
    return y_;
  }
  void Quaternion::y(const float y)
  {
    y_ = y;
  }

  auto Quaternion::z() const -> float
  {
    return z_;
  }
  void Quaternion::z(const float z)
  {
    z_ = z;
  }

  Vector3f Quaternion::xyz() const
  {
    return { x_, y_, z_ };
  }

  void Quaternion::xyz(const Vector3f& v)
  {
    x_ = v.x;
    y_ = v.y;
    z_ = v.z;
  }

  const Quaternion& Quaternion::Normalize()
  {
    const float Length = std::sqrtf(s_ * s_ + x_ * x_ + y_ * y_ + z_ * z_);

    s_ /= Length;

    x_ /= Length;
    y_ /= Length;
    z_ /= Length;

    return (*this);
  }

  Quaternion Quaternion::Normalized() const
  {
    const float Length = std::sqrtf(s_ * s_ + x_ * x_ + y_ * y_ + z_ * z_);
    return { s_ / Length, x_ / Length, y_ / Length, z_ / Length };
  }

  const Quaternion& Quaternion::Conjugate()
  {
    x_ *= -1;
    y_ *= -1;
    z_ *= -1;

    return (*this);
  }

  Quaternion Quaternion::Conjugated() const
  {
    return { -x_, -y_, -z_, s_ };
  }

  Quaternion Quaternion::operator*(const float f) const
  {
   throw std::logic_error("not implemented");
  }

  Quaternion Quaternion::operator*=(const float f) const
  {
   throw std::logic_error("not implemented");
  }

  Quaternion Quaternion::operator*(const Quaternion& r) const
  {
   throw std::logic_error("not implemented");
  }

  Quaternion Quaternion::operator*=(const Quaternion& r) const
  {
   throw std::logic_error("not implemented");
  }

  Quaternion Quaternion::operator*(const Vector3f& v) const
  {
   throw std::logic_error("not implemented");
  }

  Quaternion Quaternion::operator*=(const Vector3f& v) const
  {
   throw std::logic_error("not implemented");
  }

  Quaternion Quaternion::operator+(const float f) const
  {
   throw std::logic_error("not implemented");
  }

  const Quaternion& Quaternion::operator+=(const float f)
  {
   throw std::logic_error("not implemented");
  }

  Quaternion Quaternion::operator+(const Vector3f& v) const
  {
   throw std::logic_error("not implemented");
  }

  const Quaternion& Quaternion::operator+=(const Vector3f& v) const
  {
   throw std::logic_error("not implemented");
  }

  Quaternion Quaternion::operator+(const Quaternion& q) const
  {
   throw std::logic_error("not implemented");
  }

  const Quaternion& Quaternion::operator+=(const Quaternion& q)
  {
   throw std::logic_error("not implemented");
  }

  Quaternion Quaternion::operator-(const float f) const
  {
   throw std::logic_error("not implemented");
  }

  const Quaternion& Quaternion::operator-=(const float f)
  {
   throw std::logic_error("not implemented");
  }

  Quaternion Quaternion::operator-(const Vector3f& v) const
  {
   throw std::logic_error("not implemented");
  }

  const Quaternion& Quaternion::operator-=(const Vector3f& v)
  {
   throw std::logic_error("not implemented");
  }

  Quaternion Quaternion::operator-(const Quaternion& q) const
  {
   throw std::logic_error("not implemented");
  }

  const Quaternion& Quaternion::operator-=(const Quaternion& q)
  {
   throw std::logic_error("not implemented");
  }

  bool Quaternion::operator==(const float v) const
  {
   throw std::logic_error("not implemented");
  }

  bool Quaternion::operator==(const Vector3f q) const
  {
   throw std::logic_error("not implemented");
  }

  bool Quaternion::operator==(const Quaternion& q) const
  {
   throw std::logic_error("not implemented");
  }

  Quaternion& Quaternion::operator=(const Quaternion& other)
  {
   throw std::logic_error("not implemented");
  }

  bool Quaternion::isreal() const
  {
   throw std::logic_error("not implemented");
  }

  bool Quaternion::ispure() const
  {
   throw std::logic_error("not implemented");
  }

  Quaternion Quaternion::inverted() const
  {
   throw std::logic_error("not implemented");
  }

  void Quaternion::invert()
  {
   throw std::logic_error("not implemented");
  }

  Quaternion Quaternion::dot(const Quaternion& other)
  {
   throw std::logic_error("not implemented");
  }
}
