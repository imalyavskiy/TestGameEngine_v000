#ifndef __DOT_SCENE_OBJECT_COMPONENT_HPP__
#define __DOT_SCENE_OBJECT_COMPONENT_HPP__

#include <pch.hpp>
#include "Learning.hpp"

namespace Learning
{
	///
	class RootSceneObjectComponent : public Base::MeshComponent
	{
	public:
		///
		RootSceneObjectComponent(const std::string& name);

		///
		void Draw(const Math3D::Matrix4f& matViewProjection) override;

		///
		void Update(float dt) override;

		///
		void Init() override;
	
	private:
		///
		float rollSpeed_ = 1.f;
		
		///
		float pitchSPeed_ = 1.f;
		
		///
		float yawSpeed_ = 1.f;
	};
}

#endif // __DOT_SCENE_OBJECT_COMPONENT_HPP__