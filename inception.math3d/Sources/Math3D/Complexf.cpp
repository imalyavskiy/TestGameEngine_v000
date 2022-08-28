#include "pch.hpp"
#include "Math3D.hpp"
namespace Math3D
{
  Complexf Complexf::imunit = Complexf(0.f, 1.f);

  Complexf::Complexf(float real, float imaginary)
    : re_(real)
    , im_(imaginary)
  {
  }

  Complexf::Complexf(const Complexf& other)
    : re_(other.re_)
    , im_(other.im_)
  {
  }

  float Complexf::re() const
  {
    return re_;
  }

  float Complexf::im() const
  {
    return im_;
  }

  auto Complexf::operator+(const float r) const -> Complexf
  {
    return {re_ + r, im_};
  }

  auto Complexf::operator+=(const float r) -> const Complexf&
  {
    re_ += r;

    return (*this);
  }

  Complexf Complexf::operator+(const Complexf& r) const
  {
    return {re() + r.re(), im() + r.im()};
  }

  const Complexf& Complexf::operator+=(const Complexf& r)
  {
    re_ += r.re_;
    im_ += r.im_;

    return (*this);
  }

  Complexf Complexf::operator-(const float r) const
  {
    return { re_ - r, im_ };
  }

  const Complexf& Complexf::operator-=(const float r)
  {
    re_ -= r;
  
    return (*this);
  }

  Complexf Complexf::operator-(const Complexf& r) const
  {
    return { re() - r.re(), im() - r.im() };
  }

  const Complexf& Complexf::operator-=(const Complexf& r)
  {
    re_ -= r.re_;
    im_ -= r.im_;

    return (*this);
  }

  Complexf Complexf::operator-() const
  {
    return {-re_, -im_};
  }

  Complexf Complexf::operator*(const float fact) const
  {
    return {
      re_ * fact,
      im_ * fact
    };
  }

  const Complexf& Complexf::operator*=(const float fact)
  {
    re_ *= fact;
    im_ *= fact;

    return (*this);
  };

  Complexf Complexf::operator*(const Complexf& r) const
  {
    return {
      re_ * r.re_ - im_ * r.im_,
      re_ * r.im_ + im_ * r.re_
    };
  }

  const Complexf& Complexf::operator*=(const Complexf& r)
  {
    const float re = re_;
    const float im = im_;
    re_ = re * r.re_ - im * r.im_;
    im_ = re * r.im_ + im * r.re_;

    return (*this);
  }

  Complexf Complexf::operator/(const float div) const
  {
    return {
      re_ / div,
      im_ / div
    };
  }

  const Complexf& Complexf::operator/=(const float div)
  {
    re_ /= div;
    im_ /= div;

    return (*this);
  }

  Complexf Complexf::operator/(const Complexf& r) const
  {
    const float div = r.re_ * r.re_ + r.im_ * r.im_;
    return {
      (re_ * r.re_ + im_ * r.im_)/div,
      (im_ * r.re_ - re_ * r.im_)/div
    };
  }

  const Complexf& Complexf::operator/=(const Complexf& r)
  {
    const float div = r.re_ * r.re_ + r.im_ * r.im_;
    const float re = re_;
    const float im = im_;
    re_ = (re * r.re_ + im * r.im_) / div;
    im_ = (im * r.re_ - re * r.im_) / div;
    return (*this);
  }

  bool Complexf::operator==(const float r) const
  {
    return std::abs(re() - r) <= imprecision && std::abs(im()) <= imprecision;
  }

  bool Complexf::operator!=(const float r) const
  {
    return !operator==(r);
  }

  bool Complexf::operator==(const Complexf& r) const
  {
    const float re = std::abs(re_ - r.re_);
    const float im = std::abs(im_ - r.im_);
    return re <= imprecision && im <= imprecision;
  }

  bool Complexf::operator!=(const Complexf& r) const
  {
    return !operator==(r);
  }

  float Complexf::length(const Complexf& val)
  {
    return std::sqrt(val.re_ * val.re_ + val.im_ * val.im_);
  }

  Complexf Complexf::conjugate(const Complexf& val)
  {
    return { val.re_, -val.im_ };
  }

  auto Complexf::sqrt(const Complexf& val) -> std::pair<Complexf, Complexf>
  {
    const float sign = val.im_ >= 0 ? 1.f : -1.f;
    const Complexf result {
      std::sqrt((std::sqrt(val.re_ * val.re_ + val.im_ * val.im_) + val.re_) / 2.f),
      sign * std::sqrt((std::sqrt(val.re_ * val.re_ + val.im_ * val.im_) - val.re_) / 2.f)
    };
    return {result, -result};
  }

  auto Complexf::rotor(const float angle) -> Complexf
  {
    return { std::cosf(angle), std::sinf(angle) };
  }

  auto Complexf::root(const uint32_t power, const Complexf& arg) -> std::vector<Complexf>
  {
    if (power < 2)
      throw std::logic_error("invalid power value");

//    std::vector<Complexf> rootList(power);
//    const float l = length(arg);
//    const float phi = std::acos(arg.re() / l);
//    const float psi = std::asin(arg.im() / l);
//
//    const float r = rootf(l, power);
//
//    for(size_t cr = 0; cr < power; ++cr)
//    {
//      const float arg = (2 * PI * cr) / power;
//      rootList[cr] =
//        r * Complexf(std::cosf(arg), std::sinf(arg));
//    }
//
//    return rootList;
    throw std::logic_error("not implemented");
  }

  Complexf operator*(float l, const Complexf& r)
  {
    return { l * r.re(), l * r.im() };
  }
}
