#ifndef __BASE_CAMERA_HPP__
#define __BASE_CAMERA_HPP__
namespace Base
{
  /**
  * @brief This class represents a generic camera.
  *  Camera has `fov` property - Field Of View angle and responsible for registering in Drawing Facility object for quick access.
  */
  class CameraComponent : public SceneObjectComponent, public Generic::Camera
  {
  public:
    CameraComponent(Generic::VideoRenderer& renderer, SceneObjectComponent::wptr parent, const std::string& name);

    ~CameraComponent() override;

    [[nodiscard]]
    Math3D::Position  Position() const override;

    [[nodiscard]]
    Math3D::Direction Up() const override;

    [[nodiscard]]
    Math3D::Direction LookAt() const override;

    [[nodiscard]]
    Math3D::Direction Right() const override;

    [[nodiscard]]
    float             FoV() const override;

    [[nodiscard]]
    float             Near() const override;

    [[nodiscard]]
    float             Far() const override;

    [[nodiscard]]
    bool IsActive() const override;

    void SetActive(bool active) override;

  protected:
    float fov_ = 60.f;

    float near_ = 1.f;

    float far_ = 100.f;

    bool active_ = false;

    Generic::VideoRenderer& renderer_;
  };
}
#endif // __BASE_CAMERA_HPP__