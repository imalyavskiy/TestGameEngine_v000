#ifndef __LEARNING_VECTOR_TRIPLET_ORIGIN_HPP__
#define __LEARNING_VECTOR_TRIPLET_ORIGIN_HPP__

#include <pch.hpp>
#include "Learning.hpp"

namespace Learning
{
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

#endif // __LEARNING_VECTOR_TRIPLET_ORIGIN_HPP__