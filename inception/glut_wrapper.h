#ifndef __GLUT_WRAPPER_H__
#define __GLUT_WRAPPER_H__

#include <initializer_list>

namespace glut {
	enum class DisplayMode : unsigned int
	{
		RGB         = 0x0000,
		RGBA        = 0x0000,
		INDEX       = 0x0001,
		SINGLE      = 0x0000,
		DOUBLE      = 0x0002,
		ACCUM       = 0x0004,
		ALPHA       = 0x0008,
		DEPTH       = 0x0010,
		STENCIL     = 0x0020,
		MULTISAMPLE = 0x0080,
		STEREO      = 0x0100,
		LUMINANCE   = 0x0200,
	};

	/// Performs buffer swap in case of multi buffer rendering
	void SwapBuffers();
	
	/// Sets the pointer of the display callback function
	void DisplayFunc(void (*callback)(void));
	
	/// Intializes the GLUT library
	void Init(int argc, char** argv);
	
	/// Sets the mode
	void InitDisplayMode(std::initializer_list<DisplayMode> flags);
	
	/// Initial window size in pixels
	void InitWindowSize(int width, int height);
	
	/// Sets the left top corner of the display window
	void InitWindowPosition(int x, int y);
	
	/// Creates a new window with provided title
	void CreateWindow(const char* title);

	/// Runs GLUT rendering loop. The loop calls callback functions.
	void MainLoop();
};
#endif // __GLUT_WRAPPER_H__

