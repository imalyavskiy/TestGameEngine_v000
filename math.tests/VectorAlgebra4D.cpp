#include "pch.h"
#include <math/src/utils.h>
#include <math/src/vector2.h>
#include <math/src/vector3.h>
#include <math/src/vector4.h>

TEST(VectorAlgebra4D, Construction)
{
    {
        math::vector4f v0;
        EXPECT_EQ(v0.x(), v0.r());
        EXPECT_EQ(v0.y(), v0.g());
        EXPECT_EQ(v0.z(), v0.b());
        EXPECT_EQ(v0.x(), v0.y());
        EXPECT_EQ(v0.y(), v0.z());
        EXPECT_EQ(v0.r(), v0.g());
        EXPECT_EQ(v0.g(), v0.b());
        EXPECT_EQ(v0.x(), 0.f);
        EXPECT_EQ(v0.r(), 0.f);
        EXPECT_EQ(v0.y(), 0.f);
        EXPECT_EQ(v0.g(), 0.f);
        EXPECT_EQ(v0.z(), 0.f);
        EXPECT_EQ(v0.b(), 0.f);


        v0 = math::vector4f(1.f);
        EXPECT_EQ(v0.x(), 1.f);
        EXPECT_EQ(v0.r(), 1.f);
        EXPECT_EQ(v0.y(), 1.f);
        EXPECT_EQ(v0.g(), 1.f);
        EXPECT_EQ(v0.z(), 1.f);
        EXPECT_EQ(v0.b(), 1.f);

        v0 = math::vector4f(3.f, 10.f, 5.f);
        EXPECT_EQ(v0.x(), 3.f);
        EXPECT_EQ(v0.r(), 3.f);
        EXPECT_EQ(v0.y(), 10.f);
        EXPECT_EQ(v0.g(), 10.f);
        EXPECT_EQ(v0.z(), 5.f);
        EXPECT_EQ(v0.b(), 5.f);

        math::vector4f v1(v0);
        EXPECT_TRUE(v0 == v1);
        EXPECT_FALSE(v0 != v1);
    }
    {
        math::vector4d v0;
        EXPECT_EQ(v0.x(), v0.r());
        EXPECT_EQ(v0.y(), v0.g());
        EXPECT_EQ(v0.z(), v0.b());
        EXPECT_EQ(v0.x(), v0.y());
        EXPECT_EQ(v0.y(), v0.z());
        EXPECT_EQ(v0.r(), v0.g());
        EXPECT_EQ(v0.g(), v0.b());
        EXPECT_EQ(v0.x(), 0.0);
        EXPECT_EQ(v0.r(), 0.0);
        EXPECT_EQ(v0.y(), 0.0);
        EXPECT_EQ(v0.g(), 0.0);
        EXPECT_EQ(v0.z(), 0.0);
        EXPECT_EQ(v0.b(), 0.0);


        v0 = math::vector4d(1.0);
        EXPECT_EQ(v0.x(), 1.0);
        EXPECT_EQ(v0.r(), 1.0);
        EXPECT_EQ(v0.y(), 1.0);
        EXPECT_EQ(v0.g(), 1.0);
        EXPECT_EQ(v0.z(), 1.0);
        EXPECT_EQ(v0.b(), 1.0);

        v0 = math::vector4d(3.0, 10.0, 5.0);
        EXPECT_EQ(v0.x(), 3.0);
        EXPECT_EQ(v0.r(), 3.0);
        EXPECT_EQ(v0.y(), 10.0);
        EXPECT_EQ(v0.g(), 10.0);
        EXPECT_EQ(v0.z(), 5.0);
        EXPECT_EQ(v0.b(), 5.0);

        math::vector4d v1(v0);
        EXPECT_EQ(v0, v1);
        EXPECT_FALSE(v0 != v1);
    }
}
TEST(VectorAlgebra4D, Equality) {
    EXPECT_TRUE(math::vector4f(3.5f) == math::vector4f(3.5f));
    EXPECT_TRUE(math::vector4d(3.5) == math::vector4d(3.5));
}

TEST(VectorAlgebra4D, InEquality) {
    EXPECT_TRUE(math::vector4f(0.f) != math::vector4f(1.f));
    EXPECT_TRUE(math::vector4d(0.0) != math::vector4d(1.0));
}

