#include <pch.hpp>

#include "BaseClasses.hpp"

BaseSceneObjectComponent::BaseSceneObjectComponent(const std::string& name)
	: BaseObject(name)
{

}

void BaseSceneObjectComponent::AddChild(ptr child)
{
	childList_.push_back(child);
}

BaseSceneObjectComponent::ChildList& 
BaseSceneObjectComponent::GetChildList()
{
	return childList_;
}

void BaseSceneObjectComponent::Update(float dt)
{
	for (auto child : childList_)
		child->Update(dt);
}

void BaseSceneObjectComponent::Draw()
{
	for (auto child : childList_)
		child->Draw();
}
