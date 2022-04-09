#include "pch.h"
#include <math/src/utils.h>
#include <math/src/vector2.h>
#include <math/src/vector3.h>
#include <math/src/matrix3.h>

TEST(MatrixAlgebra3D, DefaultConstructionFloat)
{
    const math::matrix3f matrix;

    auto [r0, r1, r2] = matrix.rows();
    EXPECT_EQ(r0, math::vector3f(1.f, 0.f, 0.f));
    EXPECT_EQ(r1, math::vector3f(0.f, 1.f, 0.f));
    EXPECT_EQ(r2, math::vector3f(0.f, 0.f, 1.f));

    auto [c0, c1, c2] = matrix.columns();
    EXPECT_EQ(c0, math::vector3f(1.f, 0.f, 0.f));
    EXPECT_EQ(c1, math::vector3f(0.f, 1.f, 0.f));
    EXPECT_EQ(c2, math::vector3f(0.f, 0.f, 1.f));

    EXPECT_EQ(math::matrix3f::identity(), math::matrix3f(1.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 1.f));
    EXPECT_EQ(math::matrix3f::zero(), math::matrix3f(0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f));

    EXPECT_EQ(math::matrix3f(5.f), math::matrix3f(5.f, 5.f, 5.f, 5.f, 5.f, 5.f, 5.f, 5.f, 5.f));
}

