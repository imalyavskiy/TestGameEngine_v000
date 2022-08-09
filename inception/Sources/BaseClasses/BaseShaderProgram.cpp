#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>

#include "BaseClasses.hpp"

namespace Base {
	ShaderProgram::ShaderProgram(const std::string& name)
		: Object(name) 
	{

	}

	ShaderProgram::ShaderProgram(const std::string& name, VertexShader::ptr vertexShader, FragmentShader::ptr fragmentShader)
		: Object(name)
		, vertexShader_(vertexShader)
		, fragmentShader_(fragmentShader)
	{
	}

	ShaderProgram::ShaderProgram(const std::string& name, const std::string& vertexShader, const std::string& fragmentShader)
		: Object(name)
		, vertexShader_(std::make_shared<VertexShader>(vertexShader))
		, fragmentShader_(std::make_shared<FragmentShader>(fragmentShader))
	{
	}
	
	void ShaderProgram::SetVertexShader(const std::string& sourceCode)
	{
		vertexShader_ = std::make_shared<VertexShader>(sourceCode);
	}

	void ShaderProgram::SetVertexShader(VertexShader::ptr vertexShader)
	{
		vertexShader_ = vertexShader;
	}
	
	void ShaderProgram::SetGeometryShader(const std::string& sourceCode)
	{
		geometryShader_ = std::make_shared<GeometryShader>(sourceCode);
	}

	void ShaderProgram::SetGeometryShader(GeometryShader::ptr geometryShader)
	{
		geometryShader_ = geometryShader;
	}
	
	void ShaderProgram::SetFragmentShader(const std::string& sourceCode)
	{
		fragmentShader_ = std::make_shared<FragmentShader>(sourceCode);
	}

	void ShaderProgram::SetFragmentShader(FragmentShader::ptr fragmentShader)
	{
		fragmentShader_ = fragmentShader;
	}
	
	bool ShaderProgram::Build()
	{
		uint32_t shaderProgramID = GL::CreateProgram();

		// Compile. TODO: extract to separate method
		{
			if (shaderProgramID == 0) {
				fprintf(stderr, "Error creating shader program\n");
				return false;
			}

			if (vertexShader_ && vertexShader_->Compile())
				GL::AttachShader(shaderProgramID, vertexShader_->GetID());

			if (fragmentShader_ && fragmentShader_->Compile())
				GL::AttachShader(shaderProgramID, fragmentShader_->GetID());
		}

		// Link. TODO: extract to separate method
		{
			int32_t success = 0;
			std::string errorLog;

			GL::LinkProgram(shaderProgramID);

			GL::GetProgramiv(shaderProgramID, GL::ShaderProgramParameter::LINK_STATUS, &success);
			if (!success) {
				GL::GetProgramInfoLog(shaderProgramID_, errorLog);
				std::cout << "Error linking shader program: '" << errorLog << "'\n";
				return false;
			}
		}

		// Validate. TODO: extract to separate method
		{
			int32_t success = 0;
			std::string errorLog;

			GL::ValidateProgram(shaderProgramID);

			GL::GetProgramiv(shaderProgramID, GL::ShaderProgramParameter::VALIDATE_STATUS, &success);
			if (!success) {
				GL::GetProgramInfoLog(shaderProgramID, errorLog);
				std::cout << "Invalid shader program: '" << errorLog << "'\n";
				return false;
			}
		}

		shaderProgramID_ = shaderProgramID;

		return true;
	}
	
	void ShaderProgram::Use() const
	{
		GL::UseProgram(shaderProgramID_);
	}
	
	bool ShaderProgram::IsValid() const
	{
		return shaderProgramID_ != _UI32_MAX;
	}
	
	bool ShaderProgram::AttachToUniform(const std::string& uniformVariableName)
	{
		if(shaderProgramID_ == _UI32_MAX)
			return false;

		GL::UseProgram(shaderProgramID_);

		auto location = GL::GetUniformLocation(shaderProgramID_, uniformVariableName);
		
		// TODO: There are other error values can be returned
		if (location != -1)
		{
			uniformVariables_[uniformVariableName] = location;
			return true;
		}

		return false;
	}
	
	bool ShaderProgram::UpdateUniform(const std::string& uniformVariableName, float value)
	{
		auto it = uniformVariables_.find(uniformVariableName);
		if(it == uniformVariables_.end())
		{ 
			return false;
		}

		GL::Uniform1f(it->second, value);

		return true;
	}

	bool ShaderProgram::UpdateUniform(const std::string& uniformVariableName, const Math3D::Matrix4f& matrix)
	{
		auto it = uniformVariables_.find(uniformVariableName);
		if (it == uniformVariables_.end())
		{
			return false;
		}

		GL::UniformMatrix4fv(it->second, matrix);

		return true;
	}

}