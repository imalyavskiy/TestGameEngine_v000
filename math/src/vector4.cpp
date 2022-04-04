#include <cmath>
#include "utils.h"
#include "vector2.h"
#include "vector3.h"
#include "vector4.h"

namespace math
{
    const vector4f vector4f::X = vector4f(1.f, 0.f, 0.f);
    const vector4f vector4f::Y = vector4f(0.f, 1.f, 0.f);
    const vector4f vector4f::Z = vector4f(0.f, 0.f, 1.f);

    const vector4d vector4d::X = vector4d(1.0, 0.0, 0.0);
    const vector4d vector4d::Y = vector4d(0.0, 1.0, 0.0);
    const vector4d vector4d::Z = vector4d(0.0, 0.0, 1.0);

    float length(const vector4f& v) {
        return v.length();
    }

    float dot(const vector4f& left, const vector4f& right) {
        return left.dot(right);
    }

    vector4f cross(const vector4f& _l, const vector4f& _r) {
        return _l.cross(_r);
    }

    bool isUnit(const vector4f& v) {
        return v.isUnit();
    }

    double length(const vector4d& v) {
        return v.length();
    }

    double dot(const vector4d& left, const vector4d& right) {
        return left.dot(right);
    }

    vector4d cross(const vector4d& _l, const vector4d& _r) {
        return _l.cross(_r);
    }

    bool isUnit(const vector4d& v) {
        return v.isUnit();
    }
}