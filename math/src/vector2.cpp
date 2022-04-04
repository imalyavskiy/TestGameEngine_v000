#include <cmath>
#include "utils.h"
#include "vector2.h"
namespace math
{
    float dot(const vector2f& left, const vector2f& right) {
        return left.dot(right);
    }

    double dot(const vector2d& left, const vector2d& right) {
        return left.dot(right);
    }
}