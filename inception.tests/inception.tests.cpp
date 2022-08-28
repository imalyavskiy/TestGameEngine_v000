#include "gtest/gtest.h"
#include <Math3D/Math3d.hpp>
bool operator==(const Math3D::Direction& l, const Math3D::Direction& r)
{
  constexpr float imprecision = 0.000001f;

  const float dx = std::abs(l.x - r.x);
  const float dy = std::abs(l.y - r.y);
  const float dz = std::abs(l.z - r.z);

  return dx < imprecision&& dy < imprecision&& dz < imprecision;
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

  {
    const Math3D::Vector4f direction{ 1.f, 1.f, 1.f, 0.f };
    const Math3D::Vector4f resultDirection = rotateZ * direction;
    EXPECT_TRUE(resultDirection == Math3D::Vector4f(-1.f, -1.f, 1.f, 0.f));
  }
  {
    const Math3D::Vector4f direction{ 0.f, 0.f, 1.f, 0.f };
    const Math3D::Vector4f v4 = rotateZ * direction;
    EXPECT_TRUE(v4 == direction);
  }

  {
    const Math3D::Vector4f position{ 1.f, 1.f, 1.f, 1.f };
    const Math3D::Vector4f resultPosition = rotateZ * position;
    EXPECT_TRUE(resultPosition == Math3D::Vector4f(-1.f, -1.f, 1.f, 1.f));
  }
  {
    const Math3D::Vector4f position{ 0.f, 0.f, 1.f, 0.f };
    const Math3D::Vector4f v4 = rotateZ * position;
    EXPECT_TRUE(v4 == position);
  }

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

  {
    const Math3D::Vector4f direction{ 1.f, 1.f, 1.f, 0.f };
    const Math3D::Vector4f resultDirection = rotateX * direction;
    EXPECT_TRUE(resultDirection == Math3D::Vector4f(1.f, -1.f, -1.f, 0.f));
  }
  {
    const Math3D::Vector4f direction{ 1.f, 0.f, 0.f, 0.f };
    const Math3D::Vector4f v4 = rotateX * direction;
    EXPECT_TRUE(v4 == direction);
  }

  {
    const Math3D::Vector4f position{ 1.f, 1.f, 1.f, 1.f };
    const Math3D::Vector4f resultPosition = rotateX * position;
    EXPECT_TRUE(resultPosition == Math3D::Vector4f(1.f, -1.f, -1.f, 1.f));
  }
  {
    const Math3D::Vector4f position{ 1.f, 0.f, 0.f, 1.f };
    const Math3D::Vector4f v4 = rotateX * position;
    EXPECT_TRUE(v4 == position);
  }

}

TEST(Math3DTests, RotateYTransform)
{
  const float angle = Math3D::DegToRad(90);
  const float cos = std::cosf(angle);
  const float sin = std::sinf(angle);
  const Math3D::Matrix4f rotateY
  {
    { cos, 0.f, sin, 0.f },
    { 0.f, 1.f, 0.f, 0.f },
    {-sin, 0.f, cos, 0.f },
    { 0.f, 0.f, 0.f, 1.f },
  };

  {
    Math3D::Vector4f direction{ 1.f, 1.f, 1.f, 0.f };

    direction = rotateY * direction;
    EXPECT_EQ(direction, Math3D::Vector4f( 1.f, 1.f, -1.f, 0.f ));

    direction = rotateY * direction;
    EXPECT_EQ(direction, Math3D::Vector4f( -1.f, 1.f, -1.f, 0.f));
  }
  {
    Math3D::Vector4f direction{ 0.f, 1.f, 0.f, 0.f };
    direction = rotateY * direction;
    EXPECT_EQ(direction, Math3D::Vector4f( 0.f, 1.f, 0.f, 0.f ));
  }

  {
    Math3D::Vector4f position{ 1.f, 1.f, 1.f, 1.f };

    position = rotateY * position;
    EXPECT_EQ(position, Math3D::Vector4f(1.f, 1.f, -1.f, 1.f));

    position = rotateY * position;
    EXPECT_EQ(position, Math3D::Vector4f(-1.f, 1.f, -1.f, 1.f));
  }
  {
    Math3D::Vector4f position{ 0.f, 1.f, 0.f, 1.f };
    position = rotateY * position;
    EXPECT_EQ(position, Math3D::Vector4f(0.f, 1.f, 0.f, 1.f));
  }
}

