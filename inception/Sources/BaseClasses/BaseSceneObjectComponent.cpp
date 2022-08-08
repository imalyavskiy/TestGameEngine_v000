#include <pch.hpp>
#include <Utilities/Utilities.hpp>
#include "BaseClasses.hpp"
namespace Base {
	SceneObjectComponent::SceneObjectComponent(const std::string& name)
		: Object(name)
	{

	}

	void SceneObjectComponent::AddChild(ptr child)
	{
		childList_.push_back(child);
	}

	SceneObjectComponent::ChildList&
		SceneObjectComponent::GetChildList()
	{
		return childList_;
	}

	void SceneObjectComponent::Update(float dt)
	{
		for (auto child : childList_)
			child->Update(dt);
	}

	void SceneObjectComponent::Draw()
	{
		for (auto child : childList_)
			child->Draw();
	}
}