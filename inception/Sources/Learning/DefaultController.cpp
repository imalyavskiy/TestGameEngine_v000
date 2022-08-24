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
    std::shared_ptr<Button> up(new Button(GLUT::KEY::UP));
    std::shared_ptr<Button> dn(new Button(GLUT::KEY::DOWN));
    std::shared_ptr<AxisAction> fwd(new AxisAction(dn, up, [&](float val) {
      if(controlledPawn_)
        controlledPawn_->MoveForward(val);
    }));
    registeredKeys_[up->id] = up;
    registeredKeys_[dn->id] = dn;
    actionList_.push_back(fwd);

    std::shared_ptr<Button> rt(new Button(GLUT::KEY::RIGHT));
    std::shared_ptr<Button> lt(new Button(GLUT::KEY::LEFT));
    std::shared_ptr<AxisAction> rght(new AxisAction(rt, lt, [&](float val) {
      if(controlledPawn_)
        controlledPawn_->MoveRight(val);
    }));
    registeredKeys_[rt->id] = rt;
    registeredKeys_[lt->id] = lt;
    actionList_.push_back(rght);
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
}
