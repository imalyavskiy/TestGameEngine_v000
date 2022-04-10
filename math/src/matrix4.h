#ifndef __MATRIX4_H_73D68B2C_B311_11EC_B909_0242AC120002__
#define __MATRIX4_H_73D68B2C_B311_11EC_B909_0242AC120002__
#include <memory>
#include "utils.h"
#include "vector4.h"
namespace math
{
    template<typename _base_t>
    class matrix4 {
    public:
        matrix4() = default;
        ~matrix4() = default;

        matrix4(_base_t i00, _base_t i01, _base_t i02, _base_t i03, 
                _base_t i10, _base_t i11, _base_t i12, _base_t i13, 
                _base_t i20, _base_t i21, _base_t i22, _base_t i23, 
                _base_t i30, _base_t i31, _base_t i32, _base_t i33)
            : _00(i00), _01(i01), _02(i02), _03(i03)
            , _10(i10), _11(i11), _12(i12), _13(i13)
            , _20(i20), _21(i21), _22(i22), _23(i23)
            , _30(i30), _31(i31), _32(i32), _33(i33)
        { }

        matrix4(const matrix4& other)
            : _00(other._00), _01(other._01), _02(other._02), _03(other._03)
            , _10(other._10), _11(other._11), _12(other._12), _13(other._13)
            , _20(other._20), _21(other._21), _22(other._22), _23(other._23)
            , _30(other._30), _31(other._31), _32(other._32), _33(other._33)
        { }

        bool operator==(const matrix4& other) const
        {
            // It is required to roughen up the precision in order to give true when comparing original matrix with one twice inverted
            constexpr auto epsilon = (_base_t)100 * std::numeric_limits<_base_t>::epsilon();
            return std::isless(std::abs(_00 - other._00), epsilon) && std::isless(std::abs(_01 - other._01), epsilon) && std::isless(std::abs(_02 - other._02), epsilon) && std::isless(std::abs(_03 - other._03), epsilon) &&
                   std::isless(std::abs(_10 - other._10), epsilon) && std::isless(std::abs(_11 - other._11), epsilon) && std::isless(std::abs(_12 - other._12), epsilon) && std::isless(std::abs(_13 - other._13), epsilon) &&
                   std::isless(std::abs(_20 - other._20), epsilon) && std::isless(std::abs(_21 - other._21), epsilon) && std::isless(std::abs(_22 - other._22), epsilon) && std::isless(std::abs(_23 - other._23), epsilon) &&
                   std::isless(std::abs(_30 - other._30), epsilon) && std::isless(std::abs(_31 - other._31), epsilon) && std::isless(std::abs(_32 - other._32), epsilon) && std::isless(std::abs(_33 - other._33), epsilon);
        }

        bool operator!=(const matrix4& other) const
        {
            return !operator==(other);
        }

        _base_t _00 = _base_t(); _base_t _01 = _base_t(); _base_t _02 = _base_t(); _base_t _03 = _base_t();
        _base_t _10 = _base_t(); _base_t _11 = _base_t(); _base_t _12 = _base_t(); _base_t _13 = _base_t();
        _base_t _20 = _base_t(); _base_t _21 = _base_t(); _base_t _22 = _base_t(); _base_t _23 = _base_t();
        _base_t _30 = _base_t(); _base_t _31 = _base_t(); _base_t _32 = _base_t(); _base_t _33 = _base_t();
    };

    template<typename _item_t>
    class matrix4impl
    {
        using item_t = _item_t;
        using data_t = matrix4<_item_t>;
        std::unique_ptr<data_t> d_;
    public:

        matrix4impl()
            : d_(std::make_unique<data_t>((item_t)1, (item_t)0, (item_t)0, (item_t)0, 
                                          (item_t)0, (item_t)1, (item_t)0, (item_t)0, 
                                          (item_t)0, (item_t)0, (item_t)1, (item_t)0,
                                          (item_t)0, (item_t)0, (item_t)0, (item_t)1))
        { }

        matrix4impl(const matrix4impl& other)
            : d_(std::make_unique<data_t>(*other.d_))
        { }

        matrix4impl(matrix4impl&& other)
            : d_(std::move(other.d_))
        { }

