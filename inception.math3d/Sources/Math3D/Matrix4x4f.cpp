#include "pch.hpp"
#include "Math3d.hpp"

namespace Math3D
{
  Matrix4f::Matrix4f(float _00, float _01, float _02, float _03,
    float _10, float _11, float _12, float _13,
    float _20, float _21, float _22, float _23,
    float _30, float _31, float _32, float _33)
    : m{ {_00, _01, _02, _03},
         {_10, _11, _12, _13},
         {_20, _21, _22, _23},
         {_30, _31, _32, _33} }
  {
  }

  Matrix4f::Matrix4f(Vector4f r0, Vector4f r1, Vector4f r2, Vector4f r3)
    : m{ {r0.x, r0.y, r0.z, r0.w},
         {r1.x, r1.y, r1.z, r1.w},
         {r2.x, r2.y, r2.z, r2.w},
         {r3.x, r3.y, r3.z, r3.w} }
  {
  }

  const float* Matrix4f::data() const
  {
    return &m[0][0];
  }

  Matrix4f Matrix4f::operator*(const Matrix4f& right) const
  {
    Matrix4f Ret;

    for (size_t i = 0; i < 4; i++) {
      for (size_t j = 0; j < 4; j++) {
        Ret.m[i][j] =
          m[i][0] * right.m[0][j] +
          m[i][1] * right.m[1][j] +
          m[i][2] * right.m[2][j] +
          m[i][3] * right.m[3][j];
      }
    }

    return Ret;
  }

  Vector4f Matrix4f::operator*(const Vector4f& right) const
  {
    return {
      m[0][0] * right.x + m[0][1] * right.y + m[0][2] * right.z + m[0][3] * right.w,
      m[1][0] * right.x + m[1][1] * right.y + m[1][2] * right.z + m[1][3] * right.w,
      m[2][0] * right.x + m[2][1] * right.y + m[2][2] * right.z + m[2][3] * right.w,
      m[3][0] * right.x + m[3][1] * right.y + m[3][2] * right.z + m[3][3] * right.w
    };
  }

  Transform::Transform()
    : scale(1.f, 1.f, 1.f)
  {
  }

  Transform::Transform(const Position _position, const Rotation _rotation, const Scale _scale)
    : position(_position)
    , rotation(_rotation)
    , scale(_scale)
  {
  }
}