#include <pch.hpp>
#include <Utilities/Utilities.hpp>
#include "BaseClasses.hpp"

namespace Base {
	ShaderObject::ShaderObject(const std::string& name, GL::ShaderType shaderType)
		: Object(name)
		, shaderType_(shaderType)
	{
	}

	ShaderObject::ShaderObject(const std::string& name, GL::ShaderType shaderType, const std::string& sourceCode)
		: Object(name)
		, shaderType_(shaderType)
		, sourceCode_(sourceCode)
	{
	}
	
	bool ShaderObject::Compile()
	{
		shaderObjectID_ = GL::CreateShader(shaderType_);

		if (shaderObjectID_ == 0) {
			std::cout << "Error creating shader of "<< GL::toString(shaderType_) <<" type\n";
			return false;
		}

		GL::ShaderSource(shaderObjectID_, { sourceCode_ });

		GL::CompileShader(shaderObjectID_);

		int32_t success = 0;
		GL::GetShaderiv(shaderObjectID_, GL::ShaderObjectParameter::COMPILE_STATUS, &success);

		if (!success) {
			std::string infoLog;

			GL::GetShaderInfoLog(shaderObjectID_, infoLog);
			std::cout << "Error compiling shader type " << GL::toString(shaderType_) << " : '" << infoLog << "'\n";
			return false;
		}

		return true;
	}
	uint32_t ShaderObject::GetID() const
	{
		return shaderObjectID_;
	}
}