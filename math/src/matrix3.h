#ifndef __MATRIX3_H_5230485A_B311_11EC_B909_0242AC120002__
#define __MATRIX3_H_5230485A_B311_11EC_B909_0242AC120002__
#include <memory>
#include "utils.h"
#include "vector3.h"

namespace math
{
    template<typename _base_t>
    class matrix3 {
    public:
        matrix3() = default;
        ~matrix3() = default;

        matrix3(_base_t i00, _base_t i01, _base_t i02, _base_t i10, _base_t i11, _base_t i12, _base_t i20, _base_t i21, _base_t i22)
            : _00(i00)
            , _01(i01)
            , _02(i02)
            , _10(i10)
            , _11(i11)
            , _12(i12)
            , _20(i20)
            , _21(i21)
            , _22(i22)
        { }

        matrix3(const matrix3& other)
            : _00(other._00)
            , _01(other._01)
            , _02(other._02)
            , _10(other._10)
            , _11(other._11)
            , _12(other._12)
            , _20(other._20)
            , _21(other._21)
            , _22(other._22)
        { }

        bool operator==(const matrix3& other) const
        {
            // It is required to roughen up the precision in order to give true when comparing original matrix with one twice inverted
            constexpr auto epsilon = (_base_t)100 * std::numeric_limits<_base_t>::epsilon();
            return std::isless(std::abs(_00 - other._00), epsilon) && std::isless(std::abs(_01 - other._01), epsilon) && std::isless(std::abs(_02 - other._02), epsilon) &&
                   std::isless(std::abs(_10 - other._10), epsilon) && std::isless(std::abs(_11 - other._11), epsilon) && std::isless(std::abs(_12 - other._12), epsilon) &&
                   std::isless(std::abs(_20 - other._20), epsilon) && std::isless(std::abs(_21 - other._21), epsilon) && std::isless(std::abs(_22 - other._22), epsilon);
        }

        bool operator!=(const matrix3& other) const
        {
            return !operator==(other);
        }

        _base_t _00 = _base_t();
        _base_t _01 = _base_t();
        _base_t _02 = _base_t();
        _base_t _10 = _base_t();
        _base_t _11 = _base_t();
        _base_t _12 = _base_t();
        _base_t _20 = _base_t();
        _base_t _21 = _base_t();
        _base_t _22 = _base_t();
    };

    template<typename _item_t>
    class matrix3impl
    {
        using item_t = _item_t;
        using data_t = matrix3<_item_t>;
        std::unique_ptr<data_t> d_;
    public:

        matrix3impl()
            : d_(std::make_unique<data_t>((item_t)1, (item_t)0, (item_t)0, (item_t)0, (item_t)1, (item_t)0, (item_t)0, (item_t)0, (item_t)1))
        { }

        matrix3impl(const matrix3impl& other)
            : d_(std::make_unique<data_t>(*other.d_))
        { }

        matrix3impl(matrix3impl&& other)
            : d_(std::move(other.d_))
        { }

        matrix3impl(_item_t v)
            : d_(std::make_unique<data_t>(v, v, v, v, v, v, v, v, v))
        { }

        matrix3impl(_item_t i00, _item_t i01, _item_t i02, _item_t i10, _item_t i11, _item_t i12, _item_t i20, _item_t i21, _item_t i22)
            : d_(std::make_unique<data_t>(i00, i01, i02, i10, i11, i12, i20, i21, i22))
        { }

        // construct by rows
        matrix3impl(const vector3_impl<_item_t>& row0, const vector3_impl<_item_t>& row1, const vector3_impl<_item_t>& row2)
            : d_(std::make_unique<data_t>(row0.x(), row0.y(), row0.z(), row1.x(), row1.y(), row1.z(), row2.x(), row2.y(), row2.z()))
        { }

        matrix3impl& operator=(const matrix3impl& other)
        {
            d_ = std::make_unique<data_t>(*other.d_);
            return (*this);
        }

        matrix3impl& operator=(matrix3impl&& other) noexcept
        {
            d_ = std::move(other.d_);
            return (*this);
        }

