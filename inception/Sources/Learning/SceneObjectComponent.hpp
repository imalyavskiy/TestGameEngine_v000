#ifndef __DOT_SCENE_OBJECT_COMPONENT_HPP__
#define __DOT_SCENE_OBJECT_COMPONENT_HPP__

#include <pch.hpp>
#include "Learning.hpp"

namespace Learning
{
	class VectorArrow : public Base::MeshComponent
	{
	public:
		VectorArrow(const std::string& name);

		void Draw(const Math3D::Matrix4f& matViewProjection) override;

		void Init() override;

		void SetColor(Math3D::Vector3f color);

    const Math3D::Vector3f& GetColor() const;


  protected:

	  Math3D::Vector3f color_;
	};

	class VectorTripletOrigin : public Base::MeshComponent
	{
	public:
		VectorTripletOrigin(const std::string& name);

		void Draw(const Math3D::Matrix4f& matViewProjection) override;

	  void Init() override;

		void SetColor(const Math3D::Vector3f& color);

    const Math3D::Vector3f& GetColor() const;
  protected:

		Math3D::Vector3f color_;
	};
}

#endif // __DOT_SCENE_OBJECT_COMPONENT_HPP__