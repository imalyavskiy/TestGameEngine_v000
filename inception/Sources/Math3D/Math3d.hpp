#ifndef __MATH_3D_H__
#define __MATH_3D_H__

// TODO: replace this library with my own implementation - math.
namespace Math3D
{
    static const float PI = 3.14159265f;

    /**
     * @brief Converts degrees to radians.
     */
    inline float DegToRad(float x)
    { 
        return x * PI / 180.0f; 
    }

    /**
     * @brief Converts radians to degrees.
     */
    inline float RadToDeg(float x)
    { 
        return x * 180.0f / PI;
    }

    /**
     * @brief Three dimensional floating point vector.
     */
    struct Vector3f
    {
        float x = 0.f;
        float y = 0.f;
        float z = 0.f;

        Vector3f() = default;

        Vector3f(const Vector3f& other) = default;

        Vector3f(const float _x, const float _y, const float _z);

        Vector3f& Normalize();

        Vector3f operator-() const
        {
            return { -x, -y, -z };
        }
    };

    /**
     * @brief Vector cross product.
     */
    Vector3f Cross(const Vector3f& l, const Vector3f& r);

    /**
     * @brief Returns normalized version of the given vector.
     */
    Vector3f Normalized(const Vector3f& v);


    /**
     * @brief This is a convenience class required to distinguish between regular 3D vector and set of rotation angles, aka rotator.
     */
    struct Rotation : Vector3f
    {
        Rotation() = default;
        Rotation(const float roll, const float pitch, const float yaw) : Vector3f(roll, pitch, yaw) {}
    };

    /**
     * @brief This is a convenience class required to distinguish between regular 3D vector and set of scale factors.
     */
    struct Scale : Vector3f
    {
        Scale() = default;
        Scale(const float val) : Vector3f(val, val, val) {}
        Scale(const float _x, const float _y, const float _z) : Vector3f(_x, _y, _z) {}
    };

    /**
     * @brief This is a convenience class required to distinguish between regular 3D vector and set of position increments.
     */
    struct Position : Vector3f
    {
        Position() = default;
        Position(const float _x, const float _y, const float _z) : Vector3f(_x, _y, _z) {}

        Position operator-() const { return { -x, -y, -z }; }
    };


    Position operator*(const float factor, const Position& p3);

    Position operator*(const Position& p3, float factor);

    /**
     * @brief This is a convenience class required to distinguish between regular 3D vector and set of position increments.
     */
    struct Direction : Vector3f
    {
        Direction() = default;
        Direction(const float _x, const float _y, const float _z) : Vector3f(_x, _y, _z) {}
    };


    /**
     * @brief Three dimensional floating point vector with 4th coordinate required by homogeneous coordinates.
     */
    struct Vector4f
    {
        float x = 0.f;
        float y = 0.f;
        float z = 0.f;
        float w = 0.f;

        Vector4f() = default;

        /**
         * @brief Initializes homogeneous coordinate item. Caller have to choose whether it a point or a vector.
         */
        Vector4f(const Vector3f& v3, const float _w);

        /**
         * @brief Initializes homogeneous coordinate point(component w == 1)
         */
        Vector4f(const Position& p3);

        /**
         * @brief Initializes homogeneous coordinate vector(component w == 0)
         */
        Vector4f(const Direction& d3);

        /**
         * @brief Initializes homogeneous coordinate item by component..
         */
        Vector4f(const float _x, const float _y, const float _z, const float _w);
    };

    /**
     * @brief Four dimensional square matrix used to perform calculations in homogeneous coordinates.
     *        By default the initial matrix is ZERO matrix.
     */
    struct Matrix4f
    {
        Matrix4f() = default;

        Matrix4f( float _00, float _01, float _02, float _03,
                  float _10, float _11, float _12, float _13,
                  float _20, float _21, float _22, float _23,
                  float _30, float _31, float _32, float _33 );

        Matrix4f(Vector4f r0, Vector4f r1, Vector4f r2, Vector4f r3);

        float m[4][4] = {
            { 0.f, 0.f, 0.f, 0.f },
            { 0.f, 0.f, 0.f, 0.f },
            { 0.f, 0.f, 0.f, 0.f },
            { 0.f, 0.f, 0.f, 0.f }
        };

        const float* data() const;

        /**
         * @brief Implements matrix multiplication algorithm.
         */
        Matrix4f operator*(const Matrix4f& right) const;
    };

    /**
     * @brief This class contains constructors for special matrices
     *        such as translation, scale, rotation and projection.
     */
    struct Transform
    {
        static Transform& Instance();

        static Matrix4f Identity();

        static Matrix4f Projection(float fov, uint32_t width, uint32_t height, float zNear, float zFar);

        static Matrix4f ViewRotation(const Direction& direction, const Direction& up);

        static Matrix4f Create(const Position& position);

        static Matrix4f Create(const Rotation& rotation);

        static Matrix4f Create(const Scale& scale);

        void SetTransform(const Position& position, const Rotation& rotation, const Scale& scale )
        {
            position_ = position;
            rotation_ = rotation;
            scale_ = scale;
        }

        void SetCamera(const Position& position, const Direction& forward, const Direction& up)
        {
            cameraPosition_ = position;
            cameraForward_ = forward;
            cameraUp_ = up;
        }

        /**
         * @brief Sets perspective projection parameters
         * @param fov Field Of View in degrees
         * @param width Viewport width in pixels.
         * @param height Viewport height in pixels
         * @param near Near clipping plane.
         * @param far Far clipping plane.
         */
        void SetProjection(float fov, int width, int height, float near, float far);

        /**
         * @brief Returns full Model-View-Projection matrix.
         */
        Matrix4f GetMVPMatrix() const;

    protected:
        Position  position_;
        Rotation  rotation_;
        Scale     scale_;

        Direction cameraForward_;
        Direction cameraUp_;
        Position  cameraPosition_;

        float     fov_ = 0.f;
        uint32_t  width_ = 0;
        uint32_t  height_ = 0;
        float     near_ = 0.f;
        float     far_ = 0.f;
    };
}
using Math3D::operator*;
#endif // __MATH_3D_H__
