#ifndef __VECTOR2_H_93FC91F8_B311_11EC_B909_0242AC120002__
#define __VECTOR2_H_93FC91F8_B311_11EC_B909_0242AC120002__
namespace math
{
    template<typename _base_t>
    class vector2 {
        friend vector2<_base_t> dot(const vector2<_base_t>&, const vector2<_base_t>&);
    public:
        vector2()
            : _0()
            , _1()
        { }

        vector2(_base_t v)
            : _0(v)
            , _1(v)
        { }

        vector2(_base_t v0, _base_t v1)
            : _0(v0)
            , _1(v1)
        { }

        vector2(const vector2& other)
            : _0(other._0)
            , _1(other._1)
        { }

        _base_t x() const { return _0; }
        void x(_base_t x) { _0 = x; }

        _base_t r() const { return _0; }
        void r(_base_t r) { _0 = r; }

        _base_t y() const { return _1; }
        void y(_base_t y) { _1 = y; }

        _base_t g() const { return _1; }
        void g(_base_t g) { _1 = g; }

        bool operator==(const vector2& other) const {
            return _0 == other._0 && _1 == other._1;
        }

        bool operator!=(const vector2& other) const {
            return !operator==(other);
        }

        vector2 operator+(const vector2& other) {
            return vector2{ _0 + other._0, _1 + other._1 };
        }

        vector2 operator-(const vector2& other) {
            return vector2{ _0 - other._0, _1 - other._1 };
        }

        vector2 operator*(_base_t v) {
            return vector2{ _0 * v, _1 * v };
        }

        const vector2& operator*=(_base_t v) {
            _0 *= v;
            _1 *= v;
            return (*this);
        }

        vector2 operator/(_base_t v) {
            return vector2{ _0 / v, _1 / v };
        }

        const vector2& operator/=(_base_t v) {
            _0 /= v;
            _1 /= v;
            return (*this);
        }

        vector2 operator -() const{
            return vector2(-_0, -_1);
        }

    protected:
        _base_t _0;
        _base_t _1;
    };

    class vector2f
        : public vector2<float>
    {
    public:
        vector2f() : vector2() 
        { }

        vector2f(float v) : vector2(v) 
        { }

        vector2f(float v0, float v1) : vector2(v0, v1) 
        { }

        vector2f(const vector2f& other) : vector2(other) 
        { }

        float length() const {
            return std::sqrtf((float)_0 * (float)_0 + (float)_1 * (float)_1);
        }

        float dot(const vector2f& _r) const {
            return _0 * _r._0 + _1 * _r._1;
        }

        const vector2f& normalize() {
            const auto len = length();
            
            _0 = _0 / len;
            _1 = _1 / len;
            
            return (*this);
        }

        bool isUnit() const {
            const auto len = length();
            return 0.99999999f <= len && len <= 1.00000001;
        }
    };

    float dot(const vector2f& left, const vector2f& right);

    class vector2d
        : public vector2<double>
    {
    public:
        vector2d() : vector2() 
        { }
        
        vector2d(double v) : vector2(v) 
        { }
        
        vector2d(double v0, double v1) : vector2(v0, v1) 
        { }
        
        vector2d(const vector2d& other) : vector2(other) 
        { }

        double length() const {
            return std::sqrt((double)_0 * (double)_0 + (double)_1 * (double)_1);
        }

        double dot(const vector2d& _r) const {
            return _0 * _r._0 + _1 * _r._1;
        }

        const vector2d& normalize() {
            const auto len = length();

            _0 = _0 / len;
            _1 = _1 / len;

            return (*this);
        }

        bool isUnit() const {
            const auto len = length();
            return 0.99999999 <= len && len <= 1.00000001;
        }
    };

    double dot(const vector2d& left, const vector2d& right);
}
#endif // __VECTOR2_H_93FC91F8_B311_11EC_B909_0242AC120002__