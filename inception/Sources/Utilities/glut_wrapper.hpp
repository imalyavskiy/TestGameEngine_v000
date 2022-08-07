#ifndef __GLUT_WRAPPER_H__
#define __GLUT_WRAPPER_H__

#include <initializer_list>

#ifdef CreateWindow
#undef CreateWindow
#endif

/// TODO: Document. Add link.
namespace GLUT {
	/// TODO: Document. Add link.
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

	/// TODO: Document. Add link.
	void SwapBuffers();
	
	/// TODO: Document. Add link.
	void DisplayFunc(void (*callback)(void));
	
	/// TODO: Document. Add link.
	void Init(int32_t argc, char** argv);
	
	/// TODO: Document. Add link.
	void InitDisplayMode(std::initializer_list<DisplayMode> flags);
	
	/// TODO: Document. Add link.
	void InitWindowSize(int32_t width, int32_t height);
	
	/// TODO: Document. Add link.
	void InitWindowPosition(int32_t x, int32_t y);
	
	/// TODO: Document. Add link.
	void CreateWindow(const char* title);

	/// TODO: Document. Add link.
	void MainLoop();
};
#endif // __GLUT_WRAPPER_H__

