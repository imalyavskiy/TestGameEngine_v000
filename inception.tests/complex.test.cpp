#include <vector>
#include "gtest/gtest.h"
#include <Math3D/Math3d.hpp>
using Math3D::Complexf;
TEST(Complex, Construction)
{
  const Complexf c0;
  EXPECT_EQ(c0.re(), 0.f);
  EXPECT_EQ(c0.im(), 0.f);

  constexpr float re = 0.f;
  constexpr float im = 2.f;
  const Complexf c1{ re, im };
  EXPECT_EQ(c1.re(), re);
  EXPECT_EQ(c1.im(), im);

  const Complexf c2(c1);
  EXPECT_EQ(c2.re(), re);
  EXPECT_EQ(c2.im(), im);
}

TEST(Complex, Negate)
{
  constexpr float re = 3.f;
  constexpr float im = 2.f;
  const Complexf c1{ re, im };

  EXPECT_EQ(-c1, Complexf(-re, -im));
}

TEST(Complex, Equality)
{
  const Complexf c1{ 0.f, 0.f };
  const Complexf c2{ 0.f, 0.f };
  const Complexf c3{ 1.f, 0.f };
  const Complexf c4{ 0.f, 1.f };

  EXPECT_EQ(c1, c2);
  EXPECT_NE(c1, c3);
  EXPECT_NE(c1, c4);
  EXPECT_NE(c2, c3);
  EXPECT_NE(c2, c4);
  EXPECT_NE(c3, c4);
}

TEST(Complex, PlusMinusScalar)
{
  {
    const Complexf c1{ 1.f, 5.f };
    const Complexf c2 = c1 + 3.f;
    EXPECT_EQ(c2, Complexf(4.f, 5.f));

    const Complexf c3 = c2 - 4.f;
    EXPECT_EQ(c3, Complexf(0.f, 5.f));
  }

  {
    Complexf c{ 1.f, 5.f };
    c += 3.f;
    EXPECT_EQ(c, Complexf(4.f, 5.f));

    c -= 4.f;
    EXPECT_EQ(c, Complexf(0.f, 5.f));
  }
}

TEST(Complex, PlusMinusComplex)
{
  {
    const Complexf c1{ 1.f, 5.f };
    const Complexf c2{5.f, 1.f};
    EXPECT_EQ(c1 + c2, Complexf(6.f, 6.f));
    EXPECT_EQ(c1 - c2, Complexf(-4.f, 4.f));
  }

  {
    Complexf c1{ 1.f, 5.f };
    Complexf c2{ 5.f, 1.f };
    c1 += c2;
    EXPECT_EQ(c1, Complexf(6.f, 6.f));

    c2 -= c1;
    EXPECT_EQ(c2, Complexf(-1.f, -5.f));
  }
}

TEST(Complex, MultiplyDivideByScalar)
{
  constexpr float re = 2.f;
  constexpr float im = 3.f;
  constexpr float fact = 2.f;

  const Complexf c0(re, im);
  EXPECT_EQ(c0 * 2, Complexf(re * fact, im * fact));
  EXPECT_EQ(c0 / 2, Complexf(re / fact, im / fact));

  Complexf c(c0);
  c *= fact;
  EXPECT_EQ(c, Complexf(re * fact, im * fact));

  c = c0;
  c /= fact;
  EXPECT_EQ(c, Complexf(re / fact, im / fact));
}

TEST(Complex, MultiplyByComplex)
{
  const Complexf c0(5.f, 2.f);
  const Complexf c1(4.f, 7.f);

  const Complexf prod = c0 * c1;
  EXPECT_EQ(prod, Complexf(c0.re() * c1.re() - c0.im() * c1.im(), c0.re() * c1.im() + c0.im() * c1.re()));
}

TEST(Complex, DivideByComplex)
{
  const Complexf c0(5.f, 2.f);
  const Complexf c1(4.f, 7.f);

  const Complexf prod = c0 / c1;

  const float divisor = c1.re() * c1.re() + c1.im() * c1.im();
  const Complexf res{(c0.re() * c1.re() + c0.im() * c1.im())/divisor, (c0.im() * c1.re() - c0.re() * c1.im())/divisor};

  EXPECT_EQ(prod, res);
}

TEST(Complex, Length)
{
  const float re = 6.f;
  const float im = 2.f;

  const Complexf c0(re, im);
  const Complexf c1 = c0 * Complexf::imunit;
  const Complexf c2 = c1 * Complexf::imunit;
  const Complexf c3 = c2 * Complexf::imunit;

  EXPECT_EQ(c1, Complexf(-im, re));
  EXPECT_EQ(c2, Complexf(-re, -im));
  EXPECT_EQ(c3, Complexf(im, -re));

  const float len0 = Complexf::length(c0);
  const float len1 = Complexf::length(c1);
  const float len2 = Complexf::length(c2);
  const float len3 = Complexf::length(c3);

  EXPECT_LE(std::abs(len0 - len1), Math3D::imprecision);
  EXPECT_LE(std::abs(len0 - len2), Math3D::imprecision);
  EXPECT_LE(std::abs(len0 - len3), Math3D::imprecision);
}

TEST(Complex, Power)
{
  const Complexf c0(0.f, 1.f);
  EXPECT_EQ(c0 * c0, -1.f);
  EXPECT_NE(c0 * c0 * c0, -1.f);
  EXPECT_NE(c0 * c0 * c0, Complexf(-1.f, 1.f));
}

TEST(Complex, Abs)
{
  constexpr float re = 2.f;
  constexpr float im = 5.f;
  const Complexf c0{ re, im };
  EXPECT_EQ(Complexf::length(c0), std::sqrt(re * re + im * im));
}

