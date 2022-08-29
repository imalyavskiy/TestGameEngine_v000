#include "gtest/gtest.h"
#include <Math3D/Math3d.hpp>

using Math3D::Quaternion;
using Math3D::Vector3f;

TEST(Quaternion, Construction)
{
  {
    Quaternion q;

    EXPECT_EQ(0.f, q.s());
    EXPECT_EQ(0.f, q.x());
    EXPECT_EQ(0.f, q.y());
    EXPECT_EQ(0.f, q.z());

    EXPECT_EQ(Vector3f(), q.xyz());
  }

  {
    Quaternion q{ 1.f, 2.f, 3.f, 4.f };

    EXPECT_EQ(1.f, q.s());
    EXPECT_EQ(2.f, q.x());
    EXPECT_EQ(3.f, q.y());
    EXPECT_EQ(4.f, q.z());

    EXPECT_EQ(Vector3f(2.f, 3.f, 4.f), q.xyz());
  }

  {
    Vector3f v{ 2.f, 3.f, 4.f };
    Quaternion q{ 1.f, v };

    EXPECT_EQ(1.f, q.s());
    EXPECT_EQ(2.f, q.x());
    EXPECT_EQ(3.f, q.y());
    EXPECT_EQ(4.f, q.z());

    EXPECT_EQ(v, q.xyz());
  }

  {
    Quaternion q{ 1.f };

    EXPECT_EQ(1.f, q.s());
    EXPECT_EQ(0.f, q.x());
    EXPECT_EQ(0.f, q.y());
    EXPECT_EQ(0.f, q.z());

    EXPECT_EQ(Vector3f(), q.xyz());
    EXPECT_TRUE(q.IsReal());
  }

  {
    Vector3f v{ 2.f, 3.f, 4.f };
    Quaternion q{ v };

    EXPECT_EQ(0.f, q.s());
    EXPECT_EQ(2.f, q.x());
    EXPECT_EQ(3.f, q.y());
    EXPECT_EQ(4.f, q.z());

    EXPECT_EQ(v, q.xyz());
    EXPECT_TRUE(q.IsPure());
  }
}

TEST(Quaternion, Assignment)
{
  const float  s = 0.5f;
  const float ix = 0.6f;
  const float jy = 0.7f;
  const float kz = 0.8f;

  {
    Quaternion q;

    q = s;

    EXPECT_EQ(s, q.s());
    EXPECT_EQ(0.f, q.x());
    EXPECT_EQ(0.f, q.y());
    EXPECT_EQ(0.f, q.z());
  }
  {
    Quaternion q;

    q = Vector3f{ ix, jy, kz };

    EXPECT_EQ(0.f, q.s());
    EXPECT_EQ(ix, q.x());
    EXPECT_EQ(jy, q.y());
    EXPECT_EQ(kz, q.z());
  }
  {
    Quaternion q;

    q = Quaternion{ s, ix, jy, kz };

    EXPECT_EQ(s, q.s());
    EXPECT_EQ(ix, q.x());
    EXPECT_EQ(jy, q.y());
    EXPECT_EQ(kz, q.z());
  }
}

TEST(Quaternion, Equality)
{
  const float  s = 0.5f;
  const float ix = 0.6f;
  const float jy = 0.7f;
  const float kz = 0.8f;

  EXPECT_NE( s, 0.f);
  EXPECT_NE(ix, 0.f);
  EXPECT_NE(jy, 0.f);
  EXPECT_NE(kz, 0.f);

  EXPECT_NE(s, 0.f);
  EXPECT_EQ(Quaternion(s), s);
  EXPECT_EQ(s, Quaternion(s));
  EXPECT_NE(Quaternion(s), 0.f);
  EXPECT_NE(0.f, Quaternion(s));

  EXPECT_NE(Vector3f(ix, jy, kz), Vector3f::zero);
  EXPECT_EQ(Quaternion(Vector3f(ix, jy, kz)), Vector3f(ix, jy, kz));
  EXPECT_EQ(Vector3f(ix, jy, kz), Quaternion(Vector3f(ix, jy, kz)));
  EXPECT_NE(Quaternion(Vector3f(ix, jy, kz)), Vector3f::zero);
  EXPECT_NE(Vector3f::zero, Quaternion(Vector3f(ix, jy, kz)));

  EXPECT_NE(Quaternion(s, ix, jy, kz), Quaternion::zero);
  EXPECT_EQ(Quaternion(s, ix, jy, kz), Quaternion(s, ix, jy, kz));
  EXPECT_EQ(Quaternion(s, Vector3f(ix, jy, kz)), Quaternion(s, ix, jy, kz));
  EXPECT_EQ(Quaternion(s, ix, jy, kz), Quaternion(s, Vector3f(ix, jy, kz)));
  EXPECT_EQ(Quaternion(s), Quaternion(s, Vector3f::zero));
  EXPECT_EQ(Quaternion(s, Vector3f::zero), Quaternion(s));
}

