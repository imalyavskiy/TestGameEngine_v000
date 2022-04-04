#ifndef __VECTOR3_H_B208B79E_B311_11EC_B909_0242AC120002__
#define __VECTOR3_H_B208B79E_B311_11EC_B909_0242AC120002__

namespace math
{
    template<typename _base_t>
    class vector3
        : public vector2<_base_t>
    {
        using Super = vector2<_base_t>;
    public:
        vector3()
            : Super()
            , _2()
        {

        }

        vector3(_base_t v)
            : Super(v)
            , _2(v)
        {

        }

        vector3(_base_t v0, _base_t v1, _base_t v2)
            : Super(v0, v1)
            , _2(v2)
        {

        }

        vector3(const vector3& other)
            : Super(other)
            , _2(other._2)
        {

        }

        _base_t z() const { return _2; }
        void z(_base_t z) { _2 = z; }

        _base_t b() const { return _2; }
        void b(_base_t b) { _2 = b; }

        bool operator==(const vector3& other) const {
            return _2 == other._2 && Super::operator==(other);
        }

        bool operator!=(const vector3& other) const {
            return !operator==(other);
        }

        vector3 operator+(const vector3& other) {
            return vector3{ Super::_0 + other._0, Super::_1 + other._1, _2 + other._2 };
        }

        vector3 operator-(const vector3& other) {
            return vector3{ Super::_0 - other._0, Super::_1 - other._1, _2 - other._2 };
        }

        vector3 operator*(_base_t v) {
            return vector3{ Super::_0 * v, Super::_1 * v, _2 * v };
        }

        const vector3& operator*=(_base_t v) {
            Super::operator*=(v);
            _2 *= v;
            return (*this);
        }

        vector3 operator/(_base_t v) {
            return vector3{ Super::_0 / v, Super::_1 / v, _2 / v };
        }

        const vector3& operator/=(_base_t v) {
            Super::operator/=(v);
            _2 /= v;
            return (*this);
        }

        vector3 operator-() const{
            return vector3(-Super::_0, -Super::_1, -_2);
        }

    protected:
        _base_t _2;
    };

    class vector3f
        : public vector3<float>
    {
    public:
        static const vector3f X;
        static const vector3f Y;
        static const vector3f Z;

        vector3f() : vector3()
        { }

        vector3f(float v) : vector3(v)
        { }

        vector3f(float v0, float v1, float v2) : vector3(v0, v1, v2)
        { }

        vector3f(const vector2& v01, float v2) : vector3(v01.x(), v01.y(), v2)
        { }

        vector3f(float v0, const vector2& v12) : vector3(v0, v12.x(), v12.y())
        { }

        vector3f(const vector3f& other) : vector3(other)
        { }

        vector3f(const vector3<float>& other) : vector3(other)
        { }

        float length() const {
            return std::sqrtf(_0*_0 + _1*_1 + _2*_2);
        }

        float dot(const vector3f& _r) const {
            return _0*_r._0 + _1*_r._1 + _2*_r._2;
        }

        const vector3f& normalize() {
            const auto len = length();
            
            _0 = _0 / len;
            _1 = _1 / len;
            _2 = _2 / len;

            return (*this);
        }

        bool isUnit() const {
            const auto len = length();
            return 0.9999999f <= len && len <= 1.0000001;
        }

        vector3f cross(const vector3f& _r) const {
            return 
#ifdef USE_RIGH_HAND_BASIS
            // RH basis: +1.f * (a.z*b.y - a.y*b.z, a.x*b.z - a.z*b.x, a.y*b.x - a.x*b.y)
            vector3f(_2 * _r._1 - _1 * _r._2, _0 * _r._2 - _2 * _r._0, _1 * _r._0 - _0 * _r._1) * +1.f;
#else
            // LH basis: -1.f * (a.z*b.y - a.y*b.z, a.x*b.z - a.z*b.x, a.y*b.x - a.x*b.y)
            vector3f(_2 * _r._1 - _1 * _r._2, _0 * _r._2 - _2 * _r._0, _1 * _r._0 - _0 * _r._1) * -1.f;
#endif
        }
    };

    float dot(const vector3f& left, const vector3f& right);

    vector3f cross(const vector3f& _l, const vector3f& _r);

    class vector3d
        : public vector3<double>
    {
    public:

        static const vector3d X;
        static const vector3d Y;
        static const vector3d Z;

        vector3d() : vector3()
        { }

        vector3d(double v) : vector3(v)
        { }

        vector3d(double v0, double v1, double v2) : vector3(v0, v1, v2)
        { }

        vector3d(const vector2& v01, double v2) : vector3(v01.x(), v01.y(), v2)
        { }

        vector3d(double v0, const vector2& v12) : vector3(v0, v12.x(), v12.y())
        { }

        vector3d(const vector3d& other) : vector3(other)
        { }

        vector3d(const vector3<double>& other) : vector3(other)
        { }

        double length() const {
            return std::sqrt(_0 * _0 + _1 * _1 + _2 * _2);
        }

        double dot(const vector3d& _r) const {
            return _0 * _r._0 + _1 * _r._1 + _2 * _r._2;
        }

        const vector3d& normalize() {
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

        vector3d cross(const vector3d& _r) const {
            return
#ifdef USE_RIGH_HAND_BASIS
                // RH basis: +1.f * (a.z*b.y - a.y*b.z, a.x*b.z - a.z*b.x, a.y*b.x - a.x*b.y)
                vector3d(_2 * _r._1 - _1 * _r._2, _0 * _r._2 - _2 * _r._0, _1 * _r._0 - _0 * _r._1) * +1.f;
#else
                // LH basis: -1.f * (a.z*b.y - a.y*b.z, a.x*b.z - a.z*b.x, a.y*b.x - a.x*b.y)
                vector3d(_2 * _r._1 - _1 * _r._2, _0 * _r._2 - _2 * _r._0, _1 * _r._0 - _0 * _r._1) * -1.f;
#endif
        }
    };

    double dot(const vector3d& left, const vector3d& right);

    vector3d cross(const vector3d& _l, const vector3d& _r);
}
#endif // __VECTOR3_H_B208B79E_B311_11EC_B909_0242AC120002__