TEST(Math3DTests, ComplexTransform30deg)
{
  const Math3D::Direction fwd{ 1.0f, 0.f, 0.f};

  const float angle = Math3D::DegToRad(30.f);
  const float cos = std::cosf(angle);
  const float sin = std::sinf(angle);

  const Math3D::Matrix4f rotateZ
  {
    { cos,-sin, 0.f, 0.f },
    { sin, cos, 0.f, 0.f },
    { 0.f, 0.f, 1.f, 0.f },
    { 0.f, 0.f, 0.f, 1.f },
  };
  const Math3D::Matrix4f rotateX
  {
    { 1.f, 0.f, 0.f, 0.f },
    { 0.f, cos,-sin, 0.f },
    { 0.f, sin, cos, 0.f },
    { 0.f, 0.f, 0.f, 1.f },
  };
  const Math3D::Matrix4f rotateY
  {
    { cos, 0.f, sin, 0.f },
    { 0.f, 1.f, 0.f, 0.f },
    {-sin, 0.f, cos, 0.f },
    { 0.f, 0.f, 0.f, 1.f },
  };

  Math3D::Vector4f v4 = 
    Math3D::Vector4f(fwd);

  v4 = rotateZ * v4; //  30
  v4 = rotateZ * v4; //  60
  v4 = rotateZ * v4; //  90
  v4 = rotateZ * v4; // 120
  v4 = rotateZ * v4; // 150
  v4 = rotateZ * v4; // 180
  v4 = rotateZ * v4; // 210
  v4 = rotateZ * v4; // 240
  v4 = rotateZ * v4; // 270
  v4 = rotateZ * v4; // 300
  v4 = rotateZ * v4; // 330
  v4 = rotateZ * v4; // 360

  EXPECT_TRUE(v4 == fwd);

  v4 = fwd;

  v4 = rotateZ * v4; //  30
  v4 = rotateZ * v4; //  60
  v4 = rotateZ * v4; //  90
  EXPECT_TRUE(v4 == Math3D::Vector4f(0.f, 1.f, 0.f, 0.f));

  v4 = rotateX * v4; //  30
  v4 = rotateX * v4; //  60
  v4 = rotateX * v4; //  90
  EXPECT_TRUE(v4 == Math3D::Vector4f(0.f, 0.f, 1.f, 0.f));

  v4 = rotateY * v4; //  30
  v4 = rotateY * v4; //  60
  v4 = rotateY * v4; //  90
  EXPECT_TRUE(v4 == Math3D::Vector4f(1.f, 0.f, 0.f, 0.f));
}

TEST(Math3DTests, ComplexTransform90deg)
{
  const Math3D::Direction f{ 1.0f, 0.f, 0.f };
  const Math3D::Direction r{ 0.0f, 1.f, 0.f };
  const Math3D::Direction u{ 0.0f, 0.f, 1.f };

  const float angle = Math3D::DegToRad(90.f);
  const float cos = std::cosf(angle);
  const float sin = std::sinf(angle);

  const Math3D::Matrix4f yaw
  {
    { cos,-sin, 0.f, 0.f },
    { sin, cos, 0.f, 0.f },
    { 0.f, 0.f, 1.f, 0.f },
    { 0.f, 0.f, 0.f, 1.f },
  };
  const Math3D::Matrix4f roll
  {
    { 1.f, 0.f, 0.f, 0.f },
    { 0.f, cos,-sin, 0.f },
    { 0.f, sin, cos, 0.f },
    { 0.f, 0.f, 0.f, 1.f },
  };
  const Math3D::Matrix4f pitch
  {
    { cos, 0.f, sin, 0.f },
    { 0.f, 1.f, 0.f, 0.f },
    {-sin, 0.f, cos, 0.f },
    { 0.f, 0.f, 0.f, 1.f },
  };

  {
    const Math3D::Matrix4f rotate = 
      pitch * roll * yaw;
    Math3D::Vector4f f1 = 
      rotate * Math3D::Vector4f(f);
    Math3D::Vector4f r1 = 
      rotate * Math3D::Vector4f(r);
    Math3D::Vector4f u1 = 
      rotate * Math3D::Vector4f(u);

    Math3D::Vector4f f2 = 
      pitch * roll * yaw * Math3D::Vector4f(f);
    Math3D::Vector4f r2 = 
      pitch * roll * yaw * Math3D::Vector4f(r);
    Math3D::Vector4f u2 = 
      pitch * roll * yaw * Math3D::Vector4f(u);

    EXPECT_EQ(f1, f2);
    EXPECT_EQ(r1, r2);
    EXPECT_EQ(u1, u2);
  }
}