        matrix3impl operator*(const matrix3impl& m) const
        {
            const data_t& l = *d_;
            const data_t& r = *m.d_;

                    // 00 01 02     00 01 02     00*00 + 01*10 + 02*20  00*01 + 01*11 + 02*21  00*02 + 01*12 + 02*22
                    // 10 11 12  *  10 11 12  =  10*00 + 11*10 + 12*20  10*01 + 11*11 + 12*21  10*02 + 11*12 + 12*22
                    // 20 21 22     20 21 22     20*00 + 21*10 + 22*20  20*01 + 21*11 + 22*21  20*02 + 21*12 + 22*22

            return { l._00 * r._00 + l._01 * r._10 + l._02 * r._20,
                     l._00 * r._01 + l._01 * r._11 + l._02 * r._21,
                     l._00 * r._02 + l._01 * r._12 + l._02 * r._22,

                     l._10 * r._00 + l._11 * r._10 + l._12 * r._20,
                     l._10 * r._01 + l._11 * r._11 + l._12 * r._21,
                     l._10 * r._02 + l._11 * r._12 + l._12 * r._22,

                     l._20 * r._00 + l._21 * r._10 + l._22 * r._20,
                     l._20 * r._01 + l._21 * r._11 + l._22 * r._21,
                     l._20 * r._02 + l._21 * r._12 + l._22 * r._22 };
        }

        matrix3impl& operator*=(const matrix3impl& m)
        {
            const data_t& l = *d_;
            const data_t& r = *m.d_;

            auto data_new = std::make_unique<data_t>(
                    l._00 * r._00 + l._01 * r._10 + l._02 * r._20,
                    l._00 * r._01 + l._01 * r._11 + l._02 * r._21,
                    l._00 * r._02 + l._01 * r._12 + l._02 * r._22,
                    
                    l._10 * r._00 + l._11 * r._10 + l._12 * r._20,
                    l._10 * r._01 + l._11 * r._11 + l._12 * r._21,
                    l._10 * r._02 + l._11 * r._12 + l._12 * r._22,
                    
                    l._20 * r._00 + l._21 * r._10 + l._22 * r._20,
                    l._20 * r._01 + l._21 * r._11 + l._22 * r._21,
                    l._20 * r._02 + l._21 * r._12 + l._22 * r._22 );

            d_ = std::move(data_new);

            return (*this);
        }

        matrix3impl operator+(const matrix3impl& m) const
        {
            const data_t& l = *d_;
            const data_t& r = *m.d_;

            return { l._00 + r._00, l._01 + r._01, l._02 + r._02,
                     l._10 + r._10, l._11 + r._11, l._12 + r._12,
                     l._20 + r._20, l._21 + r._21, l._22 + r._22 };
        }

        matrix3impl& operator+=(const matrix3impl& m)
        {
            data_t& l = *d_;
            const data_t& r = *m.d_;

            l._00 += r._00;
            l._01 += r._01;
            l._02 += r._02;
            l._10 += r._10;
            l._11 += r._11;
            l._12 += r._12;
            l._20 += r._20;
            l._21 += r._21;
            l._22 += r._22;

            return (*this);
        }

        matrix3impl operator-(const matrix3impl& m) const
        {
            const data_t& l = *d_;
            const data_t& r = *m.d_;

            return { l._00 - r._00
                   , l._01 - r._01
                   , l._02 - r._02
                   , l._10 - r._10
                   , l._11 - r._11
                   , l._12 - r._12
                   , l._20 - r._20
                   , l._21 - r._21
                   , l._22 - r._22 };
        }

        matrix3impl& operator-=(const matrix3impl& m)
        {
            data_t& l = *d_;
            const data_t& r = *m.d_;

            l._00 -= r._00; l._01 -= r._01; l._02 -= r._02;
            l._10 -= r._10; l._11 -= r._11; l._12 -= r._12;
            l._20 -= r._20; l._21 -= r._21; l._22 -= r._22;

            return (*this);
        }

        matrix3impl operator*(item_t val) const
        {
            const data_t& d = *d_;
            return { val * d._00, val * d._01, val * d._02,
                     val * d._10, val * d._11, val * d._12,
                     val * d._20, val * d._21, val * d._22 };
        }

