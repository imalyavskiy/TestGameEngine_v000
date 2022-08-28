#include "gtest/gtest.h"
#include <Math3D/Math3d.hpp>

using Math3D::Quaternion;
using Math3D::Vector3f;

TEST(Quaternion, Construction)
{
  Quaternion q;

  EXPECT_EQ(0.f, q.s());
  EXPECT_EQ(0.f, q.x());
  EXPECT_EQ(0.f, q.y());
  EXPECT_EQ(0.f, q.z());

  EXPECT_EQ(Vector3f(), q.xyz());
}
