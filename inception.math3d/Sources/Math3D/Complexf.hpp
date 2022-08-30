#ifndef __COMPLEXF_HPP__
#define __COMPLEXF_HPP__
namespace Math3D
{
  /**
   * @brief Float base complex number representation. This code was written by theoretical bases written here https://habr.com/ru/post/426863/
   */
  class Complexf
  {
  public:
    Complexf() = default;
    Complexf(float real, float imaginary);
    Complexf(const Complexf& other);

    auto re() const -> float;
    auto im() const -> float;

    auto operator+(const float r) const -> Complexf;
    auto operator+=(const float r) -> const Complexf&;

    auto operator+(const Complexf& r) const -> Complexf;
    auto operator+=(const Complexf& r) -> const Complexf&;

    auto operator-(const float r) const -> Complexf;
    auto operator-=(const float r) -> const Complexf&;

    auto operator-(const Complexf& r) const -> Complexf;
    auto operator-=(const Complexf& r) -> const Complexf&;

    // same as *(-1)
    auto operator-() const ->Complexf;

    auto operator*(const float fact) const -> Complexf;
    auto operator*=(const float fact) -> const Complexf&;

    auto operator*(const Complexf& r) const -> Complexf;
    auto operator*=(const Complexf& r) -> const Complexf&;

    auto operator/(const float div) const -> Complexf;
    auto operator/=(const float div) -> const Complexf&;

    auto operator/(const Complexf& r) const -> Complexf;
    auto operator/=(const Complexf& r) -> const Complexf&;

    auto operator==(const float r) const -> bool;
    auto operator!=(const float r) const -> bool;

    auto operator==(const Complexf& r) const -> bool;
    auto operator!=(const Complexf& r) const -> bool;

    static auto length(const Complexf& val) -> float;

    static auto conjugate(const Complexf& val) -> Complexf;

    /**
     * @return Returns a pair of roots - positive and negative.
     * Taken here - http://fxdx.ru/page/kvadratnyj-koren-iz-kompleksnogo-chisla.
     */
    static auto sqrt(const Complexf& val) -> std::pair<Complexf, Complexf>;

    /**
     * @param angle Angle in radians.
     */
    static auto rotor(const float angle) -> Complexf;

    /**
     * @remarks NOT IMPLEMENTED - Didn't get how to transform arbitrary complex number tp it's trigonometric representation.
     * https://lms2.sseu.ru/courses/eresmat/course1/razd8z1/par8_34z1.htm
     * @brief Calculates a root on arbitrary power from given argument
     * @param power The power of the requested root.
     * @param arg The argument to get root from.
     * @return List of roots. Number of roots equals the power.
     */
    static auto root(const uint32_t power, const Complexf& arg) -> std::vector<Complexf>;

    auto operator=(const Complexf& other) -> Complexf& = default;

    /**
     * @brief imaginary unit, e.g. Complexf(0.f, 1.f)
     */
    static Complexf imunit;

  protected:
    float re_ = 0.f; // real
    float im_ = 0.f; // imaginary
  };

  Complexf operator*(float l, const Complexf& r);
}
#endif // __COMPLEXF_HPP__