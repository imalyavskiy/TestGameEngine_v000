#include <GL/freeglut.h>

#include "glut_wrapper.hpp"

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

	void Init(int argc, char** argv)
	{
		glutInit(&argc, argv);
	}

	void InitDisplayMode(std::initializer_list<DisplayMode> flags)
	{
		unsigned int arg = 0;
		for (auto flag : flags)
			arg |= (unsigned int)flag;

		glutInitDisplayMode(arg);
	}

	void CreateWindow(const char* title)
	{
		glutCreateWindow(title);
	}

	void InitWindowSize(int width, int height)
	{
		glutInitWindowSize(1024, 768);
	}

	void InitWindowPosition(int x, int y)
	{
		glutInitWindowPosition(100, 100);
	}

	void MainLoop()
	{
		glutMainLoop();
	}
}