        matrix4impl(_item_t v)
            : d_(std::make_unique<data_t>(v, v, v, v, v, v, v, v, v, v, v, v, v, v, v, v))
        { }

        matrix4impl(_item_t i00, _item_t i01, _item_t i02, _item_t i03, 
                    _item_t i10, _item_t i11, _item_t i12, _item_t i13, 
                    _item_t i20, _item_t i21, _item_t i22, _item_t i23,
                    _item_t i30, _item_t i31, _item_t i32, _item_t i33
        )
            : d_(std::make_unique<data_t>(i00, i01, i02, i03, 
                                             i10, i11, i12, i13, 
                                             i20, i21, i22, i23,
                                             i30, i31, i32, i33
                ))
        { }

        // construct by rows
        matrix4impl(const vector4_impl<_item_t>& row0, 
                    const vector4_impl<_item_t>& row1, 
                    const vector4_impl<_item_t>& row2, 
                    const vector4_impl<_item_t>& row3)
            : d_(std::make_unique<data_t>(row0.x(), row0.y(), row0.z(), row0.w(), 
                                             row1.x(), row1.y(), row1.z(), row1.w(), 
                                             row2.x(), row2.y(), row2.z(), row2.w(),
                                             row3.x(), row3.y(), row3.z(), row3.w()))
        { }

        matrix4impl& operator=(const matrix4impl& other)
        {
            d_ = std::make_unique<data_t>(*other.d_);
            return (*this);
        }

        matrix4impl& operator=(matrix4impl&& other) noexcept
        {
            d_ = std::move(other.d_);
            return (*this);
        }

        matrix4impl operator*(const matrix4impl& m) const
        {
            const data_t& l = *d_;
            const data_t& r = *m.d_;

            // 00 01 02 03     00 01 02 03    00*00 + 01*10 + 02*20 + 03*30   00*01 + 01*11 + 02*21 + 03*31   00*02 + 01*12 + 02*22 + 03*32   00*03 + 01*13 + 02*23 + 03*33
            // 10 11 12 13  *  10 11 12 13 =  10*00 + 11*10 + 12*20 + 13*30   10*01 + 11*11 + 12*21 + 13*31   10*02 + 11*12 + 12*22 + 13*32   10*03 + 11*13 + 12*23 + 13*33
            // 20 21 22 23     20 21 22 23 =  20*00 + 21*10 + 22*20 + 23*30   20*01 + 21*11 + 22*21 + 23*31   20*02 + 21*12 + 22*22 + 23*32   20*03 + 21*13 + 22*23 + 23*33
            // 30 31 32 33     30 31 32 33    30*00 + 31*10 + 32*20 + 33*30   30*01 + 31*11 + 32*21 + 33*31   30*02 + 31*12 + 32*22 + 33*32   30*03 + 31*13 + 32*23 + 33*33

            return {
                 l._00 * r._00 + l._01 * r._10 + l._02 * r._20 + l._03 * r._30,
                 l._00 * r._01 + l._01 * r._11 + l._02 * r._21 + l._03 * r._31,
                 l._00 * r._02 + l._01 * r._12 + l._02 * r._22 + l._03 * r._32,
                 l._00 * r._03 + l._01 * r._13 + l._02 * r._23 + l._03 * r._33,

                 l._10 * r._00 + l._11 * r._10 + l._12 * r._20 + l._13 * r._30,
                 l._10 * r._01 + l._11 * r._11 + l._12 * r._21 + l._13 * r._31,
                 l._10 * r._02 + l._11 * r._12 + l._12 * r._22 + l._13 * r._32,
                 l._10 * r._03 + l._11 * r._13 + l._12 * r._23 + l._13 * r._33,

                 l._20 * r._00 + l._21 * r._10 + l._22 * r._20 + l._23 * r._30,
                 l._20 * r._01 + l._21 * r._11 + l._22 * r._21 + l._23 * r._31,
                 l._20 * r._02 + l._21 * r._12 + l._22 * r._22 + l._23 * r._32,
                 l._20 * r._03 + l._21 * r._13 + l._22 * r._23 + l._23 * r._33,

                 l._30 * r._00 + l._31 * r._10 + l._32 * r._20 + l._33 * r._30,
                 l._30 * r._01 + l._31 * r._11 + l._32 * r._21 + l._33 * r._31,
                 l._30 * r._02 + l._31 * r._12 + l._32 * r._22 + l._33 * r._32,
                 l._30 * r._03 + l._31 * r._13 + l._32 * r._23 + l._33 * r._33,
            };
        }

