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

  auto Quaternion::Normalize() -> const Quaternion&
  {
    return operator/=(Norm());
  }

  auto Quaternion::Normalized() const -> Quaternion
  {
    return Quaternion{ s_, x_, y_, z_ }.Normalize();
  }

  const Quaternion& Quaternion::Conjugate()
  {
    x_ *= -1.f;
    y_ *= -1.f;
    z_ *= -1.f;

    return (*this);
  }

  [[nodiscard]]
  auto Quaternion::Conjugated() const -> Quaternion
  {
    return { s_, (-1.f) * x_, (-1.f) * y_, (-1.f) * z_ };
  }

  [[nodiscard]]
  auto Quaternion::operator*(const float f) const -> Quaternion
  {
    return { s_ * f, x_ * f, y_ * f, z_ * f };
  }

  auto Quaternion::operator*=(const float f) -> const Quaternion&
  {
    s_ *= f;
    x_ *= f;
    y_ *= f;
    z_ *= f;

    return (*this);
  }

  auto Quaternion::operator*(const Quaternion& r) const -> Quaternion
  {
    return {
      s_ * r.s_ - x_ * r.x_ - y_ * r.y_ - z_ * r.z_,
      s_ * r.x_ + r.s_ * x_ + y_ * r.z_ - r.y_ * z_,
      s_ * r.y_ + r.s_ * y_ - x_ * r.z_ + r.x_ * z_,
      s_ * r.z_ + r.s_ * z_ + x_ * r.y_ - r.x_ * y_,
    };
  }

  auto Quaternion::operator*=(const Quaternion& r) -> const Quaternion&
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

  auto Quaternion::operator/(const float f) const -> Quaternion
  {
    return { s_ / f, x_ / f, y_ / f, z_ / f };
  }

  auto Quaternion::operator/=(const float f) -> const Quaternion&
  {
    s_ /= f;
    x_ /= f;
    y_ /= f;
    z_ /= f;

    return (*this);
  }

  auto Quaternion::operator*(const Vector3f& v) const -> Quaternion
  {
    return {
      (-1.f) * x_ * v.x - y_ * v.y - z_ * v.z
    , s_ * v.x + y_ * v.z - z_ * v.y
    , s_ * v.y - x_ * v.z + z_ * v.x
    , s_ * v.z + x_ * v.y - y_ * v.x
    };
  }

  const Quaternion& Quaternion::operator*=(const Vector3f& v)
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

  auto Quaternion::operator+(const float f) const -> Quaternion
  {
    return { s_ + f, x_, y_, z_};
  }

  auto Quaternion::operator+=(const float f) -> const Quaternion&
  {
    s_ += f;

    return (*this);
  }

  auto Quaternion::operator+(const Vector3f& v) const -> Quaternion
  {
    return { s_, x_ + v.x, y_ + v.y, z_ + v.z };
  }

  auto Quaternion::operator+=(const Vector3f& v) -> const Quaternion&
  {
    x_ += v.x;
    y_ += v.y;
    z_ += v.z;

    return (*this);
  }

  auto Quaternion::operator+(const Quaternion& q) const -> Quaternion
  {
    return { s_ + q.s_, x_ + q.x_, y_ + q.y_, z_ + q.z_ };
  }

  auto Quaternion::operator+=(const Quaternion& q) -> const Quaternion&
  {
    s_ += q.s_;
    x_ += q.x_;
    y_ += q.y_;
    z_ += q.z_;

    return (*this);
  }

  auto Quaternion::operator-(const float f) const -> Quaternion
  {
    return {s_ - f, x_, y_, z_};
  }

  auto Quaternion::operator-=(const float f) -> const Quaternion&
  {
    s_ -= f;

    return (*this);
  }

  auto Quaternion::operator-(const Vector3f& v) const -> Quaternion
  {
    return { s_, x_ - v.x, y_ - v.y, z_ - v.z };
  }

  auto Quaternion::operator-=(const Vector3f& v) -> const Quaternion&
  {
    x_ -= v.x;
    y_ -= v.y;
    z_ -= v.z;

    return (*this);
  }

  auto Quaternion::operator-(const Quaternion& q) const -> Quaternion
  {
    return { s_ - q.s(), x_ - q.x(), y_ - q.y(), z_ - q.z() };
  }

  auto Quaternion::operator-=(const Quaternion& q) -> const Quaternion&
  {
    s_ -= q.s();
    x_ -= q.x();
    y_ -= q.y();
    z_ -= q.z();

    return (*this);
  }

  auto Quaternion::operator==(const float s) const -> bool
  {
    return s_ == s && IsReal();
  }

  auto Quaternion::operator!=(const float s) const -> bool
  {
    return !operator==(s);
  }

  auto Quaternion::operator==(const Vector3f v) const -> bool
  {
    const float dx = std::abs(x_ - v.x);
    const float dy = std::abs(y_ - v.y);
    const float dz = std::abs(z_ - v.z);

    return IsPure() && dx <= imprecision && dy <= imprecision && dz <= imprecision;
  }

  auto Quaternion::operator!=(const Vector3f v) const -> bool
  {
    return !operator==(v);
  }

  auto Quaternion::operator==(const Quaternion& q) const -> bool
  {
    const float ds = std::abs(s_ - q.s_);
    const float dx = std::abs(x_ - q.x_);
    const float dy = std::abs(y_ - q.y_);
    const float dz = std::abs(z_ - q.z_);

    return ds <= imprecision && dx <= imprecision && dy <= imprecision && dz <= imprecision;
  }

  auto Quaternion::operator!=(const Quaternion& q) const -> bool
  {
    return !operator==(q);
  }

  auto Quaternion::IsReal() const -> bool
  {
    return std::abs(x_) <= imprecision && std::abs(y_) <= imprecision && std::abs(z_) <= imprecision;
  }

  auto Quaternion::IsPure() const -> bool
  {
    return std::abs(s_) <= imprecision && (std::abs(x_) > imprecision || std::abs(y_) > imprecision || std::abs(z_) > imprecision);
  }

  auto Quaternion::IsNull() const -> bool
  {
    const float ds = std::abs(s_);
    const float dx = std::abs(x_);
    const float dy = std::abs(y_);
    const float dz = std::abs(z_);

    return ds <= imprecision && dx <= imprecision && dy <= imprecision && dz <= imprecision;
  }

  auto Quaternion::operator=(const float s) -> Quaternion&
  {
    s_ = s;

    return (*this);
  }

  auto Quaternion::operator=(const Vector3f& v) -> Quaternion&
  {
    s_ = 0.f;
    x_ = v.x;
    y_ = v.y;
    z_ = v.z;

    return (*this);
  }

  auto Quaternion::Inversed() const -> Quaternion
  {
    return Conjugated() / Norm();
  }

  const Quaternion& Quaternion::Inverse()
  {
    const float n = Norm();

    s_ /=  n;
    x_ /= -n;
    y_ /= -n;
    z_ /= -n;

    return (*this);
  }

  auto Quaternion::Norm() const -> float
  {
    return s_ * s_ + x_ * x_ + y_ * y_ + z_ * z_;
  }

  auto Quaternion::Module() const -> float
  {
    return std::sqrt(Norm());
  }

  auto Quaternion::dot(const Quaternion& r) const -> float
  {
    return (s_ * r.s_ + x_ * r.x_ + y_ * r.y_ + z_ * r.z_) / (Module() * r.Module());
  }

  auto operator==(const float l, const Quaternion& r) -> bool
  {
    return r == l;
  }

  auto operator!=(const float l, const Quaternion& r) -> bool
  {
    return !operator==(l, r);
  }

  auto operator==(const Vector3f& l, const Quaternion& r) -> bool
  {
    return r == l;
  }

  auto operator!=(const Vector3f& l, const Quaternion& r) -> bool
  {
    return !operator==(l, r);
  }

  auto operator+(const Vector3f& l, const Quaternion& r) -> Quaternion
  {
    return {r.s(), l.x + r.x(), l.y + r.y(), l.z + r.z()};
  }

  auto operator+(const float l, const Quaternion& r) -> Quaternion
  {
    return { l + r.s(), r.x(), r.y(), r.z() };
  }

  auto operator-(const Vector3f& l, const Quaternion& r) -> Quaternion
  {
    return {-r.s(), l.x - r.x(), l.y - r.y(), l.z - r.z()};
  }

  auto operator-(const float l, const Quaternion& r) -> Quaternion
  {
    return { l - r.s(), -r.x(), -r.y(), -r.z() };
  }

  auto operator*(const Vector3f& l, const Quaternion& r) -> Quaternion
  {
    return {
      (-1.f) * l.x * r.x() - l.y * r.y() - l.z * r.z()
    , l.x * r.s() + l.y * r.z() - l.z * r.y()
    , (-1.f) * l.x * r.z() + l.y * r.s() + l.z * r.x()
    , l.x * r.y() - l.y * r.x() + l.z * r.s()
    };
  }

  auto operator*(const float f, const Quaternion& r) -> Quaternion
  {
    return {f * r.s(), f* r.x(), f * r.y(), f * r.z()};
  }

  auto dot(const Quaternion& l, const Quaternion& r) -> float
  {
    return (l.s() * r.s() + l.x() * r.x() + l.y() * r.y() + l.z() * r.z()) / (l.Module() * r.Module());
  }
}
