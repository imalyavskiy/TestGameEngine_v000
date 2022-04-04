#include <cmath>
#include "utils.h"
#include "vector2.h"
#include "vector3.h"

namespace math
{
    const vector3f vector3f::X = vector3f(1.f, 0.f, 0.f);
    const vector3f vector3f::Y = vector3f(0.f, 1.f, 0.f);
    const vector3f vector3f::Z = vector3f(0.f, 0.f, 1.f);

    const vector3d vector3d::X = vector3d(1.0, 0.0, 0.0);
    const vector3d vector3d::Y = vector3d(0.0, 1.0, 0.0);
    const vector3d vector3d::Z = vector3d(0.0, 0.0, 1.0);

    float dot(const vector3f& left, const vector3f& right) {
        return left.dot(right);
    }

    vector3f cross(const vector3f& _l, const vector3f& _r) {
        return _l.cross(_r);
    }

    double dot(const vector3d& left, const vector3d& right) {
        return left.dot(right);
    }

    vector3d cross(const vector3d& _l, const vector3d& _r) {
        return _l.cross(_r);
    }
}