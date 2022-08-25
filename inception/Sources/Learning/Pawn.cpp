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

  void Pawn::Draw(const Math3D::Matrix4f& matViewProjection)
  {
    Base::Pawn::Draw(matViewProjection);
//    std::cout << "F:" << (std::string)root_->GetWorldForwardVector() << " "
//              << "U:" << (std::string)root_->GetWorldUpVector() << " "
//              << "R:" << (std::string)root_->GetWorldRightVector() << " "
//              << "P:" << (std::string)root_->GetWorldPosition() << "\n";
  }

  void Pawn::Update(float dt)
  {
    auto& transform = Transform();
    const auto f = root_->GetWorldForwardVector();
    const auto flen = f.len();
    const auto r = root_->GetWorldRightVector();
    const auto rlen = r.len();
    const auto u = root_->GetWorldUpVector();
    const auto ulen = u.len();

    // Translation is relative to object's forward, right and up vectors
    transform.position.x += 0.0005f * (forwardDelta_ * (f.x / flen) + rightDelta_ * (r.x / rlen) + upDelta_ * (u.x / ulen));
    transform.position.y += 0.0005f * (forwardDelta_ * (f.y / flen) + rightDelta_ * (r.y / rlen) + upDelta_ * (u.y / ulen));
    transform.position.z += 0.0005f * (forwardDelta_ * (f.z / flen) + rightDelta_ * (r.z / rlen) + upDelta_ * (u.z / ulen));

    // Rotation is absolute - wrong
    transform.rotation.x += 0.0005f * rollDelta_;
    transform.rotation.y += 0.0005f * pitchDelta_;
    transform.rotation.z += 0.0005f * yawDelta_;

    Base::Pawn::Update(dt);
  }
}
