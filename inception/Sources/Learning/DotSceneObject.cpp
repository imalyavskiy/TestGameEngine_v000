#include <pch.hpp>
#include "Learning.hpp"

namespace Learning
{
    DotSceneObject::DotSceneObject(const std::string& name)
        : BaseSceneObject(name)
    {
    }

    void DotSceneObject::Update(float dt)
    {
        if (auto root = GetRootComponent())
            root->Update(dt);
    }

    void DotSceneObject::Draw()
    {
        if (auto root = GetRootComponent())
            root->Draw();
    }
}