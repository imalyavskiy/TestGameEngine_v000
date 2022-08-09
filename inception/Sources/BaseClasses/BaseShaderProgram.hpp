#ifndef __BASE_SHADER_PROGRAM_HPP__
#define __BASE_SHADER_PROGRAM_HPP__
namespace Base
{
	class ShaderProgram : public Object
	{
	public:
		///
		using ptr = std::shared_ptr<ShaderProgram>;

		///
		ShaderProgram(const std::string& name);
		ShaderProgram(const std::string& name, VertexShader::ptr vertexShader, FragmentShader::ptr fragmentShader);
		ShaderProgram(const std::string& name, const std::string& vertexShader, const std::string& fragmentShader);

		///
		void SetVertexShader(const std::string& vertexShader);
		void SetVertexShader(VertexShader::ptr vertexShader);

		///
		void SetGeometryShader(const std::string& gemetryShader);
		void SetGeometryShader(GeometryShader::ptr geometryShader);

		///
		void SetFragmentShader(const std::string& fragmentShader);
		void SetFragmentShader(FragmentShader::ptr fragmentShader);

		///
		bool Build();

		///
		void Use() const;

		///
		bool IsValid() const;

		/// 
		bool AttachToUniform(const std::string& uniformVariableName);

		/// 
		bool UpdateUniform(const std::string& uniformVariableName, float value);

		///
		bool UpdateUniform(const std::string& uniformVariableName, const Math3D::Matrix4f& matrix);

	protected:
		///
		uint32_t shaderProgramID_ = _UI32_MAX;

		///
		VertexShader::ptr vertexShader_;
		
		///
		GeometryShader::ptr geometryShader_;
		
		///
		TessControlShader::ptr tessColtrolShader_;

		///
		TessEveluationShader::ptr tessEvaluationShader_;

		///
		FragmentShader::ptr fragmentShader_;

		///
		std::map<std::string, int32_t> uniformVariables_;
	};
}
#endif // __BASE_SHADER_PROGRAM_HPP__