#include "pch.h"
#include <math/src/utils.h>
#include <math/src/vector2.h>

TEST(VectorAlgebra2D, Construction) 
{
    {
        math::vector2f v0;
        EXPECT_EQ(v0.x(), v0.r());
        EXPECT_EQ(v0.y(), v0.g());
        EXPECT_EQ(v0.x(), v0.y());
        EXPECT_EQ(v0.r(), v0.g());
        EXPECT_EQ(v0.x(), 0.f);
        EXPECT_EQ(v0.r(), 0.f);
        EXPECT_EQ(v0.y(), 0.f);
        EXPECT_EQ(v0.g(), 0.f);


        v0 = math::vector2f(1.f);
        EXPECT_EQ(v0.x(), 1.f);
        EXPECT_EQ(v0.r(), 1.f);
        EXPECT_EQ(v0.y(), 1.f);
        EXPECT_EQ(v0.g(), 1.f);

        v0 = math::vector2f(3.f, 10.f);
        EXPECT_EQ(v0.x(), 3.f);
        EXPECT_EQ(v0.r(), 3.f);
        EXPECT_EQ(v0.y(), 10.f);
        EXPECT_EQ(v0.g(), 10.f);

        math::vector2f v1(v0);
        EXPECT_EQ(v0, v1);
        EXPECT_FALSE(v0 != v1); 
    }
    {
        math::vector2d v0;
        EXPECT_EQ(v0.x(), v0.r());
        EXPECT_EQ(v0.y(), v0.g());
        EXPECT_EQ(v0.x(), v0.y());
        EXPECT_EQ(v0.r(), v0.g());
        EXPECT_EQ(v0.x(), 0.0);
        EXPECT_EQ(v0.r(), 0.0);
        EXPECT_EQ(v0.y(), 0.0);
        EXPECT_EQ(v0.g(), 0.0);


        v0 = math::vector2d(1.0);
        EXPECT_EQ(v0.x(), 1.0);
        EXPECT_EQ(v0.r(), 1.0);
        EXPECT_EQ(v0.y(), 1.0);
        EXPECT_EQ(v0.g(), 1.0);

        v0 = math::vector2d(3.0, 10.0);
        EXPECT_EQ(v0.x(), 3.0);
        EXPECT_EQ(v0.r(), 3.0);
        EXPECT_EQ(v0.y(), 10.0);
        EXPECT_EQ(v0.g(), 10.0);

        math::vector2d v1(v0);
        EXPECT_EQ(v0, v1);
        EXPECT_FALSE(v0 != v1); 
    }
}

TEST(VectorAlgebra2D, Equality) {
    EXPECT_EQ(math::vector2f(0), math::vector2f(0));
    EXPECT_EQ(math::vector2d(0), math::vector2d(0));
}

TEST(VectorAlgebra2D, InEquality) {
    EXPECT_NE(math::vector2f(0.f),math::vector2f(1.f));
    EXPECT_NE(math::vector2d(0), math::vector2d(1));
}