TEST(Complex, Conjugate)
{
  constexpr float re = 6.f;
  constexpr float im = 2.1f;

  const Complexf c0(re, im);
  const Complexf c0c(Complexf::conjugate(c0));
  EXPECT_EQ(c0c, Complexf(re, -im));

  const Complexf c = c0 * c0c;
  EXPECT_EQ(c.im(), 0.f);

  EXPECT_TRUE(std::abs(std::sqrt(c.re()) - Complexf::length(c0)) <= Math3D::imprecision);
}

TEST(Complex, RotateWithImaginaryUnit)
{
  constexpr float scalar0 = 6.f;
  constexpr float scalar1 = 3.f;

  { // CCW
    Complexf c(scalar0, scalar1);
    EXPECT_EQ(c, Complexf(scalar0, scalar1));

    c *= Complexf::imunit;
    EXPECT_EQ(c, Complexf(-scalar1, scalar0));

    c *= Complexf::imunit;
    EXPECT_EQ(c, Complexf(-scalar0, -scalar1));

    c *= Complexf::imunit;
    EXPECT_EQ(c, Complexf(scalar1, -scalar0));

    c *= Complexf::imunit;
    EXPECT_EQ(c, Complexf(scalar0, scalar1));
  }

  { // CW
    Complexf c(scalar0, scalar1);
    EXPECT_EQ(c, Complexf(scalar0, scalar1));

    c *= -Complexf::imunit;
    EXPECT_EQ(c, Complexf(scalar1, -scalar0));

    c *= -Complexf::imunit;
    EXPECT_EQ(c, Complexf(-scalar0, -scalar1));

    c *= -Complexf::imunit;
    EXPECT_EQ(c, Complexf(-scalar1, scalar0));

    c *= -Complexf::imunit;
    EXPECT_EQ(c, Complexf(scalar0, scalar1));
  }
}

TEST(Complex, RotateWithRotor)
{
  constexpr float scalar0 = 6.f;
  constexpr float scalar1 = 3.f;

  { // CCW
    const Complexf rotor30degCCW = Complexf::rotor(Math3D::DegToRad(30.f));

    Complexf c(scalar0, scalar1);
    EXPECT_EQ(c, Complexf(scalar0, scalar1));

    c *= rotor30degCCW * rotor30degCCW * rotor30degCCW;
    EXPECT_EQ(c, Complexf(-scalar1, scalar0));

    c *= rotor30degCCW * rotor30degCCW * rotor30degCCW;
    EXPECT_EQ(c, Complexf(-scalar0, -scalar1));

    c *= rotor30degCCW * rotor30degCCW * rotor30degCCW;
    EXPECT_EQ(c, Complexf(scalar1, -scalar0));

    c *= rotor30degCCW * rotor30degCCW * rotor30degCCW;
    EXPECT_EQ(c, Complexf(scalar0, scalar1));
  }

  { // CW
    const Complexf rotor30degCW = Complexf::rotor(Math3D::DegToRad(-30.f));

    Complexf c(scalar0, scalar1);
    EXPECT_EQ(c, Complexf(scalar0, scalar1));

    c *= rotor30degCW * rotor30degCW * rotor30degCW;
    EXPECT_EQ(c, Complexf(scalar1, -scalar0));

    c *= rotor30degCW * rotor30degCW * rotor30degCW;
    EXPECT_EQ(c, Complexf(-scalar0, -scalar1));

    c *= rotor30degCW * rotor30degCW * rotor30degCW;
    EXPECT_EQ(c, Complexf(-scalar1, scalar0));

    c *= rotor30degCW * rotor30degCW * rotor30degCW;
    EXPECT_EQ(c, Complexf(scalar0, scalar1));
  }
}

TEST(Complex, SquareRoot)
{
  {
    const Complexf c(5.f, 9.f);
    const Complexf powerOf2 = c * c;
    const std::pair<Complexf, Complexf> rootOf2 = 
      Complexf::sqrt(powerOf2);
    EXPECT_EQ(c, rootOf2.first);
  }

  {
    const Complexf c(-5.f, -9.f);
    const Complexf powerOf2 = c * c;
    const std::pair<Complexf, Complexf> rootOf2 = 
      Complexf::sqrt(powerOf2);
    EXPECT_EQ(c, rootOf2.second);
  }

  {
    const Complexf c(5.f, -9.f);
    const Complexf powerOf2 = c * c;
    const std::pair<Complexf, Complexf> rootOf2 =
      Complexf::sqrt(powerOf2);
    EXPECT_EQ(c, rootOf2.first);
  }

  {
    const Complexf c(-5.f, 9.f);
    const Complexf powerOf2 = c * c;
    const std::pair<Complexf, Complexf> rootOf2 =
      Complexf::sqrt(powerOf2);
    EXPECT_EQ(c, rootOf2.second);
  }
}

TEST(Complex, RootOfN)
{
  {
    const double v = Math3D::root(27.0, 3.0);
    EXPECT_TRUE(std::abs(3.0 - v) < Math3D::imprecision);
  }
  {
    const float v = Math3D::rootf(27.f, 3.f);
    EXPECT_TRUE(std::abs(3.f - v) < Math3D::imprecision);
  }

  const Complexf c1(3.f, 4.f);

  {
    const float len1 = Complexf::length(c1);
    const float _11 = std::atan(c1.im() / c1.re());
    const float _21 = std::acos(c1.re() / len1);
    const float _31 = std::asin(c1.im() / len1);

    EXPECT_LE(std::abs(_11 - _21), Math3D::imprecision);
    EXPECT_LE(std::abs(_21 - _31), Math3D::imprecision);
    EXPECT_LE(std::abs(_31 - _11), Math3D::imprecision);
  }

  {
    // Didn't get how to calculate
  }
}
