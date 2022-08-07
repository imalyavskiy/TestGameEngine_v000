#include <pch.hpp>
#include <Utilities/Utilities.hpp>
#include <Learning/Learning.hpp>

namespace Learning
{
    RootSceneObjectComponent::RootSceneObjectComponent(const std::string& name)
        : Base::SceneObjectComponent(name)
    {
        vertices_[0] = Math3D::Vector3f( -1.0f, -1.0f,  0.0f);
        vertices_[1] = Math3D::Vector3f(  1.0f, -1.0f,  0.0f);
        vertices_[2] = Math3D::Vector3f(  0.0f,  1.0f,  0.0f);
        GL::GenBuffer(vertexBufferObject_);

        GL::BindBuffer(GL::BufferType::ARRAY_BUFFER, vertexBufferObject_);

        GL::BufferData(GL::BufferType::ARRAY_BUFFER, vertices_.size() * sizeof vertices_[0], vertices_.data(), GL::Action::STATIC_DRAW);

        shaderProgram_ = std::make_shared<Base::ShaderProgram>(
            "shader program",
            std::make_shared<Base::VertexShader>(
                                "#version 330                                                                  \n"
                                "layout (location = 0) in vec3 Position;                                       \n"
                                "void main()                                                                   \n"
                                "{                                                                             \n"
                                // Scaling coordinates in a half. If shader program will fail to build the 
                                // triangle will reside entire viewport otherwize it will be in half smaller
                                "    gl_Position = vec4(0.5 * Position.x, 0.5 * Position.y, Position.z, 1.0);  \n" 
                                "}                                                                             \n"),
            std::make_shared<Base::FragmentShader>(
                                "#version 330                                                                  \n"
                                "out vec4 FragColor;                                                           \n"
                                "void main()                                                                   \n"
                                "{                                                                             \n"
                                "    FragColor = vec4(1.0, 0.0, 0.0, 1.0);                                     \n"
                                "}                                                                             \n")
        );
        
        shaderProgram_->Build();
    }

    void RootSceneObjectComponent::Draw()
    {
        shaderProgram_->Use();

        GL::EnableVertexAttribArray(0);

        GL::BindBuffer(GL::BufferType::ARRAY_BUFFER, vertexBufferObject_);

        GL::VertexAttribPointer(0, 3, GL::Type::FLOAT, false, 0, 0);

        GL::DrawArrays(GL::DataType::TRIANGLES, 0, vertices_.size());

        GL::DisableVertexAttribArray(0);

        Base::SceneObjectComponent::Draw();
    }
}