#include <pch.hpp>
#include <Windows.h>
#include <GL/glew.h>
#include <Math3D/Math3d.hpp>
#include "Utilities.hpp"
namespace GL 
{
	std::string toString(AttribMask arg)
	{
		switch (arg)
		{
		case AttribMask::CURRENT_BIT: 
			return "AttribMask::CURRENT_BIT";
		case AttribMask::POINT_BIT:
			return "AttribMask::POINT_BIT";
		case AttribMask::LINE_BIT:
			return "AttribMask::LINE_BIT";
		case AttribMask::POLYGON_BIT:
			return "AttribMask::POLYGON_BIT";
		case AttribMask::POLYGON_STIPPLE_BIT:
			return "AttribMask::POLYGON_STIPPLE_BIT";
		case AttribMask::PIXEL_MODE_BIT:
			return "AttribMask::PIXEL_MODE_BIT";
		case AttribMask::LIGHTING_BIT:
			return "AttribMask::LIGHTING_BIT";
		case AttribMask::FOG_BIT:
			return "AttribMask::FOG_BIT";
		case AttribMask::DEPTH_BUFFER_BIT:
			return "AttribMask::DEPTH_BUFFER_BIT";
		case AttribMask::ACCUM_BUFFER_BIT:
			return "AttribMask::ACCUM_BUFFER_BIT";
		case AttribMask::STENCIL_BUFFER_BIT:
			return "AttribMask::STENCIL_BUFFER_BIT";
		case AttribMask::VIEWPORT_BIT:
			return "AttribMask::VIEWPORT_BIT";
		case AttribMask::TRANSFORM_BIT:
			return "AttribMask::TRANSFORM_BIT";
		case AttribMask::ENABLE_BIT:
			return "AttribMask::ENABLE_BIT";
		case AttribMask::COLOR_BUFFER_BIT:
			return "AttribMask::COLOR_BUFFER_BIT";
		case AttribMask::HINT_BIT:
			return "AttribMask::HINT_BIT";
		case AttribMask::EVAL_BIT:
			return "AttribMask::EVAL_BIT";
		case AttribMask::LIST_BIT:
			return "AttribMask::LIST_BIT";
		case AttribMask::TEXTURE_BIT:
			return "AttribMask::TEXTURE_BIT";
		case AttribMask::SCISSOR_BIT:
			return "AttribMask::SCISSOR_BIT";
		case AttribMask::ALL_ATTRIB_BITS:
			return "AttribMask::ALL_ATTRIB_BITS";
		}
			
		return std::string("AttribMask::INVALID_ATTRIB_MASK");
	}

	std::string toString(BufferType arg)
	{
		// TODO: implement
		throw std::logic_error("not  implemented");
	}

	std::string toString(Action arg)
	{
		// TODO: implement
		throw std::logic_error("not  implemented");
	}

	std::string toString(Type arg)
	{
		// TODO: implement
		throw std::logic_error("not  implemented");
	}

	std::string toString(DataType arg)
	{
		// TODO: implement
		throw std::logic_error("not  implemented");
	}

	std::string toString(ShaderType arg)
	{
		switch (arg)
		{
		case ShaderType::VERTEX_SHADER:
			return "ShaderType::VERTEX_SHADER";
		case ShaderType::GEOMETRY_SHADER:
			return "ShaderType::GEOMETRY_SHADER";
		case ShaderType::TESS_CONTROL_SHADER:
			return "ShaderType::TESS_CONTROL_SHADER";
		case ShaderType::TESS_EVALUATION_SHADER:
			return "ShaderType::TESS_EVALUATION_SHADER";
		case ShaderType::FRAGMENT_SHADER:
			return "ShaderType::FRAGMENT_SHADER";
		case ShaderType::COMPUTE_SHADER:
			return "ShaderType::COMPUTE_SHADER";
		}
		
		return "ShaderType::INVALID_SHADER_TYPE";
	}

	std::string toString(ShaderObjectParameter arg)
	{
		// TODO: implement
		throw std::logic_error("not  implemented");
	}

	std::string toString(ShaderProgramParameter arg)
	{
		// TODO: implement
		throw std::logic_error("not  implemented");
	}

	void Clear(std::initializer_list<AttribMask> mask)
	{
		uint32_t arg = 0;
		for (auto& flag : mask)
			arg |= (uint32_t)flag;

		glClear(arg);
	}

	void ClearColor(float red, float green, float blue, float alpha)
	{
		glClearColor(red, green, blue, alpha);
	}
	