TEST(VectorAlgebra2D, Length) {
    EXPECT_EQ(math::vector2f( 1.f, 0.f).length(), sqrt(std::pow( 1.f, 2.f)));
    EXPECT_EQ(math::vector2f(-1.f, 0.f).length(), sqrt(std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector2d( 1.0, 0.0).length(), sqrt(std::pow( 1.0, 2.0)));
    EXPECT_EQ(math::vector2d(-1.0, 0.0).length(), sqrt(std::pow(-1.0, 2.0)));
    
    EXPECT_EQ(math::vector2f( 0.f,  1.f).length(), sqrt(std::pow( 1.f, 2.f)));
    EXPECT_EQ(math::vector2f( 0.f, -1.f).length(), sqrt(std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector2d( 0.0,  1.0).length(), sqrt(std::pow( 1.0, 2.0)));
    EXPECT_EQ(math::vector2d( 0.0, -1.0).length(), sqrt(std::pow(-1.0, 2.0)));
    
    EXPECT_EQ(math::vector2f( 1.f,  1.f).length(), sqrt(std::pow( 1.f, 2.f) + std::pow( 1.f, 2.f)));
    EXPECT_EQ(math::vector2f(-1.f,  1.f).length(), sqrt(std::pow(-1.f, 2.f) + std::pow( 1.f, 2.f)));
    EXPECT_EQ(math::vector2f( 1.f, -1.f).length(), sqrt(std::pow( 1.f, 2.f) + std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector2f(-1.f, -1.0).length(), sqrt(std::pow(-1.f, 2.f) + std::pow(-1.f, 2.f)));
    EXPECT_EQ(math::vector2d( 1.0,  1.0).length(), sqrt(std::pow( 1.0, 2.0) + std::pow( 1.0, 2.0)));
    EXPECT_EQ(math::vector2d(-1.0,  1.0).length(), sqrt(std::pow(-1.0, 2.0) + std::pow( 1.0, 2.0)));
    EXPECT_EQ(math::vector2d( 1.0, -1.0).length(), sqrt(std::pow( 1.0, 2.0) + std::pow(-1.0, 2.0)));
    EXPECT_EQ(math::vector2d(-1.0, -1.0).length(), sqrt(std::pow(-1.0, 2.0) + std::pow(-1.0, 2.0)));

    EXPECT_EQ(math::vector2f( 3.f,  5.f).length(), sqrt(std::pow( 3.f, 2.f) + std::pow( 5.f, 2.f)));
    EXPECT_EQ(math::vector2f(-3.f,  5.f).length(), sqrt(std::pow(-3.f, 2.f) + std::pow( 5.f, 2.f)));
    EXPECT_EQ(math::vector2f( 3.f, -5.f).length(), sqrt(std::pow( 3.f, 2.f) + std::pow(-5.f, 2.f)));
    EXPECT_EQ(math::vector2f(-3.f, -5.f).length(), sqrt(std::pow(-3.f, 2.f) + std::pow(-5.f, 2.f)));
    
    EXPECT_EQ(math::vector2d( 3.0, -5.0).length(), sqrt(std::pow( 3.0, 2.0) + std::pow( 5.f, 2.f)));
    EXPECT_EQ(math::vector2d(-3.0,  5.0).length(), sqrt(std::pow(-3.0, 2.0) + std::pow( 5.f, 2.0)));
    EXPECT_EQ(math::vector2d( 3.0, -5.0).length(), sqrt(std::pow( 3.0, 2.0) + std::pow(-5.f, 2.f)));
    EXPECT_EQ(math::vector2d(-3.0, -5.0).length(), sqrt(std::pow(-3.0, 2.0) + std::pow(-5.f, 2.0)));

    EXPECT_EQ(math::length(math::vector2d( 3.0, -5.0)), math::vector2d(3.0, -5.0).length());
    EXPECT_EQ(math::length(math::vector2d(-3.0, 5.0)),  math::vector2d(-3.0, 5.0).length());
    EXPECT_EQ(math::length(math::vector2d( 3.0, -5.0)), math::vector2d(3.0, -5.0).length());
    EXPECT_EQ(math::length(math::vector2d(-3.0, -5.0)), math::vector2d(-3.0, -5.0).length());
}

TEST(VectorAlgebra2D, Normalization) {
    {
        constexpr float x = -3.f, y = -5.f;
        EXPECT_TRUE(math::vector2f(x, y).normalize().is_unit());
        EXPECT_TRUE(math::is_unit(math::vector2f(x, y).normalize()));
        EXPECT_EQ(math::normalized(math::vector2f(x, y)), math::vector2f(x, y).normalize());
    }
    {
        constexpr double x = -3.f, y = -5.f;
        EXPECT_TRUE(math::vector2d(x, y).normalize().is_unit());
        EXPECT_TRUE(math::is_unit(math::vector2d(x, y).normalize()));
        EXPECT_EQ(math::normalized(math::vector2d(x, y)), math::vector2d(x, y).normalize());
    }
}

TEST(VectorAlgebra2D, DotProduct) {
    EXPECT_EQ(math::vector2f(+1.f, 0.f).dot(math::vector2f( 0.f, 1.f)), 0.f);
    EXPECT_EQ(math::vector2f(+1.f, 0.f).dot(math::vector2f( 0.f,-1.f)), 0.f);
    EXPECT_EQ(math::vector2f( 0.f, 1.f).dot(math::vector2f(+1.f, 0.f)), 0.f);
    EXPECT_EQ(math::vector2f( 0.f, 1.f).dot(math::vector2f(-1.f, 0.f)), 0.f);
    EXPECT_EQ(math::vector2f(+1.f, 0.f).dot(math::vector2f(-1.f, 0.f)),-1.0f);
    EXPECT_EQ(math::vector2f( 0.f,+1.f).dot(math::vector2f( 0.f,-1.f)),-1.0f);
    EXPECT_EQ(math::vector2f(+1.f, 0.f).dot(math::vector2f(+1.f, 0.f)), 1.0f);
    EXPECT_EQ(math::vector2f( 0.f,+1.f).dot(math::vector2f( 0.f,+1.f)), 1.0f);
    EXPECT_GT(math::vector2f(+3.f,+5.f).dot(math::vector2f(+5.f,+3.f)), 0.f);
    EXPECT_LT(math::vector2f(+3.f,+5.f).dot(math::vector2f(-5.f,-3.f)), 0.f);

    EXPECT_EQ(math::dot(math::vector2f(+1.f, 0.f), math::vector2f(0.f, 1.f)), 0.f);
    EXPECT_EQ(math::dot(math::vector2f(+1.f, 0.f), math::vector2f(0.f, -1.f)), 0.f);
    EXPECT_EQ(math::dot(math::vector2f(0.f, 1.f), math::vector2f(+1.f, 0.f)), 0.f);
    EXPECT_EQ(math::dot(math::vector2f(0.f, 1.f), math::vector2f(-1.f, 0.f)), 0.f);
    EXPECT_EQ(math::dot(math::vector2f(+1.f, 0.f), math::vector2f(-1.f, 0.f)), -1.0f);
    EXPECT_EQ(math::dot(math::vector2f(0.f, +1.f), math::vector2f(0.f, -1.f)), -1.0f);
    EXPECT_EQ(math::dot(math::vector2f(+1.f, 0.f), math::vector2f(+1.f, 0.f)), 1.0f);
    EXPECT_EQ(math::dot(math::vector2f(0.f, +1.f), math::vector2f(0.f, +1.f)), 1.0f);
    EXPECT_GT(math::dot(math::vector2f(+3.f, +5.f), math::vector2f(+5.f, +3.f)), 0.f);
    EXPECT_LT(math::dot(math::vector2f(+3.f, +5.f), math::vector2f(-5.f, -3.f)), 0.f);

    EXPECT_EQ(math::vector2d(+1.0, 0.0).dot(math::vector2d(0.0, 1.0)), 0.0);
    EXPECT_EQ(math::vector2d(+1.0, 0.0).dot(math::vector2d(0.0, -1.0)), 0.0);
    EXPECT_EQ(math::vector2d(0.0, 1.0).dot(math::vector2d(+1.0, 0.0)), 0.0);
    EXPECT_EQ(math::vector2d(0.0, 1.0).dot(math::vector2d(-1.0, 0.0)), 0.0);
    EXPECT_EQ(math::vector2d(+1.0, 0.0).dot(math::vector2d(-1.0, 0.0)), -1.0);
    EXPECT_EQ(math::vector2d(0.0, +1.0).dot(math::vector2d(0.0, -1.0)), -1.0);
    EXPECT_EQ(math::vector2d(+1.0, 0.0).dot(math::vector2d(+1.0, 0.0)), 1.0);
    EXPECT_EQ(math::vector2d(0.0, +1.0).dot(math::vector2d(0.0, +1.0)), 1.0);
    EXPECT_GT(math::vector2d(+3.0, +5.0).dot(math::vector2d(+5.0, +3.0)), 0.0);
    EXPECT_LT(math::vector2d(+3.0, +5.0).dot(math::vector2d(-5.0, -3.0)), 0.0);

    EXPECT_EQ(math::dot(math::vector2d(+1.0, 0.0), math::vector2d(0.0, 1.0)), 0.0);
    EXPECT_EQ(math::dot(math::vector2d(+1.0, 0.0), math::vector2d(0.0, -1.0)), 0.0);
    EXPECT_EQ(math::dot(math::vector2d(0.0, 1.0), math::vector2d(+1.0, 0.0)), 0.0);
    EXPECT_EQ(math::dot(math::vector2d(0.0, 1.0), math::vector2d(-1.0, 0.0)), 0.0);
    EXPECT_EQ(math::dot(math::vector2d(+1.0, 0.0), math::vector2d(-1.0, 0.0)), -1.0);
    EXPECT_EQ(math::dot(math::vector2d(0.0, +1.0), math::vector2d(0.0, -1.0)), -1.0);
    EXPECT_EQ(math::dot(math::vector2d(+1.0, 0.0), math::vector2d(+1.0, 0.0)), 1.0);
    EXPECT_EQ(math::dot(math::vector2d(0.0, +1.0), math::vector2d(0.0, +1.0)), 1.0);
    EXPECT_GT(math::dot(math::vector2d(+3.0, +5.0), math::vector2d(+5.0, +3.0)), 0.0);
    EXPECT_LT(math::dot(math::vector2d(+3.0, +5.0), math::vector2d(-5.0, -3.0)), 0.0);
}

TEST(VectorAlgebra2D, PlusMinusVector) {
    EXPECT_EQ(math::vector2f(0.f) + math::vector2f(1.f), math::vector2f(1.f));
    EXPECT_EQ(math::vector2f(1.f, 2.f) + math::vector2f(2.f, 1.f), math::vector2f(3.f));

    EXPECT_EQ(math::vector2d(0.0) + math::vector2d(1.0), math::vector2d(1.0));
    EXPECT_EQ(math::vector2d(1.0, 2.0) + math::vector2d(2.0, 1.0), math::vector2d(3.0));
}

TEST(VectorAlgebra2D, MultiplyScalar) {
    EXPECT_EQ(math::vector2f(0.f) * 1.f, math::vector2f(0.f));
    EXPECT_EQ(math::vector2f(1.f, 2.f) * 2.f, math::vector2f(2.f, 4.f));
    EXPECT_EQ(math::vector2f(1.f, 2.f) / 2.f, math::vector2f(.5f, 1.f));

    EXPECT_EQ(math::vector2f(0.0) * 1.0, math::vector2f(0.0));
    EXPECT_EQ(math::vector2f(1.0, 2.0) * 2.0, math::vector2f(2.0, 4.0));
    EXPECT_EQ(math::vector2f(1.0, 2.0) / 2.0, math::vector2f(.5, 1.0));
}