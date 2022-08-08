#ifndef __GLUT_WRAPPER_H__
#define __GLUT_WRAPPER_H__

#include <initializer_list>

#ifdef CreateWindow
#undef CreateWindow
#endif

/// Functions in this namespace wraps glut functions in order to join together sources and documentation
/// https://www.opengl.org/resources/libraries/glut/spec3/node1.html
namespace GLUT {
	/// InitDisplayMode function constants(https://www.opengl.org/resources/libraries/glut/spec3/node12.html#SECTION00033000000000000000)
	enum class DisplayMode : uint32_t
	{
		RGB         = 0x00000000,
		RGBA        = 0x00000000,
		INDEX       = 0x00000001,
		SINGLE      = 0x00000000,
		DOUBLE      = 0x00000002,
		ACCUM       = 0x00000004,
		ALPHA       = 0x00000008,
		DEPTH       = 0x00000010,
		STENCIL     = 0x00000020,
		MULTISAMPLE = 0x00000080,
		STEREO      = 0x00000100,
		LUMINANCE   = 0x00000200,
		INVALID_DISPLAY_MODE = _UI32_MAX,
	};

	/// Swaps the buffers of the current window if double buffered(https://www.opengl.org/resources/libraries/glut/spec3/node21.html#SECTION00056000000000000000).
	void SwapBuffers();
	
	/// Initializes the GLUT library(https://www.opengl.org/resources/libraries/glut/spec3/node10.html#SECTION00031000000000000000).
	void Init(int32_t argc, char** argv);
	
	/// Sets the initial display mode(https://www.opengl.org/resources/libraries/glut/spec3/node12.html#SECTION00033000000000000000).
	void InitDisplayMode(std::initializer_list<DisplayMode> flags);
	
	/// Sets the initial window size(https://www.opengl.org/resources/libraries/glut/spec3/node11.html#SECTION00032000000000000000).
	void InitWindowSize(int32_t width, int32_t height);
	
	/// Sets the initial window position(https://www.opengl.org/resources/libraries/glut/spec3/node11.html#SECTION00032000000000000000).
	void InitWindowPosition(int32_t x, int32_t y);
	
	/// Creates a top-level window(https://www.opengl.org/resources/libraries/glut/spec3/node16.html#SECTION00051000000000000000).
	void CreateWindow(const char* title);

	/// Enters the GLUT event processing loop(https://www.opengl.org/resources/libraries/glut/spec3/node14.html#SECTION00041000000000000000).
	void MainLoop();
	
	/// Sets the global idle callback(https://www.opengl.org/resources/libraries/glut/spec3/node63.html#SECTION000818000000000000000).
	void IdleFunc(void (*callback)(void));

	/// Registers a timer callback to be triggered in a specified number of milliseconds(https://www.opengl.org/resources/libraries/glut/spec3/node64.html#SECTION000819000000000000000).
	void TimerFunc(unsigned int time, void (*callback)(int), int value);
	
	/// Sets the keyboard callback for the current window(https://www.opengl.org/resources/libraries/glut/spec3/node49.html#SECTION00084000000000000000).
	void KeyboardFunc(void (*callback)(unsigned char, int, int));
	
	/// Sets the special keyboard callback for the current window(https://www.opengl.org/resources/libraries/glut/spec3/node54.html#SECTION00089000000000000000).
	void SpecialFunc(void (*callback)(int, int, int));
	
	/// Sets the reshape callback for the current window(https://www.opengl.org/resources/libraries/glut/spec3/node48.html#SECTION00083000000000000000).
	void ReshapeFunc(void (*callback)(int, int));
	
	/// Sets the visibility callback for the current window(https://www.opengl.org/resources/libraries/glut/spec3/node52.html#SECTION00087000000000000000).
	void VisibilityFunc(void (*callback)(int));
	
