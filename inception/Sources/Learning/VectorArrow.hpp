#ifndef __LEARNING_VECTOR_ARROW_HPP__
#define __LEARNING_VECTOR_ARROW_HPP__

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
}

#endif // __LEARNING_VECTOR_ARROW_HPP__