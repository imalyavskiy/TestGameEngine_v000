#include "pch.h"
#include <math/src/utils.h>
#include <math/src/vector2.h>
#include <math/src/vector3.h>
#include <math/src/vector4.h>
#include <math/src/matrix4.h>

TEST(MatrixAlgebra4D, DefaultConstructionFloat)
{
    const math::matrix4f matrix;

    auto [r0, r1, r2, r3] = matrix.rows();
    EXPECT_EQ(r0, math::vector4f(1.f, 0.f, 0.f, 0.f));
    EXPECT_EQ(r1, math::vector4f(0.f, 1.f, 0.f, 0.f));
    EXPECT_EQ(r2, math::vector4f(0.f, 0.f, 1.f, 0.f));
    EXPECT_EQ(r3, math::vector4f(0.f, 0.f, 0.f, 1.f));

    auto [c0, c1, c2, c3] = matrix.columns();
    EXPECT_EQ(c0, math::vector4f(1.f, 0.f, 0.f, 0.f));
    EXPECT_EQ(c1, math::vector4f(0.f, 1.f, 0.f, 0.f));
    EXPECT_EQ(c2, math::vector4f(0.f, 0.f, 1.f, 0.f));
    EXPECT_EQ(c3, math::vector4f(0.f, 0.f, 0.f, 1.f));

    EXPECT_EQ(math::matrix4f::identity(), math::matrix4f(1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f));
    EXPECT_EQ(math::matrix4f::zero(), math::matrix4f(0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f));

    EXPECT_EQ(math::matrix4f::zero(), math::matrix4f(0.f));
    EXPECT_EQ(math::matrix4f(5.f), math::matrix4f(5.f));
}