TEST(VectorAlgebra4D, Length) {
    EXPECT_EQ(math::vector4f(1.f, 0.f, 0.f).length(), sqrt(std::pow(1.f, 2.f)));
    EXPECT_EQ(math::vector4f(-1.f, 0.f, 0.f).length(), sqrt(std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector4d(1.0, 0.0, 0.0).length(), sqrt(std::pow(1.0, 2.0)));
    EXPECT_EQ(math::vector4d(-1.0, 0.0, 0.0).length(), sqrt(std::pow(-1.0, 2.0)));

    EXPECT_EQ(math::vector4f(0.f, 1.f, 0.f).length(), sqrt(std::pow(1.f, 2.f)));
    EXPECT_EQ(math::vector4f(0.f, -1.f, 0.f).length(), sqrt(std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector4d(0.0, 1.0, 0.0).length(), sqrt(std::pow(1.0, 2.0)));
    EXPECT_EQ(math::vector4d(0.0, -1.0, 0.0).length(), sqrt(std::pow(-1.0, 2.0)));

    EXPECT_EQ(math::vector4f(0.f, 0.f, 1.f).length(), sqrt(std::pow(1.f, 2.f)));
    EXPECT_EQ(math::vector4f(0.f, 0.f, -1.f).length(), sqrt(std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector4d(0.0, 0.0, 1.0).length(), sqrt(std::pow(1.0, 2.0)));
    EXPECT_EQ(math::vector4d(0.0, 0.0, -1.0).length(), sqrt(std::pow(-1.0, 2.0)));

    EXPECT_EQ(math::vector4f(+1.f, +1.f, +1.f).length(), sqrt(std::pow(+1.f, 2.f) + std::pow(+1.f, 2.f) + std::pow(+1.f, 2.f)));
    EXPECT_EQ(math::vector4f(-1.f, +1.f, +1.f).length(), sqrt(std::pow(-1.f, 2.f) + std::pow(+1.f, 2.f) + std::pow(+1.f, 2.f)));
    EXPECT_EQ(math::vector4f(+1.f, -1.f, +1.f).length(), sqrt(std::pow(+1.f, 2.f) + std::pow(-1.f, 2.f) + std::pow(+1.f, 2.f)));
    EXPECT_EQ(math::vector4f(+1.f, +1.f, -1.f).length(), sqrt(std::pow(+1.f, 2.f) + std::pow(+1.f, 2.f) + std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector4f(+1.f, -1.f, -1.f).length(), sqrt(std::pow(+1.f, 2.f) + std::pow(-1.f, 2.f) + std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector4f(-1.f, +1.f, -1.f).length(), sqrt(std::pow(-1.f, 2.f) + std::pow(+1.f, 2.f) + std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector4f(-1.f, -1.f, +1.f).length(), sqrt(std::pow(-1.f, 2.f) + std::pow(-1.f, 2.f) + std::pow(+1.f, 2.f)));
    EXPECT_EQ(math::vector4f(-1.f, -1.f, -1.f).length(), sqrt(std::pow(-1.f, 2.f) + std::pow(-1.f, 2.f) + std::pow(-1.f, 2.f)));

    EXPECT_EQ(math::vector4d(+1.0, +1.0, +1.0).length(), sqrt(std::pow(+1.0, 2.0) + std::pow(+1.0, 2.0) + std::pow(+1.0, 2.0)));
    EXPECT_EQ(math::vector4d(-1.0, +1.0, +1.0).length(), sqrt(std::pow(-1.0, 2.0) + std::pow(+1.0, 2.0) + std::pow(+1.0, 2.0)));
    EXPECT_EQ(math::vector4d(+1.0, -1.0, +1.0).length(), sqrt(std::pow(+1.0, 2.0) + std::pow(-1.0, 2.0) + std::pow(+1.0, 2.0)));
    EXPECT_EQ(math::vector4d(+1.0, +1.0, -1.0).length(), sqrt(std::pow(+1.0, 2.0) + std::pow(+1.0, 2.0) + std::pow(-1.0, 2.0)));
    EXPECT_EQ(math::vector4d(+1.0, -1.0, -1.0).length(), sqrt(std::pow(+1.0, 2.0) + std::pow(-1.0, 2.0) + std::pow(-1.0, 2.0)));
    EXPECT_EQ(math::vector4d(-1.0, +1.0, -1.0).length(), sqrt(std::pow(-1.0, 2.0) + std::pow(+1.0, 2.0) + std::pow(-1.0, 2.0)));
    EXPECT_EQ(math::vector4d(-1.0, -1.0, +1.0).length(), sqrt(std::pow(-1.0, 2.0) + std::pow(-1.0, 2.0) + std::pow(+1.0, 2.0)));
    EXPECT_EQ(math::vector4d(-1.0, -1.0, -1.0).length(), sqrt(std::pow(-1.0, 2.0) + std::pow(-1.0, 2.0) + std::pow(-1.0, 2.0)));

    EXPECT_EQ(math::vector4f(+3.f, +5.f, +2.5f).length(), sqrt(std::pow(+3.f, 2.f) + std::pow(+5.f, 2.f) + std::pow(+2.5f, 2.f)));
    EXPECT_EQ(math::vector4f(-3.f, +5.f, +2.5f).length(), sqrt(std::pow(-3.f, 2.f) + std::pow(+5.f, 2.f) + std::pow(+2.5f, 2.f)));
    EXPECT_EQ(math::vector4f(+3.f, -5.f, +2.5f).length(), sqrt(std::pow(+3.f, 2.f) + std::pow(-5.f, 2.f) + std::pow(+2.5f, 2.f)));
    EXPECT_EQ(math::vector4f(+3.f, +5.f, -2.5f).length(), sqrt(std::pow(+3.f, 2.f) + std::pow(+5.f, 2.f) + std::pow(-2.5f, 2.f)));
    EXPECT_EQ(math::vector4f(+3.f, -5.f, -2.5f).length(), sqrt(std::pow(+3.f, 2.f) + std::pow(-5.f, 2.f) + std::pow(-2.5f, 2.f)));
    EXPECT_EQ(math::vector4f(-3.f, +5.f, -2.5f).length(), sqrt(std::pow(-3.f, 2.f) + std::pow(+5.f, 2.f) + std::pow(-2.5f, 2.f)));
    EXPECT_EQ(math::vector4f(-3.f, -5.f, +2.5f).length(), sqrt(std::pow(-3.f, 2.f) + std::pow(-5.f, 2.f) + std::pow(+2.5f, 2.f)));
    EXPECT_EQ(math::vector4f(-3.f, -5.f, -2.5f).length(), sqrt(std::pow(-3.f, 2.f) + std::pow(-5.f, 2.f) + std::pow(-2.5f, 2.f)));

    EXPECT_EQ(math::vector4d(+3.0, +5.0, +2.5).length(), sqrt(std::pow(+3.0, 2.0) + std::pow(+5.0, 2.0) + std::pow(+2.5, 2.0)));
    EXPECT_EQ(math::vector4d(-3.0, +5.0, +2.5).length(), sqrt(std::pow(-3.0, 2.0) + std::pow(+5.0, 2.0) + std::pow(+2.5, 2.0)));
    EXPECT_EQ(math::vector4d(+3.0, -5.0, +2.5).length(), sqrt(std::pow(+3.0, 2.0) + std::pow(-5.0, 2.0) + std::pow(+2.5, 2.0)));
    EXPECT_EQ(math::vector4d(+3.0, +5.0, -2.5).length(), sqrt(std::pow(+3.0, 2.0) + std::pow(+5.0, 2.0) + std::pow(-2.5, 2.0)));
    EXPECT_EQ(math::vector4d(+3.0, -5.0, -2.5).length(), sqrt(std::pow(+3.0, 2.0) + std::pow(-5.0, 2.0) + std::pow(-2.5, 2.0)));
    EXPECT_EQ(math::vector4d(-3.0, +5.0, -2.5).length(), sqrt(std::pow(-3.0, 2.0) + std::pow(+5.0, 2.0) + std::pow(-2.5, 2.0)));
    EXPECT_EQ(math::vector4d(-3.0, -5.0, +2.5).length(), sqrt(std::pow(-3.0, 2.0) + std::pow(-5.0, 2.0) + std::pow(+2.5, 2.0)));
    EXPECT_EQ(math::vector4d(-3.0, -5.0, -2.5).length(), sqrt(std::pow(-3.0, 2.0) + std::pow(-5.0, 2.0) + std::pow(-2.5, 2.0)));

    EXPECT_EQ(math::length(math::vector4f(+3.f, +5.f, +2.5f)), math::vector4f(+3.f, +5.f, +2.5f).length());
    EXPECT_EQ(math::length(math::vector4f(-3.f, +5.f, +2.5f)), math::vector4f(-3.f, +5.f, +2.5f).length());
    EXPECT_EQ(math::length(math::vector4f(+3.f, -5.f, +2.5f)), math::vector4f(+3.f, -5.f, +2.5f).length());
    EXPECT_EQ(math::length(math::vector4f(+3.f, +5.f, -2.5f)), math::vector4f(+3.f, +5.f, -2.5f).length());
    EXPECT_EQ(math::length(math::vector4f(+3.f, -5.f, -2.5f)), math::vector4f(+3.f, -5.f, -2.5f).length());
    EXPECT_EQ(math::length(math::vector4f(-3.f, +5.f, -2.5f)), math::vector4f(-3.f, +5.f, -2.5f).length());
    EXPECT_EQ(math::length(math::vector4f(-3.f, -5.f, +2.5f)), math::vector4f(-3.f, -5.f, +2.5f).length());
    EXPECT_EQ(math::length(math::vector4f(-3.f, -5.f, -2.5f)), math::vector4f(-3.f, -5.f, -2.5f).length());

    EXPECT_EQ(math::length(math::vector4d(+3.0, +5.0, +2.5)), math::vector4d(+3.0, +5.0, +2.5).length());
    EXPECT_EQ(math::length(math::vector4d(-3.0, +5.0, +2.5)), math::vector4d(-3.0, +5.0, +2.5).length());
    EXPECT_EQ(math::length(math::vector4d(+3.0, -5.0, +2.5)), math::vector4d(+3.0, -5.0, +2.5).length());
    EXPECT_EQ(math::length(math::vector4d(+3.0, +5.0, -2.5)), math::vector4d(+3.0, +5.0, -2.5).length());
    EXPECT_EQ(math::length(math::vector4d(+3.0, -5.0, -2.5)), math::vector4d(+3.0, -5.0, -2.5).length());
    EXPECT_EQ(math::length(math::vector4d(-3.0, +5.0, -2.5)), math::vector4d(-3.0, +5.0, -2.5).length());
    EXPECT_EQ(math::length(math::vector4d(-3.0, -5.0, +2.5)), math::vector4d(-3.0, -5.0, +2.5).length());
    EXPECT_EQ(math::length(math::vector4d(-3.0, -5.0, -2.5)), math::vector4d(-3.0, -5.0, -2.5).length());
}

TEST(VectorAlgebra4D, Normalization) {
    {
        constexpr float x = -3.f, y = -5.f, z = -1.f;
        EXPECT_TRUE(math::vector4f(x, y, z).normalize().is_unit());
        EXPECT_TRUE(math::is_unit(math::vector4f(x, y, z).normalize()));
        EXPECT_EQ(math::normalized(math::vector4f(x, y, z)), math::vector4f(x, y, z).normalize());
    }
    {
        constexpr double x = -3.0, y = -5.0, z = -1.0;
        EXPECT_TRUE(math::vector4d(x, y, z).normalize().is_unit());
        EXPECT_TRUE(math::is_unit(math::vector4d(x, y, z).normalize()));
        EXPECT_EQ(math::normalized(math::vector4d(x, y, z)), math::vector4d(x, y, z).normalize());
    }
}

TEST(VectorAlgebra4D, DotProduct) {
    EXPECT_EQ(math::vector4f(+1.f, +0.f, +0.f).dot(math::vector4f(+1.f, +0.f, +0.f)), +1.f);
    EXPECT_EQ(math::vector4f(+1.f, +0.f, +0.f).dot(math::vector4f(-1.f, +0.f, +0.f)), -1.f);
    EXPECT_EQ(math::vector4f(+1.f, +0.f, +0.f).dot(math::vector4f(+0.f, +1.f, +0.f)), +0.f);
    EXPECT_EQ(math::vector4f(+1.f, +0.f, +0.f).dot(math::vector4f(+0.f, -1.f, +0.f)), +0.f);
    EXPECT_EQ(math::vector4f(+1.f, +0.f, +0.f).dot(math::vector4f(+0.f, +0.f, +1.f)), +0.f);
    EXPECT_EQ(math::vector4f(+1.f, +0.f, +0.f).dot(math::vector4f(+0.f, +0.f, -1.f)), +0.f);

    EXPECT_EQ(math::vector4f(+0.f, +1.f, +0.f).dot(math::vector4f(+0.f, +1.f, +0.f)), +1.f);
    EXPECT_EQ(math::vector4f(+0.f, +1.f, +0.f).dot(math::vector4f(+0.f, -1.f, +0.f)), -1.f);
    EXPECT_EQ(math::vector4f(+0.f, +1.f, +0.f).dot(math::vector4f(+1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::vector4f(+0.f, +1.f, +0.f).dot(math::vector4f(-1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::vector4f(+0.f, +1.f, +0.f).dot(math::vector4f(+0.f, +0.f, +1.f)), +0.f);
    EXPECT_EQ(math::vector4f(+0.f, +1.f, +0.f).dot(math::vector4f(+0.f, +0.f, -1.f)), +0.f);

    EXPECT_EQ(math::vector4f(+0.f, +0.f, +1.f).dot(math::vector4f(+0.f, +0.f, +1.f)), +1.f);
    EXPECT_EQ(math::vector4f(+0.f, +0.f, +1.f).dot(math::vector4f(+0.f, +0.f, -1.f)), -1.f);
    EXPECT_EQ(math::vector4f(+0.f, +0.f, +1.f).dot(math::vector4f(+1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::vector4f(+0.f, +0.f, +1.f).dot(math::vector4f(-1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::vector4f(+0.f, +0.f, +1.f).dot(math::vector4f(+0.f, +1.f, +0.f)), +0.f);
    EXPECT_EQ(math::vector4f(+0.f, +0.f, +1.f).dot(math::vector4f(+0.f, -1.f, +0.f)), +0.f);

    EXPECT_GT(math::vector4f(+3.f, +5.f, +2.f).dot(math::vector4f(+5.f, +3.f, +2.f)), 0.f);
    EXPECT_LT(math::vector4f(+3.f, +5.f, -3.f).dot(math::vector4f(-5.f, -3.f, -3.f)), 0.f);

    EXPECT_EQ(math::dot(math::vector4f(+1.f, +0.f, +0.f), math::vector4f(+1.f, +0.f, +0.f)), +1.f);
    EXPECT_EQ(math::dot(math::vector4f(+1.f, +0.f, +0.f), math::vector4f(-1.f, +0.f, +0.f)), -1.f);
    EXPECT_EQ(math::dot(math::vector4f(+1.f, +0.f, +0.f), math::vector4f(+0.f, +1.f, +0.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector4f(+1.f, +0.f, +0.f), math::vector4f(+0.f, -1.f, +0.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector4f(+1.f, +0.f, +0.f), math::vector4f(+0.f, +0.f, +1.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector4f(+1.f, +0.f, +0.f), math::vector4f(+0.f, +0.f, -1.f)), +0.f);

    EXPECT_EQ(math::dot(math::vector4f(+0.f, +1.f, +0.f), math::vector4f(+0.f, +1.f, +0.f)), +1.f);
    EXPECT_EQ(math::dot(math::vector4f(+0.f, +1.f, +0.f), math::vector4f(+0.f, -1.f, +0.f)), -1.f);
    EXPECT_EQ(math::dot(math::vector4f(+0.f, +1.f, +0.f), math::vector4f(+1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector4f(+0.f, +1.f, +0.f), math::vector4f(-1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector4f(+0.f, +1.f, +0.f), math::vector4f(+0.f, +0.f, +1.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector4f(+0.f, +1.f, +0.f), math::vector4f(+0.f, +0.f, -1.f)), +0.f);

    EXPECT_EQ(math::dot(math::vector4f(+0.f, +0.f, +1.f), math::vector4f(+0.f, +0.f, +1.f)), +1.f);
    EXPECT_EQ(math::dot(math::vector4f(+0.f, +0.f, +1.f), math::vector4f(+0.f, +0.f, -1.f)), -1.f);
    EXPECT_EQ(math::dot(math::vector4f(+0.f, +0.f, +1.f), math::vector4f(+1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector4f(+0.f, +0.f, +1.f), math::vector4f(-1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector4f(+0.f, +0.f, +1.f), math::vector4f(+0.f, +1.f, +0.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector4f(+0.f, +0.f, +1.f), math::vector4f(+0.f, -1.f, +0.f)), +0.f);

    EXPECT_GT(math::dot(math::vector4f(+3.f, +5.f, +2.f), math::vector4f(+5.f, +3.f, +2.f)), 0.f);
    EXPECT_LT(math::dot(math::vector4f(+3.f, +5.f, -3.f), math::vector4f(-5.f, -3.f, -3.f)), 0.f);


    EXPECT_EQ(math::vector4d(+1.0, +0.0, +0.0).dot(math::vector4d(+1.0, +0.0, +0.0)), +1.0);
    EXPECT_EQ(math::vector4d(+1.0, +0.0, +0.0).dot(math::vector4d(-1.0, +0.0, +0.0)), -1.0);
    EXPECT_EQ(math::vector4d(+1.0, +0.0, +0.0).dot(math::vector4d(+0.0, +1.0, +0.0)), +0.0);
    EXPECT_EQ(math::vector4d(+1.0, +0.0, +0.0).dot(math::vector4d(+0.0, -1.0, +0.0)), +0.0);
    EXPECT_EQ(math::vector4d(+1.0, +0.0, +0.0).dot(math::vector4d(+0.0, +0.0, +1.0)), +0.0);
    EXPECT_EQ(math::vector4d(+1.0, +0.0, +0.0).dot(math::vector4d(+0.0, +0.0, -1.0)), +0.0);

    EXPECT_EQ(math::vector4d(+0.0, +1.0, +0.0).dot(math::vector4d(+0.0, +1.0, +0.0)), +1.0);
    EXPECT_EQ(math::vector4d(+0.0, +1.0, +0.0).dot(math::vector4d(+0.0, -1.0, +0.0)), -1.0);
    EXPECT_EQ(math::vector4d(+0.0, +1.0, +0.0).dot(math::vector4d(+1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::vector4d(+0.0, +1.0, +0.0).dot(math::vector4d(-1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::vector4d(+0.0, +1.0, +0.0).dot(math::vector4d(+0.0, +0.0, +1.0)), +0.0);
    EXPECT_EQ(math::vector4d(+0.0, +1.0, +0.0).dot(math::vector4d(+0.0, +0.0, -1.0)), +0.0);

    EXPECT_EQ(math::vector4d(+0.0, +0.0, +1.0).dot(math::vector4d(+0.0, +0.0, +1.0)), +1.0);
    EXPECT_EQ(math::vector4d(+0.0, +0.0, +1.0).dot(math::vector4d(+0.0, +0.0, -1.0)), -1.0);
    EXPECT_EQ(math::vector4d(+0.0, +0.0, +1.0).dot(math::vector4d(+1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::vector4d(+0.0, +0.0, +1.0).dot(math::vector4d(-1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::vector4d(+0.0, +0.0, +1.0).dot(math::vector4d(+0.0, +1.0, +0.0)), +0.0);
    EXPECT_EQ(math::vector4d(+0.0, +0.0, +1.0).dot(math::vector4d(+0.0, -1.0, +0.0)), +0.0);

    EXPECT_GT(math::vector4d(+3.0, +5.0, +2.0).dot(math::vector4d(+5.0, +3.0, +2.0)), 0.0);
    EXPECT_LT(math::vector4d(+3.0, +5.0, -3.0).dot(math::vector4d(-5.0, -3.0, -3.0)), 0.0);


    EXPECT_EQ(math::dot(math::vector4d(+1.0, +0.0, +0.0), math::vector4d(+1.0, +0.0, +0.0)), +1.0);
    EXPECT_EQ(math::dot(math::vector4d(+1.0, +0.0, +0.0), math::vector4d(-1.0, +0.0, +0.0)), -1.0);
    EXPECT_EQ(math::dot(math::vector4d(+1.0, +0.0, +0.0), math::vector4d(+0.0, +1.0, +0.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector4d(+1.0, +0.0, +0.0), math::vector4d(+0.0, -1.0, +0.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector4d(+1.0, +0.0, +0.0), math::vector4d(+0.0, +0.0, +1.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector4d(+1.0, +0.0, +0.0), math::vector4d(+0.0, +0.0, -1.0)), +0.0);

    EXPECT_EQ(math::dot(math::vector4d(+0.0, +1.0, +0.0), math::vector4d(+0.0, +1.0, +0.0)), +1.0);
    EXPECT_EQ(math::dot(math::vector4d(+0.0, +1.0, +0.0), math::vector4d(+0.0, -1.0, +0.0)), -1.0);
    EXPECT_EQ(math::dot(math::vector4d(+0.0, +1.0, +0.0), math::vector4d(+1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector4d(+0.0, +1.0, +0.0), math::vector4d(-1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector4d(+0.0, +1.0, +0.0), math::vector4d(+0.0, +0.0, +1.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector4d(+0.0, +1.0, +0.0), math::vector4d(+0.0, +0.0, -1.0)), +0.0);

    EXPECT_EQ(math::dot(math::vector4d(+0.0, +0.0, +1.0), math::vector4d(+0.0, +0.0, +1.0)), +1.0);
    EXPECT_EQ(math::dot(math::vector4d(+0.0, +0.0, +1.0), math::vector4d(+0.0, +0.0, -1.0)), -1.0);
    EXPECT_EQ(math::dot(math::vector4d(+0.0, +0.0, +1.0), math::vector4d(+1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector4d(+0.0, +0.0, +1.0), math::vector4d(-1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector4d(+0.0, +0.0, +1.0), math::vector4d(+0.0, +1.0, +0.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector4d(+0.0, +0.0, +1.0), math::vector4d(+0.0, -1.0, +0.0)), +0.0);

    EXPECT_GT(math::dot(math::vector4d(+3.0, +5.0, +2.0), math::vector4d(+5.0, +3.0, +2.0)), 0.0);
    EXPECT_LT(math::dot(math::vector4d(+3.0, +5.0, -3.0), math::vector4d(-5.0, -3.0, -3.0)), 0.0);
}

TEST(VectorAlgebra4D, PlusMinusVector) {
    EXPECT_EQ(math::vector4f(0.f) + math::vector4f(1.f), math::vector4f(1.f));
    EXPECT_EQ(math::vector4f(1.f, 2.f, 3.f) + math::vector4f(3.f, 2.f, 1.f), math::vector4f(4.f, 4.f, 4.f));

    EXPECT_EQ(math::vector4d(0.0) + math::vector4d(1.0), math::vector4d(1.0));
    EXPECT_EQ(math::vector4d(1.0, 2.0, 3.0) + math::vector4d(3.0, 2.0, 1.0), math::vector4d(4.0, 4.0, 4.0));
}


TEST(VectorAlgebra4D, MultiplyScalar) {
    EXPECT_EQ(math::vector4f(0.f) * 1.f, math::vector4f(0.f));
    EXPECT_EQ(math::vector4f(1.f, 2.f, 3.f) * 2.f, math::vector4f(2.f, 4.f, 6.f));
    EXPECT_EQ(math::vector4f(1.f, 2.f, 3.f) / 2.f, math::vector4f(.5f, 1.f, 1.5f));

    EXPECT_EQ(math::vector4d(0.0) * 1.0, math::vector4d(0.0));
    EXPECT_EQ(math::vector4d(1.0, 2.0, 3.0) * 2.0, math::vector4d(2.0, 4.0, 6.0));
    EXPECT_EQ(math::vector4d(1.0, 2.0, 3.0) / 2.0, math::vector4d(.5f, 1.0, 1.5));
}

TEST(VectorAlgebra4D, CrossProduct) {
    EXPECT_EQ(math::vector4f::X.cross(math::vector4f::Y), math::vector4f::Z);
    EXPECT_EQ(math::vector4f::Y.cross(math::vector4f::Z), math::vector4f::X);
    EXPECT_EQ(math::vector4f::Z.cross(math::vector4f::X), math::vector4f::Y);
    EXPECT_EQ(math::vector4f::Y.cross(math::vector4f::X), -math::vector4f::Z);
    EXPECT_EQ(math::vector4f::Z.cross(math::vector4f::Y), -math::vector4f::X);
    EXPECT_EQ(math::vector4f::X.cross(math::vector4f::Z), -math::vector4f::Y);

    EXPECT_EQ(math::cross(math::vector4f::X, math::vector4f::Y), math::vector4f::Z);
    EXPECT_EQ(math::cross(math::vector4f::Y, math::vector4f::Z), math::vector4f::X);
    EXPECT_EQ(math::cross(math::vector4f::Z, math::vector4f::X), math::vector4f::Y);
    EXPECT_EQ(math::cross(math::vector4f::Y, math::vector4f::X), -math::vector4f::Z);
    EXPECT_EQ(math::cross(math::vector4f::Z, math::vector4f::Y), -math::vector4f::X);
    EXPECT_EQ(math::cross(math::vector4f::X, math::vector4f::Z), -math::vector4f::Y);

    EXPECT_EQ(math::normalized(math::vector4f(1.f, 0.f, 0.f).cross(math::vector4f(0.5f, 10.f, 0.0))), math::vector4f::Z);
    EXPECT_EQ(math::normalized(math::vector4f(0.5f, 10.f, 0.0).cross(math::vector4f(1.f, 0.f, 0.f))), -math::vector4f::Z);
    EXPECT_EQ(math::normalized(math::vector4f(0.f, 1.f, 0.f).cross(math::vector4f(0.f, 0.5f, 10.f))), math::vector4f::X);
    EXPECT_EQ(math::normalized(math::vector4f(0.f, 0.5f, 10.f).cross(math::vector4f(0.f, 1.f, 0.f))), -math::vector4f::X);
    EXPECT_EQ(math::normalized(math::vector4f(0.f, 0.f, 1.f).cross(math::vector4f(0.5f, 0.0, 10.f))), math::vector4f::Y);
    EXPECT_EQ(math::normalized(math::vector4f(0.5f, 0.0, 10.f).cross(math::vector4f(0.f, 0.f, 1.f))), -math::vector4f::Y);

    EXPECT_EQ(math::normalized(math::cross(math::vector4f(1.f, 0.f, 0.f), math::vector4f(0.5f, 10.f, 0.0))), math::vector4f::Z);
    EXPECT_EQ(math::normalized(math::cross(math::vector4f(0.5f, 10.f, 0.0), math::vector4f(1.f, 0.f, 0.f))), -math::vector4f::Z);
    EXPECT_EQ(math::normalized(math::cross(math::vector4f(0.f, 1.f, 0.f), math::vector4f(0.f, 0.5f, 10.f))), math::vector4f::X);
    EXPECT_EQ(math::normalized(math::cross(math::vector4f(0.f, 0.5f, 10.f), math::vector4f(0.f, 1.f, 0.f))), -math::vector4f::X);
    EXPECT_EQ(math::normalized(math::cross(math::vector4f(0.f, 0.f, 1.f), math::vector4f(0.5f, 0.0, 10.f))), math::vector4f::Y);
    EXPECT_EQ(math::normalized(math::cross(math::vector4f(0.5f, 0.0, 10.f), math::vector4f(0.f, 0.f, 1.f))), -math::vector4f::Y);


    EXPECT_EQ(math::vector4d::X.cross(math::vector4d::Y), math::vector4d::Z);
    EXPECT_EQ(math::vector4d::Y.cross(math::vector4d::Z), math::vector4d::X);
    EXPECT_EQ(math::vector4d::Z.cross(math::vector4d::X), math::vector4d::Y);
    EXPECT_EQ(math::vector4d::Y.cross(math::vector4d::X), -math::vector4d::Z);
    EXPECT_EQ(math::vector4d::Z.cross(math::vector4d::Y), -math::vector4d::X);
    EXPECT_EQ(math::vector4d::X.cross(math::vector4d::Z), -math::vector4d::Y);

    EXPECT_EQ(math::cross(math::vector4d::X, math::vector4d::Y), math::vector4d::Z);
    EXPECT_EQ(math::cross(math::vector4d::Y, math::vector4d::Z), math::vector4d::X);
    EXPECT_EQ(math::cross(math::vector4d::Z, math::vector4d::X), math::vector4d::Y);
    EXPECT_EQ(math::cross(math::vector4d::Y, math::vector4d::X), -math::vector4d::Z);
    EXPECT_EQ(math::cross(math::vector4d::Z, math::vector4d::Y), -math::vector4d::X);
    EXPECT_EQ(math::cross(math::vector4d::X, math::vector4d::Z), -math::vector4d::Y);

    EXPECT_EQ(math::normalized(math::vector4d(1.0, 0.0, 0.0).cross(math::vector4d(0.5, 10.0, 0.0))), math::vector4d::Z);
    EXPECT_EQ(math::normalized(math::vector4d(0.5, 10.0, 0.0).cross(math::vector4d(1.0, 0.0, 0.0))), -math::vector4d::Z);
    EXPECT_EQ(math::normalized(math::vector4d(0.0, 1.0, 0.0).cross(math::vector4d(0.0, 0.5, 10.0))), math::vector4d::X);
    EXPECT_EQ(math::normalized(math::vector4d(0.0, 0.5, 10.0).cross(math::vector4d(0.0, 1.0, 0.0))), -math::vector4d::X);
    EXPECT_EQ(math::normalized(math::vector4d(0.0, 0.0, 1.0).cross(math::vector4d(0.5f, 0.0, 10.0))), math::vector4d::Y);
    EXPECT_EQ(math::normalized(math::vector4d(0.5, 0.0, 10.0).cross(math::vector4d(0.0, 0.0, 1.0))), -math::vector4d::Y);

    EXPECT_EQ(math::normalized(math::cross(math::vector4d(1.0, 0.0, 0.0), math::vector4d(0.5, 10.0, 0.0))), math::vector4d::Z);
    EXPECT_EQ(math::normalized(math::cross(math::vector4d(0.5, 10.0, 0.0), math::vector4d(1.0, 0.0, 0.0))), -math::vector4d::Z);
    EXPECT_EQ(math::normalized(math::cross(math::vector4d(0.0, 1.0, 0.0), math::vector4d(0.0, 0.5, 10.0))), math::vector4d::X);
    EXPECT_EQ(math::normalized(math::cross(math::vector4d(0.0, 0.5, 10.0), math::vector4d(0.0, 1.0, 0.0))), -math::vector4d::X);
    EXPECT_EQ(math::normalized(math::cross(math::vector4d(0.0, 0.0, 1.0), math::vector4d(0.5, 0.0, 10.0))), math::vector4d::Y);
    EXPECT_EQ(math::normalized(math::cross(math::vector4d(0.5, 0.0, 10.0), math::vector4d(0.0, 0.0, 1.0))), -math::vector4d::Y);
}

TEST(VectorAlgebra4D, Parts)
{
    EXPECT_EQ(math::vector4f(math::vector2f(1.f, 2.f), 3.f), math::vector4f(1.f, math::vector2f(2.f, 3.f)));
    EXPECT_EQ(math::vector4f(math::vector2f(1.f, 2.f), 3.f).xy(), math::vector2f(1.f, 2.f));
    EXPECT_EQ(math::vector4f(math::vector2f(1.f, 2.f), 3.f).rg(), math::vector2f(1.f, 2.f));
    EXPECT_EQ(math::vector4f(math::vector3f(1.f, 2.f, 3.f)), math::vector4f(1.f, math::vector2f(2.f, 3.f)));
    EXPECT_EQ(math::vector4f(math::vector3f(1.f, 2.f, 3.f)).xy(), math::vector2f(1.f, 2.f));
    EXPECT_EQ(math::vector4f(math::vector3f(1.f, 2.f, 3.f)).rg(), math::vector2f(1.f, 2.f));

    EXPECT_EQ(math::vector4f(1.f, 2.f, 3.f).rg(), math::vector4f(1.f, 2.f, 3.f).xy());
    EXPECT_EQ(math::vector4f(1.f, 2.f, 3.f).gb(), math::vector4f(1.f, 2.f, 3.f).yz());
    EXPECT_EQ(math::vector4f(1.f, 2.f, 3.f).xyz(), math::vector4f(1.f, 2.f, 3.f).rgb());

    EXPECT_EQ(math::vector4f().xy(math::vector2f(1.f, 2.f)), math::vector4f(1.f, 2.f, 0.f));
    EXPECT_EQ(math::vector4f().xy(math::vector2f(1.f, 2.f)), math::vector4f().rg(math::vector2f(1.f, 2.f)));
    EXPECT_EQ(math::vector4f().yz(math::vector2f(1.f, 2.f)), math::vector4f(0.f, 1.f, 2.f));
    EXPECT_EQ(math::vector4f().yz(math::vector2f(1.f, 2.f)), math::vector4f().gb(math::vector2f(1.f, 2.f)));
    EXPECT_EQ(math::vector4f().xyz(math::vector3f(1.f, 2.f, 3.f)), math::vector4f(1.f, 2.f, 3.f));
    EXPECT_EQ(math::vector4f().xyz(math::vector3f(1.f, 2.f, 3.f)), math::vector4f().rgb(math::vector3f(1.f, 2.f, 3.f)));
}
