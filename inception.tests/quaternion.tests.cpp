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
  {
    const Quaternion qa{ 2,4,3,5 };
    const Quaternion qb{ 3,2,4,3 };
    const Quaternion qab{-29,5,15,31};
    const Quaternion qba{-29, 27, 19, 11};

    EXPECT_EQ(qa * qb, qab); 
    EXPECT_NE(qb * qa, qab);

    EXPECT_EQ(qb * qa, qba);
    EXPECT_NE(qb * qa, qab);
  }

  {
    const Quaternion qa{ 2,4,3,5 };
    const Quaternion qb{ 3,2,4,3 };
    {
      Quaternion q = qa;
      q *= qb;
      EXPECT_EQ(q, qa * qb); 
      EXPECT_NE(q, qb * qa);
    }

    {
      Quaternion q = qb;
      q *= qa;
      EXPECT_EQ(q, qb * qa);
      EXPECT_NE(q, qa * qb);
    }
  }

  {
    Quaternion qa{5, -4, 7, 1};
    Vector3f vb{ 3, 7,-2 };
    Quaternion qab{-35, -6, 30, -59};
    Quaternion qba{-35, 36, 40, 39};

    {
      Quaternion q = qa * vb;
      EXPECT_EQ(q, qab);
      EXPECT_NE(q, qba);
    }

    {
      Quaternion q = vb * qa;
      EXPECT_EQ(q, qba);
      EXPECT_NE(q, qab);
    }

    {
      Quaternion q = qa;
      q *= vb;

      EXPECT_EQ(q, qab);
      EXPECT_NE(q, qba);
      EXPECT_EQ(q, qa * vb);
      EXPECT_NE(q, vb * qa);
    }
  }

  {
    Quaternion qa{5, -4, 7, 1};
    float fb = 7;
    Quaternion qab {35, -28, 49, 7};
    Quaternion qba {35, -28, 49, 7};

    EXPECT_EQ(qa * fb, qab);
    EXPECT_EQ(fb * qa, qba);
    EXPECT_EQ(qa * fb, fb * qa);

    {
      Quaternion q = qa;
      q *= fb;

      EXPECT_EQ(q, qa * fb);
      EXPECT_EQ(q, fb * qa);
    }
  }
}

TEST(Quaternion, Conjugation)
{
  {
    const Quaternion qa{ 2,4,3,5 };
    const Quaternion qb{ 3,2,4,3 };

    EXPECT_EQ((qa * qb).Conjugated(), qb.Conjugated() * qa.Conjugated());
  }

  {
    Quaternion q(9.f, -3.f, 4.f, 7.f);
    Quaternion qc(9.f, 3.f, -4.f, -7.f);

    EXPECT_EQ(q.Conjugated(), qc);

    EXPECT_TRUE((q * q.Conjugated()).IsReal());

    EXPECT_EQ(Quaternion(q).Conjugate(), qc);

    EXPECT_EQ(q * qc, Quaternion(q.s() * q.s() + std::powf(std::sqrtf(q.x() * q.x() + q.y() * q.y() + q.z() * q.z()),2)));
    EXPECT_EQ(qc * q, Quaternion(q.s() * q.s() + std::powf(std::sqrtf(q.x() * q.x() + q.y() * q.y() + q.z() * q.z()),2)));

    EXPECT_EQ((q * q.Conjugated()).Conjugated(), q * q.Conjugated());

    EXPECT_EQ(q * q.Conjugated(), q.Conjugated() * q);
  }
}
TEST(Quaternion, Norm)
{
  constexpr float s = 2.f;
  constexpr float x = 4.f;
  constexpr float y = 3.f;
  constexpr float z = 5.f;

  const Quaternion qa{ s, x, y, z };
  EXPECT_EQ(qa.Norm(), s * s + x * x + y * y + z * z);
}

TEST(Quaternion, Module)
{
  constexpr float s = 2.f;
  constexpr float x = 4.f;
  constexpr float y = 3.f;
  constexpr float z = 5.f;

  const Quaternion qa{ s, x, y, z };
  EXPECT_EQ(qa.Module(), std::sqrt(s * s + x * x + y * y + z * z));
}

