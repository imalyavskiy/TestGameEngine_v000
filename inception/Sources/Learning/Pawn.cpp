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
    forwardDelta_ = value;
  }

  void Pawn::MoveUp(float value)
  {
    upDelta_ = value;
  }

  void Pawn::MoveRight(float value)
  {
    rightDelta_ = value;
  }

  void Pawn::Yaw(float value)
  {
    yawDelta_ = value;
  }

  void Pawn::Pitch(float value)
  {
    pitchDelta_ = value;
  }

  void Pawn::Roll(float value)
  {
    rollDelta_ = value;
  }

  void Pawn::Update(float dt)
  {
    auto& transform = Transform();

    transform.position.x += 0.0005f * forwardDelta_;
    transform.position.y += 0.0005f * rightDelta_;
    transform.position.z += 0.0005f * upDelta_;

    transform.rotation.x += 0.0005f * rollDelta_;
    transform.rotation.y += 0.0005f * pitchDelta_;
    transform.rotation.z += 0.0005f * yawDelta_;

    Base::Pawn::Update(dt);
  }
}
