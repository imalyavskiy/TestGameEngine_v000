#ifndef __MATH_3D_H__
#define __MATH_3D_H__

// TODO: replace this library with my own implementation - math.
namespace Math3D
{
    struct Vector3f
    {
        float x = 0.f;
        float y = 0.f;
        float z = 0.f;

        Vector3f() = default;

        Vector3f(const float _x, const float _y, const float _z);
    };

    struct Vector4f
    {
        float x = 0.f;
        float y = 0.f;
        float z = 0.f;
        float w = 0.f;

        Vector4f() = default;

        Vector4f(const float _x, const float _y, const float _z, const float _w);
    };

    using Rotation4f = Vector4f;
    using Scale4f    = Vector4f;
    using Position4f = Vector4f;

    struct Matrix4f
    {
        static Matrix4f Identity();

        Matrix4f(float _00, float _01, float _02, float _03, float _10, float _11, float _12, float _13, float _20, float _21, float _22, float _23, float _30, float _31, float _32, float _33);

        Matrix4f(Vector4f r0, Vector4f r1, Vector4f r2, Vector4f r3);

        Matrix4f(Position4f position, Rotation4f rotation, Scale4f scale);

        float m[4][4] = { {0.f, 0.f, 0.f, 0.f},{0.f, 0.f, 0.f, 0.f},{0.f, 0.f, 0.f, 0.f},{0.f, 0.f, 0.f, 0.f} };

        const float* data() const;
    };
}
#endif // __MATH_3D_H__
