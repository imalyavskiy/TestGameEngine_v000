#ifndef __ENGINE_IMPL_HPP__
#define __ENGINE_IMPL_HPP__
namespace Engine
{
  class Impl
  {
  public:
    Impl(Base::Settings settings);

    /**
     * @todo add description
     */
    void  SpecialKeyboardProc(GLUT::KEY key, int x, int y);

    /**
     * @todo add description
     */
    void  SpecialKeyboardUpProc(GLUT::KEY key, int, int);

    /**
     * @todo add description
     */
    void  ReshapeFunc(int w, int h);

    /**
     * @todo add description
     */
    void  VisibilityFunc(int _0);

    /**
     * @todo add description
     */
    void  RenderProc();

    /**
     * @todo add description
     */
    void  MouseProc(GLUT::MOUSE_BUTTON button, GLUT::MOUSE_BUTTON_STATE state, int x, int y);

    /**
     * @todo add description
     */
    void  MotionProc(int x, int y);

    /**
     * @todo add description
     */
    void  PassiveMotionProc(int x, int y);

    /**
     * @todo add description
     */
    void  EntryProc(GLUT::MOUSE_STATE state);

    /**
     * @todo add description
     */
    void  KeyboardFunc(unsigned char ch, int x, int y);

    /**
     * @todo add description
     */
    void  KeyboardUpFunc(unsigned char _0, int _1, int _2);

    /**
     * @todo add description
     */
    void  JoystickFunc(unsigned int _0, int _1, int _2, int _3);

    /**
     * @todo add description
     */
    void  MenuStateFunc(int _0);

    /**
     * @todo add description
     */
    void  MenuStatusFunc(int _0, int _1, int _2);

    /**
     * @todo add description
     */
    void  OverlayDisplayFunc();

    /**
     * @todo add description
     */
    void  WindowStatusFunc(int status);

    /**
     * @todo add description
     */
    void  SpaceballMotionFunc(int _0, int _1, int _2);

    /**
     * @todo add description
     */
    void  SpaceballRotateFunc(int _0, int _1, int _2);

    /**
     * @todo add description
     */
    void  SpaceballButtonFunc(int _0, int _1);

    /**
     * @todo add description
     */
    void  ButtonBoxFunc(int _0, int _1);

    /**
     * @todo add description
     */
    void  DialsFunc(int _0, int _1);

    /**
     * @todo add description
     */
    void  TabletMotionFunc(int _0, int _1);

    /**
     * @todo add description
     */
    void  TabletButtonFunc(int _0, int _1, int _2, int _3);

    /**
     * @todo add description
     */
    void SetScene(Base::Scene::sptr scene);

    /**
     *
     */
    void SetRenderer(Base::RenderFacility::sptr renderer);

    /**
     *
     */
    void SetController(Base::Controller::sptr controller);

  protected:
    /**
     * @todo add description
     */
    Base::Settings settings_;

    /**
     * @todo add description
     */
    Base::Scene::sptr scene_;

    /**
     * @todo add description
     */
    Base::RenderFacility::sptr renderFacility_;

    /**
     * @todo add description
     */
    Base::Controller::sptr inputController_;
  };
}
#endif // __ENGINE_IMPL_HPP__