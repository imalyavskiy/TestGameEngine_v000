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
    const Base::Scene::sptr scene =
      std::make_shared<Learning::DefaultScene>();

    const Base::RenderFacility::sptr renderer =
      std::make_shared<Engine::RenderFacility>(settings);

    scene->Load(renderer);

    Instance().SetScene(scene);
    Instance().SetRenderer(renderer);

    return true; // @todo wrong! return value makes no sense
  }

  void  KeyboardFunc(unsigned char ch, int x, int y)
  {
    Instance().KeyboardFunc(ch, x, y);
  }

  void  SpecialFunc(int id, int x, int y)
  {
    Instance().SpecialFunc(id, x, y);
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

  void  MouseFunc(int button, int state, int x, int y)
  {
    Instance().MouseFunc(button, state, x, y);
  }

  void  MotionFunc(int x, int y)
  {
    Instance().MotionFunc(x, y);
  }

  void  PassiveMotionFunc(int x, int y)
  {
    Instance().PassiveMotionFunc(x, y);
  }

  void  EntryFunc(int state) {
    Instance().EntryFunc(state);
  }

  void  KeyboardUpFunc(unsigned char key, int x, int y) {
    Instance().KeyboardUpFunc(key, x, y);
  }

  void  SpecialUpFunc(int key, int x, int y) {
    Instance().SpecialUpFunc(key, x, y);
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