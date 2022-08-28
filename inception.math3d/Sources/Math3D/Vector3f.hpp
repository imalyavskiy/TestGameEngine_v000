#ifndef __VECTOR3F_HPP__
#define __VECTOR3F_HPP__
namespace Math3D
{
  /**
   * @brief Three dimensional floating point vector.
   */
  struct Vector3f
  {
    float x = 0.f;
    float y = 0.f;
    float z = 0.f;

    Vector3f() = default;

    Vector3f(const Vector3f& other) = default;

    Vector3f(const float _x, const float _y, const float _z);

    Vector3f& Normalize();

    Vector3f operator-() const;

    Vector3f operator*(const float factor) const;

    Vector3f operator+=(const float v);

    const float* data() const;

    operator std::string() const;

    float len() const;
  };

  /**
   * @brief Vector cross product.
   */
  Vector3f Cross(const Vector3f& l, const Vector3f& r);

  /**
   * @brief Returns normalized version of the given vector.
   */
  Vector3f Normalized(const Vector3f& v);


  /**
   * @brief This is a convenience class required to distinguish between regular 3D vector and set of rotation angles, aka rotator.
   */
  struct Rotation : Vector3f
  {
    Rotation() = default;
    Rotation(const float roll, const float pitch, const float yaw) : Vector3f(roll, pitch, yaw) {}
    explicit Rotation(const Vector3f& v3);
  };

  /**
   * @brief This is a convenience class required to distinguish between regular 3D vector and set of scale factors.
   */
  struct Scale : Vector3f
  {
    Scale() = default;
    Scale(const float val) : Vector3f(val, val, val) {}
    Scale(const float _x, const float _y, const float _z) : Vector3f(_x, _y, _z) {}

    explicit Scale(const Vector3f& v3);

    Scale& operator*=(float factor);
  };

  /**
   * @brief This is a convenience class required to distinguish between regular 3D vector and set of position increments.
   */
  struct Position : Vector3f
  {
    Position() = default;
    Position(const float _x, const float _y, const float _z) : Vector3f(_x, _y, _z) {}
    explicit Position(const Vector3f& v3);

    Position operator-() const;

    bool operator==(const Position& r);
  };


  Position operator*(const float factor, const Position& p3);

  Position operator*(const Position& p3, float factor);

  /**
   * @brief This is a convenience class required to distinguish between regular 3D vector and set of position increments.
   */
  struct Direction : Vector3f
  {
    Direction() = default;
    Direction(const float _x, const float _y, const float _z);
    explicit Direction(const Vector3f& v3);

    Direction& operator=(const Vector3f& other);

    Direction operator-() const;

    Direction operator*(const float factor) const;

    bool operator==(const Direction& r) const;

    bool operator==(const Vector3f& r) const;

    static const Direction Forward;
    static const Direction Backward;
    static const Direction Up;
    static const Direction Down;
    static const Direction Right;
    static const Direction Left;
  };

  bool operator==(const Vector3f& l, const Direction& r);
  bool operator==(const Direction& l, const Vector3f& r);

  bool operator==(const Vector3f& l, const Scale& r);
  bool operator==(const Scale& l, const Vector3f& r);

  bool operator==(const Vector3f& l, const Position& r);
  bool operator==(const Position& l, const Vector3f& r);

  bool operator==(const Vector3f& l, const Vector3f& r);
}
#endif // __VECTOR3F_HPP__