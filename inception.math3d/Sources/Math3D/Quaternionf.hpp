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
    auto s() const -> float;
    void s(const float s);

    /**
     *
     */
    auto x() const -> float;
    void x(const float x);

    /**
     *
     */
    auto y() const -> float;
    void y(const float y);

    /**
     *
     */
    auto z() const -> float;
    void z(const float z);

    /**
     *
     */
    Vector3f xyz() const;
    void xyz(const Vector3f& v);

    bool IsReal() const; // x_, y_, z_ are zeroes
    bool IsPure() const; // s_ is zero

    Quaternion& operator=(const float s);
    Quaternion& operator=(const Vector3f& v);
    Quaternion& operator=(const Quaternion& other);

    bool operator==(const float s) const;
    bool operator!=(const float s) const;
    bool operator==(const Vector3f v) const;
    bool operator!=(const Vector3f v) const;
    bool operator==(const Quaternion& q) const;
    bool operator!=(const Quaternion& q) const;

    Quaternion operator*(const float f) const;
    Quaternion operator*=(const float f) const;
    Quaternion operator*(const Vector3f& v) const;
    Quaternion operator*=(const Vector3f& v) const;
    Quaternion operator*(const Quaternion& r) const;
    Quaternion operator*=(const Quaternion& r) const;

    Quaternion operator/(const float f) const;
    Quaternion operator/=(const float f) const;
    Quaternion operator/(const Vector3f& v) const;
    Quaternion operator/=(const Vector3f& v) const;
    Quaternion operator/(const Quaternion& r) const;
    Quaternion operator/=(const Quaternion& r) const;

    Quaternion operator+(const float f) const;
    const Quaternion& operator+=(const float f);
    Quaternion operator+(const Vector3f& v) const;
    const Quaternion& operator+=(const Vector3f& v);
    Quaternion operator+(const Quaternion& q) const;
    const Quaternion& operator+=(const Quaternion& q);

    Quaternion operator-(const float f) const;
    const Quaternion& operator-=(const float f);
    Quaternion operator-(const Vector3f& v) const;
    const Quaternion& operator-=(const Vector3f& v);
    Quaternion operator-(const Quaternion& q) const;
    const Quaternion& operator-=(const Quaternion& q);

    /**
     *
     */
    Quaternion inverted() const;

    /**
     *
     */
    void invert();

    /**
     * @brief normalizes current quaternion
     */
    const Quaternion& Normalize();

    /**
     * @brief return normalized version of the current quaternion
     */
    Quaternion Normalized() const;

    /**
     * @brief turns current quaternion to its conjugation
     */
    const Quaternion& Conjugate();

    /**
     * @brief returns conjugation of the current quaternion
     */
    Quaternion Conjugated() const;

    /**
     *
     */
    Quaternion dot(const Quaternion& other);

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

  bool operator==(const float l, const Quaternion& r);
  bool operator!=(const float l, const Quaternion& r);
  bool operator==(const Vector3f& l, const Quaternion& r);
  bool operator!=(const Vector3f& l, const Quaternion& r);

  Quaternion operator+(const Vector3f& l, const Quaternion& r);
  Quaternion operator+(const float l, const Quaternion& r);

  Quaternion operator-(const Vector3f& l, const Quaternion& r);
  Quaternion operator-(const float l, const Quaternion& r);
}
#endif // __QUATERNION_HPP__