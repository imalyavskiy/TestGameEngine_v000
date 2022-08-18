#include <pch.hpp>
#include <Math3D/Math3D.hpp>
#include <Utilities/Utilities.hpp>
#include "BaseClasses.hpp"

namespace Base
{
	CameraComponent::CameraComponent(Generic::VideoRenderer& renderer, SceneObjectComponent::wptr parent, const std::string& name)
	  : SceneObjectComponent(parent, name)
    , renderer_(renderer)
  {
    renderer_.AddCamera(*this);
	}

  CameraComponent::~CameraComponent()
  {
    renderer_.RemoveCamera(*this);
  }

  Math3D::Position CameraComponent::Position() const
  {
    return SceneObjectComponent::GetWorldPosition();
  }

  Math3D::Direction CameraComponent::Up() const
  {
    return SceneObjectComponent::GetWorldUpVector();
  }

  Math3D::Direction CameraComponent::LookAt() const
  {
    return SceneObjectComponent::GetWorldForwardVector();
  }

  Math3D::Direction CameraComponent::Right() const
  {
    return SceneObjectComponent::GetWorldRightVector();
  }

  float CameraComponent::FoV() const
  {
    return fov_;
  }

  bool CameraComponent::IsActive() const
  {
    return active_;
  }

  void CameraComponent::SetActive(bool active)
  {
    active_ = active;
  }
}
