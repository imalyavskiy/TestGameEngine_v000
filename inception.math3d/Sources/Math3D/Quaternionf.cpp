#include "pch.hpp"
#include "Math3D.hpp"

namespace Math3D
{
  const Quaternion Quaternion::zero = { 0.f, 0.f, 0.f, 0.f };

  Quaternion::Quaternion(const float s)
    : s_(s)
  {
  }

  Quaternion::Quaternion(const float s, const float x, const float y, const float z)
    : s_(s)
    , x_(x)
    , y_(y)
    , z_(z)
  {
  }

  Quaternion::Quaternion(const float s, const Vector3f& v)
    : s_(s)
    , x_(v.x)
    , y_(v.y)
    , z_(v.z)
  {
  }

  Quaternion::Quaternion(const Vector3f& v)
    : x_(v.x)
    , y_(v.y)
    , z_(v.z)
  {
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
    return { s_ * f, x_ * f, y_ * f, z_ * f };
  }

  Quaternion Quaternion::operator*=(const float f)
  {
    s_ *= f;
    x_ *= f;
    y_ *= f;
    z_ *= f;

    return (*this);
  }

  Quaternion Quaternion::operator*(const Quaternion& r) const
  {
    return {
      s_ * r.s_ - x_ * r.x_ - y_ * r.y_ - z_ * r.z_,
      s_ * r.x_ + r.s_ * x_ + y_ * r.z_ - r.y_ * z_,
      s_ * r.y_ + r.s_ * y_ - x_ * r.z_ + r.x_ * z_,
      s_ * r.z_ + r.s_ * z_ + x_ * r.y_ - r.x_ * y_,
    };
  }

  const Quaternion& Quaternion::operator*=(const Quaternion& r)
  {
    const float s = s_ * r.s_ - x_ * r.x_ - y_ * r.y_ - z_ * r.z_;
    const float x = s_ * r.x_ + r.s_ * x_ + y_ * r.z_ - r.y_ * z_;
    const float y = s_ * r.y_ + r.s_ * y_ - x_ * r.z_ + r.x_ * z_;
    const float z = s_ * r.z_ + r.s_ * z_ + x_ * r.y_ - r.x_ * y_;

    s_ = s;
    x_ = x;
    y_ = y;
    z_ = z;

    return (*this);
  }

  Quaternion Quaternion::operator*(const Vector3f& v) const
  {
    return {
      (-1.f) * x_ * v.x - y_ * v.y - z_ * v.z
    , s_ * v.x + y_ * v.z - z_ * v.y
    , s_ * v.y - x_ * v.z + z_ * v.x
    , s_ * v.z + x_ * v.y - y_ * v.x
    };
  }

  Quaternion Quaternion::operator*=(const Vector3f& v)
  {
    const float s = (-1.f) * x_ * v.x - y_ * v.y - z_ * v.z;
    const float x = s_ * v.x + y_ * v.z - z_ * v.y;
    const float y = s_ * v.y - x_ * v.z + z_ * v.x;
    const float z = s_ * v.z + x_ * v.y - y_ * v.x;

    s_ = s;
    x_ = x;
    y_ = y;
    z_ = z;

    return (*this);
  }

  Quaternion Quaternion::operator+(const float f) const
  {
    return { s_ + f, x_, y_, z_};
  }

  const Quaternion& Quaternion::operator+=(const float f)
  {
    s_ += f;

    return (*this);
  }

  Quaternion Quaternion::operator+(const Vector3f& v) const
  {
    return { s_, x_ + v.x, y_ + v.y, z_ + v.z };
  }

  const Quaternion& Quaternion::operator+=(const Vector3f& v)
  {
    x_ += v.x;
    y_ += v.y;
    z_ += v.z;

    return (*this);
  }

  Quaternion Quaternion::operator+(const Quaternion& q) const
  {
    return { s_ + q.s_, x_ + q.x_, y_ + q.y_, z_ + q.z_ };
  }

  const Quaternion& Quaternion::operator+=(const Quaternion& q)
  {
    s_ += q.s_;
    x_ += q.x_;
    y_ += q.y_;
    z_ += q.z_;

    return (*this);
  }

  Quaternion Quaternion::operator-(const float f) const
  {
    return {s_ - f, x_, y_, z_};
  }

  const Quaternion& Quaternion::operator-=(const float f)
  {
    s_ -= f;

    return (*this);
  }

  Quaternion Quaternion::operator-(const Vector3f& v) const
  {
    return { s_, x_ - v.x, y_ - v.y, z_ - v.z };
  }

