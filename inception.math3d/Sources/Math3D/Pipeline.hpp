#ifndef __PIEPELINE_HPP__
#define __PIEPELINE_HPP__
namespace Math3D
{
  /**
   * @brief This class contains constructors for special matrices
   *        such as translation, scale, rotation and projection.
   */
  struct Pipeline
  {
    [[nodiscard]]
    static Pipeline& Instance();

    [[nodiscard]]
    static Matrix4f Identity();

    [[nodiscard]]
    static Matrix4f Projection(float fov, uint32_t width, uint32_t height, float zNear, float zFar);

    [[nodiscard]]
    static Matrix4f ViewRotation(const Direction& direction, const Direction& up);

    [[nodiscard]]
    static Matrix4f Create(const Position& position);

    [[nodiscard]]
    static Matrix4f Create(const Rotation& rotation);

    [[nodiscard]]
    static Matrix4f Create(const Scale& scale);

    [[nodiscard]]
    static Matrix4f Create(const Transform& transform);

    [[nodiscard]]
    void SetTransform(const Transform& transform);

    [[nodiscard]]
    void SetTransform(const Position& position, const Rotation& rotation, const Scale& scale);

    [[nodiscard]]
    void SetCamera(const Position& position, const Direction& forward, const Direction& up);

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
    [[nodiscard]]
    Matrix4f GetMVPMatrix() const;

  protected:
    Transform transform_;

    Direction cameraForward_;
    Direction cameraUp_;
    Position  cameraPosition_;

    float     fov_ = 0.f;  // degrees
    uint32_t  width_ = 0;  // pixels
    uint32_t  height_ = 0; // pixels
    float     near_ = 0.f; // units
    float     far_ = 0.f;  // units
  };
}
#endif // __PIPELINE_HPP__