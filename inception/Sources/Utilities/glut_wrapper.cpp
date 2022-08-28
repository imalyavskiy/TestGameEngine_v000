#include <pch.hpp>
#include <GL/freeglut.h>
#include <Math3D/Math3d.hpp>
#include "Utilities.hpp"

namespace GLUT 
{
  std::string toString(KEY key)
  {
    switch (key) {
		case GLUT::KEY::F1:
			return "F1";
		case GLUT::KEY::F2:
			return "F2";
		case GLUT::KEY::F3:
			return "F3";
		case GLUT::KEY::F4:
			return "F4";
		case GLUT::KEY::F5:
			return "F5";
		case GLUT::KEY::F6:
			return "F6";
		case GLUT::KEY::F7:
			return "F7";
		case GLUT::KEY::F8:
			return "F8";
		case GLUT::KEY::F9:
			return "F9";
		case GLUT::KEY::F10:
			return "F10";
		case GLUT::KEY::F11:
			return "F11";
		case GLUT::KEY::F12:
			return "F12";
		case GLUT::KEY::LEFT:
			return "LEFT";
		case GLUT::KEY::UP:
			return "UP";
		case GLUT::KEY::RIGHT:
			return "RIGHT";
		case GLUT::KEY::DOWN:
			return "DOWN";
		case GLUT::KEY::PAGE_UP:
			return "PAGE_UP";
		case GLUT::KEY::PAGE_DOWN:
			return "PAGE_DOWN";
		case GLUT::KEY::HOME:
			return "HOME";
		case GLUT::KEY::END:
			return "END";
		case GLUT::KEY::INSERT:
			return "INSERT";
		case GLUT::KEY::LSHIFT:
			return "LSHIFT";
		case GLUT::KEY::RSHIFT:
			return "RSHIFT";
		case GLUT::KEY::LCTRL:
			return "LCTRL";
		case GLUT::KEY::RCTRL:
			return "RCTRL";
		case GLUT::KEY::LALT:
			return "LALT";
		case GLUT::KEY::RALT:
			return "RALT";
		case GLUT::KEY::BACKSPACE:
			return "BACKSPACE";
		case GLUT::KEY::TAB:
			return "TAB";
		case GLUT::KEY::ENTER:
			return "ENTER";
		case GLUT::KEY::CAPSLOCK:
			return "CAPSLOCK";
		case GLUT::KEY::ESCAPE:
			return "ESCAPE";
		case GLUT::KEY::EXCLAMATION:
			return "EXCLAMATION";
		case GLUT::KEY::DBLQUOTE:
			return "DBLQUOTE";
		case GLUT::KEY::SHARP:
			return "SHARP";
		case GLUT::KEY::DOLLAR:
			return "DOLLAR";
		case GLUT::KEY::PRECENT:
			return "PRECENT";
		case GLUT::KEY::AND:
			return "AND";
		case GLUT::KEY::SGLQUOTE:
			return "SGLQUOTE";
		case GLUT::KEY::LBRACE:
			return "LBRACE";
		case GLUT::KEY::RBRACE:
			return "RBRACE";
		case GLUT::KEY::ASTERISK:
			return "ASTERISK";
		case GLUT::KEY::PLUS:
			return "PLUS";
		case GLUT::KEY::COMMA:
			return "COMMA";
		case GLUT::KEY::MINUS:
			return "MINUS";
		case GLUT::KEY::DOT:
			return "DOT";
		case GLUT::KEY::SLASH:
			return "SLASH";
		case GLUT::KEY::ZERO:
			return "ZERO";
		case GLUT::KEY::ONE:
			return "ONE";
		case GLUT::KEY::TWO:
			return "TWO";
		case GLUT::KEY::THREE:
			return "THREE";
		case GLUT::KEY::FOUR:
			return "FOUR";
		case GLUT::KEY::FIVE:
			return "FIVE";
		case GLUT::KEY::SIX:
			return "SIX";
		case GLUT::KEY::SEVEN:
			return "SEVEN";
		case GLUT::KEY::EIGHT:
			return "EIGHT";
		case GLUT::KEY::NINE:
			return "NINE";
		case GLUT::KEY::COLON:
			return "COLON";
		case GLUT::KEY::SEMICOLON:
			return "SEMICOLON";
		case GLUT::KEY::LANGLEBRACE:
			return "LANGLEBRACE";
		case GLUT::KEY::EQUALS:
			return "EQUALS";
		case GLUT::KEY::RANGLEBRACE:
			return "RANGLEBRACE";
		case GLUT::KEY::QUESTION:
			return "QUESTION";
		case GLUT::KEY::AT:
			return "AT";
		case GLUT::KEY::CAPITAL_A:
			return "CAPITAL_A";
		case GLUT::KEY::CAPITAL_B:
			return "CAPITAL_B";
		case GLUT::KEY::CAPITAL_C:
			return "CAPITAL_C";
		case GLUT::KEY::CAPITAL_D:
			return "CAPITAL_D";
		case GLUT::KEY::CAPITAL_E:
			return "CAPITAL_E";
		case GLUT::KEY::CAPITAL_F:
			return "CAPITAL_F";
		case GLUT::KEY::CAPITAL_G:
			return "CAPITAL_G";
		case GLUT::KEY::CAPITAL_H:
			return "CAPITAL_H";
		case GLUT::KEY::CAPITAL_I:
			return "CAPITAL_I";
		case GLUT::KEY::CAPITAL_J:
			return "CAPITAL_J";
		case GLUT::KEY::CAPITAL_K:
			return "CAPITAL_K";
		case GLUT::KEY::CAPITAL_L:
			return "CAPITAL_L";
		case GLUT::KEY::CAPITAL_M:
			return "CAPITAL_M";
		case GLUT::KEY::CAPITAL_N:
			return "CAPITAL_N";
		case GLUT::KEY::CAPITAL_O:
			return "CAPITAL_O";
		case GLUT::KEY::CAPITAL_P:
			return "CAPITAL_P";
		case GLUT::KEY::CAPITAL_Q:
			return "CAPITAL_Q";
		case GLUT::KEY::CAPITAL_R:
			return "CAPITAL_R";
		case GLUT::KEY::CAPITAL_S:
			return "CAPITAL_S";
		case GLUT::KEY::CAPITAL_T:
			return "CAPITAL_T";
		case GLUT::KEY::CAPITAL_U:
			return "CAPITAL_U";
		case GLUT::KEY::CAPITAL_V:
			return "CAPITAL_V";
		case GLUT::KEY::CAPITAL_W:
			return "CAPITAL_W";
		case GLUT::KEY::CAPITAL_X:
			return "CAPITAL_X";
		case GLUT::KEY::CAPITAL_Y:
			return "CAPITAL_Y";
		case GLUT::KEY::CAPITAL_Z:
			return "CAPITAL_Z";
		case GLUT::KEY::LSQUAREBRACE:
			return "LSQUAREBRACE";
		case GLUT::KEY::BACKSLASH:
			return "BACKSLASH";
		case GLUT::KEY::RSQUAREBRACE:
			return "RSQUAREBRACE";
		case GLUT::KEY::CIRCUMFLEX:
			return "CIRCUMFLEX";
		case GLUT::KEY::UNDERSCORE:
			return "UNDERSCORE";
		case GLUT::KEY::APOSTROPHE:
			return "APOSTROPHE";
		case GLUT::KEY::SMALL_A:
			return "SMALL_A";
		case GLUT::KEY::SMALL_B:
			return "SMALL_B";
		case GLUT::KEY::SMALL_C:
			return "SMALL_C";
		case GLUT::KEY::SMALL_D:
			return "SMALL_D";
		case GLUT::KEY::SMALL_E:
			return "SMALL_E";
		case GLUT::KEY::SMALL_F:
			return "SMALL_F";
		case GLUT::KEY::SMALL_G:
			return "SMALL_G";
		case GLUT::KEY::SMALL_H:
			return "SMALL_H";
		case GLUT::KEY::SMALL_I:
			return "SMALL_I";
		case GLUT::KEY::SMALL_J:
			return "SMALL_J";
		case GLUT::KEY::SMALL_K:
			return "SMALL_K";
		case GLUT::KEY::SMALL_L:
			return "SMALL_L";
		case GLUT::KEY::SMALL_M:
			return "SMALL_M";
		case GLUT::KEY::SMALL_N:
			return "SMALL_N";
		case GLUT::KEY::SMALL_O:
			return "SMALL_O";
		case GLUT::KEY::SMALL_P:
			return "SMALL_P";
		case GLUT::KEY::SMALL_Q:
			return "SMALL_Q";
		case GLUT::KEY::SMALL_R:
			return "SMALL_R";
		case GLUT::KEY::SMALL_S:
			return "SMALL_S";
		case GLUT::KEY::SMALL_T:
			return "SMALL_T";
		case GLUT::KEY::SMALL_U:
			return "SMALL_U";
		case GLUT::KEY::SMALL_V:
			return "SMALL_V";
		case GLUT::KEY::SMALL_W:
			return "SMALL_W";
		case GLUT::KEY::SMALL_X:
			return "SMALL_X";
		case GLUT::KEY::SMALL_Y:
			return "SMALL_Y";
		case GLUT::KEY::SMALL_Z:
			return "SMALL_Z";
		case GLUT::KEY::LCURLYBRACE:
			return "LCURLYBRACE";
		case GLUT::KEY::PIPE:
			return "PIPE";
		case GLUT::KEY::RCURLYBRACE:
			return "RCURLYBRACE";
		case GLUT::KEY::TILD:
			return "TILD";
		case GLUT::KEY::DEL:
			return "DEL";
    }
    return "n/a";
  }

