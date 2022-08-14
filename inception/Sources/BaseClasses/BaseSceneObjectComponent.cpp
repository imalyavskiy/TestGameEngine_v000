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

    Math3D::Matrix4f SceneObjectComponent::GetWorldTransformMatrix() const
    {
        if (parent_.expired())
            return Math3D::Pipeline::Create(transform_);
        return parent_.lock()->GetWorldTransformMatrix(Math3D::Pipeline::Create(transform_));
    }

    Math3D::Matrix4f SceneObjectComponent::GetWorldTransformMatrix(const Math3D::Matrix4f& local) const
    {
        const auto m = Math3D::Pipeline::Create(transform_) * local;
        if (parent_.expired())
            return m;
        return parent_.lock()->GetWorldTransformMatrix(m);
    }

    Math3D::Direction SceneObjectComponent::GetForwardVector() const
    {
        const auto forward = Math3D::Vector4f(Math3D::Direction::Forward, 0.f);
        const auto world = GetWorldTransformMatrix();

        return Math3D::Direction((world * forward).xyz());
    }

    Math3D::Direction SceneObjectComponent::GetBackwardVector() const
    {
        const auto forward = Math3D::Vector4f(Math3D::Direction::Backward, 0.f);
        const auto world = GetWorldTransformMatrix();

        return Math3D::Direction((world * forward).xyz());
    }

    Math3D::Direction SceneObjectComponent::GetUpVector() const
    {
        const auto forward = Math3D::Vector4f(Math3D::Direction::Up, 0.f);
        const auto world = GetWorldTransformMatrix();

        return Math3D::Direction((world * forward).xyz());
    }

    Math3D::Direction SceneObjectComponent::GetDownVector() const
    {
        const auto forward = Math3D::Vector4f(Math3D::Direction::Down, 0.f);
        const auto world = GetWorldTransformMatrix();

        return Math3D::Direction((world * forward).xyz());
    }

    Math3D::Direction SceneObjectComponent::GetRightVector() const
    {
        const auto forward = Math3D::Vector4f(Math3D::Direction::Right, 0.f);
        const auto world = GetWorldTransformMatrix();

        return Math3D::Direction((world * forward).xyz());
    }

    Math3D::Direction SceneObjectComponent::GetLeftVector() const
    {
        const auto forward = Math3D::Vector4f(Math3D::Direction::Left, 0.f);
        const auto world = GetWorldTransformMatrix();

        return Math3D::Direction((world * forward).xyz());
    }
}
