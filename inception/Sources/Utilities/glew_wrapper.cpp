#include <pch.hpp>
#include <Windows.h>
#include <GL/glew.h>
#include "Utilities.hpp"

namespace GLEW
{
	Error Init()
	{
		return (Error)glewInit();
	}

	std::string GetErrorString(Error error)
	{
		return { (char*)glewGetErrorString((GLenum)error) };
	}
}