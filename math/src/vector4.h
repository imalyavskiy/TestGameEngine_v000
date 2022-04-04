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
            : vector3()
            , _3()
        { }

        vector4(_base_t v)
            : vector3(v)
            , _3(v)
        { }

        vector4(_base_t v0, _base_t v1, _base_t v2, _base_t v3)
            : vector3(v0, v1, v2)
            , _3(v3)
        { }

        vector4(const vector4& other)
            : vector3(other)
            , _3(other._3)
        { }

        _base_t w() const { return _3; }
        void w(_base_t w) { _3 = w; }

        _base_t a() const { return _3; }
        void a(_base_t a) { _2 = a; }

        bool operator==(const vector2& other) const {
            return _3 == other._3 && Super::operator==(other);
        }

        bool operator!=(const vector2& other) const {
            return !operator==(other);
        }

        void normalize() {
            const double len = lengthd();

            _0 = _0 / len;
            _1 = _1 / len;
            _2 = _2 / len;
            _3 = _3 / len;
        }

    protected:
        _base_t _3;
    };

    using vector4f = vector4<float>;
    using vector4d = vector4<double>;
}
#endif // __VECTOR4_H_C8D1B49E_B311_11EC_B909_0242AC120002__