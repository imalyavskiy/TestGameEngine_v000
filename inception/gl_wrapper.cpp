#include "gl_wrapper.h"
#include <Windows.h>
#include <GL/GL.h>
namespace gl 
{
	void Clear(std::initializer_list<AttribMask> mask)
	{
		unsigned int arg = 0;
		for (auto flag : mask)
			arg |= (unsigned int)flag;

		glClear(arg);
	}

	void ClearColor(float red, float green, float blue, float alpha)
	{
		glClearColor(red, green, blue, alpha);
	}
}