#include <pch.hpp>

#include "Math3d.hpp"

namespace Math3D {
	Vector3f::Vector3f(const float _x, const float _y, const float _z)
		: x(_x)
		, y(_y)
		, z(_z)
	{
	}

	Vector4f::Vector4f(const float _x, const float _y, const float _z, const float _w)
		: x(_x)
		, y(_y)
		, z(_z)
		, w(_w)
	{
	}

	Matrix4f::Matrix4f(float _00, float _01, float _02, float _03, float _10, float _11, float _12, float _13, float _20, float _21, float _22, float _23, float _30, float _31, float _32, float _33)
		: m{ _00, _01, _02, _03, _10, _11, _12, _13, _20, _21, _22, _23, _30, _31, _32, _33 }
	{
	}

	Matrix4f::Matrix4f(Vector4f r0, Vector4f r1, Vector4f r2, Vector4f r3)
		: m{r0.x, r0.y, r0.z, r0.w, r1.x, r1.y, r1.z, r1.w, r2.x, r2.y, r2.z, r2.w, r3.x, r3.y, r3.z, r3.w}
	{
	}

	const float* Matrix4f::data() const
	{
		return &m[0][0];
	}

	Matrix4f Transform::projectionMatrix_ = Transform::Identity();

	Matrix4f Transform::Identity()
	{
		return Matrix4f({ 1.f, 0.f, 0.f, 0.f },
						{ 0.f, 1.f, 0.f, 0.f }, 
						{ 0.f, 0.f, 1.f, 0.f }, 
						{ 0.f, 0.f, 0.f, 1.f });
	}

	Matrix4f Transform::Projection(float fov, float width, float height, float zNear, float zFar)
	{
		const float ar = width / height;
		const float zRange = zFar - zNear;

#if 0
		const float tanHalfFov = std::tanf(fov / 2.f);
		return {
			{ 1.f / (ar * tanHalfFov),       0.f,                    0.f,                      0.f              },
			{           0.f,            1 / tanHalfFov,              0.f,                      0.f              },
			{           0.f,                  0.f,        (-zNear - zFar) / zRange, 2.f * zNear * zFar / zRange },
			{           0.f,                  0.f,                    1.f,                      0.f             },
		};
#else
		const float ctanHalfFov = 1 / std::tanf(fov / 2.f);
		return {
			{ ctanHalfFov / ar,     0.f,              0.f,                      0.f              },
			{       0.f,        ctanHalfFov,          0.f,                      0.f              },
			{       0.f,            0.f,     (zNear+zFar) / zRange, -2.f * zNear * zFar / zRange    },
			{       0.f,            0.f,              1.f,                      0.f              },
		};
#endif
	}

	Matrix4f Transform::Create(Position position, Rotation rotation, Scale scale)
	{
		const auto trTranslate = Create(position);
		const auto trRotate = Create(rotation);
		const auto trScale = Create(scale);

		return /*projectionMatrix_ * */trTranslate * trRotate * trScale;
	}

	Matrix4f Transform::Create(Position position)
	{
		return {
			1.f, 0.f, 0.f, position.x,
			0.f, 1.f, 0.f, position.y,
			0.f, 0.f, 1.f, position.z,
			0.f, 0.f, 0.f,    1.f
		};
	}

	Matrix4f Transform::Create(Rotation rotation)
	{
		const float sr = std::sinf(rotation.x); // sin(roll)
		const float cr = std::cosf(rotation.x); // cos(roll)
		const float sp = std::sinf(rotation.y); // sin(pitch)
		const float cp = std::cosf(rotation.y); // cos(pitch)
		const float sy = std::sinf(rotation.z); // sin(yaw)
		const float cy = std::cosf(rotation.z); // cos(yaw)

	/*
		const Matrix4f rx
		{
			1.0f,  0.0f,   0.0f, 0.0f,
			0.0f,   cr ,   -sr , 0.0f,
			0.0f,   sr ,    cr , 0.0f,
			0.0f,  0.0f,   0.0f, 1.0f,
		};
	
		const Matrix4f ry
		{
			 cp , 0.0f, -sp , 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			 sp , 0.0f,  cp , 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f,
		};
	
		const Matrix4f rz
		{
			 cy ,  -sy , 0.0f, 0.0f,
			 sy ,   cy , 0.0f, 0.0f,
			0.0f,  0.0f, 1.0f, 0.0f,
			0.0f,  0.0f, 0.0f, 1.0f,
		};
	
		// This variant takes 128 multiplication and 96 addition operations.
		return rz * ry * rx;
	*/

		// This is the analytically deduced matrix after 2 multiplications.
		// This variant has 16 multiplication and 4 addition operations. Such 
		// advantage reached because of all multiplications by ZERO were 
		// pre-calculated.
		return {
			cy*cp, (-sy)*cr+cy*(-sp)*(-sr), (-sy)*sr+cy*(-sp)*cr, 0,
			sy*cp,   cy*cr+sy*(-sp)*(-sr) ,   cy*sr+sy*(-sp)*cr , 0,
			  sp ,         cp*(-sr)       ,         cp*cr       , 0,
			   0 ,           0            ,           0         , 1,
		};
	}

	Matrix4f Transform::Create(Scale scale)
	{
		return {
			scale.x,   0.f  ,   0.f  ,  0.f,
			  0.f  , scale.y,   0.f  ,  0.f,
			  0.f  ,   0.f  , scale.z,  0.f,
			  0.f  ,   0.f  ,   0.f  ,  1.f
		};
	}
}