  const Quaternion& Quaternion::operator-=(const Vector3f& v)
  {
    x_ -= v.x;
    y_ -= v.y;
    z_ -= v.z;

    return (*this);
  }

  Quaternion Quaternion::operator-(const Quaternion& q) const
  {
    return { s_ - q.s(), x_ - q.x(), y_ - q.y(), z_ - q.z() };
  }

  const Quaternion& Quaternion::operator-=(const Quaternion& q)
  {
    s_ -= q.s();
    x_ -= q.x();
    y_ -= q.y();
    z_ -= q.z();

    return (*this);
  }

  bool Quaternion::operator==(const float s) const
  {
    return s_ == s && IsReal();
  }

  bool Quaternion::operator!=(const float s) const
  {
    return !operator==(s);
  }

  bool Quaternion::operator==(const Vector3f v) const
  {
    const float dx = std::abs(x_ - v.x);
    const float dy = std::abs(y_ - v.y);
    const float dz = std::abs(z_ - v.z);

    return IsPure() && dx <= imprecision && dy <= imprecision && dz <= imprecision;
  }

  bool Quaternion::operator!=(const Vector3f v) const
  {
    return !operator==(v);
  }

  bool Quaternion::operator==(const Quaternion& q) const
  {
    const float ds = std::abs(s_ - q.s_);
    const float dx = std::abs(x_ - q.x_);
    const float dy = std::abs(y_ - q.y_);
    const float dz = std::abs(z_ - q.z_);

    return ds <= imprecision && dx <= imprecision && dy <= imprecision && dz <= imprecision;
  }

  bool Quaternion::operator!=(const Quaternion& q) const
  {
    return !operator==(q);
  }

  bool Quaternion::IsReal() const
  {
    return std::abs(x_) <= imprecision && std::abs(y_) <= imprecision && std::abs(z_) <= imprecision;
  }

  bool Quaternion::IsPure() const
  {
    return std::abs(s_) <= imprecision && (std::abs(x_) > imprecision || std::abs(y_) > imprecision || std::abs(z_) > imprecision);
  }

  Quaternion& Quaternion::operator=(const float s)
  {
    s_ = s;

    return (*this);
  }

  Quaternion& Quaternion::operator=(const Vector3f& v)
  {
    s_ = 0.f;
    x_ = v.x;
    y_ = v.y;
    z_ = v.z;

    return (*this);
  }

  Quaternion& Quaternion::operator=(const Quaternion& other)
  {
    s_ = other.s_;
    x_ = other.x_;
    y_ = other.y_;
    z_ = other.z_;

    return (*this);
  }

  Quaternion Quaternion::inverted() const
  {
    throw std::logic_error(NOT_IMPLEMENTED_EXC);
  }

  void Quaternion::invert()
  {
    throw std::logic_error(NOT_IMPLEMENTED_EXC);
  }

  Quaternion Quaternion::dot(const Quaternion& other)
  {
    throw std::logic_error(NOT_IMPLEMENTED_EXC);
  }

  bool operator==(const float l, const Quaternion& r)
  {
    return r == l;
  }

  bool operator!=(const float l, const Quaternion& r)
  {
    return !operator==(l, r);
  }

  bool operator==(const Vector3f& l, const Quaternion& r)
  {
    return r == l;
  }

  bool operator!=(const Vector3f& l, const Quaternion& r)
  {
    return !operator==(l, r);
  }

  Quaternion operator+(const Vector3f& l, const Quaternion& r)
  {
    return {r.s(), l.x + r.x(), l.y + r.y(), l.z + r.z()};
  }

  Quaternion operator+(const float l, const Quaternion& r)
  {
    return { l + r.s(), r.x(), r.y(), r.z() };
  }

  Quaternion operator-(const Vector3f& l, const Quaternion& r)
  {
    return {-r.s(), l.x - r.x(), l.y - r.y(), l.z - r.z()};
  }

  Quaternion operator-(const float l, const Quaternion& r)
  {
    return { l - r.s(), -r.x(), -r.y(), -r.z() };
  }

  Quaternion operator*(const Vector3f& l, const Quaternion& r)
  {
    return {
      (-1.f) * l.x * r.x() - l.y * r.y() - l.z * r.z()
    , l.x * r.s() + l.y * r.z() - l.z * r.y()
    , (-1.f) * l.x * r.z() + l.y * r.s() + l.z * r.x()
    , l.x * r.y() - l.y * r.x() + l.z * r.s()
    };
  }

  Quaternion operator*(const float f, const Quaternion& r)
  {
    return {f * r.s(), f* r.x(), f * r.y(), f * r.z()};
  }
}