        matrix4impl& operator*=(const matrix4impl& m)
        {
            const data_t& l = *d_;
            const data_t& r = *m.d_;

            auto data_new = std::make_unique<data_t>(
                l._00 * r._00 + l._01 * r._10 + l._02 * r._20 + l._03 * r._30,
                l._00 * r._01 + l._01 * r._11 + l._02 * r._21 + l._03 * r._31,
                l._00 * r._02 + l._01 * r._12 + l._02 * r._22 + l._03 * r._32,
                l._00 * r._03 + l._01 * r._13 + l._02 * r._23 + l._03 * r._33,

                l._10 * r._00 + l._11 * r._10 + l._12 * r._20 + l._13 * r._30,
                l._10 * r._01 + l._11 * r._11 + l._12 * r._21 + l._13 * r._31,
                l._10 * r._02 + l._11 * r._12 + l._12 * r._22 + l._13 * r._32,
                l._10 * r._03 + l._11 * r._13 + l._12 * r._23 + l._13 * r._33,

                l._20 * r._00 + l._21 * r._10 + l._22 * r._20 + l._23 * r._30,
                l._20 * r._01 + l._21 * r._11 + l._22 * r._21 + l._23 * r._31,
                l._20 * r._02 + l._21 * r._12 + l._22 * r._22 + l._23 * r._32,
                l._20 * r._03 + l._21 * r._13 + l._22 * r._23 + l._23 * r._33,

                l._30 * r._00 + l._31 * r._10 + l._32 * r._20 + l._33 * r._30,
                l._30 * r._01 + l._31 * r._11 + l._32 * r._21 + l._33 * r._31,
                l._30 * r._02 + l._31 * r._12 + l._32 * r._22 + l._33 * r._32,
                l._30 * r._03 + l._31 * r._13 + l._32 * r._23 + l._33 * r._33
            );

            d_ = std::move(data_new);

            return (*this);
        }

        matrix4impl operator+(const matrix4impl& m) const
        {
            const data_t& l = *d_;
            const data_t& r = *m.d_;

            return {
                l._00 + r._00, l._01 + r._01, l._02 + r._02, l._03 + r._03,
                l._10 + r._10, l._11 + r._11, l._12 + r._12, l._13 + r._13,
                l._20 + r._20, l._21 + r._21, l._22 + r._22, l._23 + r._23,
                l._30 + r._30, l._31 + r._31, l._32 + r._32, l._33 + r._33
            };
        }

        matrix4impl& operator+=(const matrix4impl& m)
        {
            data_t& l = *d_;
            const data_t& r = *m.d_;

            l._00 += r._00; l._01 += r._01; l._02 += r._02; l._03 += r._03;
            l._10 += r._10; l._11 += r._11; l._12 += r._12; l._13 += r._13;
            l._20 += r._20; l._21 += r._21; l._22 += r._22; l._23 += r._23;
            l._30 += r._30; l._31 += r._31; l._32 += r._32; l._33 += r._33;

            return (*this);
        }

        matrix4impl operator-(const matrix4impl& m) const
        {
            const data_t& l = *d_;
            const data_t& r = *m.d_;

            return {
                l._00 - r._00, l._01 - r._01, l._02 - r._02, l._03 - r._03,
                l._10 - r._10, l._11 - r._11, l._12 - r._12, l._13 - r._13,
                l._20 - r._20, l._21 - r._21, l._22 - r._22, l._23 - r._23,
                l._30 - r._30, l._31 - r._31, l._32 - r._32, l._33 - r._33
            };
        }

        matrix4impl& operator-=(const matrix4impl& m)
        {
            data_t& l = *d_;
            const data_t& r = *m.d_;

            l._00 -= r._00; l._01 -= r._01; l._02 -= r._02; l._03 -= r._03;
            l._10 -= r._10; l._11 -= r._11; l._12 -= r._12; l._13 -= r._13;
            l._20 -= r._20; l._21 -= r._21; l._22 -= r._22; l._23 -= r._23;
            l._30 -= r._30; l._31 -= r._31; l._32 -= r._32; l._33 -= r._33;

            return (*this);
        }

