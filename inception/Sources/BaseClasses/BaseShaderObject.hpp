#ifndef __BASE_SHADER_OBJECT_HPP__
#define __BASE_SHADER_OBJECT_HPP__
namespace Base
{
	class ShaderObject : public Object 
	{
	public:
		///
		using ptr = std::shared_ptr<ShaderObject>;

		///
		ShaderObject(const std::string& name, GL::ShaderType type);

		///
		ShaderObject(const std::string& name, GL::ShaderType type, const std::string& sourceCode);

		///
		bool Compile();

		///
		uint32_t GetID() const;
	
	protected:
		///
		std::string sourceCode_;

		///
		uint32_t shaderObjectID_ = _UI32_MAX;

		/// 
		GL::ShaderType shaderType_ = GL::ShaderType::INVALID_SHADER_TYPE;
	};

	template<GL::ShaderType TYPE>
	class GenericShaderObject : public ShaderObject
	{
	public:
		///
		using ptr = std::shared_ptr<ShaderObject>;

		///
		GenericShaderObject()
			: ShaderObject(GL::toString(TYPE), TYPE)
		{ }


		///
		GenericShaderObject(const std::string& sourceCode)
			: ShaderObject(GL::toString(TYPE), TYPE, sourceCode)
		{ }
	};

	using VertexShader         = GenericShaderObject<GL::ShaderType::VERTEX_SHADER>;
	using GeometryShader       = GenericShaderObject<GL::ShaderType::GEOMETRY_SHADER>;
	using TessControlShader    = GenericShaderObject<GL::ShaderType::TESS_CONTROL_SHADER>;
	using TessEveluationShader = GenericShaderObject<GL::ShaderType::TESS_EVALUATION_SHADER>;
	using FragmentShader       = GenericShaderObject<GL::ShaderType::FRAGMENT_SHADER>;
	using ComputeShader        = GenericShaderObject<GL::ShaderType::COMPUTE_SHADER>;

}
#endif // __BASE_SHADER_OBJECT_HPP__