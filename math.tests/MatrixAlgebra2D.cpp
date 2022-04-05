#include "pch.h"
#include <math/src/utils.h>
#include <math/src/vector2.h>
#include <math/src/matrix2.h>

TEST(MatrixAlgebra2D, DefaultConstruction)
{
    {
        const math::matrix2f matrix;

        auto [r0, r1] = matrix.rows();
        EXPECT_EQ(r0, math::vector2f(1.f, 0.f));
        EXPECT_EQ(r1, math::vector2f(0.f, 1.f));

        auto [c0, c1] = matrix.columns();
        EXPECT_EQ(c0, math::vector2f(1.f, 0.f));
        EXPECT_EQ(c1, math::vector2f(0.f, 1.f));

        EXPECT_EQ(math::matrix2f::identity(), math::matrix2f(1.f, 0.f, 0.f, 1.f));
        EXPECT_EQ(math::matrix2f::zero(), math::matrix2f(0.f, 0.f, 0.f, 0.f));
    }
    {
        const math::matrix2d matrix;

        auto [r0, r1] = matrix.rows();
        EXPECT_EQ(r0, math::vector2d(1.0, 0.0));
        EXPECT_EQ(r1, math::vector2d(0.0, 1.0));

        auto [c0, c1] = matrix.columns();
        EXPECT_EQ(c0, math::vector2d(1.0, 0.0));
        EXPECT_EQ(c1, math::vector2d(0.0, 1.0));

        EXPECT_EQ(math::matrix2d::identity(), math::matrix2d(1.0, 0.0, 0.0, 1.0));
        EXPECT_EQ(math::matrix2d::zero(), math::matrix2d(0.0, 0.0, 0.0, 0.0));
    }
}

TEST(MatrixAlgebra2D, ParametrizedConstruction)
{
    {
        const math::matrix2f matrix(1.f, 2.f, 3.f, 4.f);

        auto [r0, r1] = matrix.rows();
        EXPECT_EQ(r0, math::vector2f(1.f, 2.f));
        EXPECT_EQ(r1, math::vector2f(3.f, 4.f));

        auto [c0, c1] = matrix.columns();
        EXPECT_EQ(c0, math::vector2f(1.f, 3.f));
        EXPECT_EQ(c1, math::vector2f(2.f, 4.f));
    }

    {
        const math::matrix2d matrix(1.0, 2.0, 3.0, 4.0);

        auto [r0, r1] = matrix.rows();
        EXPECT_EQ(r0, math::vector2d(1.0, 2.0));
        EXPECT_EQ(r1, math::vector2d(3.0, 4.0));

        auto [c0, c1] = matrix.columns();
        EXPECT_EQ(c0, math::vector2d(1.0, 3.0));
        EXPECT_EQ(c1, math::vector2d(2.0, 4.0));
    }
}

TEST(MatrixAlgebra2D, CopyConstruction)
{
    {
        const math::matrix2f matrix2f_orig(1.f, 2.f, 3.f, 4.f);
        const math::matrix2f matrix2f_copy(matrix2f_orig);

        auto [r0_orig, r1_orig] = matrix2f_orig.rows();
        auto [r0_copy, r1_copy] = matrix2f_copy.rows();
        EXPECT_EQ(r0_orig, r0_copy);
        EXPECT_EQ(r1_orig, r1_copy);

        auto [c0_orig, c1_orig] = matrix2f_orig.columns();
        auto [c0_copy, c1_copy] = matrix2f_copy.columns();
        EXPECT_EQ(c0_orig, c0_copy);
        EXPECT_EQ(c1_orig, c1_copy);
    }
    {
        const math::matrix2d matrix2d_orig(1.0, 2.0, 3.0, 4.0);
        const math::matrix2d matrix2d_copy(matrix2d_orig);

        auto [r0_orig, r1_orig] = matrix2d_orig.rows();
        auto [r0_copy, r1_copy] = matrix2d_copy.rows();
        EXPECT_EQ(r0_orig, r0_copy);
        EXPECT_EQ(r1_orig, r1_copy);

        auto [c0_orig, c1_orig] = matrix2d_orig.columns();
        auto [c0_copy, c1_copy] = matrix2d_copy.columns();
        EXPECT_EQ(c0_orig, c0_copy);
        EXPECT_EQ(c1_orig, c1_copy);
    }
}

