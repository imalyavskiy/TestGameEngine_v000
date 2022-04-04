#include <cmath>
#include "utils.h"
#include "vector2.h"
namespace math
{

    float length(const vector2f& v) {
        return v.length();
    }

    float dot(const vector2f& left, const vector2f& right) {
        return left.dot(right);
    }

    bool isUnit(const vector2f& v) {
        return v.isUnit();
    }

    double length(const vector2d& v) {
        return v.length();
    }

    double dot(const vector2d& left, const vector2d& right) {
        return left.dot(right);
    }

    bool isUnit(const vector2d& v) {
        return v.isUnit();
    }
}