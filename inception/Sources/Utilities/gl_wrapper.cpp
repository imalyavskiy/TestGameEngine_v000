#include <pch.hpp>
#include <Windows.h>
#include <GL/glew.h>
#include "Utilities.hpp"
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
		glBindBuffer((GLenum)targetBufferType, bufferId);
	}
	
	void BufferData(BufferType targetBufferType, unsigned int dataSize, void* data, Action action)
	{
		glBufferData((unsigned int)targetBufferType, dataSize, data, (GLenum)action);
	}

	void EnableVertexAttribArray(unsigned int index)
	{
		glEnableVertexAttribArray(index);
	}

	void VertexAttribPointer(unsigned int index, int size, Type type, bool normalized, int stride, const void* pointer)
	{
		glVertexAttribPointer(index, size, (GLenum)type, normalized, stride, pointer);
	}

	void DrawArrays(DataType dataType, int first, int count)
	{
		glDrawArrays((GLenum)dataType, first, count);
	}

	void DisableVertexAttribArray(unsigned int index)
	{
		glDisableVertexAttribArray(index);
	}
}