#ifndef __DOT_SCENE_OBJECT_COMPONENT_HPP__
#define __DOT_SCENE_OBJECT_COMPONENT_HPP__

#include <pch.hpp>
#include "Learning.hpp"

namespace Learning
{
	///
	class RootSceneObjectComponent : public Base::SceneObjectComponent
	{
	public:
		///
		RootSceneObjectComponent(const std::string& name);

		///
		void Draw() override;

		///
		void Update(float dt) override;
	
	private:
		///
		uint32_t vertexBufferObject_ = _UI32_MAX;

		///
		std::array<Math3D::Vector3f, 3> vertices_;

		///
		Base::ShaderProgram::ptr shaderProgram_;

		///
		float scale_ = 0.f;
	};
}

#endif // __DOT_SCENE_OBJECT_COMPONENT_HPP__