#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include "BaseClasses.hpp"

namespace Base {
	SceneObject::SceneObject(const std::string name)
		: Object(name)
	{
	}

	void SceneObject::SetRootComponent(SceneObjectComponent::sptr p)
	{
		root_ = p;
	}

	SceneObjectComponent::sptr SceneObject::GetRootComponent()
	{
		return root_;
	}

    void SceneObject::Update(float dt)
    {
		if (root_)
			root_->Update(dt);
    }

    void SceneObject::Draw()
    {
		if (root_)
			root_->Draw();
    }
}
