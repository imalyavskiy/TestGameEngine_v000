#ifndef __GLEW_WRAPPER_HPP__
#define __GLEW_WRAPPER_HPP__

#ifdef NO_ERROR
#undef NO_ERROR
#endif

namespace GLEW
{
	enum class Error : unsigned int
	{
        OK                        = 0,
        NO_ERROR                  = 0,
        ERROR_NO_GL_VERSION       = 1, /* missing GL version */
        ERROR_GL_VERSION_10_ONLY  = 2, /* Need at least OpenGL 1.1 */
        ERROR_GLX_VERSION_11_ONLY = 3, /* Need at least GLX 1.2 */
	};

	Error Init();

    std::string GetErrorString(Error error);
}
#endif // __GLEW_WRAPPER_HPP__