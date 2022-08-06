#ifndef __GL_WRAPPER_H__
#define __GL_WRAPPER_H__
#include <initializer_list>
namespace GL {

	/// ID's of the buffers to act to
	enum class AttribMask : unsigned int
	{
		CURRENT_BIT          = 0x00000001,
		POINT_BIT            = 0x00000002,
		LINE_BIT             = 0x00000004,
		POLYGON_BIT          = 0x00000008,
		POLYGON_STIPPLE_BIT  = 0x00000010,
		PIXEL_MODE_BIT       = 0x00000020,
		LIGHTING_BIT         = 0x00000040,
		FOG_BIT              = 0x00000080,
		DEPTH_BUFFER_BIT     = 0x00000100,
		ACCUM_BUFFER_BIT     = 0x00000200,
		STENCIL_BUFFER_BIT   = 0x00000400,
		VIEWPORT_BIT         = 0x00000800,
		TRANSFORM_BIT        = 0x00001000,
		ENABLE_BIT           = 0x00002000,
		COLOR_BUFFER_BIT     = 0x00004000,
		HINT_BIT             = 0x00008000,
		EVAL_BIT             = 0x00010000,
		LIST_BIT             = 0x00020000,
		TEXTURE_BIT          = 0x00040000,
		SCISSOR_BIT          = 0x00080000,
		ALL_ATTRIB_BITS      = 0x000fffff,
	};

	enum class BufferType : unsigned int
	{
		ARRAY_BUFFER         = 0x00008892,
		ELEMENT_ARRAY_BUFFER = 0x00008893,
	};

	enum class Action : unsigned int
	{
		STREAM_DRAW         = 0x000088E0,
		STREAM_READ         = 0x000088E1,
		STREAM_COPY         = 0x000088E2,
		STATIC_DRAW         = 0x000088E4,
		STATIC_READ         = 0x000088E5,
		STATIC_COPY         = 0x000088E6,
		DYNAMIC_DRAW        = 0x000088E8,
		DYNAMIC_READ        = 0x000088E9,
		DYNAMIC_COPY        = 0x000088EA,
	};

	enum class Type : unsigned int
	{
		BYTE                = 0x00001400,
		UNSIGNED_BYTE       = 0x00001401,
		SHORT               = 0x00001402,
		UNSIGNED_SHORT      = 0x00001403,
		INT                 = 0x00001404,
		UNSIGNED_INT        = 0x00001405,
		FLOAT               = 0x00001406,
		TWO_BYTES           = 0x00001407,
		TREE_BYTES          = 0x00001408,
		FOUR_BYTES          = 0x00001409,
		DOUBLE              = 0x0000140A,
	};

	enum class DataType : unsigned int
	{
        POINTS                   = 0x00000000,
        LINES                    = 0x00000001,
        LINE_LOOP                = 0x00000002,
        LINE_STRIP               = 0x00000003,
        TRIANGLES                = 0x00000004,
        TRIANGLE_STRIP           = 0x00000005,
        TRIANGLE_FAN             = 0x00000006,
        QUADS                    = 0x00000007,
        QUAD_STRIP               = 0x00000008,
        LINES_ADJACENCY          = 0x0000000A,
        LINE_STRIP_ADJACENCY     = 0x0000000B,
        TRIANGLES_ADJACENCY      = 0x0000000C,
        TRIANGLE_STRIP_ADJACENCY = 0x0000000D,
        PATCHES                  = 0x0000000E,
    };

	/// Clears the mentioned buffers
	void Clear(std::initializer_list<AttribMask> mask);

	/// Sets the color the frame buffer to be filled with
	void ClearColor(float red, float green, float blue, float alpha);

	///
	void GenBuffers(unsigned int numBuffers, unsigned int* buffers);

	///
	void BindBuffer(BufferType targetBufferType, unsigned int bufferId);

	///
	void BufferData(BufferType, unsigned int numElements, void* data, Action action);

	///
	void EnableVertexAttribArray(unsigned int index);

	///
	void VertexAttribPointer(unsigned int index, int size, Type type, bool normalized, int stride, const void* pointer);

	///
	void DrawArrays(DataType dataType, int first, int count);

	///
	void DisableVertexAttribArray(unsigned int index);
};
#endif // __GL_WRAPPER_H__