TEST(MatrixAlgebra2D, Equality)
{
    {
        EXPECT_TRUE(math::matrix2f() == math::matrix2f());
        EXPECT_FALSE(math::matrix2f() != math::matrix2f());
    }
    {
        EXPECT_TRUE(math::matrix2d() == math::matrix2d());
        EXPECT_FALSE(math::matrix2d() != math::matrix2d());
    }
}

TEST(MatrixAlgebra2D, LinearOperations)
{
    {
        const math::matrix2f matrix1(1.f, 2.f, 3.f, 4.f);
        const math::matrix2f matrix2(4.f, 3.f, 2.f, 1.f);
        const math::matrix2f matrix3(5.f, 5.f, 5.f, 5.f);
        EXPECT_EQ(matrix1 + matrix2, matrix3);
        EXPECT_EQ(matrix3 - matrix1, matrix2);
        EXPECT_EQ(matrix3 - matrix2, matrix1);

        const math::matrix2f matrix4(1.f, 2.f, 3.f, 4.f);
        EXPECT_EQ(matrix4 * 2.f, math::matrix2f(2.f, 4.f, 6.f, 8.f));
        EXPECT_EQ(2.f * matrix4, math::matrix2f(2.f, 4.f, 6.f, 8.f));
        EXPECT_EQ(matrix4 / 2.f, math::matrix2f(.5f, 1.f, 1.5f, 2.f));
        EXPECT_EQ(matrix4 + math::matrix2f::zero(), matrix4);
        EXPECT_EQ(-matrix4, math::matrix2f(-1.f, -2.f, -3.f, -4.f));
        EXPECT_EQ(matrix4 - matrix4, math::matrix2f::zero());
    }
    {
        const math::matrix2d matrix1(1.0, 2.0, 3.0, 4.0);
        const math::matrix2d matrix2(4.0, 3.0, 2.0, 1.0);
        const math::matrix2d matrix3(5.0, 5.0, 5.0, 5.0);
        EXPECT_EQ(matrix1 + matrix2, matrix3);
        EXPECT_EQ(matrix3 - matrix1, matrix2);
        EXPECT_EQ(matrix3 - matrix2, matrix1);

        const math::matrix2d matrix4(1.0, 2.0, 3.0, 4.0);
        EXPECT_EQ(matrix4 * 2.0, math::matrix2d(2.0, 4.0, 6.0, 8.0));
        EXPECT_EQ(2.0 * matrix4, math::matrix2d(2.0, 4.0, 6.0, 8.0));
        EXPECT_EQ(matrix4 / 2.0, math::matrix2d(.5, 1.0, 1.5, 2.0));
        EXPECT_EQ(matrix4 + math::matrix2d::zero(), matrix4);
        EXPECT_EQ(-matrix4, math::matrix2d(-1.0, -2.0, -3.0, -4.0));
        EXPECT_EQ(matrix4 - matrix4, math::matrix2d::zero());
    }
}

