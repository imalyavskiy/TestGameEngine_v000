#include <pch.hpp>
#include <Windows.h>
#include <GL/glew.h>

#include "gl_wrapper.hpp"
#include "glew_wrapper.hpp"

namespace GLEW
{
	Error Init()
	{
		return (Error)glewInit();
	}

	std::string GetErrorString(Error error)
	{
		return { (char*)glewGetErrorString((unsigned int)error) };
	}
}