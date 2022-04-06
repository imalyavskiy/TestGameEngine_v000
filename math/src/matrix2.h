#ifndef __MATRIX2_H_30433216_B311_11EC_B909_0242AC120002__
#define __MATRIX2_H_30433216_B311_11EC_B909_0242AC120002__

#include <memory>
#include "vector2.h"

namespace math
{
    template<typename _base_t>
    class matrix2 {
    public:
        matrix2() = default;
        ~matrix2() = default;

        matrix2(_base_t i00, _base_t i01, _base_t i10, _base_t i11)
            : _00(i00)
            , _01(i01)
            , _10(i10)
            , _11(i11)
        { }

        matrix2(const matrix2& other)
            : _00(other._00)
            , _01(other._01)
            , _10(other._10)
            , _11(other._11)
        { }

        bool operator==(const matrix2& other) const
        {
            return _00 == other._00 && _01 == other._01 && _10 == other._10 && _11 == other._11;
        }

        bool operator!=(const matrix2& other) const
        {
            return !operator==(other);
        }

        _base_t _00 = _base_t();
        _base_t _01 = _base_t();
        _base_t _10 = _base_t();
        _base_t _11 = _base_t();
    };

    template<typename _item_t>
    class matrix2impl
    {
        using item_t = _item_t;
        using data_t = matrix2<_item_t>;
        std::unique_ptr<data_t> data_;
    public:

        matrix2impl()
            : data_(std::make_unique<data_t>((item_t)1, (item_t)0, (item_t)0, (item_t)1))
        { }

        matrix2impl(const matrix2impl& other)
            : data_(std::make_unique<data_t>(*other.data_))
        { }

        matrix2impl(matrix2impl&& other)
            : data_(std::move(other.data_))
        { }

        matrix2impl(_item_t v)
            : data_(std::make_unique<data_t>(v, v, v, v))
        { }

        matrix2impl(_item_t i00, _item_t i01, _item_t i10, _item_t i11)
            : data_(std::make_unique<data_t>(i00, i01, i10, i11))
        { }

        // construct by rows
        matrix2impl(const vector2<_item_t>& row0, const vector2<_item_t>& row1)
            : data_(std::make_unique<data_t>(row0.x(), row0.y(), row1.x(), row1.y()))
        { }

        matrix2impl& operator=(const matrix2impl& other)
        {
            data_ = std::make_unique<data_t>(*other.data_);
            return (*this);
        }

        matrix2impl& operator=(matrix2impl&& other) noexcept
        {
            data_ = std::move(other.data_);
            return (*this);
        }

        matrix2impl operator*(const matrix2impl& m) const
        {
            const data_t& data_l = *data_;
            const data_t& data_r = *m.data_;

            return { data_l._00 * data_r._00 + data_l._01 * data_r._10
                     , data_l._00 * data_r._01 + data_l._01 * data_r._11
                     , data_l._10 * data_r._00 + data_l._11 * data_r._10
                     , data_l._10 * data_r._01 + data_l._11 * data_r._11 };
        }

        matrix2impl& operator*=(const matrix2impl& m)
        {
            const data_t& data_l = *data_;
            const data_t& data_r = *m.data_;

            auto data_new = std::make_unique<data_t>
                ( data_l._00 * data_r._00 + data_l._01 * data_r._10
                , data_l._00 * data_r._01 + data_l._01 * data_r._11
                , data_l._10 * data_r._00 + data_l._11 * data_r._10
                , data_l._10 * data_r._01 + data_l._11 * data_r._11 );

            data_ = std::move(data_new);

            return (*this);
        }

        matrix2impl operator+(const matrix2impl& m) const
        {
            const data_t& data_l = *data_;
            const data_t& data_r = *m.data_;

            return { data_l._00 + data_r._00
                     , data_l._01 + data_r._01
                     , data_l._10 + data_r._10
                     , data_l._11 + data_r._11 };
        }

