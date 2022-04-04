#include "pch.h"
#include <math/src/utils.h>
#include <math/src/vector2.h>
#include <math/src/vector3.h>

TEST(VectorAlgebra3D, Construction)
{
    {
        math::vector3f v0;
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


        v0 = math::vector3f(1.f);
        EXPECT_EQ(v0.x(), 1.f);
        EXPECT_EQ(v0.r(), 1.f);
        EXPECT_EQ(v0.y(), 1.f);
        EXPECT_EQ(v0.g(), 1.f);
        EXPECT_EQ(v0.z(), 1.f);
        EXPECT_EQ(v0.b(), 1.f);

        v0 = math::vector3f(3.f, 10.f, 5.f);
        EXPECT_EQ(v0.x(), 3.f);
        EXPECT_EQ(v0.r(), 3.f);
        EXPECT_EQ(v0.y(), 10.f);
        EXPECT_EQ(v0.g(), 10.f);
        EXPECT_EQ(v0.z(), 5.f);
        EXPECT_EQ(v0.b(), 5.f);

        math::vector3f v1(v0);
        EXPECT_TRUE(v0 == v1);
        EXPECT_FALSE(v0 != v1);
    }
    {
        math::vector3d v0;
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


        v0 = math::vector3d(1.0);
        EXPECT_EQ(v0.x(), 1.0);
        EXPECT_EQ(v0.r(), 1.0);
        EXPECT_EQ(v0.y(), 1.0);
        EXPECT_EQ(v0.g(), 1.0);
        EXPECT_EQ(v0.z(), 1.0);
        EXPECT_EQ(v0.b(), 1.0);

        v0 = math::vector3d(3.0, 10.0, 5.0);
        EXPECT_EQ(v0.x(), 3.0);
        EXPECT_EQ(v0.r(), 3.0);
        EXPECT_EQ(v0.y(), 10.0);
        EXPECT_EQ(v0.g(), 10.0);
        EXPECT_EQ(v0.z(), 5.0);
        EXPECT_EQ(v0.b(), 5.0);

        math::vector3d v1(v0);
        EXPECT_EQ(v0, v1);
        EXPECT_FALSE(v0 != v1);
    }
}

TEST(VectorAlgebra3D, Equality) {
    EXPECT_TRUE(math::vector3f(3.5f) == math::vector3f(3.5f));
    EXPECT_TRUE(math::vector3d(3.5) == math::vector3d(3.5));
}

TEST(VectorAlgebra3D, InEquality) {
    EXPECT_TRUE(math::vector3f(0.f) != math::vector3f(1.f));
    EXPECT_TRUE(math::vector3d(0.0) != math::vector3d(1.0));
}