TEST(Quaternion, Addition)
{
  const float  s = 3.5f;
  const float ix = 7.6f;
  const float jy = 2.7f;
  const float kz = 5.8f;

  const Quaternion q1{ s, ix, jy, kz };
  const Quaternion q2{ 2.f * s, 2.f * ix, 2.f * jy, 2.f * kz };
  const Vector3f v{ 1.1f * ix, 0.75f * jy, 3.3f * kz };
  const float fs = 2.21f * s;

  EXPECT_EQ(q1 + q2, Quaternion(q1.s() + q2.s(), q1.x() + q2.x(), q1.y() + q2.y(), q1.z() + q2.z()));
  EXPECT_EQ(q1 + v, Quaternion(q1.s(), q1.x() + v.x, q1.y() + v.y, q1.z() + v.z));
  EXPECT_EQ(v + q1, Quaternion(q1.s(), v.x + q1.x(), v.y + q1.y(), v.z + q1.z()));
  EXPECT_EQ(fs + q1, Quaternion(q1.s() + fs, q1.x(), q1.y(), q1.z()));

  auto q = q2;

  q += q1;
  EXPECT_EQ(q, q1 + q2);
  EXPECT_EQ(q, q2 + q1);

  q += v;
  EXPECT_EQ(q, q2 + q1 + v);
  EXPECT_EQ(q, q1 + q2 + v);
  EXPECT_EQ(q, q2 + v + q1);
  EXPECT_EQ(q, q1 + v + q2);
  EXPECT_EQ(q, v + q2 + q1);
  EXPECT_EQ(q, v + q1 + q2);

  q += fs;
  EXPECT_EQ(q, q2 + q1 + v + fs);
  EXPECT_EQ(q, q2 + q1 + fs + v);
  EXPECT_EQ(q, q2 + fs + q1 + v);
  EXPECT_EQ(q, fs + q2 + q1 + v);
}

TEST(Quaternion, Subtraction)
{
  const float  s = 3.5f;
  const float ix = 7.6f;
  const float jy = 2.7f;
  const float kz = 5.8f;

  const Quaternion q1{ s, ix, jy, kz };
  const Quaternion q2{ 2.f * s, 2.f * ix, 2.f * jy, 2.f * kz };
  const Vector3f v{ 1.1f * ix, 0.75f * jy, 3.3f * kz };
  const float fs = 2.21f * s;

  EXPECT_EQ(q1 - q2, Quaternion(q1.s() - q2.s(), q1.x() - q2.x(), q1.y() - q2.y(), q1.z() - q2.z()));
  EXPECT_EQ(q1 -  v, Quaternion(q1.s(), q1.x() - v.x, q1.y() - v.y, q1.z() - v.z));
  EXPECT_EQ( v - q1, Quaternion(-q1.s(), v.x - q1.x(), v.y - q1.y(), v.z - q1.z()));
  EXPECT_EQ(fs - q1, Quaternion(fs - q1.s(), -q1.x(), -q1.y(), -q1.z()));

  auto q = q2;

  q -= q1;
  EXPECT_EQ(q, q2 - q1);
  EXPECT_NE(q, q1 - q2);

  q -= v;
  EXPECT_EQ(q, q2 - q1 - v);
  EXPECT_NE(q, q1 - q2 - v);
  EXPECT_EQ(q, q2 - v - q1);
  EXPECT_NE(q, q1 - v - q2);
  EXPECT_NE(q, v - q2 - q1);
  EXPECT_NE(q, v - q1 - q2);

  q -= fs;
  EXPECT_EQ(q, q2 - q1 -  v - fs);
  EXPECT_EQ(q, q2 - q1 - fs -  v);
  EXPECT_EQ(q, q2 - fs - q1 -  v);
  EXPECT_NE(q, fs - q2 - q1 -  v);
}

TEST(Quaternion, Multiplication)
{
  
}

TEST(Quaternion, Division)
{

}