        matrix3impl operator/(item_t val) const
        {
            const data_t& d = *d_;
            return { d._00 / val, d._01 / val, d._02 / val,
                     d._10 / val, d._11 / val, d._12 / val,
                     d._20 / val, d._21 / val, d._22 / val };
        }

        matrix3impl& operator*=(item_t val)
        {
            data_t& d = *d_;

            d._00 *= val; d._01 *= val; d._02 *= val;
            d._10 *= val; d._11 *= val; d._12 *= val;
            d._20 *= val; d._21 *= val; d._22 *= val;

            return (*this);
        }

        matrix3impl operator-() const
        {
            const data_t& d = *d_;
            return { -d._00, -d._01, -d._02,
                     -d._10, -d._11, -d._12,
                     -d._20, -d._21, -d._22 };
        }

        bool operator==(const matrix3impl& other) const
        {
            return *d_ == *other.d_;
        }

        bool operator!=(const matrix3impl& other) const
        {
            return !operator==(other);
        }

        [[nodiscard]]
        item_t det() const {
            const data_t& data_l = *d_;
            return DET3(data_l._00, data_l._01, data_l._02, data_l._10, data_l._11, data_l._12, data_l._20, data_l._21, data_l._22);
        }

        [[nodiscard]]
        matrix3impl alg_complement_matrix() const
        {
            const data_t& data_l = *d_;
            return {
                +DET2(data_l._11, data_l._12, data_l._21, data_l._22),
                -DET2(data_l._10, data_l._12, data_l._20, data_l._22),
                +DET2(data_l._10, data_l._11, data_l._20, data_l._21),

                -DET2(data_l._01, data_l._02, data_l._21, data_l._22),
                +DET2(data_l._00, data_l._02, data_l._20, data_l._22),
                -DET2(data_l._00, data_l._01, data_l._20, data_l._21),

                +DET2(data_l._01, data_l._02, data_l._11, data_l._12),
                -DET2(data_l._00, data_l._02, data_l._10, data_l._12),
                +DET2(data_l._00, data_l._01, data_l._10, data_l._11)
            };
        }

        matrix3impl& transpose()
        {
            data_t& d = *d_;
            item_t tmp = d._10; d._10 = d._01; d._01 = tmp;
                   tmp = d._20; d._20 = d._02; d._02 = tmp;
                   tmp = d._21; d._21 = d._12; d._12 = tmp;

            return (*this);
        }

        matrix3impl& invert()
        {
            d_ = std::move((alg_complement_matrix().transpose() / det()).d_);
            return (*this);
        }

        [[nodiscard]]
        std::tuple<vector3_impl<item_t>, vector3_impl<item_t>, vector3_impl<item_t>> rows() const
        {
            const data_t& d = *d_;
            return { {d._00, d._01, d._02}, {d._10, d._11, d._12}, {d._20, d._21, d._22} };
        }

        [[nodiscard]]
        std::tuple<vector3_impl<item_t>, vector3_impl<item_t>, vector3_impl<item_t>> columns() const
        {
            const data_t& d = *d_;
            return { {d._00, d._10, d._20}, {d._01, d._11, d._21}, {d._02, d._12, d._22} };
        }

        static matrix3impl identity()
        {
            return matrix3impl((item_t)1, (item_t)0, (item_t)0, (item_t)0, (item_t)1, (item_t)0, (item_t)0, (item_t)0, (item_t)1);
        }

        static matrix3impl zero()
        {
            return matrix3impl((item_t)0, (item_t)0, (item_t)0, (item_t)0, (item_t)0, (item_t)0, (item_t)0, (item_t)0, (item_t)0);
        }
    };

    using matrix3f = matrix3impl<float>;
    using matrix3d = matrix3impl<double>;

    inline float det(const math::matrix3f& m)
    {
        return m.det();
    }

    inline double det(const math::matrix3d& m)
    {
        return m.det();
    }
}

inline math::matrix3f operator*(float scalar, const math::matrix3f& matrix)
{
    return matrix * scalar;
}

inline math::matrix3d operator*(double scalar, const math::matrix3d& matrix)
{
    return matrix * scalar;
}
#endif // __MATRIX3_H_5230485A_B311_11EC_B909_0242AC120002__