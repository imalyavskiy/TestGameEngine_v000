#ifndef __QUATERNION_HPP__
#define __QUATERNION_HPP__
namespace Math3D
{
  /**
* @brief Float base quaternion number representation. This code was written by theoretical bases written here https://habr.com/ru/post/426863/
   */
  class Quaternion
  {
  public:
    /**
     *
     */
    Quaternion() = default;

    /**
     *
     */
    Quaternion(const float s);

    /**
     *
     */
    Quaternion(const float s, const float x, const float y, const float z);

    /**
     *
     */
    Quaternion(const float s, const Vector3f& v);

    /**
     *
     */
    Quaternion(const Vector3f& v);

    /**
     *
     */
    Quaternion(const Quaternion& q) = default;

    /**
     *
     */
    [[nodiscard]]
    auto s() const -> float;
    void s(const float s);

    /**
     *
     */
    [[nodiscard]]
    auto x() const -> float;
    void x(const float x);

    /**
     *
     */
    [[nodiscard]]
    auto y() const -> float;
    void y(const float y);

    /**
     *
     */
    [[nodiscard]]
    auto z() const -> float;
    void z(const float z);

    /**
     *
     */
    [[nodiscard]]
    auto xyz() const -> Vector3f;
    void xyz(const Vector3f& v);

    [[nodiscard]]
    bool IsReal() const; // x_, y_, z_ are zeroes
    [[nodiscard]]
    bool IsPure() const; // s_ is zero
    [[nodiscard]]
    bool IsNull() const;

    auto operator=(const float s) -> Quaternion&;
    auto operator=(const Vector3f& v) -> Quaternion&;
    auto operator=(const Quaternion& other) -> Quaternion& = default;

    [[nodiscard]]
    auto operator==(const float s) const -> bool;
    [[nodiscard]]
    auto operator!=(const float s) const -> bool;
    [[nodiscard]]
    auto operator==(const Vector3f v) const -> bool;
    [[nodiscard]]
    auto operator!=(const Vector3f v) const -> bool;
    [[nodiscard]]
    auto operator==(const Quaternion& q) const -> bool;
    [[nodiscard]]
    auto operator!=(const Quaternion& q) const -> bool;

    [[nodiscard]]
    auto operator*(const float f) const -> Quaternion;
    auto operator*=(const float f) -> const Quaternion&;
    [[nodiscard]]
    auto operator*(const Vector3f& v) const -> Quaternion;
    auto operator*=(const Vector3f& v) -> const Quaternion&;
    [[nodiscard]]
    auto operator*(const Quaternion& r) const -> Quaternion;
    auto operator*=(const Quaternion& r) -> const Quaternion&;

    [[nodiscard]]
    auto operator/(const float f) const -> Quaternion;
    auto operator/=(const float f) -> const Quaternion&;

    // Because multiplication of quaternions is not commutative, division of a quaternion is also
    // not commutative (division is multiplication by a number to the power of -1). Writing a/b
    // means a divided by b, but in our case there is also another notation b\a - left
    // division - it is impossible to code such operation, so the operation of division by vector
    // (pure imaginary quaternion) will not be implemented at all.
    auto operator/(const Vector3f&) const -> Quaternion = delete;

    // Because multiplication of quaternions is not commutative, division of a quaternion is also
    // not commutative (division is multiplication by a number to the power of -1). Writing a/b
    // means a divided by b, but in our case there is also another notation b\a - left
    // division - it is impossible to code such operation, so the operation of division by vector
    // (pure imaginary quaternion) will not be implemented at all.
    auto operator/=(const Vector3f&) -> const Quaternion& = delete;

    // Because multiplication of quaternions is not commutative, division of a quaternion is also
    // not commutative (division is multiplication by a number to the power of -1). Writing a/b
    // means a divided by b, but in our case there is also another notation b\a - left
    // division - it is impossible to code such operation, so the operation of division by quaternion
    // we will not be implemented at all.
    auto operator/(const Quaternion&) const -> Quaternion = delete;

