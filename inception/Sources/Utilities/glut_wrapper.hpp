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

	enum class KEY : unsigned short
	{
		F1             = 0x0101, // 0x01|GLUT_KEY_F1
		F2             = 0x0102, // 0x01|GLUT_KEY_F2
		F3             = 0x0103, // 0x01|GLUT_KEY_F3
		F4             = 0x0104, // 0x01|GLUT_KEY_F4
		F5             = 0x0105, // 0x01|GLUT_KEY_F5
		F6             = 0x0106, // 0x01|GLUT_KEY_F6
		F7             = 0x0107, // 0x01|GLUT_KEY_F7
		F8             = 0x0108, // 0x01|GLUT_KEY_F8
		F9             = 0x0109, // 0x01|GLUT_KEY_F9
		F10            = 0x010A, // 0x01|GLUT_KEY_F10
		F11            = 0x010B, // 0x01|GLUT_KEY_F11
		F12            = 0x010C, // 0x01|GLUT_KEY_F12
		LEFT           = 0x0164, // 0x01|GLUT_KEY_LEFT
		UP             = 0x0165, // 0x01|GLUT_KEY_UP
		RIGHT          = 0x0166, // 0x01|GLUT_KEY_RIGHT
		DOWN           = 0x0167, // 0x01|GLUT_KEY_DOWN
		PAGE_UP        = 0x0168, // 0x01|GLUT_KEY_PAGE_UP
		PAGE_DOWN      = 0x0169, // 0x01|GLUT_KEY_PAGE_DOWN
		HOME           = 0x016A, // 0x01|GLUT_KEY_HOME
		END            = 0x016B, // 0x01|GLUT_KEY_END
		INSERT         = 0x016C, // 0x01|GLUT_KEY_INSERT
		PGUP           = 0x0168, // PgUp
		PGDN           = 0x0169, // PgDn'
		LSHIFT         = 0x0170, // L.Shift'
		RSHIFT         = 0x0171, // R.Shift'
		LCTRL          = 0x0172, // L.Ctrl'
		RCTRL          = 0x0173, // R.Ctrl'
		LALT           = 0x0174, // L.Alt'
		RALT           = 0x0175, // R.Alt'

		BACKSPACE      = 0x0008, // Backspace
		TAB            = 0x0009, // Tab
		ENTER          = 0x000D, // Enter
		CAPSLOCK       = 0x0014, // CapsLock
		ESCAPE         = 0x001b, // Esc'
		EXCLAMATION    = 0x0021, // !
		DBLQUOTE       = 0x0022, // "
		SHARP          = 0x0023, // #
		DOLLAR         = 0x0024, // $
		PRECENT        = 0x0025, // %
		AND            = 0x0026, // &
		SGLQUOTE       = 0x0027, // '
		LBRACE         = 0x0028, // (
		RBRACE         = 0x0029, // )
		ASTERISK       = 0x002A, // *
		PLUS           = 0x002B, // +
		COMMA          = 0x002C, // ,
		MINUS          = 0x002D, // -
		DOT            = 0x002E, // .
		SLASH          = 0x002F, // /
		ZERO           = 0x0030, // 0
		ONE            = 0x0031, // 1
		TWO            = 0x0032, // 2
		THREE          = 0x0033, // 3
		FOUR           = 0x0034, // 4
		FIVE           = 0x0035, // 5
		SIX            = 0x0036, // 6
		SEVEN          = 0x0037, // 7
		EIGHT          = 0x0038, // 8
		NINE           = 0x0039, // 9
		COLON          = 0x003A, // :
		SEMICOLON      = 0x003B, // ;
		LANGLEBRACE    = 0x003C, // <
		EQUALS         = 0x003D, // =
		RANGLEBRACE    = 0x003E, // >
		QUESTION       = 0x003F, // ?
		AT             = 0x0040, // @
		CAPITAL_A      = 0x0041, // A
		CAPITAL_B      = 0x0042, // B
		CAPITAL_C      = 0x0043, // C
		CAPITAL_D      = 0x0044, // D
		CAPITAL_E      = 0x0045, // E
		CAPITAL_F      = 0x0046, // F
		CAPITAL_G      = 0x0047, // G
		CAPITAL_H      = 0x0048, // H
		CAPITAL_I      = 0x0049, // I
		CAPITAL_J      = 0x004A, // J
		CAPITAL_K      = 0x004B, // K
		CAPITAL_L      = 0x004C, // L
		CAPITAL_M      = 0x004D, // M
		CAPITAL_N      = 0x004E, // N
		CAPITAL_O      = 0x004F, // O
		CAPITAL_P      = 0x0050, // P
		CAPITAL_Q      = 0x0051, // Q
		CAPITAL_R      = 0x0052, // R
		CAPITAL_S      = 0x0053, // S
		CAPITAL_T      = 0x0054, // T
		CAPITAL_U      = 0x0055, // U
		CAPITAL_V      = 0x0056, // V
		CAPITAL_W      = 0x0057, // W
		CAPITAL_X      = 0x0058, // X
		CAPITAL_Y      = 0x0059, // Y
		CAPITAL_Z      = 0x005A, // Z
		LSQUAREBRACE   = 0x005B, // [
		BACKSLASH      = 0x005C, // \ 
		RSQUAREBRACE   = 0x005D, // ]
		CIRCUMFLEX     = 0x005E, // ^
		UNDERSCORE     = 0x005F, // _
		APOSTROPHE     = 0x0060, // `
		SMALL_A        = 0x0061, // a
		SMALL_B        = 0x0062, // b
		SMALL_C        = 0x0063, // c
		SMALL_D        = 0x0064, // d
		SMALL_E        = 0x0065, // e
		SMALL_F        = 0x0066, // f
		SMALL_G        = 0x0067, // g
		SMALL_H        = 0x0068, // h
		SMALL_I        = 0x0069, // i
		SMALL_J        = 0x006A, // j
		SMALL_K        = 0x006B, // k
		SMALL_L        = 0x006C, // l
		SMALL_M        = 0x006D, // m
		SMALL_N        = 0x006E, // n
		SMALL_O        = 0x006F, // o
		SMALL_P        = 0x0070, // p
		SMALL_Q        = 0x0071, // q
		SMALL_R        = 0x0072, // r
		SMALL_S        = 0x0073, // s
		SMALL_T        = 0x0074, // t
		SMALL_U        = 0x0075, // u
		SMALL_V        = 0x0076, // v
		SMALL_W        = 0x0077, // w
		SMALL_X        = 0x0078, // x
		SMALL_Y        = 0x0079, // y
		SMALL_Z        = 0x007A, // z
		LCURLYBRACE    = 0x007B, // {
		PIPE           = 0x007C, // |
		RCURLYBRACE    = 0x007D, // }
		TILD           = 0x007E, // ~
		DEL            = 0x007F, // Del
	};

  enum class MOUSE_BUTTON : int {
    LEFT     = 0x0000,
    MIDDLE   = 0x0001,
    RIGHT    = 0x0002,
  };

  enum class MOUSE_BUTTON_STATE : int {
    DOWN     = 0x0000,
    UP       = 0x0001,
  };

  enum class MOUSE_STATE : int {
    LEFT    = 0x0000,
    ENTERED = 0x0001,
  };

  std::string toString(KEY key);

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