	void SwapBuffers() 
	{
		glutSwapBuffers();
	}

	void Init(int32_t argc, char** argv)
	{
		glutInit(&argc, argv);
	}

	void InitDisplayMode(std::initializer_list<DisplayMode> flags)
	{
		uint32_t arg = 0;
		for (auto flag : flags)
			arg |= (uint32_t)flag;

		glutInitDisplayMode(arg);
	}

	void CreateWindow(const char* title)
	{
		glutCreateWindow(title);
	}

	void InitWindowSize(int32_t width, int32_t height)
	{
		glutInitWindowSize(width, height);
	}

	void InitWindowPosition(int32_t x, int32_t y)
	{
		glutInitWindowPosition(x, y);
	}

	void MainLoop()
	{
		glutMainLoop();
	}

	void IdleFunc(void(*callback)(void))
	{
		glutIdleFunc(callback);
	}

	void DisplayFunc(void(*callback)(void))
	{
		glutDisplayFunc(callback);
	}

	void MouseFunc(void(*callback)(int, int, int, int))
	{
		glutMouseFunc(callback);
	}

	void MotionFunc(void(*callback)(int, int))
	{
		glutMotionFunc(callback);
	}

	void PassiveMotionFunc(void(*callback)(int, int))
	{
		glutPassiveMotionFunc(callback);
	}

