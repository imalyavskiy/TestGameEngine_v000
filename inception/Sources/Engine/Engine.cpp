#include <pch.hpp>
#include "Math3D/Math3d.hpp"
#include "Utilities/Utilities.hpp"
#include "BaseClasses/BaseClasses.hpp"
#include "Engine.hpp"
#include "RenderFacility.hpp"
#include "EngineImpl.hpp"
#include "Learning/Learning.hpp"

namespace Engine
{
  static Impl* instance = nullptr;

  Impl& Instance()
  {
    assert(instance);
    return *instance;
  }

  bool Initialize(const Base::Settings& settings)
  {
    instance = new Impl(settings);

    return true; // @todo wrong! return value makes no sense
  }

  bool Load(const Base::Settings& settings)
  {
    const Base::Controller::sptr controller =
      std::make_shared<Learning::DefaultController>(settings);

    const Base::RenderFacility::sptr renderer =
      std::make_shared<Engine::RenderFacility>(settings);

    const Base::Scene::sptr scene =
      std::make_shared<Learning::DefaultScene>();

    scene->Load(renderer, controller);

    Instance().SetScene(scene);
    Instance().SetRenderer(renderer);
    Instance().SetController(controller);

    return true; // @todo wrong! return value makes no sense
  }

  void  KeyboardProc(unsigned char ch, int x, int y)
  {
    const uint16_t ui16id = 0x0000 | static_cast<uint8_t>(ch);
    Instance().KeyboardProc(static_cast<GLUT::KEY>(ui16id), x, y);
  }

  void  KeyboardUpProc(unsigned char key, int x, int y) {
    const uint16_t ui16id = 0x0000 | static_cast<uint8_t>(key);
    Instance().KeyboardUpFunc(static_cast<GLUT::KEY>(ui16id), x, y);
  }

  void  SpecialKeyboardProc(int id, int x, int y)
  {
    const uint16_t ui16id = 0x0100|static_cast<uint8_t>(id);
    Instance().SpecialKeyboardProc(static_cast<GLUT::KEY>(ui16id), x, y);
  }

  void  SpecialKeyboardUpProc(int id, int x, int y) {
    const uint16_t ui16id = 0x0100 | static_cast<uint8_t>(id);
    Instance().SpecialKeyboardUpProc(static_cast<GLUT::KEY>(ui16id), x, y);
  }

  void  ReshapeFunc(int w, int h)
  {
    Instance().ReshapeFunc(w, h);
  }

  void  VisibilityFunc(int state)
  {
    Instance().VisibilityFunc(state);
  }

  void  RenderProc()
  {
    Instance().RenderProc();
  }

  void  MouseProc(int button, int state, int x, int y)
  {
    Instance().MouseProc(static_cast<GLUT::MOUSE_BUTTON>(button), static_cast<GLUT::MOUSE_BUTTON_STATE>(state), x, y);
  }

  void  MotionProc(int x, int y)
  {
    Instance().MotionProc(x, y);
  }

  void  PassiveMotionProc(int x, int y)
  {
    Instance().PassiveMotionProc(x, y);
  }

  void  EntryProc(int state) {
    Instance().EntryProc(static_cast<GLUT::MOUSE_STATE>(state));
  }

  void  JoystickFunc(unsigned int buttons, int x, int y, int z)
  {
      Instance().JoystickFunc(buttons, x, y, z);
  }

  void  MenuStateFunc(int state)
  {
    Instance().MenuStateFunc(state);
  }

  void  MenuStatusFunc(int status, int x, int y)
  {
    Instance().MenuStatusFunc(status, x, y);
  }

  void  OverlayDisplayFunc()
  {
    Instance().OverlayDisplayFunc();
  }

  void  WindowStatusFunc(int status)
  {
    Instance().WindowStatusFunc(status);
  }

  void  SpaceballMotionFunc(int x, int y, int z) {
    Instance().SpaceballMotionFunc(x, y, z);
  }

  void  SpaceballRotateFunc(int x, int y, int z)
  {
    Instance().SpaceballRotateFunc(x, y, z);
  }

  void  SpaceballButtonFunc(int button, int state) {
    Instance().SpaceballButtonFunc(button, state);
  }

  void  ButtonBoxFunc(int button, int state) {
    Instance().ButtonBoxFunc(button, state);
  }

  void  DialsFunc(int dial, int value) {
    Instance().DialsFunc(dial, value);
  }

  void  TabletMotionFunc(int x, int y) {
    Instance().TabletMotionFunc(x, y);
  }

  void  TabletButtonFunc(int button, int state, int x, int y) {
    Instance().TabletButtonFunc(button, state, x, y);
  }

}