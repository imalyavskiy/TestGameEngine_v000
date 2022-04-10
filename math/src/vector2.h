#ifndef __VECTOR2_H_93FC91F8_B311_11EC_B909_0242AC120002__
#define __VECTOR2_H_93FC91F8_B311_11EC_B909_0242AC120002__

#include <memory>
#include "utils.h"
#include "vector2.h"

namespace math
{
    template<typename _item_t>
    class vector2 {
    public:
        vector2() = default;
        ~vector2() = default;
        vector2(const vector2&) = default;
        vector2(vector2&&) = default;
        vector2& operator=(const vector2&) = default;
        vector2& operator=(vector2&&) = default;

        vector2(_item_t i0, _item_t i1)
            : _0(i0)
            , _1(i1)
        { }

        _item_t _0 = _item_t();
        _item_t _1 = _item_t();
    };

    template<typename _item_t>
    class vector2_impl
    {
        using data_t = vector2<_item_t>;
    protected:
        std::unique_ptr<data_t> d_;

    public:
        using item_t = _item_t;

        vector2_impl()
            : d_(std::make_unique<data_t>(static_cast<_item_t>(0), static_cast<_item_t>(0)))
        { }

        ~vector2_impl() = default;

        explicit vector2_impl(_item_t v)
            : d_(std::make_unique<data_t>(v, v))
        { }

        vector2_impl(_item_t v0, _item_t v1)
            : d_(std::make_unique<data_t>(v0, v1))
        { }

        vector2_impl(const vector2_impl& other)
            : d_(std::make_unique<data_t>(other.d_->_0, other.d_->_1))
        { }

        vector2_impl(vector2_impl&& other) noexcept
            : d_(std::move(other.d_))
        { }

        vector2_impl& operator=(const vector2_impl& other)
        {
            d_ = std::make_unique<data_t>(*other.d_);
            return (*this);
        }

        vector2_impl& operator=(vector2_impl&& other) noexcept
        {
            d_ = std::move(other.d_);
            return (*this);
        }

        bool operator==(const vector2_impl& other) const
        {
            const auto &l = *d_, &r = *other.d_;
            return l._0 == r._0 && l._1 == r._1;
        }

        bool operator!=(const vector2_impl& other) const { return !operator==(other); }

        [[nodiscard]]
        _item_t x() const { return d_->_0; }
        void x(const _item_t x) { d_->_0 = x; }

        [[nodiscard]]
        _item_t r() const { return d_->_0; }
        void r(const _item_t r) { d_->_0 = r; }

        [[nodiscard]]
        _item_t y() const { return d_->_1; }
        void y(const _item_t y) { d_->_1 = y; }

        [[nodiscard]]
        _item_t g() const { return d_->_1; }
        void g(const _item_t g) { d_->_1 = g; }


        vector2_impl operator+(const vector2_impl& other) {
            const auto &l = *d_, &r = *other.d_;
            return { l._0 + r._0, l._1 + r._1 };
        }

        vector2_impl operator-(const vector2_impl& other) {
            const auto &l = *d_, &r = *other.d_;
            return { l._0 - r._0, l._1 - r._1 };
        }

        vector2_impl operator*(_item_t v) {
            const auto &d = *d_;
            return { d._0 * v, d._1 * v };
        }

        const vector2_impl& operator*=(_item_t v) {
            auto &d = *d_;
            d._0 *= v; d._1 *= v;
            return (*this);
        }

        vector2_impl operator/(_item_t v) {
            const auto& d = *d_;
            return vector2_impl{ d._0 / v, d._1 / v };
        }

        const vector2_impl& operator/=(_item_t v) {
            auto& d = *d_;
            d._0 /= v; d._1 /= v;
            return (*this);
        }

        vector2_impl operator -() const{
            const auto &d = *d_;
            return { -d._0, -d._1 };
        }

        [[nodiscard]]
        _item_t length() const {
            const auto &d = *d_;
            return std::sqrt(d._0 * d._0 + d._1 * d._1);
        }

        [[nodiscard]]
        _item_t dot(const vector2_impl& r) const {
            return x() * r.x() + y() * r.y();
        }

        const vector2_impl& normalize() {
            const auto len = length();
            auto &d = *d_;
            d._0 = d._0 / len;
            d._1 = d._1 / len;

            return (*this);
        }

        [[nodiscard]]
        bool is_unit() const {
            const auto len = length();
            return static_cast<_item_t>(0.999999) <= len && len <= static_cast<_item_t>(1.000001);
        }
    };

    using vector2f = vector2_impl<float>;
    using vector2d = vector2_impl<double>;
}
#endif // __VECTOR2_H_93FC91F8_B311_11EC_B909_0242AC120002__