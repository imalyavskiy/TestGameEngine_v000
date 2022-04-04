#ifndef __VECTOR4_H_C8D1B49E_B311_11EC_B909_0242AC120002__
#define __VECTOR4_H_C8D1B49E_B311_11EC_B909_0242AC120002__
namespace math
{
    template<typename _base_t>
    class vector4
        : public vector3<_base_t>
    {
        using Super = vector3<_base_t>;
    public:
        vector4()
            : Super()
            , _3()
        { }

        vector4(_base_t v)
            : Super(v)
            , _3(v)
        { }

        vector4(_base_t v0, _base_t v1, _base_t v2, _base_t v3)
            : Super(v0, v1, v2)
            , _3(v3)
        { }

        vector4(const vector4& other)
            : Super(other)
            , _3(other._3)
        { }

        _base_t w() const { return _3; }
        void w(_base_t w) { _3 = w; }

        _base_t a() const { return _3; }
        void a(_base_t a) { Super::_2 = a; }

        vector2<_base_t> xy() const { return { Super::_0, Super::_1 }; }
        const vector4<_base_t>& xy(const vector2<_base_t>& xy) { Super::_0 = xy.x(); Super::_1 = xy.y(); return (*this); }

        vector2<_base_t> rg() const { return { Super::_0, Super::_1 }; }
        const vector4<_base_t>& rg(const vector2<_base_t>& rg) { Super::_0 = rg.r(); Super::_1 = rg.g(); return (*this); }

        vector2<_base_t> yz() const { return { Super::_1, Super::_2 }; }
        const vector4<_base_t>& yz(const vector2<_base_t>& yz) { Super::_1 = yz.x(); Super::_2 = yz.y();  return (*this); }

        vector2<_base_t> gb() const { return { Super::_1, Super::_2 }; }
        const vector4<_base_t>& gb(const vector2<_base_t>& gb) { Super::_1 = gb.r(); Super::_2 = gb.g();  return (*this); }

        vector3<_base_t> xyz() const { return { Super::_0, Super::_1, Super::_2 }; }
        const vector4<_base_t>& xyz(const vector3<_base_t>& xyz) { Super::_0 = xyz.x(); Super::_1 = xyz.y(); Super::_2 = xyz.z(); return (*this); }

        vector3<_base_t> rgb() const { return { Super::_0, Super::_1, Super::_2 }; }
        const vector4<_base_t>& rgb(const vector3<_base_t>& rgb) { Super::_0 = rgb.r(); Super::_1 = rgb.g(); Super::_2 = rgb.b(); return (*this); }

        bool operator==(const vector4& other) const {
            return _3 == other._3 && Super::operator==(other);
        }

        bool operator==(const vector3<_base_t>& other) const {
            return Super::operator==(other);
        }

        bool operator!=(const vector4& other) const {
            return !(_3 == other._3 && operator==(other));
        }

        bool operator!=(const vector3<_base_t>& other) const {
            return !(operator==(other));
        }

    protected:
        _base_t _3;
    };

