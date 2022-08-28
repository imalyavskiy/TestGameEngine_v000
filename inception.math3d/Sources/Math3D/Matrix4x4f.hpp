#ifndef __MATRIX4X4_HPP__
#define __MATRIX4X4_HPP__
namespace Math3D
{
  /**
 * @brief Four dimensional square matrix used to perform calculations in homogeneous coordinates.
 *        By default the initial matrix is ZERO matrix.
 */
  struct Matrix4f
  {
    Matrix4f() = default;

    Matrix4f(float _00, float _01, float _02, float _03,
      float _10, float _11, float _12, float _13,
      float _20, float _21, float _22, float _23,
      float _30, float _31, float _32, float _33);

    Matrix4f(Vector4f r0, Vector4f r1, Vector4f r2, Vector4f r3);

    float m[4][4] = {
      { 0.f, 0.f, 0.f, 0.f },
      { 0.f, 0.f, 0.f, 0.f },
      { 0.f, 0.f, 0.f, 0.f },
      { 0.f, 0.f, 0.f, 0.f }
    };

    const float* data() const;

    /**
     * @brief Implements matrix multiplication algorithm.
     */
    Matrix4f operator*(const Matrix4f& right) const;

    /**
     * @brief Implements matrix to vector-column multiplication algorithm.
     */
    Vector4f operator*(const Vector4f& right) const;
  };

  /**
   * @brief ???
   */
  struct Transform
  {
    Transform();
    Transform(const Position position, const Rotation rotation, const Scale scale);

    Position  position;

    /**
     * @brief angles in radians
     */
    Rotation  rotation;

    Scale     scale;
  };
}
#endif // __MATRIX4X4_HPP__