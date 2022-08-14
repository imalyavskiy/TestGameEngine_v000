#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include "BaseClasses.hpp"
namespace Base {
	SceneObjectComponent::SceneObjectComponent(wptr parent, const std::string& name)
		: Object(name)
	{

	}

	void SceneObjectComponent::AddChild(sptr child)
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