        matrix4impl operator*(item_t val) const
        {
            const data_t& d = *d_;
            return {
                val * d._00, val * d._01, val * d._02, val * d._03,
                val * d._10, val * d._11, val * d._12, val * d._13,
                val * d._20, val * d._21, val * d._22, val * d._23,
                val * d._30, val * d._31, val * d._32, val * d._33,
            };
        }

        matrix4impl operator/(item_t v) const
        {
            const data_t& d = *d_;
            return {
                d._00 / v, d._01 / v, d._02 / v, d._03 / v,
                d._10 / v, d._11 / v, d._12 / v, d._13 / v,
                d._20 / v, d._21 / v, d._22 / v, d._23 / v,
                d._30 / v, d._31 / v, d._32 / v, d._33 / v,
            };
        }

        matrix4impl& operator*=(item_t v)
        {
            data_t& d = *d_;

            d._00 *= v; d._01 *= v; d._02 *= v; d._03 *= v;
            d._10 *= v; d._11 *= v; d._12 *= v; d._13 *= v;
            d._20 *= v; d._21 *= v; d._22 *= v; d._23 *= v;
            d._30 *= v; d._31 *= v; d._32 *= v; d._33 *= v;

            return (*this);
        }

        matrix4impl operator-() const
        {
            const data_t& d = *d_;
            return {
                -d._00, -d._01, -d._02, -d._03,
                -d._10, -d._11, -d._12, -d._13,
                -d._20, -d._21, -d._22, -d._23,
                -d._30, -d._31, -d._32, -d._33
            };
        }

        bool operator==(const matrix4impl& other) const
        {
            return *d_ == *other.d_;
        }

        bool operator!=(const matrix4impl& other) const
        {
            return !operator==(other);
        }

        [[nodiscard]]
        item_t det() const {
            const data_t& d = *d_;
            return + d._00 * DET3(d._11, d._12, d._13, d._21, d._22, d._23, d._31, d._32, d._33)
                   - d._01 * DET3(d._10, d._12, d._13, d._20, d._22, d._23, d._30, d._32, d._33)
                   + d._02 * DET3(d._10, d._11, d._13, d._20, d._21, d._23, d._30, d._31, d._33)
                   - d._03 * DET3(d._10, d._11, d._12, d._20, d._21, d._22, d._30, d._31, d._32);
        }

        [[nodiscard]]
        matrix4impl alg_complement_matrix() const
        {
            const data_t& d = *d_;

            //  |11 12 13|   |10 12 13|   |10 11 13|   |10 11 12|
            // +|21 22 23|  -|20 22 23|  +|20 21 23|  -|20 21 22| 
            //  |31 32 33|   |30 32 33|   |30 31 33|   |30 31 32|

            //  |01 02 03|   |00 02 03|   |00 01 03|   |00 01 02|
            // -|21 22 23|  +|20 22 23|  -|20 21 23|  +|20 21 22|
            //  |31 32 33|   |30 32 33|   |30 31 33|   |30 31 32|
            
            //  |01 02 03|   |00 02 03|   |00 01 03|   |00 01 02|
            // +|11 12 13|  -|10 12 13|  +|10 11 13|  -|10 11 12|
            //  |31 32 33|   |30 32 33|   |30 31 33|   |30 31 32|

            //  |01 02 03|   |00 02 03|   |00 01 03|   |00 01 02|
            // -|11 12 13|  +|10 12 13|  -|10 11 13|  +|10 11 12|
            //  |21 22 23|   |20 22 23|   |20 21 23|   |20 21 22|

            return {
                +DET3(d._11, d._12, d._13, d._21, d._22, d._23, d._31, d._32, d._33), 
                    -DET3(d._10, d._12, d._13, d._20, d._22, d._23, d._30, d._32, d._33),
                        +DET3(d._10, d._11, d._13, d._20, d._21, d._23, d._30, d._31, d._33),
                            -DET3(d._10, d._11, d._12, d._20, d._21, d._22, d._30, d._31, d._32),
                -DET3(d._01, d._02, d._03, d._21, d._22, d._23, d._31, d._32, d._33), 
                    +DET3(d._00, d._02, d._03, d._20, d._22, d._23, d._30, d._32, d._33),
                        -DET3(d._00, d._01, d._03, d._20, d._21, d._23, d._30, d._31, d._33),
                            +DET3(d._00, d._01, d._02, d._20, d._21, d._22, d._30, d._31, d._32),
                +DET3(d._01, d._02, d._03, d._11, d._12, d._13, d._31, d._32, d._33), 
                    -DET3(d._00, d._02, d._03, d._10, d._12, d._13, d._30, d._32, d._33),
                        +DET3(d._00, d._01, d._03, d._10, d._11, d._13, d._30, d._31, d._33),
                            -DET3(d._00, d._01, d._02, d._10, d._11, d._12, d._30, d._31, d._32),
                -DET3(d._01, d._02, d._03, d._11, d._12, d._13, d._21, d._22, d._23), 
                    +DET3(d._00, d._02, d._03, d._10, d._12, d._13, d._20, d._22, d._23),
                        -DET3(d._00, d._01, d._03, d._10, d._11, d._13, d._20, d._21, d._23),
                            +DET3(d._00, d._01, d._02, d._10, d._11, d._12, d._20, d._21, d._22)
            };
        }

