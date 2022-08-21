#include <pch.hpp>
#include <GL/freeglut.h>
#include <Math3D/Math3d.hpp>
#include "Utilities.hpp"

namespace GLUT 
{
  std::string toString(KEY key)
  {
    switch (key) {
    case KEY::F1:
      return "GLUT::KEY::F1";
    case KEY::F2:
      return "GLUT::KEY::F2";
    case KEY::F3:
      return "GLUT::KEY::F3";
    case KEY::F4:
      return "GLUT::KEY::F4";
    case KEY::F5:
      return "GLUT::KEY::F5";
    case KEY::F6:
      return "GLUT::KEY::F6";
    case KEY::F7:
      return "GLUT::KEY::F7";
    case KEY::F8:
      return "GLUT::KEY::F8";
    case KEY::F9:
      return "GLUT::KEY::F9";
    case KEY::F10:
      return "GLUT::KEY::F10";
    case KEY::F11:
      return "GLUT::KEY::F11";
    case KEY::F12:
      return "GLUT::KEY::F12";
    case KEY::LEFT:
      return "GLUT::KEY::LEFT";
    case KEY::UP:
      return "GLUT::KEY::UP";
    case KEY::RIGHT:
      return "GLUT::KEY::RIGHT";
    case KEY::DOWN:
      return "GLUT::KEY::DOWN";
    case KEY::PAGE_UP:
      return "GLUT::KEY::PAGE_UP";
    case KEY::PAGE_DOWN:
      return "GLUT::KEY::PAGE_DOWN";
    case KEY::HOME:
      return "GLUT::KEY::HOME";
    case KEY::END:
      return "GLUT::KEY::END";
    case KEY::INSERT:
      return "GLUT::KEY::INSERT";
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