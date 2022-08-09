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

	Matrix4f Matrix4f::Identity()
	{
		return Matrix4f({1.f, 0.f, 0.f, 0.f}, { 0.f, 1.f, 0.f, 0.f }, { 0.f, 0.f, 1.f, 0.f }, { 0.f, 0.f, 0.f, 1.f });
	}

	Matrix4f Matrix4f::Create(Position position, Rotation rotation, Scale scale) 
	{
		// TODO: requires matrix multiplication
		throw std::logic_error("not implemented");
	}

	Matrix4f Matrix4f::Create(Position position)
	{
		return Matrix4f(
			{ 1.f, 0.f, 0.f, position.x },
			{ 0.f, 1.f, 0.f, position.y },
			{ 0.f, 0.f, 1.f, position.z },
			{ 0.f, 0.f, 0.f, 1.f }
		);
	}

	Matrix4f Matrix4f::Create(Rotation rotation)
	{
		// TODO: requires matrix multiplication
		throw std::logic_error("not implemented");
	}

	Matrix4f Matrix4f::Create(Scale scale)
	{
		return Matrix4f(
			{ scale.x,     0.f,     0.f,     0.f },
			{     0.f, scale.y,     0.f,     0.f },
			{     0.f,     0.f, scale.z,     0.f },
			{     0.f,     0.f,     0.f,     1.f }
		);
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
}