	void EntryFunc(void(*callback)(int))
	{
		glutEntryFunc(callback);
	}

	void KeyboardUpFunc(void(*callback)(unsigned char, int, int))
	{
		glutKeyboardUpFunc(callback);
	}

	void SpecialUpFunc(void(*callback)(int, int, int))
	{
		glutSpecialUpFunc(callback);
	}

	void JoystickFunc(void(*callback)(unsigned int, int, int, int), int pollInterval)
	{
		glutJoystickFunc(callback, pollInterval);
	}

	void MenuStateFunc(void(*callback)(int))
	{
		glutMenuStateFunc(callback);
	}

	void MenuStatusFunc(void(*callback)(int, int, int))
	{
		glutMenuStatusFunc(callback);
	}

	void OverlayDisplayFunc(void(*callback)(void))
	{
		glutOverlayDisplayFunc(callback);
	}

	void WindowStatusFunc(void(*callback)(int))
	{
		glutWindowStatusFunc(callback);
	}

	void SpaceballMotionFunc(void(*callback)(int, int, int))
	{
		glutSpaceballMotionFunc(callback);
	}

	void SpaceballRotateFunc(void(*callback)(int, int, int))
	{
		glutSpaceballRotateFunc(callback);
	}

	void SpaceballButtonFunc(void(*callback)(int, int))
	{
		glutSpaceballButtonFunc(callback);
	}

	void ButtonBoxFunc(void(*callback)(int, int))
	{
		glutButtonBoxFunc(callback);
	}

	void DialsFunc(void(*callback)(int, int))
	{
		glutDialsFunc(callback);
	}

	void TabletMotionFunc(void(*callback)(int, int))
	{
		glutTabletMotionFunc(callback);
	}

	void TabletButtonFunc(void(*callback)(int, int, int, int))
	{
		glutTabletButtonFunc(callback);
	}

  void WarpPointer(const int x, const int y)
  {
		glutWarpPointer(x, y);
  }

  void SetCursor(CURSOR cursor)
  {
		glutSetCursor(static_cast<int>(cursor));
  }

  void TimerFunc(unsigned int time, void(*callback)(int), int value)
	{
		glutTimerFunc(time, callback, value);
	}

	void KeyboardFunc(void(*callback)(unsigned char, int, int))
	{
		glutKeyboardFunc(callback);
	}

	void SpecialFunc(void(*callback)(int, int, int))
	{
		glutSpecialFunc(callback);
	}

	void ReshapeFunc(void(*callback)(int, int))
	{
		glutReshapeFunc(callback);
	}

	void VisibilityFunc(void(*callback)(int))
	{
		glutVisibilityFunc(callback);
	}
}