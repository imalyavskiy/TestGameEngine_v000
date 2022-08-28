#include "pch.hpp"
#include "Math3d.hpp"

namespace Math3D
{
  Vector4f::Vector4f(const Vector3f& v3, const float _w)
    : x(v3.x)
    , y(v3.y)
    , z(v3.z)
    , w(_w)
  {
  }

  Vector4f::Vector4f(const Position& p3)
    : x(p3.x)
    , y(p3.y)
    , z(p3.z)
    , w(1.f)
  {
  }

  Vector4f::Vector4f(const Direction& d3)
    : x(d3.x)
    , y(d3.y)
    , z(d3.z)
    , w(0.f)
  {
  }

  Vector4f::Vector4f(const float _x, const float _y, const float _z, const float _w)
    : x(_x)
    , y(_y)
    , z(_z)
    , w(_w)
  {
  }

  Vector3f Vector4f::xyz() const
  {
    return { x, y, z };
  }

  bool Vector4f::operator==(const Math3D::Vector4f& r) const
  {
    const float dx = std::abs(x - r.x);
    const float dy = std::abs(y - r.y);
    const float dz = std::abs(z - r.z);
    const float dw = std::abs(w - r.w);

    return dx <= imprecision && dy <= imprecision && dz <= imprecision && dw <= imprecision;
  }
}
