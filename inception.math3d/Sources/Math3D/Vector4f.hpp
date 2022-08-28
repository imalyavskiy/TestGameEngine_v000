#ifndef __VECTOR4F_HPP__
#define __VECTOR4F_HPP__
namespace Math3D
{
  /**
   * @brief Three dimensional floating point vector with 4th coordinate required by homogeneous coordinates.
   */
  struct Vector4f
  {
    float x = 0.f;
    float y = 0.f;
    float z = 0.f;
    float w = 0.f;

    Vector4f() = default;

    /**
     * @brief Initializes homogeneous coordinate item. Caller have to choose whether it a point or a vector.
     */
    Vector4f(const Vector3f& v3, const float _w);

    /**
     * @brief Initializes homogeneous coordinate point(component w == 1)
     */
    Vector4f(const Position& p3);

    /**
     * @brief Initializes homogeneous coordinate vector(component w == 0)
     */
    Vector4f(const Direction& d3);

    /**
     * @brief Initializes homogeneous coordinate item by component.
     */
    Vector4f(const float _x, const float _y, const float _z, const float _w);

    /**
     * @brief Extracts first three components.
     */
    Vector3f xyz() const;

    /**
     *
     */
    bool operator==(const Math3D::Vector4f& r) const;

    /**
     *
     */
    bool operator!=(const Math3D::Vector4f& r) const { return !operator==(r); }
  };
}
#endif // __VECTOR4F_HPP__