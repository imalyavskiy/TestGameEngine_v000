#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>

#include "BaseClasses.hpp"

namespace Base {
	ShaderProgram::ShaderProgram(const std::string& name)
		: Object(name) 
	{

	}

	ShaderProgram::ShaderProgram( const std::string& name
								, VertexShader::ptr vertexShader
								, GeometryShader::ptr geometryShader
								, TessControlShader::ptr tessControlShader
								, TessEveluationShader::ptr tessEvaluationShader
								, FragmentShader::ptr fragmentShader)
		: Object(name)
		, vertexShader_(vertexShader)
		, geometryShader_(geometryShader)
		, tessControlShader_(tessControlShader)
		, tessEvaluationShader_(tessEvaluationShader)
		, fragmentShader_(fragmentShader)
	{
	}

	ShaderProgram::ShaderProgram(const std::string& name, const std::string& vertexShader, const std::string& fragmentShader)
		: Object(name)
		, vertexShader_(std::make_shared<VertexShader>(vertexShader))
		, fragmentShader_(std::make_shared<FragmentShader>(fragmentShader))
	{
	}
	
	void ShaderProgram::SetVertexShader(const std::string& vertexShader)
	{
		vertexShader_ = std::make_shared<VertexShader>(vertexShader);
	}

	void ShaderProgram::SetVertexShader(VertexShader::ptr vertexShader)
	{
		vertexShader_ = vertexShader;
	}
	
	void ShaderProgram::SetGeometryShader(const std::string& geometryShader)
	{
		geometryShader_ = std::make_shared<GeometryShader>(geometryShader);
	}

	void ShaderProgram::SetGeometryShader(GeometryShader::ptr geometryShader)
	{
		geometryShader_ = geometryShader;
	}
	
	void ShaderProgram::SetFragmentShader(const std::string& fragmentShader)
	{
		fragmentShader_ = std::make_shared<FragmentShader>(fragmentShader);
	}

	void ShaderProgram::SetFragmentShader(FragmentShader::ptr fragmentShader)
	{
		fragmentShader_ = fragmentShader;
	}
	
	bool ShaderProgram::Build()
	{
		const uint32_t shaderProgramID = GL::CreateProgram();

		auto shaderList = 
			std::make_tuple( vertexShader_
						   , geometryShader_
						   , tessControlShader_
						   , tessEvaluationShader_
						   , fragmentShader_);
		if (!CompileShaderObjects(shaderProgramID, shaderList))
			return false;

		if (!LinkShaderProgram(shaderProgramID))
			return false;

		if (!ValidateShaderProgram(shaderProgramID))
			return false;

		shaderProgramID_ = shaderProgramID;

		return true;
	}

	bool ShaderProgram::CompileShaderObjects(const uint32_t shaderProgramID, ShaderList& shaderList)
	{
		if (shaderProgramID == 0) {
			std::cerr << "Error creating shader program\n";
			return false;
		}

		auto [ vertexShader
			 , geometryShader
			 , tessControlShader
			 , tessEvaluationShader
			 , fragmentShader] = shaderList;

		if (vertexShader && vertexShader->Compile())
			GL::AttachShader(shaderProgramID, vertexShader->GetID());

		if (geometryShader && geometryShader->Compile())
			GL::AttachShader(shaderProgramID, vertexShader->GetID());

		if (tessControlShader && tessControlShader->Compile())
			GL::AttachShader(shaderProgramID, vertexShader->GetID());

		if (tessEvaluationShader&& tessEvaluationShader->Compile())
			GL::AttachShader(shaderProgramID, vertexShader->GetID());

		if (fragmentShader && fragmentShader->Compile())
			GL::AttachShader(shaderProgramID, fragmentShader->GetID());

		return true;
	}

	bool ShaderProgram::LinkShaderProgram(const uint32_t shaderProgramID)
	{

		GL::LinkProgram(shaderProgramID);

		const int32_t success = GL::GetProgramIV(shaderProgramID, GL::ShaderProgramParameter::LINK_STATUS);

		if (!success) {
			std::cerr << "Error linking shader program: '" << GL::GetProgramInfoLog(shaderProgramID) << "'\n";
			return false;
		}

		return true;
	}

	bool ShaderProgram::ValidateShaderProgram(const uint32_t shaderProgramID)
	{
		GL::ValidateProgram(shaderProgramID);

		const int32_t success = GL::GetProgramIV(shaderProgramID, GL::ShaderProgramParameter::VALIDATE_STATUS);

		if (!success) {
			std::cerr << "Invalid shader program: '" << GL::GetProgramInfoLog(shaderProgramID) << "'\n";
			return false;
		}

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

		const auto location = GL::GetUniformLocation(shaderProgramID_, uniformVariableName);
		
		// TODO: There are other error values can be returned
		if (location != -1)
		{
			uniformVariables_[uniformVariableName] = location;
			return true;
		}

		return false;
	}
	
	bool ShaderProgram::UpdateUniform(const std::string& uniformVariableName, float valuef)
	{
		const auto it = uniformVariables_.find(uniformVariableName);
		if(it == uniformVariables_.end())
		{ 
			return false;
		}

		GL::Uniform1f(it->second, valuef);

		return true;
	}

	bool ShaderProgram::UpdateUniform(const std::string& uniformVariableName, const Math3D::Matrix4f& matrix4f)
	{
		const auto it = uniformVariables_.find(uniformVariableName);
		if (it == uniformVariables_.end())
		{
			return false;
		}

		GL::UniformMatrix4fv(it->second, matrix4f);

		return true;
	}

  bool ShaderProgram::UpdateUniform(const std::string& uniformVariableName, const Math3D::Vector3f& vector3f)
  {
		const auto it = uniformVariables_.find(uniformVariableName);
		if (it == uniformVariables_.end())
		{
			return false;
		}

		GL::Uniform3fv(it->second, vector3f);

		return true;
	}
}
