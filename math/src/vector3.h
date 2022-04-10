#ifndef __VECTOR3_H_B208B79E_B311_11EC_B909_0242AC120002__
#define __VECTOR3_H_B208B79E_B311_11EC_B909_0242AC120002__

#include "vector2.h"

namespace math
{
    template<typename _item_t>
    struct vector3 {
        vector3() = default;
        ~vector3() = default;
        vector3(const vector3&) = default;
        vector3(vector3&&) = default;
        vector3& operator=(const vector3&) = default;
        vector3& operator=(vector3&&) = default;

        vector3(_item_t i0, _item_t i1, _item_t i2)
            : _0(i0)
            , _1(i1)
            , _2(i2)
        { }

        _item_t _0 = _item_t();
        _item_t _1 = _item_t();
        _item_t _2 = _item_t();
    };

    template<typename ItemT>
    class vector3_impl
    {
        using data_t = vector3<ItemT>;

    protected:
        std::unique_ptr<data_t> d_;

    public:
        using item_t = ItemT;

        static const vector3_impl X;
        static const vector3_impl Y;
        static const vector3_impl Z;

        vector3_impl()
            : d_(std::make_unique<data_t>(static_cast<item_t>(0), static_cast<item_t>(0), static_cast<item_t>(0)))
        { }

        ~vector3_impl() = default;

        explicit vector3_impl(ItemT v)
            : d_(std::make_unique<data_t>(v, v, v))
        { }

        vector3_impl(ItemT v0, ItemT v1, ItemT v2)
            : d_(std::make_unique<data_t>(v0, v1, v2))
        { }

        vector3_impl(const vector3_impl& other)
            : d_(std::make_unique<data_t>(other.d_->_0, other.d_->_1, other.d_->_2))
        { }

        vector3_impl(vector3_impl&& other) noexcept
            : d_(std::move(other.d_))
        { }

        vector3_impl(const vector2_impl<ItemT>& v01, const ItemT v2)
            : vector3_impl(v01.x(), v01.y(), v2)
        { }

        vector3_impl(const ItemT v0, const vector2_impl<ItemT>& v12)
            : vector3_impl(v0, v12.x(), v12.y())
        { }

        vector3_impl& operator=(const vector3_impl& other)
        {
            d_ = std::make_unique<data_t>(*other.d_);
            return (*this);
        }

        vector3_impl& operator=(vector3_impl&& other) noexcept
        {
            d_ = std::move(other.d_);
            return (*this);
        }

        bool operator==(const vector3_impl& other) const
        {
            const auto& l = *d_, & r = *other.d_;
            return l._0 == r._0 && l._1 == r._1 && l._2 == r._2;
        }

        bool operator!=(const vector3_impl& other) const { return !operator==(other); }

        [[nodiscard]]
        ItemT x() const { return d_->_0; }
        void x(ItemT x) { d_->_0 = x; }

        [[nodiscard]]
        ItemT r() const { return d_->_0; }
        void r(const ItemT r) { d_->_0 = r; }

        [[nodiscard]]
        ItemT y() const { return d_->_1; }
        void y(const ItemT y) { d_->_1 = y; }

        [[nodiscard]]
        ItemT g() const { return d_->_1; }
        void g(const ItemT g) { d_->_1 = g; }

        [[nodiscard]]
        ItemT z() const { return d_->_2; }
        void z(const ItemT z) { d_->_2 = z; }

        [[nodiscard]]
        ItemT b() const { return d_->_2; }
        void b(const ItemT b) { d_->_2 = b; }

        [[nodiscard]]
        vector2_impl<ItemT> xy() const { return { d_->_0, d_->_1 }; }
        vector3_impl& xy(const vector2_impl<ItemT>& v01) { d_->_0 = v01.x(); d_->_1 = v01.y(); return (*this); }

        [[nodiscard]]
        vector2_impl<ItemT> rg() const { return { d_->_0, d_->_1 }; }
        vector3_impl& rg(const vector2_impl<ItemT>& v01) { d_->_0 = v01.x(); d_->_1 = v01.y(); return (*this); }

