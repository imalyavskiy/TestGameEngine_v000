#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include "BaseClasses.hpp"

namespace Base {
	SceneObject::SceneObject(const std::string name)
		: Object(name)
	{
	}

	void SceneObject::SetRootComponent(SceneObjectComponent::ptr p)
	{
		root_ = p;
	}

	SceneObjectComponent::ptr SceneObject::GetRootComponent()
	{
		return root_;
	}
}