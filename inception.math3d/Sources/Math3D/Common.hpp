#ifndef __COMMON_HPP__
#define __COMMON_HPP__
namespace Math3D
{
  static const float PI = 3.14159265f;

  /**
   * @brief used as an error to compare floating point numbers
   */
  constexpr float imprecision = 0.000001f;

  /**
   * @brief Converts degrees to radians.
   */
  inline auto DegToRad(float x) -> float
  {
    return x * PI / 180.0f;
  }

  /**
   * @brief Converts radians to degrees.
   */
  inline auto RadToDeg(float x) -> float
  {
    return x * 180.0f / PI;
  }

  /**
   * @brief Calculates a n-th of a number.
   * @param num The number to get the n-th root of.
   * @param n The n of the root.
   * @remarks Taken here(https://stackoverflow.com/a/21142383)
   */
  inline auto root(const double num, const double n) -> double {
    constexpr double eps = 10e-6;

    auto exp = [](double a, double b) -> double {
      double t(1.);
      for (int i = 0; i < b; ++i)
        t *= a;
      return t;
    };

    double x = num * 0.5;
    double dx = (num / exp(x, n - 1) - x) / n;
    while (dx >= eps || dx <= -eps) {
      x = x + dx;
      dx = (num / exp(x, n - 1) - x) / n;
    }
    return x;
  }

  /**
   * @brief Calculates a n-th of a number(float version).
   * @param num The number to get the n-th root of.
   * @param n The n of the root.
   * @remarks Taken here(https://stackoverflow.com/a/21142383)
   */
  inline auto rootf(const float num, const float n) -> float {
    constexpr float eps = 10e-6f;

    auto exp = [](float a, float b) -> float {
      float t(1.f);
      for (int i = 0; i < b; ++i)
        t *= a;
      return t;
    };

    float x = num * .5f;
    float dx = (num / exp(x, n - 1) - x) / n;
    while (dx >= eps || dx <= -eps) {
      x = x + dx;
      dx = (num / exp(x, n - 1) - x) / n;
    }
    return x;
  }
}
#endif // __COMMON_HPP__