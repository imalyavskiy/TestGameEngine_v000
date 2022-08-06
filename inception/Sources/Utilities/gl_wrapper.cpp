#include "gl_wrapper.hpp"
#include <Windows.h>
#include <GL/glew.h>

namespace GL 
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
	
	void GenBuffers(unsigned int numBuffers, unsigned int* buffers)
	{
		glGenBuffers(numBuffers, buffers);
	}
	
	void BindBuffer(BufferType targetBufferType, unsigned int bufferId)
	{
		glBindBuffer((unsigned int)targetBufferType, bufferId);
	}
	
	void BufferData(BufferType targetBufferType, unsigned int dataSize, void* data, Action action)
	{
		glBufferData((unsigned int)targetBufferType, dataSize, data, (unsigned int)action);
	}

	void EnableVertexAttribArray(unsigned int index)
	{
		glEnableVertexAttribArray(index);
	}

	void VertexAttribPointer(unsigned int index, int size, Type type, bool normalized, int stride, const void* pointer)
	{
		glVertexAttribPointer(index, size, (unsigned int)type, normalized, stride, pointer);
	}

	void DrawArrays(DataType dataType, int first, int count)
	{
		glDrawArrays(GL_POINTS, first, count);
	}

	void DisableVertexAttribArray(unsigned int index)
	{
		glDisableVertexAttribArray(index);
	}
}