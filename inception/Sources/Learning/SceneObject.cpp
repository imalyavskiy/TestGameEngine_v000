#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include <BaseClasses/BaseClasses.hpp>
#include "Learning.hpp"

namespace Learning
{
    SceneObject::SceneObject(const std::string& name)
        : Base::SceneObject(name)
    {
    }

    void SceneObject::Update(float dt)
    {
        if (auto root = GetRootComponent())
            root->Update(dt);
    }

    void SceneObject::Draw(const Math3D::Matrix4f& matViewProjection)
    {
        if (auto root = GetRootComponent())
            root->Draw(matViewProjection);
    }
}
