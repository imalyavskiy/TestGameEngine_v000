#include <pch.hpp>
#include <GL/freeglut.h>
#include "Utilities.hpp"

namespace GLUT 
{
	void SwapBuffers() 
	{
		glutSwapBuffers();
	}

	void DisplayFunc(void(*callback)(void))
	{
		glutDisplayFunc(callback);
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
}