	void GenBuffer(uint32_t& buffer)
	{
		std::vector<uint32_t> bufferObjectList(1, _UI32_MAX);
		GL::GenBuffers(bufferObjectList);
		buffer = bufferObjectList[0];
	}

	void GenBuffers(std::vector<uint32_t>& buffers)
	{
		glGenBuffers(buffers.size(), buffers.data());
	}
	
	void BindBuffer(BufferType targetBufferType, uint32_t bufferId)
	{
		glBindBuffer((GLenum)targetBufferType, bufferId);
	}
	
	void BufferData(BufferType bufferType, uint32_t dataSize, void* data, Action action)
	{
		glBufferData((GLenum)bufferType, dataSize, data, (GLenum)action);
	}

	void EnableVertexAttribArray(uint32_t index)
	{
		glEnableVertexAttribArray(index);
	}

	void VertexAttribPointer(uint32_t index, int32_t size, Type type, bool normalized, int32_t stride, const void* pointer)
	{
		glVertexAttribPointer(index, size, (GLenum)type, normalized, stride, pointer);
	}

	void DrawArrays(DataType dataType, int32_t first, int32_t count)
	{
		glDrawArrays((GLenum)dataType, first, count);
	}

	void DrawElements(DataType dataType, int32_t count, Type type)
	{
		glDrawElements((GLenum)dataType, count, (GLenum)type, nullptr);
	}

	void DisableVertexAttribArray(uint32_t index)
	{
		glDisableVertexAttribArray(index);
	}

	uint32_t CreateShader(ShaderType shaderType)
	{
		return glCreateShader((GLuint)shaderType);
	}

	void ShaderSource(uint32_t shaderObjectID, const std::vector<std::string>& shaderSourceCode)
	{
		const uint32_t count = shaderSourceCode.size();
		
		std::vector<const char*> sources; 
		sources.reserve(count);
		
		std::vector<int32_t> lengths;
		lengths.reserve(count);

		for (auto& chunk : shaderSourceCode)
		{
			sources.push_back(chunk.data());
			lengths.push_back(chunk.size());
		}

		glShaderSource(shaderObjectID, shaderSourceCode.size(), sources.data(), lengths.data());
	}

	void CompileShader(uint32_t shaderObjectID)
	{
		glCompileShader(shaderObjectID);
	}

	void GetShaderiv(uint32_t shaderObjectID, ShaderObjectParameter parameterID, int32_t* parameterValue)
	{
		glGetShaderiv(shaderObjectID, (GLuint)parameterID, parameterValue);
	}

	void GetShaderInfoLog(uint32_t shaderObjectID, std::string& infoLog)
	{
		const uint32_t infoLogLength = 2048;
		infoLog.reserve(infoLogLength);
		int32_t infoLogFinalLength;
		glGetShaderInfoLog(shaderObjectID, infoLogLength, &infoLogFinalLength, &infoLog[0]);
	}

	uint32_t CreateProgram() 
	{
		return glCreateProgram();
	}

	void AttachShader(uint32_t shaderProgramID, uint32_t shaderObjectID)
	{
		glAttachShader(shaderProgramID, shaderObjectID);
	}

	void LinkProgram(uint32_t shaderProgramID)
	{
		glLinkProgram(shaderProgramID);
	}

	void GetProgramiv(uint32_t shaderProgramID, ShaderProgramParameter parameter, int32_t* parameterValue)
	{
		glGetProgramiv(shaderProgramID, (GLenum)parameter, parameterValue);
	}

	void GetProgramInfoLog(uint32_t shaderObjectID, std::string& infoLog)
	{
		const uint32_t infoLogLength = 2048;
		infoLog.reserve(infoLogLength);
		int32_t infoLogFinalLength;
		glGetProgramInfoLog(shaderObjectID, infoLogLength, &infoLogFinalLength, &infoLog[0]);
	}

	void ValidateProgram(uint32_t shaderProgramID)
	{
		glValidateProgram(shaderProgramID);
	}

	
	void UseProgram(uint32_t shaderProgramID)
	{
		glUseProgram(shaderProgramID);
	}

	int32_t GetUniformLocation(uint32_t shaderProgramID, const std::string& uniformVariableName)
	{
		return glGetUniformLocation(shaderProgramID, uniformVariableName.data());
	}

	void Uniform1f(uint32_t location, float value)
	{
		glUniform1f(location, value);
	}

	void UniformMatrix4fv(uint32_t location, const Math3D::Matrix4f& matrix)
	{
		// Giving just one(2nd parameter) transposed(3rd parameter) matrix.
		glUniformMatrix4fv(location, 1, GL_TRUE, matrix.data());
	}
}