#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include "BaseClasses.hpp"
namespace Base {
  SceneObjectComponent::SceneObjectComponent(wptr parent, const std::string& name)
      : Object(name)
  {

  }

  SceneObjectComponent::~SceneObjectComponent()
  {
  }

  void SceneObjectComponent::Transform(const Math3D::Transform& transform)
  {
    transform_ = transform;
  }

  const Math3D::Transform& SceneObjectComponent::Transform() const
  {
    return transform_;
  }

  Math3D::Transform& SceneObjectComponent::Transform()
  {
    return transform_;
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

  void SceneObjectComponent::Draw(const Math3D::Matrix4f& matViewProjection)
  {
    for (auto child : childList_)
      child->Draw(matViewProjection * Math3D::Pipeline::Create(transform_));
  }

  void SceneObjectComponent::Init()
  {
    for (auto child : childList_)
      child->Init();
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

  Math3D::Direction SceneObjectComponent::GetWorldForwardVector() const
  {
    const auto forward = Math3D::Vector4f(Math3D::Direction::Forward, 0.f);
    const auto world = GetWorldTransformMatrix();

    return Math3D::Direction((world * forward).xyz());
  }

  Math3D::Direction SceneObjectComponent::GetWorldBackwardVector() const
  {
    const auto forward = Math3D::Vector4f(Math3D::Direction::Backward, 0.f);
    const auto world = GetWorldTransformMatrix();

    return Math3D::Direction((world * forward).xyz());
  }

  Math3D::Direction SceneObjectComponent::GetWorldUpVector() const
  {
    const auto forward = Math3D::Vector4f(Math3D::Direction::Up, 0.f);
    const auto world = GetWorldTransformMatrix();

    return Math3D::Direction((world * forward).xyz());
  }

  Math3D::Direction SceneObjectComponent::GetWorldDownVector() const
  {
    const auto forward = Math3D::Vector4f(Math3D::Direction::Down, 0.f);
    const auto world = GetWorldTransformMatrix();

    return Math3D::Direction((world * forward).xyz());
  }

  Math3D::Direction SceneObjectComponent::GetWorldRightVector() const
  {
    const auto forward = Math3D::Vector4f(Math3D::Direction::Right, 0.f);
    const auto world = GetWorldTransformMatrix();

    return Math3D::Direction((world * forward).xyz());
  }

  Math3D::Direction SceneObjectComponent::GetWorldLeftVector() const
  {
    const auto forward = Math3D::Vector4f(Math3D::Direction::Left, 0.f);
    const auto world = GetWorldTransformMatrix();

    return Math3D::Direction((world * forward).xyz());
  }

  Math3D::Position SceneObjectComponent::GetWorldPosition() const
  {
    const auto position = Math3D::Vector4f(Math3D::Position());
    const auto world = GetWorldTransformMatrix();

    const auto result = Math3D::Position((world * position).xyz());
    return result;
  }
}
