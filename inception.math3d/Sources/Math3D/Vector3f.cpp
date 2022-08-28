#include "pch.hpp"
#include "Math3d.hpp"

namespace Math3D
{
  const Direction Direction::Forward = { 1.f, 0.f, 0.f };
  const Direction Direction::Backward = { -1.f, 0.f, 0.f };
  const Direction Direction::Up = { 0.f, 0.f, 1.f };
  const Direction Direction::Down = { 0.f, 0.f,-1.f };
  const Direction Direction::Right = { 0.f, 1.f, 0.f };
  const Direction Direction::Left = { 0.f,-1.f, 0.f };

  Vector3f::Vector3f(const float _x, const float _y, const float _z)
    : x(_x)
    , y(_y)
    , z(_z)
  {
  }

  Vector3f& Vector3f::Normalize()
  {
    const float Length = std::sqrtf(x * x + y * y + z * z);

    x /= Length;
    y /= Length;
    z /= Length;

    return *this;
  }

  Vector3f Vector3f::operator-() const
  {
    return { -x, -y, -z };
  }

  Vector3f Vector3f::operator*(const float factor) const
  {
    return { factor * x, factor * y, factor * z };
  }

  Vector3f Vector3f::operator+=(const float v)
  {
    x += v;
    y += v;
    z += v;

    return (*this);
  }

  const float* Vector3f::data() const
  {
    return &x;
  }

  Vector3f::operator std::string() const
  {
    std::stringstream sstr;
    sstr << "{" << x << ", " << y << ", " << z << "}";
    return sstr.str();
  }

  float Vector3f::len() const
  {
    return std::sqrtf(x * x + y * y + z * z);
  }

  Vector3f Cross(const Vector3f& l, const Vector3f& r)
  {
    return {
      l.y * r.z - l.z * r.y,
      l.z * r.x - l.x * r.z,
      l.x * r.y - l.y * r.x
    };
  }

  Vector3f Normalized(const Vector3f& v)
  {
    const float len = std::sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);

    return { v.x / len, v.y / len, v.z / len };
  }

  Rotation::Rotation(const Vector3f& v3)
    : Vector3f(v3)
  {
  }

  Scale::Scale(const Vector3f& v3)
    : Vector3f(v3)
  {
  }

  Scale& Scale::operator*=(float factor)
  {
    x *= factor;
    y *= factor;
    z *= factor;

    return (*this);
  }

  Position::Position(const Vector3f& v3)
    : Vector3f(v3)
  {
  }

  Position Position::operator-() const
  {
    return { -x, -y, -z };
  }

  bool Position::operator==(const Position& r)
  {
    const float dx = std::fabs(x - r.x);
    const float dy = std::fabs(y - r.y);
    const float dz = std::fabs(z - r.z);

    return dx <= imprecision && dy <= imprecision && dz <= imprecision;
  }

  Position operator*(const float factor, const Position& p3)
  {
    return { p3.x * factor, p3.y * factor, p3.z * factor };
  }

  Position operator*(const Position& p3, float factor)
  {
    return { p3.x * factor, p3.y * factor, p3.z * factor };
  }

  Direction::Direction(const float _x, const float _y, const float _z): Vector3f(_x, _y, _z)
  {}

  Direction::Direction(const Vector3f& v3)
    : Vector3f(v3)
  {
  }

  Direction& Direction::operator=(const Vector3f& other)
  {
    x = other.x;
    y = other.y;
    z = other.z;

    return (*this);
  }

  Direction Direction::operator-() const
  {
    return { -1 * x, -1 * y, -1 * z };
  }

  Direction Direction::operator*(const float factor) const
  {
    return { factor * x, factor * y, factor * z };
  }

  bool Direction::operator==(const Direction& r) const
  {
    const float dx = std::abs(x - r.x);
    const float dy = std::abs(y - r.y);
    const float dz = std::abs(z - r.z);

    return dx <= imprecision && dy <= imprecision && dz <= imprecision;
  }

  bool Direction::operator==(const Vector3f& r) const
  {
    const float dx = std::abs(x - r.x);
    const float dy = std::abs(y - r.y);
    const float dz = std::abs(z - r.z);

    return dx <= imprecision && dy <= imprecision && dz <= imprecision;
  }

  bool operator==(const Vector3f& l, const Direction& r)
  {
    const float dx = std::abs(l.x - r.x); 
    const float dy = std::abs(l.y - r.y);
    const float dz = std::abs(l.z - r.z);

    return dx <= imprecision && dy <= imprecision && dz <= imprecision;
  }

  bool operator==(const Direction& l, const Vector3f& r)
  {
    const float dx = std::abs(l.x - r.x);
    const float dy = std::abs(l.y - r.y);
    const float dz = std::abs(l.z - r.z);

    return dx <= imprecision && dy <= imprecision && dz <= imprecision;
  }

  bool operator==(const Vector3f& l, const Scale& r)
  {
    const float dx = std::abs(l.x - r.x); 
    const float dy = std::abs(l.y - r.y);
    const float dz = std::abs(l.z - r.z);

    return dx <= imprecision && dy <= imprecision && dz <= imprecision;
  }

  bool operator==(const Scale& l, const Vector3f& r)
  {
    const float dx = std::abs(l.x - r.x);
    const float dy = std::abs(l.y - r.y);
    const float dz = std::abs(l.z - r.z);

    return dx <= imprecision && dy <= imprecision && dz <= imprecision;
  }

  bool operator==(const Vector3f& l, const Position& r)
  {
    const float dx = std::abs(l.x - r.x); 
    const float dy = std::abs(l.y - r.y);
    const float dz = std::abs(l.z - r.z);

    return dx <= imprecision && dy <= imprecision && dz <= imprecision;
  }

  bool operator==(const Position& l, const Vector3f& r)
  {
    const float dx = std::abs(l.x - r.x);
    const float dy = std::abs(l.y - r.y);
    const float dz = std::abs(l.z - r.z);

    return dx <= imprecision && dy <= imprecision && dz <= imprecision;
  }

  bool operator==(const Vector3f& l, const Vector3f& r)
  {
    const float dx = std::abs(l.x - r.x);
    const float dy = std::abs(l.y - r.y);
    const float dz = std::abs(l.z - r.z);

    return dx <= imprecision && dy <= imprecision && dz <= imprecision;
  }
}
