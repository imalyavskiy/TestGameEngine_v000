#include "pch.hpp"
#include "Math3d.hpp"

namespace Math3D
{
  Pipeline& Pipeline::Instance()
  {
    static Pipeline instance;
    return instance;
  }

  Matrix4f Pipeline::Identity()
  {
    return Matrix4f({ 1.f, 0.f, 0.f, 0.f },
      { 0.f, 1.f, 0.f, 0.f },
      { 0.f, 0.f, 1.f, 0.f },
      { 0.f, 0.f, 0.f, 1.f });
  }

  Matrix4f Pipeline::Projection(float fov, uint32_t width, uint32_t height, float zNear, float zFar)
  {
    const float ar = static_cast<float>(width) / height;
    const float zRange = zFar - zNear;
    const float ctanHalfFov = 1 / std::tanf(DegToRad(fov) / 2.f);

    return {
      { ctanHalfFov / ar,     0.f,              0.f,                      0.f              },
      {       0.f,        ctanHalfFov,          0.f,                      0.f              },
      {       0.f,            0.f,     (zNear + zFar) / zRange, -2.f * zNear * zFar / zRange },
      {       0.f,            0.f,              1.f,                      0.f              },
    };
  }

  Matrix4f Pipeline::ViewRotation(const Direction& direction, const Direction& up)
  {
    // forward
    const Vector3f n = Normalized(direction);
    // right
    const Vector3f u = Cross(Normalized(up), n);
    // up
    const Vector3f v = Cross(n, u);

    return {
      { u.x, u.y, u.z, 0.f },
      { v.x, v.y, v.z, 0.f },
      { n.x, n.y, n.z, 0.f },
      { 0.f, 0.f, 0.f, 1.f },
    };
  }

  Matrix4f Pipeline::Create(const Position& position)
  {
    return {
      1.f, 0.f, 0.f, position.x,
      0.f, 1.f, 0.f, position.y,
      0.f, 0.f, 1.f, position.z,
      0.f, 0.f, 0.f,    1.f    ,
    };
  }

  Matrix4f Pipeline::Create(const Rotation& rotation)
  {
    const float sr = std::sinf(rotation.x); // sin(roll)
    const float cr = std::cosf(rotation.x); // cos(roll)
    const float sp = std::sinf(rotation.y); // sin(pitch)
    const float cp = std::cosf(rotation.y); // cos(pitch)
    const float sy = std::sinf(rotation.z); // sin(yaw)
    const float cy = std::cosf(rotation.z); // cos(yaw)

#if false
    const Matrix4f rr // roll
    {
        1.0f,  0.0f,   0.0f, 0.0f,
        0.0f,   cr ,   -sr , 0.0f,
        0.0f,   sr ,    cr , 0.0f,
        0.0f,  0.0f,   0.0f, 1.0f,
    };

    const Matrix4f rp // pitch
    {
         cp , 0.0f,  sp , 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -sp , 0.0f,  cp , 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };

    const Matrix4f ry // yaw
    {
         cy ,  -sy , 0.0f, 0.0f,
         sy ,   cy , 0.0f, 0.0f,
        0.0f,  0.0f, 1.0f, 0.0f,
        0.0f,  0.0f, 0.0f, 1.0f,
    };

    // This variant takes 128 multiplication and 96 addition operations.
    return ry * rp * rr;
#else
    // This is the analytically deduced matrix after 2 multiplications.
    // This variant has 16 multiplication and 4 addition operations. Such 
    // advantage reached because of all multiplications by ZERO were 
    // pre-calculated.
    return {
      cy * cp, -sy * cr + cy * sp * sr,  sy * sr + cy * sp * cr,  0,
      sy * cp,  cy * cr + sy * sp * sr, -cy * sr + sy * sp * cr,  0,
       -sp ,      cp * sr     ,      cp * cr     ,  0,
        0  ,        0       ,        0       ,  1,
    };
#endif
  }

  Matrix4f Pipeline::Create(const Scale& scale)
  {
    return {
      scale.x,   0.f  ,   0.f  ,  0.f,
        0.f  , scale.y,   0.f  ,  0.f,
        0.f  ,   0.f  , scale.z,  0.f,
        0.f  ,   0.f  ,   0.f  ,  1.f
    };
  }

  Matrix4f Pipeline::Create(const Transform& transform)
  {
    return Create(transform.position) * Create(transform.rotation) * Create(transform.scale);
  }

  void Pipeline::SetTransform(const Transform& transform)
  {
    transform_ = transform;
  }

  void Pipeline::SetTransform(const Position& position, const Rotation& rotation, const Scale& scale)
  {
    transform_.position = position;
    transform_.rotation = rotation;
    transform_.scale = scale;
  }

  void Pipeline::SetCamera(const Position& position, const Direction& forward, const Direction& up)
  {
    cameraPosition_ = position;
    cameraForward_ = forward;
    cameraUp_ = up;
  }

  Matrix4f Pipeline::GetMVPMatrix() const
  {
    // Projection * View * Model
    return Projection(fov_, width_, height_, near_, far_) *
      ViewRotation(cameraForward_, cameraUp_) * Create(cameraPosition_) *
      Create(transform_.position) * Create(transform_.rotation) * Create(transform_.scale);
  }

  void Pipeline::SetProjection(float fov, int width, int height, float near, float far)
  {
    fov_ = fov;
    width_ = width;
    height_ = height;
    near_ = near;
    far_ = far;
  }
}