TEST(MatrixAlgebra3D, DefaultConstructionDouble)
{
    const math::matrix3d matrix;

    auto [r0, r1, r2] = matrix.rows();
    EXPECT_EQ(r0, math::vector3d(1.0, 0.0, 0.0));
    EXPECT_EQ(r1, math::vector3d(0.0, 1.0, 0.0));
    EXPECT_EQ(r2, math::vector3d(0.0, 0.0, 1.0));

    auto [c0, c1, c2] = matrix.columns();
    EXPECT_EQ(c0, math::vector3d(1.0, 0.0, 0.0));
    EXPECT_EQ(c1, math::vector3d(0.0, 1.0, 0.0));
    EXPECT_EQ(c2, math::vector3d(0.0, 0.0, 1.0));

    EXPECT_EQ(math::matrix3d::identity(), math::matrix3d(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0));
    EXPECT_EQ(math::matrix3d::zero(), math::matrix3d(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

    EXPECT_EQ(math::matrix3d(5.0), math::matrix3d(5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0));
}

TEST(MatrixAlgebra3D, ParametrizedConstructionFloat)
{
    const math::matrix3f matrix(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);

    auto [r0, r1, r2] = matrix.rows();
    EXPECT_EQ(r0, math::vector3f(1.f, 2.f, 3.f));
    EXPECT_EQ(r1, math::vector3f(4.f, 5.f, 6.f));
    EXPECT_EQ(r2, math::vector3f(7.f, 8.f, 9.f));

    auto [c0, c1, c2] = matrix.columns();
    EXPECT_EQ(c0, math::vector3f(1.f, 4.f, 7.f));
    EXPECT_EQ(c1, math::vector3f(2.f, 5.f, 8.f));
    EXPECT_EQ(c2, math::vector3f(3.f, 6.f, 9.f));
}

TEST(MatrixAlgebra3D, ParametrizedConstructionDouble)
{
    const math::matrix3d matrix(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

    auto [r0, r1, r2] = matrix.rows();
    EXPECT_EQ(r0, math::vector3d(1.0, 2.0, 3.0));
    EXPECT_EQ(r1, math::vector3d(4.0, 5.0, 6.0));
    EXPECT_EQ(r2, math::vector3d(7.0, 8.0, 9.0));

    auto [c0, c1, c2] = matrix.columns();
    EXPECT_EQ(c0, math::vector3d(1.0, 4.0, 7.0));
    EXPECT_EQ(c1, math::vector3d(2.0, 5.0, 8.0));
    EXPECT_EQ(c2, math::vector3d(3.0, 6.0, 9.0));
}

TEST(MatrixAlgebra3D, CopyConstructionFloat)
{
    const math::matrix3f matrix3f_orig(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
    const math::matrix3f matrix3f_copy(matrix3f_orig);

    auto [r0_orig, r1_orig, r2_orig] = matrix3f_orig.rows();
    auto [r0_copy, r1_copy, r2_copy] = matrix3f_copy.rows();
    EXPECT_EQ(r0_orig, r0_copy);
    EXPECT_EQ(r1_orig, r1_copy);
    EXPECT_EQ(r2_orig, r2_copy);

    auto [c0_orig, c1_orig, c2_orig] = matrix3f_orig.columns();
    auto [c0_copy, c1_copy, c2_copy] = matrix3f_copy.columns();
    EXPECT_EQ(c0_orig, c0_copy);
    EXPECT_EQ(c1_orig, c1_copy);
    EXPECT_EQ(c2_orig, c2_copy);
}

TEST(MatrixAlgebra3D, CopyConstructionDouble)
{
    const math::matrix3d matrix3d_orig(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    const math::matrix3d matrix3d_copy(matrix3d_orig);

    auto [r0_orig, r1_orig, r2_orig] = matrix3d_orig.rows();
    auto [r0_copy, r1_copy, r2_copy] = matrix3d_copy.rows();
    EXPECT_EQ(r0_orig, r0_copy);
    EXPECT_EQ(r1_orig, r1_copy);
    EXPECT_EQ(r2_orig, r2_copy);

    auto [c0_orig, c1_orig, c2_orig] = matrix3d_orig.columns();
    auto [c0_copy, c1_copy, c2_copy] = matrix3d_copy.columns();
    EXPECT_EQ(c0_orig, c0_copy);
    EXPECT_EQ(c1_orig, c1_copy);
    EXPECT_EQ(c2_orig, c2_copy);
}

TEST(MatrixAlgebra3D, EqualityFloat)
{
    EXPECT_TRUE(math::matrix3f() == math::matrix3f());
    EXPECT_FALSE(math::matrix3f() != math::matrix3f());
}

TEST(MatrixAlgebra3D, EqualityDouble)
{
    EXPECT_TRUE(math::matrix3d() == math::matrix3d());
    EXPECT_FALSE(math::matrix3d() != math::matrix3d());
}

TEST(MatrixAlgebra3D, LinearOperationsFloat)
{
    const math::matrix3f matrix1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
    const math::matrix3f matrix2(9.f, 8.f, 7.f, 6.f, 5.f, 4.f, 3.f, 2.f, 1.f);
    const math::matrix3f matrix3(10.f);
    EXPECT_EQ(matrix1 + matrix2, matrix3);
    EXPECT_EQ(matrix3 - matrix1, matrix2);
    EXPECT_EQ(matrix3 - matrix2, matrix1);

    const math::matrix3f matrix4(2.f);
    EXPECT_EQ(matrix4 * 2.f, math::matrix3f(4.f));
    EXPECT_EQ(2.f * matrix4, math::matrix3f(4.f));
    EXPECT_EQ(matrix4 / 2.f, math::matrix3f(1.f));
    EXPECT_EQ(matrix4 + math::matrix3f::zero(), matrix4);
    EXPECT_EQ(-matrix4, math::matrix3f(-2.f));
    EXPECT_EQ(matrix4 - matrix4, math::matrix3f::zero());
}

TEST(MatrixAlgebra3D, LinearOperationsDouble)
{
    const math::matrix3d matrix1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    const math::matrix3d matrix2(9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0);
    const math::matrix3d matrix3(10.0);
    EXPECT_EQ(matrix1 + matrix2, matrix3);
    EXPECT_EQ(matrix3 - matrix1, matrix2);
    EXPECT_EQ(matrix3 - matrix2, matrix1);

    const math::matrix3d matrix4(2.0);
    EXPECT_EQ(matrix4 * 2.0, math::matrix3d(4.0));
    EXPECT_EQ(2.0 * matrix4, math::matrix3d(4.0));
    EXPECT_EQ(matrix4 / 2.0, math::matrix3d(1.0));
    EXPECT_EQ(matrix4 + math::matrix3d::zero(), matrix4);
    EXPECT_EQ(-matrix4, math::matrix3d(-2.0));
    EXPECT_EQ(matrix4 - matrix4, math::matrix3d::zero());
}

TEST(MatrixAlgebra3D, MultiplicationFloat)
{
    const math::matrix3f matrix1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
    const math::matrix3f matrix2(9.f, 8.f, 7.f, 6.f, 5.f, 4.f, 3.f, 2.f, 1.f);
    const math::matrix3f matrix3(3.f, 2.f, 1.f, 6.f, 5.f, 4.f, 9.f, 8.f, 7.f);

    EXPECT_EQ(matrix1 * matrix2, math::matrix3f(30.f, 24.f, 18.f, 84.f, 69.f, 54.f, 138.f, 114.f, 90.f));
    EXPECT_EQ(matrix2 * matrix1, math::matrix3f(90.f, 114.f, 138.f, 54.f, 69.f, 84.f, 18.f, 24.f, 30.f));
    EXPECT_NE(matrix1 * matrix2, matrix2 * matrix1);
    EXPECT_EQ(matrix1 * math::matrix3f::identity(), matrix1);
    EXPECT_EQ(math::matrix3f::identity() * matrix1, matrix1);
    EXPECT_EQ(matrix1 * math::matrix3f::identity(), math::matrix3f::identity() * matrix1);

    EXPECT_EQ(-math::matrix3f::identity() * matrix1, -matrix1);

    EXPECT_EQ((matrix1 * matrix2) * 3.5f, (matrix1 * 3.5f) * matrix2);
    EXPECT_EQ(math::matrix3f::identity() * 2.f, math::matrix3f(2.f, 0.f, 0.f, 0.f, 2.f, 0.f, 0.f, 0.f, 2.f));
    EXPECT_EQ(2.f * math::matrix3f::identity(), math::matrix3f(2.f, 0.f, 0.f, 0.f, 2.f, 0.f, 0.f, 0.f, 2.f));
    EXPECT_EQ(3.5f * (matrix1 * matrix2), (3.5f * matrix1) * matrix2);

    EXPECT_EQ((matrix1 + matrix2) * matrix3, matrix1 * matrix3 + matrix2 * matrix3);
    EXPECT_EQ(matrix3 * (matrix1 + matrix2), matrix3 * matrix1 + matrix3 * matrix2);
}

TEST(MatrixAlgebra3D, MultiplicationDouble)
{
    const math::matrix3d matrix1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    const math::matrix3d matrix2(9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0);
    const math::matrix3d matrix3(3.0, 2.0, 1.0, 6.0, 5.0, 4.0, 9.0, 8.0, 7.0);

    EXPECT_EQ(matrix1 * matrix2, math::matrix3d(30.0, 24.0, 18.0, 84.0, 69.0, 54.0, 138.0, 114.0, 90.0));
    EXPECT_EQ(matrix2 * matrix1, math::matrix3d(90.0, 114.0, 138.0, 54.0, 69.0, 84.0, 18.0, 24.0, 30.0));
    EXPECT_NE(matrix1 * matrix2, matrix2 * matrix1);
    EXPECT_EQ(matrix1 * math::matrix3d::identity(), matrix1);
    EXPECT_EQ(math::matrix3d::identity() * matrix1, matrix1);
    EXPECT_EQ(matrix1 * math::matrix3d::identity(), math::matrix3d::identity() * matrix1);

    EXPECT_EQ(-math::matrix3d::identity() * matrix1, -matrix1);

    EXPECT_EQ((matrix1 * matrix2) * 3.5, (matrix1 * 3.5) * matrix2);
    EXPECT_EQ(math::matrix3d::identity() * 2.0, math::matrix3d(2.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 2.0));
    EXPECT_EQ(2.0 * math::matrix3d::identity(), math::matrix3d(2.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 2.0));
    EXPECT_EQ(3.5 * (matrix1 * matrix2), (3.5 * matrix1) * matrix2);

    EXPECT_EQ((matrix1 + matrix2) * matrix3, matrix1 * matrix3 + matrix2 * matrix3);
    EXPECT_EQ(matrix3 * (matrix1 + matrix2), matrix3 * matrix1 + matrix3 * matrix2);
}

TEST(MatrixAlgebra3D, DeterminantFloat)
{
    const math::matrix3f matrix1(3.f, 2.f, 1.f, 6.f, 7.f, 4.f, 8.f, 8.f, 7.f);

    EXPECT_EQ(matrix1.det(), 23.f);
    EXPECT_EQ(matrix1.det(), math::det(matrix1));
    EXPECT_EQ(math::det(math::matrix3f::identity()), 1.f);
    EXPECT_EQ(math::matrix3f::identity().det(), 1.f);
    EXPECT_EQ(math::det(math::matrix3f::zero()), 0.f);
    EXPECT_EQ(math::matrix3f::zero().det(), 0.f);
    EXPECT_EQ(math::det(-matrix1), std::pow(-1.f, 3.f) * math::det(matrix1));
    EXPECT_EQ(math::det(3.f * matrix1), std::pow(3.f, 3.f) * math::det(matrix1));
}

TEST(MatrixAlgebra3D, DeterminantDouble)
{
    const math::matrix3d matrix1(3.0, 2.0, 1.0, 6.0, 7.0, 4.0, 8.0, 8.0, 7.0);

    EXPECT_EQ(matrix1.det(), 23.0);
    EXPECT_EQ(matrix1.det(), math::det(matrix1));
    EXPECT_EQ(math::det(math::matrix3d::identity()), 1.0);
    EXPECT_EQ(math::matrix3d::identity().det(), 1.0);
    EXPECT_EQ(math::det(math::matrix3d::zero()), 0.0);
    EXPECT_EQ(math::matrix3d::zero().det(), 0.0);
    EXPECT_EQ(math::det(-matrix1), std::pow(-1.0, 3.0) * math::det(matrix1));
    EXPECT_EQ(math::det(3.0 * matrix1), std::pow(3.0, 3.0) * math::det(matrix1));
}

TEST(MatrixAlgebra3D, TranspositionFloat)
{
    const math::matrix3f matrix1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
    const math::matrix3f matrix2(3.f, 2.f, 1.f, 6.f, 5.f, 4.f, 9.f, 8.f, 7.f);

    EXPECT_EQ(math::transposed(math::transposed(matrix1)), matrix1);
    EXPECT_EQ(math::transposed(matrix1) + math::transposed(matrix2), math::transposed(matrix1 + matrix2));
    EXPECT_EQ(math::transposed(5.f * matrix1), 5.f * math::transposed(matrix1));
    EXPECT_EQ(math::transposed(matrix1 * 5.f), math::transposed(matrix1) * 5.f);

    EXPECT_EQ(math::transposed(matrix1 * matrix2), math::transposed(matrix2) * math::transposed(matrix1));
    EXPECT_NE(math::transposed(matrix1 * matrix2), math::transposed(matrix1) * math::transposed(matrix2));

    const math::matrix3f matrix3f_orig(3.f, 2.f, 1.f, 6.f, 5.f, 4.f, 9.f, 8.f, 7.f);
    const math::matrix3f matrix3f_copy(math::transposed(matrix3f_orig));
    auto [r0_orig, r1_orig, r2_orig] = matrix3f_orig.rows();
    auto [c0_copy, c1_copy, c2_copy] = matrix3f_copy.columns();
    EXPECT_EQ(r0_orig, c0_copy);
    EXPECT_EQ(r1_orig, c1_copy);
    EXPECT_EQ(r2_orig, c2_copy);
}

TEST(MatrixAlgebra3D, TranspositionDouble)
{
    const math::matrix3d matrix1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    const math::matrix3d matrix2(3.0, 2.0, 1.0, 6.0, 5.0, 4.0, 9.0, 8.0, 7.0);

    EXPECT_EQ(math::transposed(math::transposed(matrix1)), matrix1);
    EXPECT_EQ(math::transposed(matrix1) + math::transposed(matrix2), math::transposed(matrix1 + matrix2));
    EXPECT_EQ(math::transposed(5.0 * matrix1), 5.0 * math::transposed(matrix1));
    EXPECT_EQ(math::transposed(matrix1 * 5.0), math::transposed(matrix1) * 5.0);

    EXPECT_EQ(math::transposed(matrix1 * matrix2), math::transposed(matrix2) * math::transposed(matrix1));
    EXPECT_NE(math::transposed(matrix1 * matrix2), math::transposed(matrix1) * math::transposed(matrix2));

    const math::matrix3d matrix3d_orig(3.0, 2.0, 1.0, 6.0, 5.0, 4.0, 9.0, 8.0, 7.0);
    const math::matrix3d matrix3d_copy(math::transposed(matrix3d_orig));
    auto [r0_orig, r1_orig, r2_orig] = matrix3d_orig.rows();
    auto [c0_copy, c1_copy, c2_copy] = matrix3d_copy.columns();
    EXPECT_EQ(r0_orig, c0_copy);
    EXPECT_EQ(r1_orig, c1_copy);
    EXPECT_EQ(r2_orig, c2_copy);
}

TEST(MatrixAlgebra3D, InversionFloat)
{
    const math::matrix3f matrix1(3.f, 2.f, 1.f, 6.f, 7.f, 4.f, 8.f, 8.f, 7.f);
    EXPECT_NE(matrix1.det(), 0.f);
    EXPECT_EQ(math::inverted(math::matrix3f::identity()), math::matrix3f::identity());

    math::matrix3f matrix2(matrix1);
    matrix2.invert();
    EXPECT_EQ(matrix2, math::inverted(matrix1));
    const auto m = matrix2 * matrix1;
    EXPECT_EQ(m, math::matrix3f::identity());
    EXPECT_EQ(matrix1 * matrix2, math::matrix3f::identity());
    EXPECT_EQ(math::inverted(matrix2), matrix1);
}

TEST(MatrixAlgebra3D, InversionDouble)
{
    const math::matrix3d matrix1(3.0, 2.0, 1.0, 6.0, 7.0, 4.0, 8.0, 8.0, 7.0);
    EXPECT_NE(matrix1.det(), 0.0);
    EXPECT_EQ(math::inverted(math::matrix3d::identity()), math::matrix3d::identity());

    math::matrix3d matrix2(matrix1);
    matrix2.invert();
    EXPECT_EQ(matrix2, math::inverted(matrix1));
    EXPECT_EQ(matrix2 * matrix1, math::matrix3d::identity());
    EXPECT_EQ(matrix1 * matrix2, math::matrix3d::identity());
    EXPECT_EQ(math::inverted(matrix2), matrix1);
}
