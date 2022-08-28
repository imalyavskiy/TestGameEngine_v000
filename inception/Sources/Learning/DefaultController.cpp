#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include <BaseClasses/BaseClasses.hpp>
#include "Learning.hpp"

namespace Learning
{
  DefaultController::DefaultController(const Base::Settings& settings, const std::string& name)
    : Base::Controller(settings, name)
  {
    {
      // Forward
      std::shared_ptr<Button> forward(new Button(GLUT::KEY::SMALL_W));
      std::shared_ptr<Button> backwards(new Button(GLUT::KEY::SMALL_S));
      std::shared_ptr<AxisAction> axisActionForward(new AxisAction(forward, backwards, [&](float val) {
        if (controlledPawn_)
          controlledPawn_->MoveForward(val);
        }));
      registeredKeys_[forward->id] = forward;
      registeredKeys_[backwards->id] = backwards;
      actionList_.push_back(axisActionForward);
    }

    {
      // Right
      std::shared_ptr<Button> right(new Button(GLUT::KEY::SMALL_D));
      std::shared_ptr<Button> left(new Button(GLUT::KEY::SMALL_A));
      std::shared_ptr<AxisAction> axisActionRight(new AxisAction(right, left, [&](float val) {
        if (controlledPawn_)
          controlledPawn_->MoveRight(val);
        }));
      registeredKeys_[right->id] = right;
      registeredKeys_[left->id] = left;
      actionList_.push_back(axisActionRight);
    }

    {
      // Up
      std::shared_ptr<Button> up(new Button(GLUT::KEY::SMALL_R));
      std::shared_ptr<Button> down(new Button(GLUT::KEY::SMALL_F));
      std::shared_ptr<AxisAction> axisActionUp(new AxisAction(up, down, [&](float val) {
        if (controlledPawn_)
          controlledPawn_->MoveUp(val);
        }));
      registeredKeys_[up->id] = up;
      registeredKeys_[down->id] = down;
      actionList_.push_back(axisActionUp);
    }

    // Roll
    {
      // Pitch
      // Angle value grows in CW direction about Y axis as it mast to be for LH basis
      std::shared_ptr<Button> pitchCW(new Button(GLUT::KEY::DOWN));
      std::shared_ptr<Button> pitchCCW(new Button(GLUT::KEY::UP));
      std::shared_ptr<AxisAction> axisActionPitch(new AxisAction(pitchCW, pitchCCW, [&](float val) {
        if (controlledPawn_)
          controlledPawn_->Pitch(val);
        }));
      registeredKeys_[pitchCCW->id] = pitchCCW;
      registeredKeys_[pitchCW->id] = pitchCW;
      actionList_.push_back(axisActionPitch);
    }

    {
      // Yaw
      // Angle value grows in CW direction about Z axis as it mast to be for LH basis
      std::shared_ptr<Button> yawCW(new Button(GLUT::KEY::RIGHT));
      std::shared_ptr<Button> yawCCW(new Button(GLUT::KEY::LEFT));
      std::shared_ptr<AxisAction> axisActionYaw(new AxisAction(yawCW, yawCCW, [&](float val) {
        if (controlledPawn_)
          controlledPawn_->Yaw(val);
        }));
      registeredKeys_[yawCW->id] = yawCW;
      registeredKeys_[yawCCW->id] = yawCCW;
      actionList_.push_back(axisActionYaw);
    }
  }

  bool DefaultController::OnKey(GLUT::KEY key, bool state)
  {
    if (!controlledPawn_)
      return false;
    if(registeredKeys_.end() != registeredKeys_.find(key))
    {
      registeredKeys_[key]->pressed = state;
      std::cout << GLUT::toString(key) << " " << (state ? "pressed" : "released") << "\n";
    }
    else
    {
      const bool usualKey = (static_cast<uint16_t>(key) >> 8) == 0;
      std::cout << "Unknown key: 0x" << std::hex << std::setw(4) << std::setfill('0') << static_cast<uint16_t>(key) << (state ? "+" : "-") << "\n";
    }

    return true;
  }

  void DefaultController::Update(float dt)
  {
    if (!controlledPawn_)
      return;

    for (auto& action : actionList_)
      action->Update();
  }

  void DefaultController::OnMouseMove(int x, int y, bool buttonPressed)
  {
    const int halfScreenWidth = 
      settings_.viewportWidth / 2;
    const int halfScreenHeight = 
      settings_.viewportHeight / 2;

    // x_ left->right
    float localMPosX = 
      static_cast<float>(x) - halfScreenWidth;
    // normalizing
    localMPosX /= static_cast<float>(halfScreenWidth);

    // y_ top->bottom THUS need to be inverted TO BE bottom->top
    float localMPosY =
      ((static_cast<int32_t>(settings_.viewportHeight) - y) - halfScreenHeight);
    // normalizing
    localMPosY /= static_cast<float>(halfScreenHeight);

    // TODO: реализовать инкремент
    // TODO: решить, как правильно начать, от чего считать инкремент. По идее надо захватить
    //       указатель и поставить его в центр окна, и от этого считать инкремент.
    std::cout << "OnMouseMove(" << localMPosX << ", " << localMPosY << ")" << (buttonPressed ? " + button" : "") << "\n";

    GLUT::WarpPointer(halfScreenWidth, halfScreenHeight);
  }
}