        [[nodiscard]]
        vector2_impl<ItemT> yz() const { return { d_->_1, d_->_2 }; }
        vector3_impl& yz(const vector2_impl<ItemT>& v12) { d_->_1 = v12.x(); d_->_2 = v12.y(); return (*this); }

        [[nodiscard]]
        vector2_impl<ItemT> gb() const { return { d_->_1, d_->_2 }; }
        vector3_impl& gb(const vector2_impl<ItemT>& v12) { d_->_1 = v12.x(); d_->_2 = v12.y(); return (*this); }

        vector3_impl operator+(const vector3_impl& other) {
            const auto &l = *d_, &r = *other.d_;
            return { l._0 + r._0, l._1 + r._1, l._2 + r._2 };
        }

        vector3_impl operator-(const vector3_impl& other) {
            const auto &l = *d_, &r = *other.d_;
            return { l._0 - r._0, l._1 - r._1, l._2 - r._2 };
        }

        vector3_impl operator*(ItemT v) {
            auto &d = *d_;
            return { d._0 * v, d._1 * v, d._2 * v };
        }

        const vector3_impl& operator*=(ItemT v) {
            const auto &d = *d_;
            d._0 *= v; d._1 *= v; d._2 *= v;
            return (*this);
        }

        vector3_impl operator/(ItemT v) {
            const auto &d = *d_;
            return { d._0 / v, d._1 / v, d._2 / v };
        }

        const vector3_impl& operator/=(ItemT v) {
            const auto &d = *d_;
            d._0 /= v;
            d._1 /= v;
            d._2 /= v;
            return (*this);
        }

        vector3_impl operator -() const {
            const auto &d = *d_;
            return { -d._0, -d._1, -d._2 };
        }

        [[nodiscard]]
        ItemT length() const {
            const auto &d = *d_;
            return std::sqrt(d._0 * d._0 + d._1 * d._1 + d._2 * d._2);
        }

        [[nodiscard]]
        ItemT dot(const vector3_impl& r) const {
            return x() * r.x() + y() * r.y() + z() * r.z();
        }

        const vector3_impl& normalize() {
            const auto len = length();
            auto &d = *d_;
            d._0 = d._0 / len;
            d._1 = d._1 / len;
            d._2 = d._2 / len;

            return (*this);
        }

        [[nodiscard]]
        vector3_impl cross(const vector3_impl& other) const {
            const auto &l = *d_, &r = *other.d_;
#ifdef USE_RIGH_HAND_BASIS
                // RH basis: +1.f * (a.z*b.y - a.y*b.z, a.x*b.z - a.z*b.x, a.y*b.x - a.x*b.y)
            return vector3_impl(l._2 * r._1 - l._1 * r._2, l._0 * r._2 - l._2 * r._0, l._1 * r._0 - l._0 * r._1) * +static_cast<ItemT>(1);
#else
                // LH basis: -1.f * (a.z*b.y - a.y*b.z, a.x*b.z - a.z*b.x, a.y*b.x - a.x*b.y)
            return vector3_impl(l._2 * r._1 - l._1 * r._2, l._0 * r._2 - l._2 * r._0, l._1 * r._0 - l._0 * r._1) * -static_cast<ItemT>(1);
#endif
        }

        [[nodiscard]]
        bool is_unit() const {
            const auto len = length();
            return static_cast<ItemT>(0.999999) <= len && len <= static_cast<ItemT>(1.000001);
        }
    };

    template<typename ItemT>
    const vector3_impl<ItemT> vector3_impl<ItemT>::X = vector3_impl<ItemT>(static_cast<ItemT>(1), static_cast<ItemT>(0), static_cast<ItemT>(0));
    template<typename ItemT>
    const vector3_impl<ItemT> vector3_impl<ItemT>::Y = vector3_impl<ItemT>(static_cast<ItemT>(0), static_cast<ItemT>(1), static_cast<ItemT>(0));
    template<typename ItemT>
    const vector3_impl<ItemT> vector3_impl<ItemT>::Z = vector3_impl<ItemT>(static_cast<ItemT>(0), static_cast<ItemT>(0), static_cast<ItemT>(1));

    using vector3f = vector3_impl<float>;
    using vector3d = vector3_impl<double>;
}
#endif // __VECTOR3_H_B208B79E_B311_11EC_B909_0242AC120002__