#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include <BaseClasses/BaseClasses.hpp>
#include "Learning.hpp"

namespace Learning
{
    RotatingObject::RotatingObject(const std::string& name)
      : Base::SceneObject(name)
    {
    }

    void RotatingObject::Update(float dt)
    {
      auto& transform = Transform();

      transform.rotation.x += Math3D::DegToRad(rotationSpeed_.x * dt);
      transform.rotation.y += Math3D::DegToRad(rotationSpeed_.y * dt);
      transform.rotation.z += Math3D::DegToRad(rotationSpeed_.z * dt);



      SceneObject::Update(dt);
    }
}