    class vector4f
        : public vector4<float>
    {
        using Super = vector4<float>;
    public:
        static const vector4f X;
        static const vector4f Y;
        static const vector4f Z;

        vector4f() : vector4()
        { }

        vector4f(float v) : vector4(v)
        { }

        vector4f(float v0, float v1, float v2, float v3 = 0.f) : vector4(v0, v1, v2, v3)
        { }

        vector4f(const vector2& v01, float v2, float v3 = 0.f) : vector4(v01.x(), v01.y(), v2, v3)
        { }

        vector4f(float v0, const vector2& v12, float v3 = 0.f) : vector4(v0, v12.x(), v12.y(), v3)
        { }

        vector4f(const vector3& v012, float v3 = 0.f) : vector4(v012.x(), v012.y(), v012.z(), v3)
        { }

        vector4f(const vector4f& other) : vector4(other)
        { }

        vector4f(const vector4<float>& other) : vector4(other)
        { }

        float length() const {
            return std::sqrtf(_0*_0 + _1*_1 + _2*_2);
        }

        float dot(const vector4f& _r) const {
            return Super::_0 * _r._0 + Super::_1 * _r._1 + Super::_2 * _r._2;
        }

        const vector4f& normalize() {
            const auto len = length();

            Super::_0 = Super::_0 / len;
            Super::_1 = Super::_1 / len;
            Super::_2 = Super::_2 / len;

            return (*this);
        }

        bool isUnit() const {
            const auto len = length();
            return 0.9999999f <= len && len <= 1.0000001f;
        }

        vector4f cross(const vector4f& _r) const {
            return
#ifdef USE_RIGH_HAND_BASIS
                // RH basis: +1.f * (a.z*b.y - a.y*b.z, a.x*b.z - a.z*b.x, a.y*b.x - a.x*b.y)
                vector4f(_2 * _r._1 - _1 * _r._2, _0 * _r._2 - _2 * _r._0, _1 * _r._0 - _0 * _r._1) * +1.f;
#else
                // LH basis: -1.f * (a.z*b.y - a.y*b.z, a.x*b.z - a.z*b.x, a.y*b.x - a.x*b.y)
                vector4f{ _2 * _r._1 - _1 * _r._2,
                          _0 * _r._2 - _2 * _r._0,
                          _1 * _r._0 - _0 * _r._1 } *-1.f;
#endif
        }
    };

    float length(const vector4f& v);

    float dot(const vector4f& left, const vector4f& right);

    vector4f cross(const vector4f& _l, const vector4f& _r);

    bool isUnit(const vector4f& v);

    class vector4d
        : public vector4<double>
    {
        using Super = vector4<double>;
    public:

        static const vector4d X;
        static const vector4d Y;
        static const vector4d Z;

        vector4d() : vector4()
        { }

        vector4d(double v) : vector4(v)
        { }

        vector4d(double v0, double v1, double v2, double v3 = 0.0) : vector4(v0, v1, v2, v3)
        { }

        vector4d(const vector2& v01, double v2, double v3 = 0.0) : vector4(v01.x(), v01.y(), v2, v3)
        { }

        vector4d(double v0, const vector2& v12, double v3 = 0.0) : vector4(v0, v12.x(), v12.y(), v3)
        { }

        vector4d(const vector3& v012, double v3 = 0.0) : vector4(v012.x(), v012.y(), v012.z(), v3)
        { }

        vector4d(const vector4d& other) : vector4(other)
        { }

        vector4d(const vector4<double>& other) : vector4(other)
        { }

        double length() const {
            return std::sqrt(_0 * _0 + _1 * _1 + _2 * _2);
        }

        double dot(const vector4d& _r) const {
            return _0 * _r._0 + _1 * _r._1 + _2 * _r._2;
        }

        const vector4d& normalize() {
            const auto len = length();

            _0 = _0 / len;
            _1 = _1 / len;
            _2 = _2 / len;

            return (*this);
        }

        bool isUnit() const {
            const auto len = length();
            return 0.99999999f <= len && len <= 1.00000001;
        }

        vector3d cross(const vector4d& _r) const {
            return
#ifdef USE_RIGH_HAND_BASIS
                // RH basis: +1.f * (a.z*b.y - a.y*b.z, a.x*b.z - a.z*b.x, a.y*b.x - a.x*b.y)
                vector3d(_2 * _r._1 - _1 * _r._2, _0 * _r._2 - _2 * _r._0, _1 * _r._0 - _0 * _r._1) * +1.f;
#else
                // LH basis: -1.f * (a.z*b.y - a.y*b.z, a.x*b.z - a.z*b.x, a.y*b.x - a.x*b.y)
                vector4d( _2 * _r._1 - _1 * _r._2, 
                            _0 * _r._2 - _2 * _r._0, 
                            _1 * _r._0 - _0 * _r._1 ) * -1.f;
#endif
        }
    };

    double length(const vector4d& v);

    double dot(const vector4d& left, const vector4d& right);

    vector4d cross(const vector4d& _l, const vector4d& _r);

    bool isUnit(const vector4d& v);
}
#endif // __VECTOR4_H_C8D1B49E_B311_11EC_B909_0242AC120002__