TEST(Quaternion, Null)
{
  EXPECT_EQ(Quaternion(1.f, 6.f, 9.f, 3.f).IsNull(), false);
  EXPECT_EQ(Quaternion(Math3D::imprecision, Vector3f(Math3D::imprecision)).IsNull(), true);
  EXPECT_EQ(Quaternion(2.f * Math3D::imprecision, Vector3f(Math3D::imprecision)).IsNull(), false);
  EXPECT_EQ(Quaternion().IsNull(), true);

  EXPECT_EQ(Quaternion(0.f, 0.f, 0.f, 0.f).IsNull(), true);
  EXPECT_EQ(Quaternion(1.f, 0.f, 0.f, 0.f).IsNull(), false);
  EXPECT_EQ(Quaternion(0.f, 1.f, 0.f, 0.f).IsNull(), false);
  EXPECT_EQ(Quaternion(0.f, 0.f, 1.f, 0.f).IsNull(), false);
  EXPECT_EQ(Quaternion(0.f, 0.f, 0.f, 1.f).IsNull(), false);
}

TEST(Quaternion, Normalization)
{
  const Quaternion q{ 5.f, 8.f, 3.f, 1.f };
  const float norm = q.Norm();
  const Quaternion qn{ q.s() / norm, q.x() / norm, q.y() / norm, q.z() / norm };

  EXPECT_EQ(q.Normalized(), qn);
  EXPECT_EQ(Quaternion(q).Normalize(), qn);
}

TEST(Quaternion, Inversion)
{
  constexpr float s = 5.f;
  constexpr float x = 8.f;
  constexpr float y = 3.f;
  constexpr float z = 1.f;

  const Quaternion q{ s, x, y, z};
  const float q0norm = s * s + x * x + y * y + z * z;
  const Quaternion qInversed{ s / q0norm, -x / q0norm, -y / q0norm , -z / q0norm };

  EXPECT_EQ(q.Inversed(), qInversed);
  EXPECT_EQ(Quaternion(q).Inverse(), qInversed);
  EXPECT_EQ(q * q.Inversed(), 1.f);
  EXPECT_EQ(q.Inversed() * q, 1.f);

  const Quaternion q1{ 5.f, 1.f, -6.f, 0.5f };
  EXPECT_NE(q.Inversed() * q1, q1 * q.Inversed());

  EXPECT_EQ((q * q1).Inversed(), q1.Inversed() * q.Inversed());
}

// Because multiplication of quaternions is not commutative, division of a quaternion is also
// not commutative (division is multiplication by a number to the power of -1). Writing a/b
// means a divided by b, but in our case there is also another notation b\a - left
// division - it is impossible to code such operation, so the operation of division by vector
// (pure imaginary quaternion) and simply by quaternion we will not be implemented at all.
TEST(Quaternion, Division)
{
  constexpr float s = 9.f;
  constexpr float x =-3.f;
  constexpr float y = 4.f;
  constexpr float z = 7.f;

  constexpr float f = 2.f;

  const Quaternion q(s, x, y, z);
  EXPECT_EQ(q / f, Quaternion(s / f, x / f, y / f, z / f));

  Quaternion q1(q);
  q1 /= f;
  EXPECT_EQ(q1, Quaternion(s / f, x / f, y / f, z / f));
}

TEST(Quaternion, DotProduct)
{
  const Quaternion q0{ 4.f, 6.f, 1.f, 8.f };
  const Quaternion q1{ 8.f, 3.f, 8.f, 5.f };

  const float q0Module =
    std::sqrt(q0.s() * q0.s() + q0.x() * q0.x() + q0.y() * q0.y() + q0.z() * q0.z());

  const float q1Module =
    std::sqrt(q1.s() * q1.s() + q1.x() * q1.x() + q1.y() * q1.y() + q1.z() * q1.z());

  const float q1q2DotProduct =
    (q0.s() * q1.s() + q0.x() * q1.x() + q0.y() * q1.y() + q0.z() * q1.z()) / (q0Module * q1Module);

  EXPECT_EQ(q0.dot(q1), q1q2DotProduct);

  EXPECT_EQ(q1.dot(q0), q1q2DotProduct);

  EXPECT_LE(q0.dot(q1) - Math3D::dot(q0, q1), Math3D::imprecision);

  EXPECT_EQ(q0.dot(q1), q1.dot(q0));

  EXPECT_EQ(Math3D::dot(q0, q1), Math3D::dot(q1, q0));
}

TEST(Quaternion, Misc)
{
  Quaternion q0{ 4.f, 6.f, 1.f, 8.f };
  Quaternion q1{ 8.f, 3.f, 8.f, 5.f };

  EXPECT_EQ((q0 * q1).Norm(),(q0 * q1)* (q0 * q1).Conjugated());

  EXPECT_EQ((q0 * q1).Norm(),q0.Norm() * q1.Norm());
}