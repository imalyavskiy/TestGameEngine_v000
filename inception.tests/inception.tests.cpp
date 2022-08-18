#include "gtest/gtest.h"
#include <inception.math3d/Math3d.hpp>
bool operator==(const Math3D::Vector4f& l, const Math3D::Vector4f& r)
{
  constexpr float imprecision = 0.000001f;

  const float dx = std::abs(l.x - r.x);
  const float dy = std::abs(l.y - r.y);
  const float dz = std::abs(l.z - r.z);
  const float dw = std::abs(l.w - r.w);

  return dx < imprecision && dy < imprecision && dz < imprecision && dw < imprecision;
}

bool operator!=(const Math3D::Vector4f& l, const Math3D::Vector4f& r)
{
  return !::operator==(l, r);
}

TEST(Math3DTests, TranslateTransform)
{
  constexpr float dx = 5.f;
  constexpr float dy = 5.f;
  constexpr float dz = 5.f;
  const Math3D::Matrix4f translate
  {
    { 1.f, 0.f, 0.f,  dx },
    { 0.f, 1.f, 0.f,  dy },
    { 0.f, 0.f, 1.f,  dz },
    { 0.f, 0.f, 0.f, 1.f },
  };

  const Math3D::Vector4f direction{ 1.f, 0.f, 0.f, 0.f };
  const auto resultDirection = translate * direction;
  EXPECT_TRUE(direction == resultDirection);

  const Math3D::Vector4f position{ 1.f, 0.f, 0.f, 1.f };
  const auto resultPosition = translate * position;
  EXPECT_TRUE(resultPosition == Math3D::Vector4f(6.f, 5.f, 5.f, 1.f));
}

TEST(Math3DTests, ScaleTransform)
{
  constexpr float sx = 2.f;
  constexpr float sy = 2.f;
  constexpr float sz = 2.f;
  const Math3D::Matrix4f scale
  {
    {  sx, 0.f, 0.f, 0.f },
    { 0.f,  sy, 0.f, 0.f },
    { 0.f, 0.f,  sz, 0.f },
    { 0.f, 0.f, 0.f, 1.f },
  };

  const Math3D::Vector4f direction{ 1.f, 0.f, 0.f, 0.f };
  const Math3D::Vector4f resultDirection = scale * direction;
  EXPECT_TRUE(resultDirection == Math3D::Vector4f(2.f, 0.f, 0.f, 0.f));

  const Math3D::Vector4f position{ 1.f, 0.f, 0.f, 1.f };
  const Math3D::Vector4f resultPosition = scale * position;
  EXPECT_TRUE(resultPosition == Math3D::Vector4f(2.f, 0.f, 0.f, 1.f));
}

TEST(Math3DTests, RotateZTransform)
{
  const float angle = Math3D::DegToRad(180.f);
  const float cos = std::cosf(angle);
  const float sin = std::sinf(angle);
  const Math3D::Matrix4f rotateZ
  {
    { cos,-sin, 0.f, 0.f },
    { sin, cos, 0.f, 0.f },
    { 0.f, 0.f, 1.f, 0.f },
    { 0.f, 0.f, 0.f, 1.f },
  };

  const Math3D::Vector4f direction{ 1.f, 1.f, 1.f, 0.f };
  const Math3D::Vector4f resultDirection = rotateZ * direction;
  EXPECT_TRUE(resultDirection == Math3D::Vector4f(-1.f, -1.f, 1.f, 0.f));

  const Math3D::Vector4f position{ 1.f, 1.f, 1.f, 1.f };
  const Math3D::Vector4f resultPosition = rotateZ * position;
  EXPECT_TRUE(resultPosition == Math3D::Vector4f(-1.f, -1.f, 1.f, 1.f));
}

TEST(Math3DTests, RotateXTransform)
{
  const float angle = Math3D::DegToRad(180.f);
  const float cos = std::cosf(angle);
  const float sin = std::sinf(angle);
  const Math3D::Matrix4f rotateX
  {
    { 1.f, 0.f, 0.f, 0.f },
    { 0.f, cos,-sin, 0.f },
    { 0.f, sin, cos, 0.f },
    { 0.f, 0.f, 0.f, 1.f },
  };

  const Math3D::Vector4f direction{ 1.f, 1.f, 1.f, 0.f };
  const Math3D::Vector4f resultDirection = rotateX * direction;
  EXPECT_TRUE(resultDirection == Math3D::Vector4f(1.f, -1.f, -1.f, 0.f));

  const Math3D::Vector4f position{ 1.f, 1.f, 1.f, 1.f };
  const Math3D::Vector4f resultPosition = rotateX * position;
  EXPECT_TRUE(resultPosition == Math3D::Vector4f(1.f, -1.f, -1.f, 1.f));
}

TEST(Math3DTests, RotateYTransform)
{
  const float angle = Math3D::DegToRad(180.f);
  const float cos = std::cosf(angle);
  const float sin = std::sinf(angle);
  const Math3D::Matrix4f rotateY
  {
    { cos, 0.f,-sin, 0.f },
    { 0.f, 1.f, 0.f, 0.f },
    { sin, 0.f, cos, 0.f },
    { 0.f, 0.f, 0.f, 1.f },
  };

  const Math3D::Vector4f direction{ 1.f, 1.f, 1.f, 0.f };
  const Math3D::Vector4f resultDirection = rotateY * direction;
  EXPECT_TRUE(resultDirection == Math3D::Vector4f(-1.f, 1.f, -1.f, 0.f));

  const Math3D::Vector4f position{ 1.f, 1.f, 1.f, 1.f };
  const Math3D::Vector4f resultPosition = rotateY * position;
  EXPECT_TRUE(resultPosition == Math3D::Vector4f(-1.f, 1.f, -1.f, 1.f));
}