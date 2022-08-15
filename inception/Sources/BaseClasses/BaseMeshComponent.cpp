#include <pch.hpp>
#include <Math3D/Math3D.hpp>
#include <Utilities/Utilities.hpp>
#include "BaseClasses.hpp"

namespace Base
{
    MeshComponent::MeshComponent(SceneObjectComponent::wptr parent, const std::string& name)
        : SceneObjectComponent(parent, name)
    {
        
    }

    MeshComponent::~MeshComponent()
    {
        
    }

    void MeshComponent::Init()
    {
        GL::GenBuffer(vertexBufferObject_);

        GL::BindBuffer(GL::BufferType::ARRAY_BUFFER, vertexBufferObject_);

        GL::BufferData(GL::BufferType::ARRAY_BUFFER, vertices_.size() * sizeof vertices_[0], vertices_.data(), GL::Action::STATIC_DRAW);

        GL::GenBuffer(indexBufferObject_);

        GL::BindBuffer(GL::BufferType::ELEMENT_ARRAY_BUFFER, indexBufferObject_);

        GL::BufferData(GL::BufferType::ELEMENT_ARRAY_BUFFER, indices_.size() * sizeof(indices_[0]), indices_.data(), GL::Action::STATIC_DRAW);

        SceneObjectComponent::Init();
    }
}
