#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include <BaseClasses/Interfaces.hpp>
#include <BaseClasses/BaseClasses.hpp>
#include "Engine.hpp"
#include "RenderFacility.hpp"
#include "EngineImpl.hpp"

#include <GL/freeglut_std.h>

namespace Engine
{
  Impl::Impl(Base::Settings settings)
    : settings_(settings)
  {

  }

  void Impl::KeyboardProc(GLUT::KEY key, int x, int y)
  {
//    std::cout << "0x" << std::hex << std::setw(4) << std::setfill('0') << static_cast<uint16_t>(key) << "+\n";
    if (inputController_)
      inputController_->OnKey(key, true);
  }

  void  Impl::KeyboardUpFunc(GLUT::KEY key, int x, int y)
  {
//    std::cout << "0x" << std::hex << std::setw(4) << std::setfill('0') << static_cast<uint16_t>(key) << "-\n";
    if (inputController_)
      inputController_->OnKey(key, false);
  }

  void Impl::SpecialKeyboardProc(GLUT::KEY key, int, int)
  {
    if (inputController_)
      inputController_->OnKey(key, true);
  }

  void  Impl::SpecialKeyboardUpProc(GLUT::KEY key, int, int)
  {
    if (inputController_)
      inputController_->OnKey(key, false);
  }

  void Impl::ReshapeFunc(int, int)
  {
    throw std::logic_error("not implemented");
  }

  void  Impl::VisibilityFunc(int)
  {
    throw std::logic_error("not implemented");
  }

  constexpr int oneThirtieth = 1000 / 30; // of a second in milliseconds
  std::chrono::steady_clock::time_point prev = 
    std::chrono::steady_clock::now() - std::chrono::milliseconds(oneThirtieth);
  void Impl::RenderProc()
  {
#ifndef _DEBUG
    const auto now = 
      std::chrono::steady_clock::now();
    const auto dtMS = 
      std::chrono::duration_cast<std::chrono::milliseconds>(now - prev);
    prev = now;
    const float dt = dtMS.count() / 1000.f;
#else
    constexpr float dt = 1.f / 30.f;
#endif

    // @todo implement 2 pass physics calculations
    inputController_->Update(dt);
    scene_->Update(dt);

    renderFacility_->Draw(scene_->GetObjectTree());
  }

  void Impl::MouseProc(GLUT::MOUSE_BUTTON button, GLUT::MOUSE_BUTTON_STATE state, int x, int y)
  {
//    switch(button)
//    {
//    case GLUT::MOUSE_BUTTON::LEFT:
//      std::cout << "LMB " << ((bool)state == true ? "up" : "down") << " at ("<< x_ << ", " << y_ << ")\n";
//      break;
//    case GLUT::MOUSE_BUTTON::RIGHT:
//      std::cout << "RMB " << ((bool)state == true ? "up" : "down") << " at (" << x_ << ", " << y_ << ")\n";
//      break;
//    case GLUT::MOUSE_BUTTON::MIDDLE:
//      std::cout << "MMB " << ((bool)state == true ? "up" : "down") << " at (" << x_ << ", " << y_ << ")\n";
//      break;
//    }
  }

  void  Impl::MotionProc(const int x, const int y) {
    constexpr bool buttonPressed = true;
    inputController_->OnMouseMove(x, y, buttonPressed);
  }

  void  Impl::PassiveMotionProc(const int x, const int y)
  {
    constexpr bool buttonPressed = false;
    inputController_->OnMouseMove(x, y, buttonPressed);
  }

  void  Impl::EntryProc(GLUT::MOUSE_STATE state)
  {
//    std::cout << "Mouse pointer " << ((bool)state == true ? "entered" : "left") << " the viewport\n";
  }

  void  Impl::JoystickFunc(unsigned int, int, int, int)
  {
    throw std::logic_error("not implemented");
  }

  void  Impl::MenuStateFunc(int)
  {
    throw std::logic_error("not implemented");
  }

  void  Impl::MenuStatusFunc(int, int, int)
  {
    throw std::logic_error("not implemented");
  }

  void  Impl::OverlayDisplayFunc()
  {
    throw std::logic_error("not implemented");
  }

  void  Impl::WindowStatusFunc(int status)
  {
    throw std::logic_error("not implemented");
  }

  void  Impl::SpaceballMotionFunc(int, int, int)
  {
    throw std::logic_error("not implemented");
  }

  void  Impl::SpaceballRotateFunc(int, int, int)
  {
    throw std::logic_error("not implemented");
  }

  void  Impl::SpaceballButtonFunc(int, int)
  {
    throw std::logic_error("not implemented");
  }

  void  Impl::ButtonBoxFunc(int, int)
  {
    throw std::logic_error("not implemented");
  }

  void  Impl::DialsFunc(int, int)
  {
    throw std::logic_error("not implemented");
  }

  void  Impl::TabletMotionFunc(int, int)
  {
    throw std::logic_error("not implemented");
  }

  void  Impl::TabletButtonFunc(int, int, int, int)
  {
    throw std::logic_error("not implemented");
  }

  void Impl::SetScene(Base::Scene::sptr scene)
  {
    scene_ = scene;
  }

  void Impl::SetRenderer(Base::RenderFacility::sptr renderer)
  {
    renderFacility_ = renderer;
  }

  void Impl::SetController(Base::Controller::sptr controller)
  {
    inputController_ = controller;
  }
}