	/// Sets the display callback for the current window(https://www.opengl.org/resources/libraries/glut/spec3/node46.html#SECTION00081000000000000000).
	void DisplayFunc(void (*callback)(void));

	/// Sets the mouse callback for the current window(https://www.opengl.org/resources/libraries/glut/spec3/node50.html#SECTION00085000000000000000).
	void MouseFunc(void (*callback)(int, int, int, int));
	
	/// Set the motion callback function(https://www.opengl.org/resources/libraries/glut/spec3/node51.html#SECTION00086000000000000000).
	void MotionFunc(void (*callback)(int, int));
	
	/// Set the passive motion callback function(https://www.opengl.org/resources/libraries/glut/spec3/node51.html#SECTION00086000000000000000).
	void PassiveMotionFunc(void (*callback)(int, int));
	
	/// Sets the mouse enter/leave callback for the current window(https://www.opengl.org/resources/libraries/glut/spec3/node53.html#SECTION00088000000000000000).
	void EntryFunc(void (*callback)(int));
	
	///  Sets the keyboard key release callback for the current window(https://linux.die.net/man/3/glutkeyboardupfunc).
	void KeyboardUpFunc(void (*callback)(unsigned char, int, int));
	
	/// Sets the special key release callback for the current window(https://linux.die.net/man/3/glutspecialupfunc).
	void SpecialUpFunc(void (*callback)(int, int, int));
	
	/// Reports joystick state for the current window(https://linux.die.net/man/3/glutjoystickfunc).
	void JoystickFunc(void (*callback)(unsigned int, int, int, int), int pollInterval);
	
	/// Sets the global menu status callback(https://www.opengl.org/resources/libraries/glut/spec3/node62.html).
	void MenuStateFunc(void (*callback)(int));
	
	/// Sets the global menu status callback(https://www.opengl.org/resources/libraries/glut/spec3/node62.html#SECTION000817000000000000000).
	void MenuStatusFunc(void (*callback)(int, int, int));
	
	/// Sets the overlay display callback for the current window(https://www.opengl.org/resources/libraries/glut/spec3/node47.html#SECTION00082000000000000000).
	void OverlayDisplayFunc(void (*callback)(void));
	
	/// Sets the window status callback(https://linux.die.net/man/3/glutwindowstatusfunc).
	void WindowStatusFunc(void (*callback)(int));
	
	/// Sets the Spaceball motion callback for the current window(https://www.opengl.org/resources/libraries/glut/spec3/node55.html#SECTION000810000000000000000).
	void SpaceballMotionFunc(void (*callback)(int, int, int));
	
	/// Sets the Spaceball rotation callback for the current window(https://www.opengl.org/resources/libraries/glut/spec3/node56.html#SECTION000811000000000000000).
	void SpaceballRotateFunc(void (*callback)(int, int, int));
	
	/// Sets the Spaceball button callback for the current window(https://www.opengl.org/resources/libraries/glut/spec3/node57.html#SECTION000812000000000000000).
	void SpaceballButtonFunc(void (*callback)(int, int));
	
	/// Sets the dial & button box button callback for the current window(https://www.opengl.org/resources/libraries/glut/spec3/node58.html#SECTION000813000000000000000).
	void ButtonBoxFunc(void (*callback)(int, int));
	
	/// Sets the dial & button box dials callback for the current window(https://www.opengl.org/resources/libraries/glut/spec3/node59.html#SECTION000814000000000000000).
	void DialsFunc(void (*callback)(int, int));
	
	/// Sets the special keyboard callback for the current window(https://www.opengl.org/resources/libraries/glut/spec3/node60.html#SECTION000815000000000000000).
	void TabletMotionFunc(void (*callback)(int, int));
	
	/// Sets the special keyboard callback for the current window(https://www.opengl.org/resources/libraries/glut/spec3/node61.html#SECTION000816000000000000000).
	void TabletButtonFunc(void (*callback)(int, int, int, int));
};
#endif // __GLUT_WRAPPER_H__