TEST(MatrixAlgebra2D, Multiplication)
{
    {
        const math::matrix2f matrix1(1.f, 2.f, 3.f, 4.f);
        const math::matrix2f matrix2(4.f, 3.f, 2.f, 1.f);
        const math::matrix2f matrix3(2.f, 1.f, 4.f, 3.f);
    
        EXPECT_EQ(matrix1 * matrix2, math::matrix2f(8.f, 5.f, 20.f, 13.f));
        EXPECT_EQ(matrix2 * matrix1, math::matrix2f(13.f, 20.f, 5.f, 8.f));
        EXPECT_NE(matrix1 * matrix2, matrix2 * matrix1);
        EXPECT_EQ(matrix1 * math::matrix2f::identity(), matrix1);
        EXPECT_EQ(math::matrix2f::identity() * matrix1, matrix1);
        EXPECT_EQ(matrix1 * math::matrix2f::identity(), math::matrix2f::identity() * matrix1);

        EXPECT_EQ(-math::matrix2f::identity() * matrix1, -matrix1);

        EXPECT_EQ((matrix1 * matrix2) * 3.5f, (matrix1 * 3.5f) * matrix2);
        EXPECT_EQ(math::matrix2f::identity() * 2.f, math::matrix2f(2.f, 0.f, 0.f, 2.f));
        EXPECT_EQ(2.f * math::matrix2f::identity(), math::matrix2f(2.f, 0.f, 0.f, 2.f));
        EXPECT_EQ(3.5f * (matrix1 * matrix2), (3.5f * matrix1) * matrix2);

        EXPECT_EQ((matrix1 + matrix2) * matrix3, matrix1 * matrix3 + matrix2 * matrix3);
        EXPECT_EQ(matrix3 * (matrix1 + matrix2), matrix3 * matrix1 + matrix3 * matrix2);
    }
    {
        const math::matrix2d matrix1(1.0, 2.0, 3.0, 4.0);
        const math::matrix2d matrix2(4.0, 3.0, 2.0, 1.0);
        const math::matrix2d matrix3(2.0, 1.0, 4.0, 3.0);

        EXPECT_EQ(matrix1 * matrix2, math::matrix2d(8.0, 5.0, 20.0, 13.0));
        EXPECT_EQ(matrix2 * matrix1, math::matrix2d(13.0, 20.0, 5.0, 8.0));
        EXPECT_NE(matrix1 * matrix2, matrix2 * matrix1);
        EXPECT_EQ(matrix1 * math::matrix2d::identity(), matrix1);
        EXPECT_EQ(math::matrix2d::identity() * matrix1, matrix1);
        EXPECT_EQ(matrix1 * math::matrix2d::identity(), math::matrix2d::identity() * matrix1);

        EXPECT_EQ(-math::matrix2d::identity() * matrix1, -matrix1);

        EXPECT_EQ((matrix1 * matrix2) * 3.5, (matrix1 * 3.5) * matrix2);
        EXPECT_EQ(math::matrix2d::identity() * 2.0, math::matrix2d(2.0, 0.0, 0.0, 2.0));
        EXPECT_EQ(2.0 * math::matrix2d::identity(), math::matrix2d(2.0, 0.0, 0.0, 2.0));
        EXPECT_EQ(3.5 * (matrix1 * matrix2), (3.5 * matrix1) * matrix2);

        EXPECT_EQ((matrix1 + matrix2) * matrix3, matrix1 * matrix3 + matrix2 * matrix3);
        EXPECT_EQ(matrix3 * (matrix1 + matrix2), matrix3 * matrix1 + matrix3 * matrix2);
    }
}

TEST(MatrixAlgebra2D, Inversion)
{
    {
        const math::matrix2f matrix1(2.f, 1.f, 4.f, 3.f);
        math::matrix2f matrix2(matrix1);
        matrix2.invert();
        EXPECT_EQ(matrix2, math::inverted(matrix1));
        EXPECT_EQ(matrix2 * matrix1, math::matrix2f::identity());
        EXPECT_EQ(matrix1 * matrix2, math::matrix2f::identity());
        EXPECT_EQ(math::inverted(matrix2), matrix1);
    }
    {
        const math::matrix2d matrix1(2.0, 1.0, 4.0, 3.0);
        math::matrix2d matrix2(matrix1);
        matrix2.invert();
        EXPECT_EQ(matrix2, math::inverted(matrix1));
        EXPECT_EQ(matrix2 * matrix1, math::matrix2d::identity());
        EXPECT_EQ(matrix1 * matrix2, math::matrix2d::identity());
        EXPECT_EQ(math::inverted(matrix2), matrix1);
    }
}

