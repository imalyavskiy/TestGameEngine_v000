#ifndef __DOT_SCENE_OBJECT_COMPONENT_HPP__
#define __DOT_SCENE_OBJECT_COMPONENT_HPP__

#include <pch.hpp>
#include "Learning.hpp"

namespace Learning
{
	class RootSceneObjectComponent : public BaseSceneObjectComponent
	{
	public:
		RootSceneObjectComponent(const std::string& name);

		void Draw() override;
	
	private:
		unsigned int vertexBufferObject_ = _UI32_MAX;

		Math3D::Vector3f vertices_[1];
	};
}

#endif // __DOT_SCENE_OBJECT_COMPONENT_HPP__