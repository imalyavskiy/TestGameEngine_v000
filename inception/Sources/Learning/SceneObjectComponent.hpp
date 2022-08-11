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
		uint32_t indexBufferObject_ = _UI32_MAX;

		///
		std::vector<Math3D::Vector3f> vertices_; // 4 vertices

		///
		std::vector<int> indices_; // 4 triangles thus 4 * 3 = 12

		///
		Base::ShaderProgram::ptr shaderProgram_;

		///
		float scale_ = 0.f;

		///
		float roll_ = 0.f;
		float rollSpeed_ = 1.f;
		
		///
		float pitch_ = 0.f;
		float pitchSPeed_ = 1.f;
		
		///
		float yaw_ = 0.f;
		float yawSpeed_ = 1.f;
	};
}

#endif // __DOT_SCENE_OBJECT_COMPONENT_HPP__