TEST(VectorAlgebra3D, Length) {
    EXPECT_EQ(math::vector3f(1.f, 0.f, 0.f).length(), sqrt(std::pow(1.f, 2.f)));
    EXPECT_EQ(math::vector3f(-1.f, 0.f, 0.f).length(), sqrt(std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector3d(1.0, 0.0, 0.0).length(), sqrt(std::pow(1.0, 2.0)));
    EXPECT_EQ(math::vector3d(-1.0, 0.0, 0.0).length(), sqrt(std::pow(-1.0, 2.0)));

    EXPECT_EQ(math::vector3f(0.f, 1.f, 0.f).length(), sqrt(std::pow(1.f, 2.f)));
    EXPECT_EQ(math::vector3f(0.f, -1.f, 0.f).length(), sqrt(std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector3d(0.0, 1.0, 0.0).length(), sqrt(std::pow(1.0, 2.0)));
    EXPECT_EQ(math::vector3d(0.0, -1.0, 0.0).length(), sqrt(std::pow(-1.0, 2.0)));

    EXPECT_EQ(math::vector3f(0.f, 0.f, 1.f).length(), sqrt(std::pow(1.f, 2.f)));
    EXPECT_EQ(math::vector3f(0.f, 0.f, -1.f).length(), sqrt(std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector3d(0.0, 0.0, 1.0).length(), sqrt(std::pow(1.0, 2.0)));
    EXPECT_EQ(math::vector3d(0.0, 0.0, -1.0).length(), sqrt(std::pow(-1.0, 2.0)));

    EXPECT_EQ(math::vector3f(+1.f, +1.f, +1.f).length(), sqrt(std::pow(+1.f, 2.f) + std::pow(+1.f, 2.f) + std::pow(+1.f, 2.f)));
    EXPECT_EQ(math::vector3f(-1.f, +1.f, +1.f).length(), sqrt(std::pow(-1.f, 2.f) + std::pow(+1.f, 2.f) + std::pow(+1.f, 2.f)));
    EXPECT_EQ(math::vector3f(+1.f, -1.f, +1.f).length(), sqrt(std::pow(+1.f, 2.f) + std::pow(-1.f, 2.f) + std::pow(+1.f, 2.f)));
    EXPECT_EQ(math::vector3f(+1.f, +1.f, -1.f).length(), sqrt(std::pow(+1.f, 2.f) + std::pow(+1.f, 2.f) + std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector3f(+1.f, -1.f, -1.f).length(), sqrt(std::pow(+1.f, 2.f) + std::pow(-1.f, 2.f) + std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector3f(-1.f, +1.f, -1.f).length(), sqrt(std::pow(-1.f, 2.f) + std::pow(+1.f, 2.f) + std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector3f(-1.f, -1.f, +1.f).length(), sqrt(std::pow(-1.f, 2.f) + std::pow(-1.f, 2.f) + std::pow(+1.f, 2.f)));
    EXPECT_EQ(math::vector3f(-1.f, -1.f, -1.f).length(), sqrt(std::pow(-1.f, 2.f) + std::pow(-1.f, 2.f) + std::pow(-1.f, 2.f)));

    EXPECT_EQ(math::vector3d(+1.0, +1.0, +1.0).length(), sqrt(std::pow(+1.0, 2.0) + std::pow(+1.0, 2.0) + std::pow(+1.0, 2.0)));
    EXPECT_EQ(math::vector3d(-1.0, +1.0, +1.0).length(), sqrt(std::pow(-1.0, 2.0) + std::pow(+1.0, 2.0) + std::pow(+1.0, 2.0)));
    EXPECT_EQ(math::vector3d(+1.0, -1.0, +1.0).length(), sqrt(std::pow(+1.0, 2.0) + std::pow(-1.0, 2.0) + std::pow(+1.0, 2.0)));
    EXPECT_EQ(math::vector3d(+1.0, +1.0, -1.0).length(), sqrt(std::pow(+1.0, 2.0) + std::pow(+1.0, 2.0) + std::pow(-1.0, 2.0)));
    EXPECT_EQ(math::vector3d(+1.0, -1.0, -1.0).length(), sqrt(std::pow(+1.0, 2.0) + std::pow(-1.0, 2.0) + std::pow(-1.0, 2.0)));
    EXPECT_EQ(math::vector3d(-1.0, +1.0, -1.0).length(), sqrt(std::pow(-1.0, 2.0) + std::pow(+1.0, 2.0) + std::pow(-1.0, 2.0)));
    EXPECT_EQ(math::vector3d(-1.0, -1.0, +1.0).length(), sqrt(std::pow(-1.0, 2.0) + std::pow(-1.0, 2.0) + std::pow(+1.0, 2.0)));
    EXPECT_EQ(math::vector3d(-1.0, -1.0, -1.0).length(), sqrt(std::pow(-1.0, 2.0) + std::pow(-1.0, 2.0) + std::pow(-1.0, 2.0)));

    EXPECT_EQ(math::vector3f(+3.f, +5.f, +2.5f).length(), sqrt(std::pow(+3.f, 2.f) + std::pow(+5.f, 2.f) + std::pow(+2.5f, 2.f)));
    EXPECT_EQ(math::vector3f(-3.f, +5.f, +2.5f).length(), sqrt(std::pow(-3.f, 2.f) + std::pow(+5.f, 2.f) + std::pow(+2.5f, 2.f)));
    EXPECT_EQ(math::vector3f(+3.f, -5.f, +2.5f).length(), sqrt(std::pow(+3.f, 2.f) + std::pow(-5.f, 2.f) + std::pow(+2.5f, 2.f)));
    EXPECT_EQ(math::vector3f(+3.f, +5.f, -2.5f).length(), sqrt(std::pow(+3.f, 2.f) + std::pow(+5.f, 2.f) + std::pow(-2.5f, 2.f)));
    EXPECT_EQ(math::vector3f(+3.f, -5.f, -2.5f).length(), sqrt(std::pow(+3.f, 2.f) + std::pow(-5.f, 2.f) + std::pow(-2.5f, 2.f)));
    EXPECT_EQ(math::vector3f(-3.f, +5.f, -2.5f).length(), sqrt(std::pow(-3.f, 2.f) + std::pow(+5.f, 2.f) + std::pow(-2.5f, 2.f)));
    EXPECT_EQ(math::vector3f(-3.f, -5.f, +2.5f).length(), sqrt(std::pow(-3.f, 2.f) + std::pow(-5.f, 2.f) + std::pow(+2.5f, 2.f)));
    EXPECT_EQ(math::vector3f(-3.f, -5.f, -2.5f).length(), sqrt(std::pow(-3.f, 2.f) + std::pow(-5.f, 2.f) + std::pow(-2.5f, 2.f)));

    EXPECT_EQ(math::vector3d(+3.0, +5.0, +2.5).length(), sqrt(std::pow(+3.0, 2.0) + std::pow(+5.0, 2.0) + std::pow(+2.5, 2.0)));
    EXPECT_EQ(math::vector3d(-3.0, +5.0, +2.5).length(), sqrt(std::pow(-3.0, 2.0) + std::pow(+5.0, 2.0) + std::pow(+2.5, 2.0)));
    EXPECT_EQ(math::vector3d(+3.0, -5.0, +2.5).length(), sqrt(std::pow(+3.0, 2.0) + std::pow(-5.0, 2.0) + std::pow(+2.5, 2.0)));
    EXPECT_EQ(math::vector3d(+3.0, +5.0, -2.5).length(), sqrt(std::pow(+3.0, 2.0) + std::pow(+5.0, 2.0) + std::pow(-2.5, 2.0)));
    EXPECT_EQ(math::vector3d(+3.0, -5.0, -2.5).length(), sqrt(std::pow(+3.0, 2.0) + std::pow(-5.0, 2.0) + std::pow(-2.5, 2.0)));
    EXPECT_EQ(math::vector3d(-3.0, +5.0, -2.5).length(), sqrt(std::pow(-3.0, 2.0) + std::pow(+5.0, 2.0) + std::pow(-2.5, 2.0)));
    EXPECT_EQ(math::vector3d(-3.0, -5.0, +2.5).length(), sqrt(std::pow(-3.0, 2.0) + std::pow(-5.0, 2.0) + std::pow(+2.5, 2.0)));
    EXPECT_EQ(math::vector3d(-3.0, -5.0, -2.5).length(), sqrt(std::pow(-3.0, 2.0) + std::pow(-5.0, 2.0) + std::pow(-2.5, 2.0)));
}

TEST(VectorAlgebra3D, Normalization) {
    {
        constexpr float x = -3.f, y = -5.f, z = -1.f;
        EXPECT_TRUE(math::vector3f(x, y, z).normalize().isUnit());
        EXPECT_EQ(math::normalized(math::vector3f(x, y, z)), math::vector3f(x, y, z).normalize());
    }
    {
        constexpr double x = -3.0, y = -5.0, z = -1.0;
        EXPECT_TRUE(math::vector3d(x, y, z).normalize().isUnit());
        EXPECT_EQ(math::normalized(math::vector3d(x, y, z)), math::vector3d(x, y, z).normalize());
    }
}

TEST(VectorAlgebra3D, DotProduct) {
    EXPECT_EQ(math::vector3f(+1.f, +0.f, +0.f).dot(math::vector3f(+1.f, +0.f, +0.f)), +1.f);
    EXPECT_EQ(math::vector3f(+1.f, +0.f, +0.f).dot(math::vector3f(-1.f, +0.f, +0.f)), -1.f);
    EXPECT_EQ(math::vector3f(+1.f, +0.f, +0.f).dot(math::vector3f(+0.f, +1.f, +0.f)), +0.f);
    EXPECT_EQ(math::vector3f(+1.f, +0.f, +0.f).dot(math::vector3f(+0.f, -1.f, +0.f)), +0.f);
    EXPECT_EQ(math::vector3f(+1.f, +0.f, +0.f).dot(math::vector3f(+0.f, +0.f, +1.f)), +0.f);
    EXPECT_EQ(math::vector3f(+1.f, +0.f, +0.f).dot(math::vector3f(+0.f, +0.f, -1.f)), +0.f);

    EXPECT_EQ(math::vector3f(+0.f, +1.f, +0.f).dot(math::vector3f(+0.f, +1.f, +0.f)), +1.f);
    EXPECT_EQ(math::vector3f(+0.f, +1.f, +0.f).dot(math::vector3f(+0.f, -1.f, +0.f)), -1.f);
    EXPECT_EQ(math::vector3f(+0.f, +1.f, +0.f).dot(math::vector3f(+1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::vector3f(+0.f, +1.f, +0.f).dot(math::vector3f(-1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::vector3f(+0.f, +1.f, +0.f).dot(math::vector3f(+0.f, +0.f, +1.f)), +0.f);
    EXPECT_EQ(math::vector3f(+0.f, +1.f, +0.f).dot(math::vector3f(+0.f, +0.f, -1.f)), +0.f);

    EXPECT_EQ(math::vector3f(+0.f, +0.f, +1.f).dot(math::vector3f(+0.f, +0.f, +1.f)), +1.f);
    EXPECT_EQ(math::vector3f(+0.f, +0.f, +1.f).dot(math::vector3f(+0.f, +0.f, -1.f)), -1.f);
    EXPECT_EQ(math::vector3f(+0.f, +0.f, +1.f).dot(math::vector3f(+1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::vector3f(+0.f, +0.f, +1.f).dot(math::vector3f(-1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::vector3f(+0.f, +0.f, +1.f).dot(math::vector3f(+0.f, +1.f, +0.f)), +0.f);
    EXPECT_EQ(math::vector3f(+0.f, +0.f, +1.f).dot(math::vector3f(+0.f, -1.f, +0.f)), +0.f);
   
    EXPECT_GT(math::vector3f(+3.f, +5.f, +2.f).dot(math::vector3f(+5.f, +3.f, +2.f)), 0.f);
    EXPECT_LT(math::vector3f(+3.f, +5.f, -3.f).dot(math::vector3f(-5.f, -3.f, -3.f)), 0.f);

    EXPECT_EQ(math::dot(math::vector3f(+1.f, +0.f, +0.f), math::vector3f(+1.f, +0.f, +0.f)), +1.f);
    EXPECT_EQ(math::dot(math::vector3f(+1.f, +0.f, +0.f), math::vector3f(-1.f, +0.f, +0.f)), -1.f);
    EXPECT_EQ(math::dot(math::vector3f(+1.f, +0.f, +0.f), math::vector3f(+0.f, +1.f, +0.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector3f(+1.f, +0.f, +0.f), math::vector3f(+0.f, -1.f, +0.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector3f(+1.f, +0.f, +0.f), math::vector3f(+0.f, +0.f, +1.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector3f(+1.f, +0.f, +0.f), math::vector3f(+0.f, +0.f, -1.f)), +0.f);

    EXPECT_EQ(math::dot(math::vector3f(+0.f, +1.f, +0.f), math::vector3f(+0.f, +1.f, +0.f)), +1.f);
    EXPECT_EQ(math::dot(math::vector3f(+0.f, +1.f, +0.f), math::vector3f(+0.f, -1.f, +0.f)), -1.f);
    EXPECT_EQ(math::dot(math::vector3f(+0.f, +1.f, +0.f), math::vector3f(+1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector3f(+0.f, +1.f, +0.f), math::vector3f(-1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector3f(+0.f, +1.f, +0.f), math::vector3f(+0.f, +0.f, +1.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector3f(+0.f, +1.f, +0.f), math::vector3f(+0.f, +0.f, -1.f)), +0.f);

    EXPECT_EQ(math::dot(math::vector3f(+0.f, +0.f, +1.f), math::vector3f(+0.f, +0.f, +1.f)), +1.f);
    EXPECT_EQ(math::dot(math::vector3f(+0.f, +0.f, +1.f), math::vector3f(+0.f, +0.f, -1.f)), -1.f);
    EXPECT_EQ(math::dot(math::vector3f(+0.f, +0.f, +1.f), math::vector3f(+1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector3f(+0.f, +0.f, +1.f), math::vector3f(-1.f, +0.f, +0.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector3f(+0.f, +0.f, +1.f), math::vector3f(+0.f, +1.f, +0.f)), +0.f);
    EXPECT_EQ(math::dot(math::vector3f(+0.f, +0.f, +1.f), math::vector3f(+0.f, -1.f, +0.f)), +0.f);

    EXPECT_GT(math::dot(math::vector3f(+3.f, +5.f, +2.f), math::vector3f(+5.f, +3.f, +2.f)), 0.f);
    EXPECT_LT(math::dot(math::vector3f(+3.f, +5.f, -3.f), math::vector3f(-5.f, -3.f, -3.f)), 0.f);


    EXPECT_EQ(math::vector3d(+1.0, +0.0, +0.0).dot(math::vector3d(+1.0, +0.0, +0.0)), +1.0);
    EXPECT_EQ(math::vector3d(+1.0, +0.0, +0.0).dot(math::vector3d(-1.0, +0.0, +0.0)), -1.0);
    EXPECT_EQ(math::vector3d(+1.0, +0.0, +0.0).dot(math::vector3d(+0.0, +1.0, +0.0)), +0.0);
    EXPECT_EQ(math::vector3d(+1.0, +0.0, +0.0).dot(math::vector3d(+0.0, -1.0, +0.0)), +0.0);
    EXPECT_EQ(math::vector3d(+1.0, +0.0, +0.0).dot(math::vector3d(+0.0, +0.0, +1.0)), +0.0);
    EXPECT_EQ(math::vector3d(+1.0, +0.0, +0.0).dot(math::vector3d(+0.0, +0.0, -1.0)), +0.0);

    EXPECT_EQ(math::vector3d(+0.0, +1.0, +0.0).dot(math::vector3d(+0.0, +1.0, +0.0)), +1.0);
    EXPECT_EQ(math::vector3d(+0.0, +1.0, +0.0).dot(math::vector3d(+0.0, -1.0, +0.0)), -1.0);
    EXPECT_EQ(math::vector3d(+0.0, +1.0, +0.0).dot(math::vector3d(+1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::vector3d(+0.0, +1.0, +0.0).dot(math::vector3d(-1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::vector3d(+0.0, +1.0, +0.0).dot(math::vector3d(+0.0, +0.0, +1.0)), +0.0);
    EXPECT_EQ(math::vector3d(+0.0, +1.0, +0.0).dot(math::vector3d(+0.0, +0.0, -1.0)), +0.0);

    EXPECT_EQ(math::vector3d(+0.0, +0.0, +1.0).dot(math::vector3d(+0.0, +0.0, +1.0)), +1.0);
    EXPECT_EQ(math::vector3d(+0.0, +0.0, +1.0).dot(math::vector3d(+0.0, +0.0, -1.0)), -1.0);
    EXPECT_EQ(math::vector3d(+0.0, +0.0, +1.0).dot(math::vector3d(+1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::vector3d(+0.0, +0.0, +1.0).dot(math::vector3d(-1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::vector3d(+0.0, +0.0, +1.0).dot(math::vector3d(+0.0, +1.0, +0.0)), +0.0);
    EXPECT_EQ(math::vector3d(+0.0, +0.0, +1.0).dot(math::vector3d(+0.0, -1.0, +0.0)), +0.0);

    EXPECT_GT(math::vector3d(+3.0, +5.0, +2.0).dot(math::vector3d(+5.0, +3.0, +2.0)), 0.0);
    EXPECT_LT(math::vector3d(+3.0, +5.0, -3.0).dot(math::vector3d(-5.0, -3.0, -3.0)), 0.0);


    EXPECT_EQ(math::dot(math::vector3d(+1.0, +0.0, +0.0), math::vector3d(+1.0, +0.0, +0.0)), +1.0);
    EXPECT_EQ(math::dot(math::vector3d(+1.0, +0.0, +0.0), math::vector3d(-1.0, +0.0, +0.0)), -1.0);
    EXPECT_EQ(math::dot(math::vector3d(+1.0, +0.0, +0.0), math::vector3d(+0.0, +1.0, +0.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector3d(+1.0, +0.0, +0.0), math::vector3d(+0.0, -1.0, +0.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector3d(+1.0, +0.0, +0.0), math::vector3d(+0.0, +0.0, +1.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector3d(+1.0, +0.0, +0.0), math::vector3d(+0.0, +0.0, -1.0)), +0.0);

    EXPECT_EQ(math::dot(math::vector3d(+0.0, +1.0, +0.0), math::vector3d(+0.0, +1.0, +0.0)), +1.0);
    EXPECT_EQ(math::dot(math::vector3d(+0.0, +1.0, +0.0), math::vector3d(+0.0, -1.0, +0.0)), -1.0);
    EXPECT_EQ(math::dot(math::vector3d(+0.0, +1.0, +0.0), math::vector3d(+1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector3d(+0.0, +1.0, +0.0), math::vector3d(-1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector3d(+0.0, +1.0, +0.0), math::vector3d(+0.0, +0.0, +1.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector3d(+0.0, +1.0, +0.0), math::vector3d(+0.0, +0.0, -1.0)), +0.0);

    EXPECT_EQ(math::dot(math::vector3d(+0.0, +0.0, +1.0), math::vector3d(+0.0, +0.0, +1.0)), +1.0);
    EXPECT_EQ(math::dot(math::vector3d(+0.0, +0.0, +1.0), math::vector3d(+0.0, +0.0, -1.0)), -1.0);
    EXPECT_EQ(math::dot(math::vector3d(+0.0, +0.0, +1.0), math::vector3d(+1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector3d(+0.0, +0.0, +1.0), math::vector3d(-1.0, +0.0, +0.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector3d(+0.0, +0.0, +1.0), math::vector3d(+0.0, +1.0, +0.0)), +0.0);
    EXPECT_EQ(math::dot(math::vector3d(+0.0, +0.0, +1.0), math::vector3d(+0.0, -1.0, +0.0)), +0.0);

    EXPECT_GT(math::dot(math::vector3d(+3.0, +5.0, +2.0), math::vector3d(+5.0, +3.0, +2.0)), 0.0);
    EXPECT_LT(math::dot(math::vector3d(+3.0, +5.0, -3.0), math::vector3d(-5.0, -3.0, -3.0)), 0.0);
}

TEST(VectorAlgebra3D, PlusMinusVector) {
    EXPECT_EQ(math::vector3f(0.f) + math::vector3f(1.f), math::vector3f(1.f));
    EXPECT_EQ(math::vector3f(1.f, 2.f, 3.f) + math::vector3f(3.f, 2.f, 1.f), math::vector3f(4.f));

    EXPECT_EQ(math::vector3d(0.0) + math::vector3d(1.0), math::vector3d(1.0));
    EXPECT_EQ(math::vector3d(1.0, 2.0, 3.0) + math::vector3d(3.0, 2.0, 1.0), math::vector3d(4.0));
}

TEST(VectorAlgebra3D, PlusMinusScalar) {
    EXPECT_EQ(math::vector3f(0.f) + 1.f, math::vector3f(1.f));
    EXPECT_EQ(math::vector3f(1.f, 2.f, 3.f) - 2.f, math::vector3f(-1.f, 0.f, 1.f));

    EXPECT_EQ(math::vector3d(0.0) + 1.0, math::vector3d(1.0));
    EXPECT_EQ(math::vector3d(1.0, 2.0, 3.0) - 2.0, math::vector3d(-1.0, 0.0, 1.0));
}

TEST(VectorAlgebra3D, MultiplyScalar) {
    EXPECT_EQ(math::vector3f(0.f) * 1.f, math::vector3f(0.f));
    EXPECT_EQ(math::vector3f(1.f, 2.f, 3.f) * 2.f, math::vector3f(2.f, 4.f, 6.f));
    EXPECT_EQ(math::vector3f(1.f, 2.f, 3.f) / 2.f, math::vector3f(.5f, 1.f, 1.5f));

    EXPECT_EQ(math::vector3d(0.0) * 1.0, math::vector3d(0.0));
    EXPECT_EQ(math::vector3d(1.0, 2.0, 3.0) * 2.0, math::vector3d(2.0, 4.0, 6.0));
    EXPECT_EQ(math::vector3d(1.0, 2.0, 3.0) / 2.0, math::vector3d(.5f, 1.0, 1.5));
}

TEST(VectorAlgebra3D, CrossProduct) {
    EXPECT_EQ(math::vector3f::X.cross(math::vector3f::Y), math::vector3f::Z);
    EXPECT_EQ(math::vector3f::Y.cross(math::vector3f::Z), math::vector3f::X);
    EXPECT_EQ(math::vector3f::Z.cross(math::vector3f::X), math::vector3f::Y);
    EXPECT_EQ(math::vector3f::Y.cross(math::vector3f::X), -math::vector3f::Z);
    EXPECT_EQ(math::vector3f::Z.cross(math::vector3f::Y), -math::vector3f::X);
    EXPECT_EQ(math::vector3f::X.cross(math::vector3f::Z), -math::vector3f::Y);
    
    EXPECT_EQ(math::cross(math::vector3f::X, math::vector3f::Y), math::vector3f::Z);
    EXPECT_EQ(math::cross(math::vector3f::Y, math::vector3f::Z), math::vector3f::X);
    EXPECT_EQ(math::cross(math::vector3f::Z, math::vector3f::X), math::vector3f::Y);
    EXPECT_EQ(math::cross(math::vector3f::Y, math::vector3f::X), -math::vector3f::Z);
    EXPECT_EQ(math::cross(math::vector3f::Z, math::vector3f::Y), -math::vector3f::X);
    EXPECT_EQ(math::cross(math::vector3f::X, math::vector3f::Z), -math::vector3f::Y);

    EXPECT_EQ(math::normalized(math::vector3f(1.f, 0.f, 0.f).cross(math::vector3f(0.5f, 10.f, 0.0))), math::vector3f::Z);
    EXPECT_EQ(math::normalized(math::vector3f(0.5f, 10.f, 0.0).cross(math::vector3f(1.f, 0.f, 0.f))), -math::vector3f::Z);
    EXPECT_EQ(math::normalized(math::vector3f(0.f, 1.f, 0.f).cross(math::vector3f(0.f, 0.5f, 10.f))), math::vector3f::X);
    EXPECT_EQ(math::normalized(math::vector3f(0.f, 0.5f, 10.f).cross(math::vector3f(0.f, 1.f, 0.f))), -math::vector3f::X);
    EXPECT_EQ(math::normalized(math::vector3f(0.f, 0.f, 1.f).cross(math::vector3f(0.5f, 0.0, 10.f))), math::vector3f::Y);
    EXPECT_EQ(math::normalized(math::vector3f(0.5f, 0.0, 10.f).cross(math::vector3f(0.f, 0.f, 1.f))), -math::vector3f::Y);

    EXPECT_EQ(math::normalized(math::cross(math::vector3f(1.f, 0.f, 0.f), math::vector3f(0.5f, 10.f, 0.0))), math::vector3f::Z);
    EXPECT_EQ(math::normalized(math::cross(math::vector3f(0.5f, 10.f, 0.0), math::vector3f(1.f, 0.f, 0.f))), -math::vector3f::Z);
    EXPECT_EQ(math::normalized(math::cross(math::vector3f(0.f, 1.f, 0.f), math::vector3f(0.f, 0.5f, 10.f))), math::vector3f::X);
    EXPECT_EQ(math::normalized(math::cross(math::vector3f(0.f, 0.5f, 10.f), math::vector3f(0.f, 1.f, 0.f))), -math::vector3f::X);
    EXPECT_EQ(math::normalized(math::cross(math::vector3f(0.f, 0.f, 1.f), math::vector3f(0.5f, 0.0, 10.f))), math::vector3f::Y);
    EXPECT_EQ(math::normalized(math::cross(math::vector3f(0.5f, 0.0, 10.f), math::vector3f(0.f, 0.f, 1.f))), -math::vector3f::Y);


    EXPECT_EQ(math::vector3d::X.cross(math::vector3d::Y), math::vector3d::Z);
    EXPECT_EQ(math::vector3d::Y.cross(math::vector3d::Z), math::vector3d::X);
    EXPECT_EQ(math::vector3d::Z.cross(math::vector3d::X), math::vector3d::Y);
    EXPECT_EQ(math::vector3d::Y.cross(math::vector3d::X), -math::vector3d::Z);
    EXPECT_EQ(math::vector3d::Z.cross(math::vector3d::Y), -math::vector3d::X);
    EXPECT_EQ(math::vector3d::X.cross(math::vector3d::Z), -math::vector3d::Y);
    
    EXPECT_EQ(math::cross(math::vector3d::X, math::vector3d::Y), math::vector3d::Z);
    EXPECT_EQ(math::cross(math::vector3d::Y, math::vector3d::Z), math::vector3d::X);
    EXPECT_EQ(math::cross(math::vector3d::Z, math::vector3d::X), math::vector3d::Y);
    EXPECT_EQ(math::cross(math::vector3d::Y, math::vector3d::X), -math::vector3d::Z);
    EXPECT_EQ(math::cross(math::vector3d::Z, math::vector3d::Y), -math::vector3d::X);
    EXPECT_EQ(math::cross(math::vector3d::X, math::vector3d::Z), -math::vector3d::Y);

    EXPECT_EQ(math::normalized(math::vector3d(1.0, 0.0, 0.0).cross(math::vector3d(0.5, 10.0, 0.0))), math::vector3d::Z);
    EXPECT_EQ(math::normalized(math::vector3d(0.5, 10.0, 0.0).cross(math::vector3d(1.0, 0.0, 0.0))), -math::vector3d::Z);
    EXPECT_EQ(math::normalized(math::vector3d(0.0, 1.0, 0.0).cross(math::vector3d(0.0, 0.5, 10.0))), math::vector3d::X);
    EXPECT_EQ(math::normalized(math::vector3d(0.0, 0.5, 10.0).cross(math::vector3d(0.0, 1.0, 0.0))), -math::vector3d::X);
    EXPECT_EQ(math::normalized(math::vector3d(0.0, 0.0, 1.0).cross(math::vector3d(0.5f, 0.0, 10.0))), math::vector3d::Y);
    EXPECT_EQ(math::normalized(math::vector3d(0.5, 0.0, 10.0).cross(math::vector3d(0.0, 0.0, 1.0))), -math::vector3d::Y);

    EXPECT_EQ(math::normalized(math::cross(math::vector3d(1.0, 0.0, 0.0), math::vector3d(0.5, 10.0, 0.0))), math::vector3d::Z);
    EXPECT_EQ(math::normalized(math::cross(math::vector3d(0.5, 10.0, 0.0), math::vector3d(1.0, 0.0, 0.0))), -math::vector3d::Z);
    EXPECT_EQ(math::normalized(math::cross(math::vector3d(0.0, 1.0, 0.0), math::vector3d(0.0, 0.5, 10.0))), math::vector3d::X);
    EXPECT_EQ(math::normalized(math::cross(math::vector3d(0.0, 0.5, 10.0), math::vector3d(0.0, 1.0, 0.0))), -math::vector3d::X);
    EXPECT_EQ(math::normalized(math::cross(math::vector3d(0.0, 0.0, 1.0), math::vector3d(0.5, 0.0, 10.0))), math::vector3d::Y);
    EXPECT_EQ(math::normalized(math::cross(math::vector3d(0.5, 0.0, 10.0), math::vector3d(0.0, 0.0, 1.0))), -math::vector3d::Y);
}
