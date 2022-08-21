#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include <BaseClasses/BaseClasses.hpp>
#include "Learning.hpp"

namespace Learning
{
  Pawn::Pawn(const std::string& name)
    : Base::Pawn(name)
  {
  }

  void Pawn::MoveForward(float value)
  {
    forwardDelta = value;
  }

  void Pawn::MoveUp(float value)
  {
    upDelta = value;
  }

  void Pawn::MoveRight(float value)
  {
    rightDelta = value;
  }

  void Pawn::Update(float dt)
  {
    auto& transform = Transform();
    transform.position.x += forwardDelta * 0.2f;
    transform.position.y += rightDelta * 0.2f;
    transform.position.z += upDelta * 0.2f;

    Base::Pawn::Update(dt);
  }
}