    // Because multiplication of quaternions is not commutative, division of a quaternion is also
    // not commutative (division is multiplication by a number to the power of -1). Writing a/b
    // means a divided by b, but in our case there is also another notation b\a - left
    // division - it is impossible to code such operation, so the operation of division by quaternion
    // we will not be implemented at all.
    auto operator/=(const Quaternion&) -> const Quaternion& = delete;

    [[nodiscard]]
    auto operator+(const float f) const -> Quaternion;
    auto operator+=(const float f) -> const Quaternion&;
    [[nodiscard]]
    auto operator+(const Vector3f& v) const -> Quaternion;
    auto operator+=(const Vector3f& v) -> const Quaternion&;
    [[nodiscard]]
    auto operator+(const Quaternion& q) const -> Quaternion;
    auto operator+=(const Quaternion& q) -> const Quaternion&;

    [[nodiscard]]
    auto operator-(const float f) const -> Quaternion;
    auto operator-=(const float f) -> const Quaternion&;
    [[nodiscard]]
    auto operator-(const Vector3f& v) const -> Quaternion;
    auto operator-=(const Vector3f& v) -> const Quaternion&;
    [[nodiscard]]
    auto operator-(const Quaternion& q) const -> Quaternion;
    auto operator-=(const Quaternion& q) -> const Quaternion&;

    /**
     * @brief Returns inverse version of current instance:
     *        q^(-1) == Conjugated(q)/N(q)
     */
    [[nodiscard]]
    auto Inversed() const -> Quaternion;

    /**
     * @brief Inverses current instance:
     *        q^(-1) == Conjugated(q)/N(q)
     */
    auto Inverse() -> const Quaternion&;

    /**
     * @brief s^2 + x^2 + y^2 + z^2
     */
    [[nodiscard]]
    auto Norm() const -> float;

    /**
     * @brief √(Norm(q)) == √(s^2 + x^2 + y^2 + z^2)
     */
    [[nodiscard]]
    auto Module() const -> float;

    /**
     * @brief normalizes current quaternion
     */
    auto Normalize() -> const Quaternion&;

    /**
     * @brief return normalized version of the current quaternion
     */
    [[nodiscard]]
    auto Normalized() const -> Quaternion;

    /**
     * @brief turns current quaternion to its conjugation
     */
    auto Conjugate() -> const Quaternion&;

    /**
     * @brief returns conjugation of the current quaternion
     */
    [[nodiscard]]
    auto Conjugated() const -> Quaternion;

    /**
     *
     */
    [[nodiscard]]
    auto dot(const Quaternion& r) const -> float;

    /**
     *
     */
    const static Quaternion zero;

  protected:
    float s_ = 0.f; // scalar

    float x_ = 0.f; // factor for imaginary i
    float y_ = 0.f; // factor for imaginary j
    float z_ = 0.f; // factor for imaginary k
  };

  auto operator==(const float l, const Quaternion& r) -> bool;
  auto operator!=(const float l, const Quaternion& r) -> bool;
  auto operator==(const Vector3f& l, const Quaternion& r) -> bool;
  auto operator!=(const Vector3f& l, const Quaternion& r) -> bool;

  auto operator+(const Vector3f& l, const Quaternion& r) -> Quaternion;
  auto operator+(const float l, const Quaternion& r) -> Quaternion;

  auto operator-(const Vector3f& l, const Quaternion& r) -> Quaternion;
  auto operator-(const float l, const Quaternion& r) -> Quaternion;

  auto operator*(const Vector3f& l, const Quaternion& r) -> Quaternion;
  auto operator*(const float, const Quaternion& r) -> Quaternion;

  auto dot(const Quaternion& l, const Quaternion& r) -> float;
}
#endif // __QUATERNION_HPP__