        matrix4impl& transpose()
        {
            data_t& d = *d_;
            item_t tmp = d._10; d._10 = d._01; d._01 = tmp;
                   tmp = d._20; d._20 = d._02; d._02 = tmp;
                   tmp = d._30; d._30 = d._03; d._03 = tmp;
                   tmp = d._21; d._21 = d._12; d._12 = tmp;
                   tmp = d._31; d._31 = d._13; d._13 = tmp;
                   tmp = d._32; d._32 = d._23; d._23 = tmp;
                   return (*this);
        }
 
        matrix4impl& invert()
        {
            auto m0 = alg_complement_matrix();
            m0.transpose();
            //d_ = std::move((alg_complement_matrix().transpose() / det()).d_);
            d_ = std::move((m0 / det()).d_);
            return (*this);
        }

        [[nodiscard]]
        std::tuple<vector4_impl<item_t>, vector4_impl<item_t>, vector4_impl<item_t>, vector4_impl<item_t>> rows() const
        {
            const data_t& d = *d_;
            return {
                {d._00, d._01, d._02, d._03},
                {d._10, d._11, d._12, d._13},
                {d._20, d._21, d._22, d._23},
                {d._30, d._31, d._32, d._33},
            };
        }

        [[nodiscard]]
        std::tuple<vector4_impl<item_t>, vector4_impl<item_t>, vector4_impl<item_t>, vector4_impl<item_t>> columns() const
        {
            const data_t& d = *d_;
            return {
                {d._00, d._10, d._20, d._30},
                {d._01, d._11, d._21, d._31},
                {d._02, d._12, d._22, d._32},
                {d._03, d._13, d._23, d._33},
            };
        }

        static matrix4impl identity()
        {
            const item_t zero = 0;
            const item_t unit = 1;
            return {
                unit, zero, zero, zero,
                zero, unit, zero, zero,
                zero, zero, unit, zero,
                zero, zero, zero, unit,
            };
        }

        static matrix4impl zero()
        {
            const item_t zero = 0;
            return {
                zero, zero, zero, zero,
                zero, zero, zero, zero,
                zero, zero, zero, zero,
                zero, zero, zero, zero,
            };
        }
    };

    using matrix4f = matrix4impl<float>;
    using matrix4d = matrix4impl<double>;

    inline float det(const math::matrix4f& m)
    {
        return m.det();
    }

    inline double det(const math::matrix4d& m)
    {
        return m.det();
    }
}

inline math::matrix4f operator*(float scalar, const math::matrix4f& matrix)
{
    return matrix * scalar;
}

inline math::matrix4d operator*(double scalar, const math::matrix4d& matrix)
{
    return matrix * scalar;
}

#endif // __MATRIX4_H_73D68B2C_B311_11EC_B909_0242AC120002__