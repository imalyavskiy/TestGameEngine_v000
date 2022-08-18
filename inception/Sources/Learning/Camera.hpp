#ifndef __LEARNING_CAMERA_H__
#define __LEARNING_CAMERA_H__
namespace Learning
{
  class CameraComponent : public Base::CameraComponent
  {
  public:
    CameraComponent(Base::Generic::VideoRenderer& renderer, Base::SceneObjectComponent::wptr parent, const std::string& name);

    void Update(float dt) override;
  protected:
    Math3D::Rotation rotationSpeed_{1.f, 0.f, 0.f};
  };
}
#endif // __LEARNING_CAMERA_H__
