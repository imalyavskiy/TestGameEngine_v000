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

  void SceneObject::Draw(const Math3D::Matrix4f& matViewProjection)
  {
	if (root_)
		root_->Draw(matViewProjection);
  }

  void SceneObject::Init()
  {
	if (root_)
		root_->Init();
  }

  void SceneObject::JoinScene()
  {
  }

  void SceneObject::Transform(const Math3D::Transform& transform)
  {
    if (root_)
      root_->Transform(transform);
    transform_ = transform;
  }

  const Math3D::Transform& SceneObject::Transform() const
  {
    if (root_)
      return root_->Transform();
    return transform_;
  }

  Math3D::Transform& SceneObject::Transform()
  {
    if (root_)
      return root_->Transform();
    return transform_;
  }

}