TEST(MatrixAlgebra4D, DefaultConstructionDouble)
{
    const math::matrix4d matrix;

    auto [r0, r1, r2, r3] = matrix.rows();
    EXPECT_EQ(r0, math::vector4d(1.0, 0.0, 0.0, 0.0));
    EXPECT_EQ(r1, math::vector4d(0.0, 1.0, 0.0, 0.0));
    EXPECT_EQ(r2, math::vector4d(0.0, 0.0, 1.0, 0.0));
    EXPECT_EQ(r3, math::vector4d(0.0, 0.0, 0.0, 1.0));

    auto [c0, c1, c2, c3] = matrix.columns();
    EXPECT_EQ(c0, math::vector4d(1.0, 0.0, 0.0, 0.0));
    EXPECT_EQ(c1, math::vector4d(0.0, 1.0, 0.0, 0.0));
    EXPECT_EQ(c2, math::vector4d(0.0, 0.0, 1.0, 0.0));
    EXPECT_EQ(c3, math::vector4d(0.0, 0.0, 0.0, 1.0));

    EXPECT_EQ(math::matrix4d::identity(), math::matrix4d(1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0));
    EXPECT_EQ(math::matrix4d::zero(), math::matrix4d(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

    EXPECT_EQ(math::matrix4d::zero(), math::matrix4d(0.0));
    EXPECT_EQ(math::matrix4d(5.0), math::matrix4d(5.0));

}

TEST(MatrixAlgebra4D, ParametrizedConstructionFloat)
{
    const math::matrix4f matrix{
        1.f, 2.f, 3.f, 4.f,
        5.f, 6.f, 7.f, 8.f,
        9.f, 8.f, 7.f, 6.f,
        5.f, 4.f, 3.f, 2.f,
    };

    auto [r0, r1, r2, r3] = matrix.rows();
    EXPECT_EQ(r0, math::vector4f(1.f, 2.f, 3.f, 4.f));
    EXPECT_EQ(r1, math::vector4f(5.f, 6.f, 7.f, 8.f));
    EXPECT_EQ(r2, math::vector4f(9.f, 8.f, 7.f, 6.f));
    EXPECT_EQ(r3, math::vector4f(5.f, 4.f, 3.f, 2.f));

    auto [c0, c1, c2, c3] = matrix.columns();
    EXPECT_EQ(c0, math::vector4f(1.f, 5.f, 9.f, 5.f));
    EXPECT_EQ(c1, math::vector4f(2.f, 6.f, 8.f, 4.f));
    EXPECT_EQ(c2, math::vector4f(3.f, 7.f, 7.f, 3.f));
    EXPECT_EQ(c3, math::vector4f(4.f, 8.f, 6.f, 2.f));
}

TEST(MatrixAlgebra4D, ParametrizedConstructionDouble)
{
    const math::matrix4d matrix{
        1.0, 2.0, 3.0, 4.0,
        5.0, 6.0, 7.0, 8.0,
        9.0, 8.0, 7.0, 6.0,
        5.0, 4.0, 3.0, 2.0,
    };

    auto [r0, r1, r2, r3] = matrix.rows();
    EXPECT_EQ(r0, math::vector4d(1.0, 2.0, 3.0, 4.0));
    EXPECT_EQ(r1, math::vector4d(5.0, 6.0, 7.0, 8.0));
    EXPECT_EQ(r2, math::vector4d(9.0, 8.0, 7.0, 6.0));
    EXPECT_EQ(r3, math::vector4d(5.0, 4.0, 3.0, 2.0));

    auto [c0, c1, c2, c3] = matrix.columns();
    EXPECT_EQ(c0, math::vector4d(1.0, 5.0, 9.0, 5.0));
    EXPECT_EQ(c1, math::vector4d(2.0, 6.0, 8.0, 4.0));
    EXPECT_EQ(c2, math::vector4d(3.0, 7.0, 7.0, 3.0));
    EXPECT_EQ(c3, math::vector4d(4.0, 8.0, 6.0, 2.0));
}

TEST(MatrixAlgebra4D, CopyConstructionFloat)
{
    const math::matrix4f matrix3f_orig{
        1.f, 2.f, 3.f, 4.f,
        5.f, 6.f, 7.f, 8.f,
        9.f, 8.f, 7.f, 6.f,
        5.f, 4.f, 3.f, 2.f,
    };

    const math::matrix4f matrix3f_copy(matrix3f_orig);

    auto [r0_orig, r1_orig, r2_orig, r3_orig] = matrix3f_orig.rows();
    auto [r0_copy, r1_copy, r2_copy, r3_copy] = matrix3f_copy.rows();
    EXPECT_EQ(r0_orig, r0_copy);
    EXPECT_EQ(r1_orig, r1_copy);
    EXPECT_EQ(r2_orig, r2_copy);
    EXPECT_EQ(r3_orig, r3_copy);

    auto [c0_orig, c1_orig, c2_orig, c3_orig] = matrix3f_orig.columns();
    auto [c0_copy, c1_copy, c2_copy, c3_copy] = matrix3f_copy.columns();
    EXPECT_EQ(c0_orig, c0_copy);
    EXPECT_EQ(c1_orig, c1_copy);
    EXPECT_EQ(c2_orig, c2_copy);
    EXPECT_EQ(c3_orig, c3_copy);
}

TEST(MatrixAlgebra4D, CopyConstructionDouble)
{
    const math::matrix4d matrix3d_orig {
        1.0, 2.0, 3.0, 4.0,
        5.0, 6.0, 7.0, 8.0,
        9.0, 8.0, 7.0, 6.0,
        5.0, 4.0, 3.0, 2.0,
    };

    const math::matrix4d matrix3d_copy(matrix3d_orig);

    auto [r0_orig, r1_orig, r2_orig, r3_orig] = matrix3d_orig.rows();
    auto [r0_copy, r1_copy, r2_copy, r3_copy] = matrix3d_copy.rows();
    EXPECT_EQ(r0_orig, r0_copy);
    EXPECT_EQ(r1_orig, r1_copy);
    EXPECT_EQ(r2_orig, r2_copy);
    EXPECT_EQ(r3_orig, r3_copy);

    auto [c0_orig, c1_orig, c2_orig, c3_orig] = matrix3d_orig.columns();
    auto [c0_copy, c1_copy, c2_copy, c3_copy] = matrix3d_copy.columns();
    EXPECT_EQ(c0_orig, c0_copy);
    EXPECT_EQ(c1_orig, c1_copy);
    EXPECT_EQ(c2_orig, c2_copy);
    EXPECT_EQ(c3_orig, c3_copy);
}

TEST(MatrixAlgebra4D, EqualityFloat)
{
    EXPECT_TRUE(math::matrix4f() == math::matrix4f());
    EXPECT_FALSE(math::matrix4f() != math::matrix4f());
}

TEST(MatrixAlgebra4D, EqualityDouble)
{
    EXPECT_TRUE(math::matrix4d() == math::matrix4d());
    EXPECT_FALSE(math::matrix4d() != math::matrix4d());
}

TEST(MatrixAlgebra4D, LinearOperationsFloat)
{
    const math::matrix4f matrix1{
        1.f, 2.f, 3.f, 4.f,
        5.f, 6.f, 7.f, 8.f,
        9.f, 8.f, 7.f, 6.f,
        5.f, 4.f, 3.f, 2.f,
    };
    const math::matrix4f matrix2{
        2.f, 3.f, 4.f, 5.f,
        6.f, 7.f, 8.f, 9.f,
        8.f, 7.f, 6.f, 5.f,
        4.f, 3.f, 2.f, 1.f
    };
    const math::matrix4f matrix3{
         3.f,  5.f,  7.f,  9.f,
        11.f, 13.f, 15.f, 17.f,
        17.f, 15.f, 13.f, 11.f,
         9.f,  7.f,  5.f,  3.f,
    };

    EXPECT_EQ(matrix1 + matrix2, matrix3);
    EXPECT_EQ(matrix3 - matrix1, matrix2);
    EXPECT_EQ(matrix3 - matrix2, matrix1);

    const math::matrix4f matrix4(2.f);
    EXPECT_EQ(matrix4 * 2.f, math::matrix4f(4.f));
    EXPECT_EQ(2.f * matrix4, math::matrix4f(4.f));
    EXPECT_EQ(matrix4 / 2.f, math::matrix4f(1.f));
    EXPECT_EQ(matrix4 + math::matrix4f::zero(), matrix4);
    EXPECT_EQ(-matrix4, math::matrix4f(-2.f));
    EXPECT_EQ(matrix4 - matrix4, math::matrix4f::zero());
}

TEST(MatrixAlgebra4D, LinearOperationsDouble)
{
    const math::matrix4d matrix1{
        1.0, 2.0, 3.0, 4.0,
        5.0, 6.0, 7.0, 8.0,
        9.0, 8.0, 7.0, 6.0,
        5.0, 4.0, 3.0, 2.0,
    };
    const math::matrix4d matrix2{
        2.0, 3.0, 4.0, 5.0,
        6.0, 7.0, 8.0, 9.0,
        8.0, 7.0, 6.0, 5.0,
        4.0, 3.0, 2.0, 1.0,
    };
    const math::matrix4d matrix3{
         3.0,  5.0,  7.0,  9.0,
        11.0, 13.0, 15.0, 17.0,
        17.0, 15.0, 13.0, 11.0,
         9.0,  7.0,  5.0,  3.0,
    };

    EXPECT_EQ(matrix1 + matrix2, matrix3);
    EXPECT_EQ(matrix3 - matrix1, matrix2);
    EXPECT_EQ(matrix3 - matrix2, matrix1);

    const math::matrix4d matrix4(2.0);
    EXPECT_EQ(matrix4 * 2.0, math::matrix4d(4.0));
    EXPECT_EQ(2.0 * matrix4, math::matrix4d(4.0));
    EXPECT_EQ(matrix4 / 2.0, math::matrix4d(1.0));
    EXPECT_EQ(matrix4 + math::matrix4d::zero(), matrix4);
    EXPECT_EQ(-matrix4, math::matrix4d(-2.0));
    EXPECT_EQ(matrix4 - matrix4, math::matrix4d::zero());
}

TEST(MatrixAlgebra4D, MultiplicationFloat)
{
    const math::matrix4f matrix1 {
        1.f, 2.f, 3.f, 4.f,  5.f, 6.f, 7.f, 8.f,
        9.f, 8.f, 7.f, 6.f,  5.f, 4.f, 3.f, 2.f
    };
    const math::matrix4f matrix2 {
        2.f, 3.f, 4.f, 5.f,  6.f, 7.f, 8.f, 9.f,
        8.f, 7.f, 6.f, 5.f,  4.f, 3.f, 2.f, 1.f,
    };
    const math::matrix4f matrix3 {
        4.f, 5.f, 3.f, 2.f,  1.f, 6.f, 5.f, 8.f,
        7.f, 4.f, 9.f, 8.f,  7.f, 5.f, 1.f, 6.f
    };

    const math::matrix4f matrix_m1Xm2 {
         54.f,  50.f,  46.f, 42.f,   134.f, 130.f, 126.f, 122.f,
        146.f, 150.f, 154.f, 158.f,  66.f,  70.f,  74.f, 78.f,
    };
    const math::matrix4f matrix_m2Xm1 {
         78.f,  74.f,  70.f,  66.f,  158.f, 154.f, 150.f, 146.f,
        122.f, 126.f, 130.f, 134.f,   42.f,  46.f,  50.f,  54.f,
    };

    EXPECT_EQ(matrix1 * matrix2, matrix_m1Xm2);
    EXPECT_EQ(matrix2 * matrix1, matrix_m2Xm1);
    EXPECT_NE(matrix1 * matrix2, matrix2 * matrix1);
    EXPECT_EQ(matrix1 * math::matrix4f::identity(), matrix1);
    EXPECT_EQ(math::matrix4f::identity() * matrix1, matrix1);
    EXPECT_EQ(matrix1 * math::matrix4f::identity(), math::matrix4f::identity() * matrix1);

    EXPECT_EQ(-math::matrix4f::identity() * matrix1, -matrix1);

    EXPECT_EQ((matrix1 * matrix2) * 3.5f, (matrix1 * 3.5f) * matrix2);
    const math::matrix4f matrix_2Xidentity(2.f, 0.f, 0.f, 0.f, 0.f, 2.f, 0.f, 0.f, 0.f, 0.f, 2.f, 0.f, 0.f, 0.f, 0.f, 2.f);
    EXPECT_EQ(math::matrix4f::identity() * 2.f, matrix_2Xidentity);
    EXPECT_EQ(2.f * math::matrix4f::identity(), matrix_2Xidentity);
    EXPECT_EQ(3.5f * (matrix1 * matrix2), (3.5f * matrix1) * matrix2);

    EXPECT_EQ((matrix1 + matrix2) * matrix3, matrix1 * matrix3 + matrix2 * matrix3);
    EXPECT_EQ(matrix3 * (matrix1 + matrix2), matrix3 * matrix1 + matrix3 * matrix2);
}

TEST(MatrixAlgebra4D, MultiplicationDouble)
{
    const math::matrix4d matrix1{
        1.0, 2.0, 3.0, 4.0,  5.0, 6.0, 7.0, 8.0,
        9.0, 8.0, 7.0, 6.0,  5.0, 4.0, 3.0, 2.0
    };
    const math::matrix4d matrix2{
        2.0, 3.0, 4.0, 5.0,  6.0, 7.0, 8.0, 9.0,
        8.0, 7.0, 6.0, 5.0,  4.0, 3.0, 2.0, 1.0,
    };
    const math::matrix4d matrix3{
        4.0, 5.0, 3.0, 2.0,  1.0, 6.0, 5.0, 8.0,
        7.0, 4.0, 9.0, 8.0,  7.0, 5.0, 1.0, 6.0
    };

    const math::matrix4d matrix_m1Xm2{
         54.0,  50.0,  46.0, 42.0,   134.0, 130.0, 126.0, 122.0,
        146.0, 150.0, 154.0, 158.0,  66.0,  70.0,  74.0, 78.0,
    };
    const math::matrix4d matrix_m2Xm1{
         78.0,  74.0,  70.0,  66.0,  158.0, 154.0, 150.0, 146.0,
        122.0, 126.0, 130.0, 134.0,   42.0,  46.0,  50.0,  54.0,
    };

    EXPECT_EQ(matrix1 * matrix2, matrix_m1Xm2);
    EXPECT_EQ(matrix2 * matrix1, matrix_m2Xm1);
    EXPECT_NE(matrix1 * matrix2, matrix2 * matrix1);
    EXPECT_EQ(matrix1 * math::matrix4d::identity(), matrix1);
    EXPECT_EQ(math::matrix4d::identity() * matrix1, matrix1);
    EXPECT_EQ(matrix1 * math::matrix4d::identity(), math::matrix4d::identity() * matrix1);

    EXPECT_EQ(-math::matrix4d::identity() * matrix1, -matrix1);

    EXPECT_EQ((matrix1 * matrix2) * 3.5, (matrix1 * 3.5) * matrix2);
    const math::matrix4d matrix_2Xidentity(2.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 2.0);
    EXPECT_EQ(math::matrix4d::identity() * 2.0, matrix_2Xidentity);
    EXPECT_EQ(2.0 * math::matrix4d::identity(), matrix_2Xidentity);
    EXPECT_EQ(3.5 * (matrix1 * matrix2), (3.5 * matrix1) * matrix2);

    EXPECT_EQ((matrix1 + matrix2) * matrix3, matrix1 * matrix3 + matrix2 * matrix3);
    EXPECT_EQ(matrix3 * (matrix1 + matrix2), matrix3 * matrix1 + matrix3 * matrix2);

    EXPECT_EQ(matrix1 * matrix2 * matrix3, matrix1 * matrix2 * matrix3);
    EXPECT_EQ((matrix1 * matrix2) * matrix3, matrix1 * (matrix2 * matrix3));
}

TEST(MatrixAlgebra4D, DeterminantFloat)
{
    const math::matrix4f matrix1{
        +4.f, +3.f, -2.f, -1.f,
        -2.f, +1.f, -4.f, +3.f,
        +0.f, +4.f, +1.f, -2.f,
        +5.f, +0.f, +1.f, -1.f
    };

    EXPECT_EQ(matrix1.det(), 120.f);
    EXPECT_EQ(matrix1.det(), math::det(matrix1));
    EXPECT_EQ(math::det(math::matrix4f::identity()), 1.f);
    EXPECT_EQ(math::matrix4f::identity().det(), 1.f);
    EXPECT_EQ(math::det(math::matrix4f::zero()), 0.f);
    EXPECT_EQ(math::matrix4f::zero().det(), 0.f);
    EXPECT_EQ(math::det(-matrix1), std::pow(-1.f, 4.f) * math::det(matrix1));
    EXPECT_EQ(math::det(3.f * matrix1), std::pow(3.f, 4.f) * math::det(matrix1));
}

TEST(MatrixAlgebra4D, DeterminantDouble)
{
    const math::matrix4d matrix1
    {
        +4.0, +3.0, -2.0, -1.0,
        -2.0, +1.0, -4.0, +3.0,
        +0.0, +4.0, +1.0, -2.0,
        +5.0, +0.0, +1.0, -1.0
    };

    EXPECT_EQ(matrix1.det(), 120.0);
    EXPECT_EQ(matrix1.det(), math::det(matrix1));
    EXPECT_EQ(math::det(math::matrix4d::identity()), 1.0);
    EXPECT_EQ(math::matrix4d::identity().det(), 1.0);
    EXPECT_EQ(math::det(math::matrix4d::zero()), 0.0);
    EXPECT_EQ(math::matrix4d::zero().det(), 0.0);
    EXPECT_EQ(math::det(-matrix1), std::pow(-1.0, 4.0) * math::det(matrix1));
    EXPECT_EQ(math::det(3.0 * matrix1), std::pow(3.0, 4.0) * math::det(matrix1));

}

TEST(MatrixAlgebra4D, TranspositionFloat)
{
    const math::matrix4f matrix1
    {
        +4.f, +3.f, -2.f, -1.f,
        -2.f, +1.f, -4.f, +3.f,
        +0.f, +4.f, +1.f, -2.f,
        +5.f, +0.f, +1.f, -1.f
    };

    const math::matrix4f matrix2
    {
        +3.f, +2.f, +0.f, -5.f,
        +4.f, +3.f, -5.f, +0.f,
        +1.f, +0.f, -2.f, +3.f,
        +0.f, +1.f, -3.f, +4.f,
    };

    EXPECT_EQ(math::transposed(math::transposed(matrix1)), matrix1);
    EXPECT_EQ(math::transposed(matrix1) + math::transposed(matrix2), math::transposed(matrix1 + matrix2));
    EXPECT_EQ(math::transposed(5.f * matrix1), 5.f * math::transposed(matrix1));
    EXPECT_EQ(math::transposed(matrix1 * 5.f), math::transposed(matrix1) * 5.f);

    EXPECT_EQ(math::transposed(matrix1 * matrix2), math::transposed(matrix2) * math::transposed(matrix1));
    EXPECT_NE(math::transposed(matrix1 * matrix2), math::transposed(matrix1) * math::transposed(matrix2));

    const math::matrix4f matrix3f_orig(matrix1);
    const math::matrix4f matrix3f_copy(math::transposed(matrix3f_orig));
    auto [r0_orig, r1_orig, r2_orig, r3_orig] = matrix3f_orig.rows();
    auto [c0_copy, c1_copy, c2_copy, c3_copy] = matrix3f_copy.columns();
    EXPECT_EQ(r0_orig, c0_copy);
    EXPECT_EQ(r1_orig, c1_copy);
    EXPECT_EQ(r2_orig, c2_copy);
    EXPECT_EQ(r3_orig, c3_copy);
}

TEST(MatrixAlgebra4D, TranspositionDouble)
{
    const math::matrix4d matrix1
    {
        +4.0, +3.0, -2.0, -1.0,
        -2.0, +1.0, -4.0, +3.0,
        +0.0, +4.0, +1.0, -2.0,
        +5.0, +0.0, +1.0, -1.0
    };

    const math::matrix4d matrix2
    {
        +3.0, +2.0, +0.0, -5.0,
        +4.0, +3.0, -5.0, +0.0,
        +1.0, +0.0, -2.0, +3.0,
        +0.0, +1.0, -3.0, +4.0,
    };

    EXPECT_EQ(math::transposed(math::transposed(matrix1)), matrix1);
    EXPECT_EQ(math::transposed(matrix1) + math::transposed(matrix2), math::transposed(matrix1 + matrix2));
    EXPECT_EQ(math::transposed(5.0 * matrix1), 5.0 * math::transposed(matrix1));
    EXPECT_EQ(math::transposed(matrix1 * 5.0), math::transposed(matrix1) * 5.0);

    EXPECT_EQ(math::transposed(matrix1 * matrix2), math::transposed(matrix2) * math::transposed(matrix1));
    EXPECT_NE(math::transposed(matrix1 * matrix2), math::transposed(matrix1) * math::transposed(matrix2));

    const math::matrix4d matrix3f_orig(matrix1);
    const math::matrix4d matrix3f_copy(math::transposed(matrix3f_orig));
    auto [r0_orig, r1_orig, r2_orig, r3_orig] = matrix3f_orig.rows();
    auto [c0_copy, c1_copy, c2_copy, c3_copy] = matrix3f_copy.columns();
    EXPECT_EQ(r0_orig, c0_copy);
    EXPECT_EQ(r1_orig, c1_copy);
    EXPECT_EQ(r2_orig, c2_copy);
    EXPECT_EQ(r3_orig, c3_copy);
}

TEST(MatrixAlgebra4D, InversionFloat)
{
    const math::matrix4f matrix1
    {
        +4.f, +3.f, -2.f, -1.f,
        -2.f, +1.f, -4.f, +3.f,
        +0.f, +4.f, +1.f, -2.f,
        +5.f, +0.f, +1.f, -1.f
    };
    EXPECT_NE(matrix1.det(), 0.f);
    EXPECT_EQ(math::inverted(math::matrix4f::identity()), math::matrix4f::identity());

    math::matrix4f matrix2(matrix1);
    matrix2.invert();
    EXPECT_EQ(matrix2, math::inverted(matrix1));
    const auto m = matrix2 * matrix1;
    EXPECT_EQ(m, math::matrix4f::identity());
    EXPECT_EQ(matrix1 * matrix2, math::matrix4f::identity());
    EXPECT_EQ(math::inverted(matrix2), matrix1);
}
TEST(MatrixAlgebra4D, InversionDouble)
{
    const math::matrix4d matrix1
    {
        +4.0, +3.0, -2.0, -1.0,
        -2.0, +1.0, -4.0, +3.0,
        +0.0, +4.0, +1.0, -2.0,
        +5.0, +0.0, +1.0, -1.0,
    };
    EXPECT_NE(matrix1.det(), 0.0);
    EXPECT_EQ(math::inverted(math::matrix4d::identity()), math::matrix4d::identity());

    math::matrix4d matrix2(matrix1);
    matrix2.invert();
    EXPECT_EQ(matrix2, math::inverted(matrix1));
    const auto m = matrix2 * matrix1;
    EXPECT_EQ(m, math::matrix4d::identity());
    EXPECT_EQ(matrix1 * matrix2, math::matrix4d::identity());
    EXPECT_EQ(math::inverted(matrix2), matrix1);
}
