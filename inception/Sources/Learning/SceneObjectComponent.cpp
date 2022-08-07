#include <pch.hpp>
#include <Utilities/Utilities.hpp>
#include <Learning/Learning.hpp>

namespace Learning
{
    RootSceneObjectComponent::RootSceneObjectComponent(const std::string& name)
        : BaseSceneObjectComponent(name)
    {
        vertices_[0] = Math3D::Vector3f(0.0f, 0.0f, 0.0f);

        GL::GenBuffers(1, &vertexBufferObject_);

        GL::BindBuffer(GL::BufferType::ARRAY_BUFFER, vertexBufferObject_);

        GL::BufferData(GL::BufferType::ARRAY_BUFFER, sizeof(vertices_), vertices_, GL::Action::STATIC_DRAW);
    }

    void RootSceneObjectComponent::Draw()
    {
        GL::EnableVertexAttribArray(0);

        GL::BindBuffer(GL::BufferType::ARRAY_BUFFER, vertexBufferObject_);

        GL::VertexAttribPointer(0, 3, GL::Type::FLOAT, false, 0, 0);

        GL::DrawArrays(GL::DataType::POINTS, 0, 1);

        GL::DisableVertexAttribArray(0);

        BaseSceneObjectComponent::Draw();
    }
}