TEST(Math3DTests, PipelineTraslate)
{
  Math3D::Position position{ 0.f, 0.f, 5.f };
  Math3D::Matrix4f translate = Math3D::Pipeline::Create(position);
  Math3D::Vector4f result = translate * Math3D::Vector4f(Math3D::Position());
  EXPECT_TRUE(position == Math3D::Position(result.xyz()));
}

TEST(Math3DTests, HardcodedDirections)
{
  EXPECT_EQ(Math3D::Direction::Forward, Math3D::Vector3f( 1.f, 0.f, 0.f));
  EXPECT_EQ(Math3D::Direction::Backward,Math3D::Vector3f(-1.f, 0.f, 0.f));
  EXPECT_EQ(Math3D::Direction::Right,   Math3D::Vector3f( 0.f, 1.f, 0.f));
  EXPECT_EQ(Math3D::Direction::Left,    Math3D::Vector3f( 0.f,-1.f, 0.f));
  EXPECT_EQ(Math3D::Direction::Up,      Math3D::Vector3f( 0.f, 0.f, 1.f));
  EXPECT_EQ(Math3D::Direction::Down,    Math3D::Vector3f( 0.f, 0.f,-1.f));
}

TEST(Math3DTests, PipelineTransform)
{

  // YAW
  {
    // Rotating in XOY, rotation must be CW if look in direction opposite to Z axis,
    // or CCW if to look in the same direction, e.g left coordinate system.
    Math3D::Transform transform;
    transform.rotation.z = Math3D::DegToRad(90.f);
    const Math3D::Matrix4f model = Math3D::Pipeline::Create(transform);
    const Math3D::Vector4f result = model * Math3D::Vector4f(Math3D::Direction::Forward);
    EXPECT_EQ(result.xyz(), Math3D::Direction::Right);
  }
  {
    Math3D::Transform transform;
    transform.rotation.z = Math3D::DegToRad(-90.f);
    const Math3D::Matrix4f model = Math3D::Pipeline::Create(transform);
    const Math3D::Vector4f result = model * Math3D::Vector4f(Math3D::Direction::Forward);
    EXPECT_EQ(result.xyz(), Math3D::Direction::Left);
  }

  // PITCH
  {
    Math3D::Transform transform;
    transform.rotation.y = Math3D::DegToRad(90.f);
    const Math3D::Matrix4f model = Math3D::Pipeline::Create(transform);
    const Math3D::Vector4f result = model * Math3D::Vector4f(Math3D::Direction::Forward);
    EXPECT_EQ(result.xyz(), Math3D::Direction::Down);
  }
  {
    Math3D::Transform transform;
    transform.rotation.y = Math3D::DegToRad(-90.f);
    const Math3D::Matrix4f model = Math3D::Pipeline::Create(transform);
    const Math3D::Vector4f result = model * Math3D::Vector4f(Math3D::Direction::Forward);
    EXPECT_EQ(result.xyz(), Math3D::Direction::Up);
  }

  // ROLL
  {
    Math3D::Transform transform;
    transform.rotation.x = Math3D::DegToRad(90.f);
    const Math3D::Matrix4f model = Math3D::Pipeline::Create(transform);
    const Math3D::Vector4f result = model * Math3D::Vector4f(Math3D::Direction::Up);
    EXPECT_EQ(result.xyz(), Math3D::Direction::Left);
  }
  {
    Math3D::Transform transform;
    transform.rotation.x = Math3D::DegToRad(-90.f);
    const Math3D::Matrix4f model = Math3D::Pipeline::Create(transform);
    const Math3D::Vector4f result = model * Math3D::Vector4f(Math3D::Direction::Up);
    EXPECT_EQ(result.xyz(), Math3D::Direction::Right);
  }
}
