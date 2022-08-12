#ifndef __MATH_3D_H__
#define __MATH_3D_H__

// TODO: replace this library with my own implementation - math.
namespace Math3D
{
    static const float PI = 3.14159265f;

    inline float DegToRad(float x) 
    { 
        return x * PI / 180.0f; 
    }

    inline float RadToDeg(float x) 
    { 
        return x * 180.0f / PI;
    }

    struct Vector3f
    {
        float x = 0.f;
        float y = 0.f;
        float z = 0.f;

        Vector3f() = default;

        Vector3f(const float _x, const float _y, const float _z);
    };

    struct Rotation : Vector3f
    {
        Rotation() = default;
        Rotation(const float roll, const float pitch, const float yaw) : Vector3f(roll, pitch, yaw) {}
    };

    struct Scale : Vector3f
    {
        Scale() = default;
        Scale(const float val) : Vector3f(val, val, val) {}
        Scale(const float _x, const float _y, const float _z) : Vector3f(_x, _y, _z) {}
    };

    struct Position : Vector3f
    {
        Position() = default;
        Position(const float _x, const float _y, const float _z) : Vector3f(_x, _y, _z) {}
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

    struct Matrix4f
    {
        Matrix4f() = default;

        Matrix4f(float _00, float _01, float _02, float _03, float _10, float _11, float _12, float _13, float _20, float _21, float _22, float _23, float _30, float _31, float _32, float _33);

        Matrix4f(Vector4f r0, Vector4f r1, Vector4f r2, Vector4f r3);

        float m[4][4] = {{0.f, 0.f, 0.f, 0.f},{0.f, 0.f, 0.f, 0.f},{0.f, 0.f, 0.f, 0.f},{0.f, 0.f, 0.f, 0.f}};

        const float* data() const;

        inline Matrix4f operator*(const Matrix4f& Right) const
        {
            Matrix4f Ret;

            for (size_t i = 0; i < 4; i++) {
                for (size_t j = 0; j < 4; j++) {
                    Ret.m[i][j] = m[i][0] * Right.m[0][j] +
                                  m[i][1] * Right.m[1][j] +
                                  m[i][2] * Right.m[2][j] +
                                  m[i][3] * Right.m[3][j];
                }
            }

            return Ret;
        }
    };

    struct Transform
    {
        static Matrix4f Identity();

        static Matrix4f Projection(float fov, float width, float height, float zNear, float zFar);

        static Matrix4f Create(Position position, Rotation rotation, Scale scale);

        static Matrix4f Create(Position position);

        static Matrix4f Create(Rotation rotation);

        static Matrix4f Create(Scale scale);
    
    private:
        static Matrix4f projectionMatrix_;
    };
}
#endif // __MATH_3D_H__
