#ifndef __GL_WRAPPER_H__
#define __GL_WRAPPER_H__
#include <initializer_list>

/// TODO: Document. Add link.
namespace GL
{
    /// ID's of the buffers to act to
    enum class AttribMask : uint32_t
    {
        CURRENT_BIT               = 0x00000001,
        POINT_BIT                 = 0x00000002,
        LINE_BIT                  = 0x00000004,
        POLYGON_BIT               = 0x00000008,
        POLYGON_STIPPLE_BIT       = 0x00000010,
        PIXEL_MODE_BIT            = 0x00000020,
        LIGHTING_BIT              = 0x00000040,
        FOG_BIT                   = 0x00000080,
        DEPTH_BUFFER_BIT          = 0x00000100,
        ACCUM_BUFFER_BIT          = 0x00000200,
        STENCIL_BUFFER_BIT        = 0x00000400,
        VIEWPORT_BIT              = 0x00000800,
        TRANSFORM_BIT             = 0x00001000,
        ENABLE_BIT                = 0x00002000,
        COLOR_BUFFER_BIT          = 0x00004000,
        HINT_BIT                  = 0x00008000,
        EVAL_BIT                  = 0x00010000,
        LIST_BIT                  = 0x00020000,
        TEXTURE_BIT               = 0x00040000,
        SCISSOR_BIT               = 0x00080000,
        ALL_ATTRIB_BITS           = 0x000fffff,
        INVALID_ATTRIB_MASK       = _UI32_MAX,
    };
    std::string toString(AttribMask arg);

    enum class BufferType : uint32_t
    {
        ARRAY_BUFFER              = 0x00008892, // Vertex attributes
        ATOMIC_COUNTER_BUFFER     = 0x000092C0, // Atomic counter storage
        COPY_READ_BUFFER          = 0x00008F36, // Buffer copy source
        COPY_WRITE_BUFFER         = 0x00008F37, // Buffer copy destination
        DISPATCH_INDIRECT_BUFFER  = 0x000090EE, // Indirect compute dispatch commands
        DRAW_INDIRECT_BUFFER      = 0x00008F3F, // Indirect command arguments
        ELEMENT_ARRAY_BUFFER      = 0x00008893, // Vertex array indices
        PIXEL_PACK_BUFFER         = 0x000088EB, // Pixel read target
        PIXEL_UNPACK_BUFFER       = 0x000088EC, // Texture data source
        QUERY_BUFFER              = 0x00009192, // Query result buffer
        SHADER_STORAGE_BUFFER     = 0x000090D2, // Read - write storage for shaders
        TEXTURE_BUFFER            = 0x00008C2A, // Texture data buffer
        TRANSFORM_FEEDBACK_BUFFER = 0x00008C8E, // Transform feedback buffer
        UNIFORM_BUFFER            = 0x00008A11, // Uniform block storage
        INVALID_BUFFER_TYPE       = _UI32_MAX,
    };
    std::string toString(BufferType arg);

    enum class Action : uint32_t
    {
        STREAM_DRAW               = 0x000088E0,
        STREAM_READ               = 0x000088E1,
        STREAM_COPY               = 0x000088E2,
        STATIC_DRAW               = 0x000088E4,
        STATIC_READ               = 0x000088E5,
        STATIC_COPY               = 0x000088E6,
        DYNAMIC_DRAW              = 0x000088E8,
        DYNAMIC_READ              = 0x000088E9,
        DYNAMIC_COPY              = 0x000088EA,
        INVALID_ACTION            = _UI32_MAX,
    };
    std::string toString(Action arg);

    enum class Type : uint32_t
    {
        BYTE                      = 0x00001400,
        UNSIGNED_BYTE             = 0x00001401,
        SHORT                     = 0x00001402,
        UNSIGNED_SHORT            = 0x00001403,
        INT                       = 0x00001404,
        UNSIGNED_INT              = 0x00001405,
        FLOAT                     = 0x00001406,
        TWO_BYTES                 = 0x00001407,
        TREE_BYTES                = 0x00001408,
        FOUR_BYTES                = 0x00001409,
        DOUBLE                    = 0x0000140A,
        INVALID_TYPE              = _UI32_MAX,  // not OpenGL value
    };
    std::string toString(Type arg);

