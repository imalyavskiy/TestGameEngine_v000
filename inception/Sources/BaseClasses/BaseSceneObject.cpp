#include <pch.hpp>

#include "BaseClasses.hpp"

BaseSceneObject::BaseSceneObject(const std::string name)
	: BaseObject(name)
{
}

void BaseSceneObject::SetRootComponent(BaseSceneObjectComponent::ptr p)
{
	root_ = p;
}

BaseSceneObjectComponent::ptr BaseSceneObject::GetRootComponent()
{
	return root_;
}
