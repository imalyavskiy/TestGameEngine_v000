#ifndef __BASE_SHADER_PROGRAM_HPP__
#define __BASE_SHADER_PROGRAM_HPP__
namespace Base
{
	class ShaderProgram : public Object
	{
	public:
		/**
		*/
		using ptr = std::shared_ptr<ShaderProgram>;

		/**
		*/
		ShaderProgram(const std::string& name);
		ShaderProgram( const std::string& name
					 , VertexShader::ptr vertexShader
					 , GeometryShader::ptr geometryShader
					 , TessControlShader::ptr tessControlShader
					 , TessEveluationShader::ptr tessEvaluationShader
					 , FragmentShader::ptr fragmentShader);

		// TODO: add other shaders
		ShaderProgram( const std::string& name, const std::string& vertexShader, const std::string& fragmentShader);

		/**
		*/
		void SetVertexShader(const std::string& vertexShader);
		void SetVertexShader(VertexShader::ptr vertexShader);

		/**
		*/
		void SetGeometryShader(const std::string& geometryShader);
		void SetGeometryShader(GeometryShader::ptr geometryShader);

		/**
		*/
		// TODO: add tessellation control shader methods

		/**
		*/
		// TODO: add tessellation evaluation shader methods

		/**
		*/
		void SetFragmentShader(const std::string& fragmentShader);
		void SetFragmentShader(FragmentShader::ptr fragmentShader);

		/**
		*/
		bool Build();

		/**
		*/
		void Use() const;

		/**
		*/
		bool IsValid() const;

		/**
		*/
		bool AttachToUniform(const std::string& uniformVariableName);

		/**
		*/
		bool UpdateUniform(const std::string& uniformVariableName, float valuef);

		/**
		*/
		bool UpdateUniform(const std::string& uniformVariableName, const Math3D::Matrix4f& matrix4f);

		/**
		*/
		bool UpdateUniform(const std::string& uniformVariableName, const Math3D::Vector3f& vector3f);

	protected:
		using ShaderList = std::tuple<VertexShader::ptr, GeometryShader::ptr, TessControlShader::ptr, TessEveluationShader::ptr, FragmentShader::ptr>;

		/**
		Compiles currently present shader objects. This function is the first step of the Build method.
		*/
		static bool CompileShaderObjects(const uint32_t shaderProgramID, ShaderList& shaderList);

		/**
		Links currently built present shader object into one shader program. This function is the second step of the Build method.
		*/
		static bool LinkShaderProgram(const uint32_t shaderProgramID);

		/**
		Validate currently linked shader program. This function is the first step of the Build method.
		*/
		static bool ValidateShaderProgram(const uint32_t shaderProgramID);

	protected:
		/**
		*/
		uint32_t shaderProgramID_ = _UI32_MAX;

		/**
		*/
		VertexShader::ptr vertexShader_;
		
		/**
		*/
		GeometryShader::ptr geometryShader_;
		
		/**
		*/
		TessControlShader::ptr tessControlShader_;

		/**
		*/
		TessEveluationShader::ptr tessEvaluationShader_;

		/**
		*/
		FragmentShader::ptr fragmentShader_;

		/**
		*/
		std::map<std::string, int32_t> uniformVariables_;
	};
}
#endif // __BASE_SHADER_PROGRAM_HPP__