    enum class DataType : uint32_t
    {
        POINTS                    = 0x00000000, // GL_POINTS
        LINES                     = 0x00000001, // GL_LINES
        LINE_LOOP                 = 0x00000002, // GL_LINE_LOOP
        LINE_STRIP                = 0x00000003, // GL_LINE_STRIP
        TRIANGLES                 = 0x00000004, // GL_TRIANGLES
        TRIANGLE_STRIP            = 0x00000005, // GL_TRIANGLE_STRIP
        TRIANGLE_FAN              = 0x00000006, // GL_TRIANGLE_FAN
        QUADS                     = 0x00000007, // GL_QUADS
        QUAD_STRIP                = 0x00000008, // GL_QUAD_STRIP
        LINES_ADJACENCY           = 0x0000000A, // GL_LINES_ADJACENCY
        LINE_STRIP_ADJACENCY      = 0x0000000B, // GL_LINE_STRIP_ADJACENCY
        TRIANGLES_ADJACENCY       = 0x0000000C, // GL_TRIANGLES_ADJACENCY
        TRIANGLE_STRIP_ADJACENCY  = 0x0000000D, // GL_TRIANGLE_STRIP_ADJACENCY
        PATCHES                   = 0x0000000E, // GL_PATCHES
        INVALID_DATA_TYPE         = _UI32_MAX,  // not OpenGL value
    };
    std::string toString(DataType arg);

    enum class ShaderType : uint32_t
    {
        VERTEX_SHADER             = 0x00008B31, // GL_VERTEX_SHADER
        GEOMETRY_SHADER           = 0x00008DD9, // GL_GEOMETRY_SHADER
        TESS_CONTROL_SHADER       = 0x00008E88, // GL_TESS_CONTROL_SHADER
        TESS_EVALUATION_SHADER    = 0x00008E87, // GL_TESS_EVALUATION_SHADER
        FRAGMENT_SHADER           = 0x00008B30, // GL_FRAGMENT_SHADER
        COMPUTE_SHADER            = 0x000091B9, // GL_COMPUTE_SHADER
        INVALID_SHADER_TYPE       = _UI32_MAX,  // not OpenGL value
    };
    std::string toString(ShaderType arg);

    enum class ShaderObjectParameter : uint32_t
    {
        SHADER_TYPE               = 0x00008B4F,
        DELETE_STATUS             = 0x00008B80,
        COMPILE_STATUS            = 0x00008B81,
        INFO_LOG_LENGTH           = 0x00008B84,
        SHADER_SOURCE_LENGTH      = 0x00008B88,
        INVALID_SHADER_OBJECT_PARAMETER = _UI32_MAX,
    };
    std::string toString(ShaderObjectParameter arg);

    enum class ShaderProgramParameter : uint32_t
    {
        DELETE_STATUS                         = 0x00008B80,
        LINK_STATUS                           = 0x00008B82,
        VALIDATE_STATUS                       = 0x00008B83,
        INFO_LOG_LENGTH                       = 0x00008B84,
        ATTACHED_SHADERS                      = 0x00008B85,
        ACTIVE_ATOMIC_COUNTER_BUFFERS         = 0x000092D9,
        ACTIVE_ATTRIBUTES                     = 0x00008B89,
        ACTIVE_ATTRIBUTE_MAX_LENGTH           = 0x00008B8A,
        ACTIVE_UNIFORMS                       = 0x00008B86,
        ACTIVE_UNIFORM_BLOCKS                 = 0x00008A36,
        ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH  = 0x00008A35,
        ACTIVE_UNIFORM_MAX_LENGTH             = 0x00008B87,
        COMPUTE_WORK_GROUP_SIZE               = 0x00008267,
        PROGRAM_BINARY_LENGTH                 = 0x00008741,
        TRANSFORM_FEEDBACK_BUFFER_MODE        = 0x00008C7F,
        TRANSFORM_FEEDBACK_VARYINGS           = 0x00008C83,
        TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = 0x00008C76,
        GEOMETRY_VERTICES_OUT                 = 0x00008916,
        GEOMETRY_INPUT_TYPE                   = 0x00008917,
        GEOMETRY_OUTPUT_TYPE                  = 0x00008918,
        INVALID_SHADER_PROGRAM_PARAMETER      = _UI32_MAX,
    };
    std::string toString(ShaderProgramParameter arg);