        matrix2impl& operator+=(const matrix2impl& m)
        {
            data_t& data_l = *data_;
            const data_t& data_r = *m.data_;

            data_l._00 += data_r._00;
            data_l._01 += data_r._01;
            data_l._10 += data_r._10;
            data_l._11 += data_r._11;

            return (*this);
        }

        matrix2impl operator-(const matrix2impl& m) const
        {
            const data_t& data_l = *data_;
            const data_t& data_r = *m.data_;

            return { data_l._00 - data_r._00
                   , data_l._01 - data_r._01
                   , data_l._10 - data_r._10
                   , data_l._11 - data_r._11 };
        }

        matrix2impl& operator-=(const matrix2impl& m)
        {
            data_t& data_l = *data_;
            const data_t& data_r = *m.data_;

            data_l._00 -= data_r._00;
            data_l._01 -= data_r._01;
            data_l._10 -= data_r._10;
            data_l._11 -= data_r._11;

            return (*this);
        }

        matrix2impl operator*(item_t val) const
        {
            const data_t& data_l = *data_;
            return { val * data_l._00, val * data_l._01, val * data_l._10, val * data_l._11 };
        }

        matrix2impl operator/(item_t val) const
        {
            const data_t& data_l = *data_;
            return { data_l._00 / val, data_l._01 / val, data_l._10 / val, data_l._11 / val };
        }

        matrix2impl& operator*=(item_t val)
        {
            data_t& data_l = *data_;

            data_l._00 *= val;
            data_l._01 *= val;
            data_l._10 *= val;
            data_l._11 *= val;

            return (*this);
        }

        matrix2impl operator-() const
        {
            const data_t& data_l = *data_;
            return { -data_l._00, -data_l._01, -data_l._10, -data_l._11 };
        }

        bool operator==(const matrix2impl& other) const
        {
            return *data_ == *other.data_;
        }

        bool operator!=(const matrix2impl& other) const
        {
            return !operator==(other);
        }

        [[nodiscard]]
        item_t det() const {
            const data_t& data_l = *data_;
            return data_l._00 * data_l._11 - data_l._01 * data_l._10;
        }

        [[nodiscard]]
        matrix2impl alg_complement_matrix() const
        {
            const data_t& data_l = *data_;
            return { data_l._11, -data_l._10, -data_l._01, data_l._00 };
        }

        matrix2impl& invert()
        {
            data_ = std::move((alg_complement_matrix().transpose() * ((item_t)1 / det())).data_);
            return (*this);
        }

        matrix2impl& transpose()
        {
            data_t& data_l = *data_;
            const auto t = data_l._10;
            data_l._10 = data_l._01;
            data_l._01 = t;

            return (*this);
        }

        std::tuple<vector2<item_t>, vector2<item_t>> rows() const
        {
            const data_t& data_l = *data_;
            return { {data_l._00, data_l._01}, {data_l._10, data_l._11} };
        }

        std::tuple<vector2<item_t>, vector2<item_t>> columns() const
        {
            const data_t& data_l = *data_;
            return { {data_l._00, data_l._10}, {data_l._01, data_l._11} };
        }

        static matrix2impl identity()
        {
            return matrix2impl((item_t)1, (item_t)0, (item_t)0, (item_t)1);
        }

        static matrix2impl zero()
        {
            return matrix2impl((item_t)0, (item_t)0, (item_t)0, (item_t)0);
        }
    };

    using matrix2f = matrix2impl<float>;
    using matrix2d = matrix2impl<double>;

    inline float det(const math::matrix2f& m)
    {
        return m.det();
    }

    inline double det(const math::matrix2d& m)
    {
        return m.det();
    }
}

inline math::matrix2f operator*(float scalar, const math::matrix2f& matrix)
{
    return matrix * scalar;
}

inline math::matrix2d operator*(double scalar, const math::matrix2d& matrix)
{
    return matrix * scalar;
}

#endif // __MATRIX2_H_30433216_B311_11EC_B909_0242AC120002__