TEST(MatrixAlgebra2D, Transposition)
{
    {
        const math::matrix2f matrix1(2.f, 1.f, 4.f, 3.f);
        const math::matrix2f matrix2(1.f, 1.f, 4.f, 7.f);
    
        EXPECT_EQ(math::transposed(math::transposed(matrix1)), matrix1);
        EXPECT_EQ(math::transposed(matrix1) + math::transposed(matrix2), math::transposed(matrix1 + matrix2));
        EXPECT_EQ(math::transposed(5.f * matrix1), 5.f * math::transposed(matrix1));
        EXPECT_EQ(math::transposed(matrix1* 5.f), math::transposed(matrix1) * 5.f);

        EXPECT_EQ(math::transposed(matrix1 * matrix2), math::transposed(matrix2) * math::transposed(matrix1));
        EXPECT_NE(math::transposed(matrix1 * matrix2), math::transposed(matrix1) * math::transposed(matrix2));

        const math::matrix2f matrix2f_orig(1.f, 2.f, 3.f, 4.f);
        const math::matrix2f matrix2f_copy(math::transposed(matrix2f_orig));
        auto [r0_orig, r1_orig] = matrix2f_orig.rows();
        auto [c0_copy, c1_copy] = matrix2f_copy.columns();
        EXPECT_EQ(r0_orig, c0_copy);
        EXPECT_EQ(r1_orig, c1_copy);
    }
    {
        const math::matrix2d matrix1(2.0, 1.0, 4.0, 3.0);
        const math::matrix2d matrix2(1.0, 1.0, 4.0, 7.0);

        EXPECT_EQ(math::transposed(math::transposed(matrix1)), matrix1);
        EXPECT_EQ(math::transposed(matrix1) + math::transposed(matrix2), math::transposed(matrix1 + matrix2));
        EXPECT_EQ(math::transposed(5.0 * matrix1), 5.0 * math::transposed(matrix1));
        EXPECT_EQ(math::transposed(matrix1 * 5.0), math::transposed(matrix1) * 5.0);

        EXPECT_EQ(math::transposed(matrix1 * matrix2), math::transposed(matrix2) * math::transposed(matrix1));
        EXPECT_NE(math::transposed(matrix1 * matrix2), math::transposed(matrix1) * math::transposed(matrix2));

        const math::matrix2d matrix2f_orig(1.0, 2.0, 3.0, 4.0);
        const math::matrix2d matrix2f_copy(math::transposed(matrix2f_orig));
        auto [r0_orig, r1_orig] = matrix2f_orig.rows();
        auto [c0_copy, c1_copy] = matrix2f_copy.columns();
        EXPECT_EQ(r0_orig, c0_copy);
        EXPECT_EQ(r1_orig, c1_copy);
    }
}

TEST(MatrixAlgebra2D, Determinant)
{
    {
        const math::matrix2f matrix1(2.f, 1.f, 4.f, 3.f);

        EXPECT_EQ(matrix1.det(), math::det(matrix1));
        EXPECT_EQ(math::det(math::matrix2f::identity()), 1.f);
        EXPECT_EQ(math::matrix2f::identity().det(), 1.f);
        EXPECT_EQ(math::det(math::matrix2f::zero()), 0.f);
        EXPECT_EQ(math::matrix2f::zero().det(), 0.f);
        EXPECT_EQ(math::det(-matrix1), std::pow(-1.f, 2.f) * math::det(matrix1));
        EXPECT_EQ(math::det(3.f * matrix1), std::pow(3.f, 2.f) * math::det(matrix1));
    }
    {
        const math::matrix2d matrix1(2.0, 1.0, 4.0, 3.0);

        EXPECT_EQ(matrix1.det(), math::det(matrix1));
        EXPECT_EQ(math::det(math::matrix2d::identity()), 1.0);
        EXPECT_EQ(math::matrix2d::identity().det(), 1.0);
        EXPECT_EQ(math::det(math::matrix2d::zero()), 0.0);
        EXPECT_EQ(math::matrix2d::zero().det(), 0.0);
        EXPECT_EQ(math::det(-matrix1), std::pow(-1.0, 2.0) * math::det(matrix1));
        EXPECT_EQ(math::det(3.0 * matrix1), std::pow(3.0, 2.0) * math::det(matrix1));
    }
}

