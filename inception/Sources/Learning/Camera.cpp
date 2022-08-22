#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include <BaseClasses/BaseClasses.hpp>
#include "Learning.hpp"

namespace Learning
{
  CameraComponent::CameraComponent(Base::Generic::VideoRenderer& renderer, Base::SceneObjectComponent::wptr parent, const std::string& name)
    : Base::CameraComponent(renderer, parent, name)
  {
  }

  void CameraComponent::Update(float dt)
  {
    Base::CameraComponent::Update(dt);
  }
}
