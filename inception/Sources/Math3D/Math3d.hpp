#ifndef __MATH_3D_H__
#define __MATH_3D_H__
namespace Math3D
{
    struct Vector3f
    {
        float x = 0.f;
        float y = 0.f;
        float z = 0.f;

        Vector3f() = default;

        Vector3f(const float _x, const float _y, const float _z)
            : x(_x), y(_y), z(_z)
        {
        }
    };
}
#endif
