#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__
namespace Engine
{
    /**
     * @brief Initializes the engine instance with Settings structure
     */
    bool Initialize(const Base::Settings& settings);

    /**
     *
     */
    bool Load(const Base::Settings& settings);

    /**
     * @brief Called each time when user presses a character key coupled with current mouse
     *        pointer position in window relative coordinates. Must be passed to glutKeyboardFunc.
     * @param ch The character of a pressed key.
     * @param x Mouse x.
     * @param y Mouse y.
     */
    void  KeyboardFunc(unsigned char ch, int x, int y);

    /**
     * @brief Triggered when keyboard function or directional keys are pressed coupled with current
     *        mouse pointer position in window relative coordinates. Functional - F1-F12, directional
     *        - Arrow keys, PgUp, PgDn, Home, End, Insert. Must be passed to glutSpecialFunc.
     * @param key Key ID - GLUT_KEY_(F[ 1..12 ]|LEFT|RIGHT|UP|DOWN|PAGE_[ UP|DOWN ]|HOME|END|INSERT)
     * @param x Mouse x.
     * @param y Mouse y.
     * @remark Note that the escape, backspace, and delete keys are generated as an ASCII character.
     */
    void  SpecialFunc(int key, int x, int y);

    /**
     * @brief Called when a window is reshaped. Also called immediately before a window's first display
     *        callback after a window is created or whenever an overlay for the window is established.
     *        The width and height parameters of the callback specify the new window size in pixels.
     *        Before the callback, the current window is set to the window that has been reshaped
     * @param w New window width.
     * @param h New window height.
     */
    void  ReshapeFunc(int w, int h);

    /**
     * @brief Called when the visibility of a window changes. The state callback parameter is either
     *        GLUT_NOT_VISIBLE or GLUT_VISIBLE depending on the current visibility of the window.
     *        GLUT_VISIBLE does not distinguish a window being totally versus partially visible.
     *        GLUT_NOT_VISIBLE means no part of the window is visible, i.e., until the window's
     *        visibility changes, all further rendering to the window is discarded.
     * @param state Window visibility state.
     * @remark GLUT considers a window visible if any pixel of the window is visible or any pixel
     *        of any descendant window is visible on the screen.
     * @remark If the visibility callback for a window is disabled and later re-enabled, the visibility
     *        status of the window is undefined; any change in window visibility will be reported,
     *        that is if you disable a visibility callback and re-enable the callback, you are
     *        guaranteed the next visibility change will be reported.
     */
    void  VisibilityFunc(int state);

    /**
     * @brief Called when window needs to be redisplayed. Mast be passed to glutDisplayFunc.
     * @remark (https://www.opengl.org/resources/libraries/glut/spec3/node46.html#SECTION00081000000000000000)
     */
    void  RenderProc();

    /**
     * @brief Called when user presses or releases some mouse key.
     * @param button Mouse button code GLUT_[LEFT|MIDDLE|RIGHT]_BUTTON
     * @param state Mouse button state GLUT_[UP|DOWN]
     * @param x Indicate the window relative x coordinate when the mouse button state changed.
     * @param y Indicate the window relative y coordinate when the mouse button state changed.
     * @remark (https://www.opengl.org/resources/libraries/glut/spec3/node50.html#SECTION00085000000000000000)
     */
    void  MouseFunc(int button, int state, int x, int y);

    /**
     * @todo add description
     * @remark (https://www.opengl.org/resources/libraries/glut/spec3/node51.html#SECTION00086000000000000000)
     */
    void  MotionFunc(int x, int y);

    /**
     * @todo add description
     * @remark (https://www.opengl.org/resources/libraries/glut/spec3/node51.html#SECTION00086000000000000000)
     */
    void  PassiveMotionFunc(int x, int y);

    /**
     * @todo add description
     * @remark (https://www.opengl.org/resources/libraries/glut/spec3/node53.html#SECTION00088000000000000000)
     */
    void  EntryFunc(int state);

    /**
     * @todo add description
     * @remark (https://www.unix.com/man-page/mojave/3GLUT/glutKeyboardUpFunc/)
     */
    void  KeyboardUpFunc(unsigned char key, int x, int y);

    /**
     * @todo add description
     * @remark (https://linux.die.net/man/3/glutspecialupfunc)
     */
    void  SpecialUpFunc(int key, int x, int y);

    /**
     * @todo add description
     * @remark (https://linux.die.net/man/3/glutjoystickfunc)
     */
    void  JoystickFunc(unsigned int buttons, int x, int y, int z);

    /**
     * @todo add description
     * @remark (https://linux.die.net/man/3/glutmenustatefunc)
     */
    void  MenuStateFunc(int state);

    /**
     * @todo add description
     * @remark (https://www.opengl.org/resources/libraries/glut/spec3/node62.html#SECTION000817000000000000000)
     */
    void  MenuStatusFunc(int status, int x, int y);

    /**
     * @todo add description
     * @remark (https://www.opengl.org/resources/libraries/glut/spec3/node47.html#SECTION00082000000000000000)
     */
    void  OverlayDisplayFunc();

    /**
     * @todo add description
     * @remark (https://linux.die.net/man/3/glutwindowstatusfunc)
     */
    void  WindowStatusFunc(int status);

    /**
     * @todo add description
     * @remark (https://www.opengl.org/resources/libraries/glut/spec3/node55.html#SECTION000810000000000000000)
     */
    void  SpaceballMotionFunc(int x, int y, int z);

    /**
     * @todo add description
     * @remark (https://www.opengl.org/resources/libraries/glut/spec3/node56.html#SECTION000811000000000000000)
     */
    void  SpaceballRotateFunc(int x, int y, int z);

    /**
     * @todo add description
     * @remark (https://www.opengl.org/resources/libraries/glut/spec3/node57.html#SECTION000812000000000000000)
     */
    void  SpaceballButtonFunc(int button, int state);

    /**
     * @todo add description
     * @remark (https://www.opengl.org/resources/libraries/glut/spec3/node58.html#SECTION000813000000000000000)
     */
    void  ButtonBoxFunc(int button, int state);

    /**
     * @todo add description
     * @remark (https://www.opengl.org/resources/libraries/glut/spec3/node59.html#SECTION000814000000000000000)
     */
    void  DialsFunc(int dial, int value);

    /**
     * @todo add description
     * @remark (https://www.opengl.org/resources/libraries/glut/spec3/node60.html#SECTION000815000000000000000)
     */
    void  TabletMotionFunc(int x, int y);

    /**
     * @todo add description
     * @remark (https://www.opengl.org/resources/libraries/glut/spec3/node61.html)
     */
    void  TabletButtonFunc(int button, int state, int x, int y);
}

#endif // __ENGINE_HPP__