    /// Clears buffers to preset values(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glClear.xhtml).
    void Clear(std::initializer_list<AttribMask> mask);

    /// Specifies clear values for the color buffers(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glClearColor.xhtml).
    void ClearColor(float red, float green, float blue, float alpha);

    /// Convinience function. Generates buffer object name fo signle buffer object(calls GenBuffers).
    void GenBuffer(uint32_t& buffer);

    /// Generate buffer object names(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGenBuffers.xhtml).
    void GenBuffers(std::vector<uint32_t>& buffers);

    /// Binds a named buffer object(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glBindBuffer.xhtml).
    void BindBuffer(BufferType bufferType, uint32_t bufferId);

    /// Сreates and initializes a buffer object's data store(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glBufferData.xhtml).
    void BufferData(BufferType bufferType, uint32_t numElements, void* data, Action action);

    /// Enables a generic vertex attribute array(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glEnableVertexAttribArray.xhtml).
    void EnableVertexAttribArray(uint32_t index);

    /// Defines an array of generic vertex attribute data(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glVertexAttribPointer.xhtml).
    void VertexAttribPointer(uint32_t index, int32_t size, Type type, bool normalized, int32_t stride, const void* pointer);

    /// Renders primitives from array data(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glDrawArrays.xhtml).
    void DrawArrays(DataType dataType, int32_t first, int32_t count);

    /// Disables a generic vertex attribute array(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glEnableVertexAttribArray.xhtml).
    void DisableVertexAttribArray(uint32_t index);

    /// Creates a shader object(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glCreateShader.xhtml).
    uint32_t CreateShader(ShaderType shaderType);

    /// Replaces the source code in a shader object(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glShaderSource.xhtml).
    void ShaderSource(uint32_t shaderObjectID, const std::vector<std::string>& shaderSourceCode);

    /// Compiles a shader object(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glCompileShader.xhtml).
    void CompileShader(uint32_t shaderObjectID);

    /// Returns a parameter from a shader object(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGetShader.xhtml).
    void GetShaderiv(uint32_t shaderObjectID, ShaderObjectParameter parameter, int32_t* parameterValue);

    /// Returns the information log for a shader object(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGetShaderInfoLog.xhtml).
    void GetShaderInfoLog(uint32_t shaderObjectID, std::string& infoLog);

    /// Creates a program object(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glCreateProgram.xhtml).
    uint32_t CreateProgram();

    /// Attaches a shader object to a program object(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glAttachShader.xhtml).
    void AttachShader(uint32_t shaderProgramID, uint32_t shaderObjectID);

    /// Links a program object(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glLinkProgram.xhtml).
    void LinkProgram(uint32_t shaderProgramID);

    /// Returns a parameter from a program object(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGetProgram.xhtml).
    void GetProgramiv(uint32_t shaderProgramID, ShaderProgramParameter parameter, int32_t* parameterValue);

    /// Returns the information log for a program object(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGetProgramInfoLog.xhtml).
    void GetProgramInfoLog(uint32_t shaderObjectID, std::string& infoLog);

    /// Validates a program object(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glValidateProgram.xhtml).
    void ValidateProgram(uint32_t shaderProgramID);

    /// Installs a program object as part of current rendering state(https://registry.khronos.org/OpenGL-Refpages/gl4/html/glUseProgram.xhtml).
    void UseProgram(uint32_t shaderProgramID);
};
#endif // __GL_WRAPPER_H__
