#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include <Learning/Learning.hpp>

namespace Learning
{
    RootSceneObjectComponent::RootSceneObjectComponent(const std::string& name)
        : Base::SceneObjectComponent(name)
    {
        vertices_[0] = { -1.0f, -1.0f,  0.0f};
        vertices_[1] = {  1.0f, -1.0f,  0.0f};
        vertices_[2] = {  0.0f,  1.0f,  0.0f};

        GL::GenBuffer(vertexBufferObject_);

        GL::BindBuffer(GL::BufferType::ARRAY_BUFFER, vertexBufferObject_);

        GL::BufferData(GL::BufferType::ARRAY_BUFFER, vertices_.size() * sizeof vertices_[0], vertices_.data(), GL::Action::STATIC_DRAW);

        shaderProgram_ = std::make_shared<Base::ShaderProgram>(
            "shader program",
            std::make_shared<Base::VertexShader>(
                                "#version 330                                                                       \n"
                                "layout (location = 0) in vec3 Position;                                            \n"
                                "uniform mat4 gWorld;                                                               \n"
                                "out vec4 Color;                                                                    \n"
                                "void main()                                                                        \n"
                                "{                                                                                  \n"
                                "    gl_Position = gWorld * vec4(Position, 1.0);                                    \n"
                                "    Color = vec4(clamp(Position, 0.4, 1.0), 1.0);                                  \n"
                                "}                                                                                  \n"),
            std::make_shared<Base::FragmentShader>(
                                "#version 330                                                                       \n"
                                "in vec4 Color;                                                                     \n"
                                "out vec4 FragColor;                                                                \n"
                                "void main()                                                                        \n"
                                "{                                                                                  \n"
                                "    FragColor = Color;                                                             \n"
                                "}                                                                                  \n") );
        bool res = false;
        res = shaderProgram_->Build();
        assert(res);

        res = shaderProgram_->AttachToUniform("gWorld");
        assert(res);
    }


    void RootSceneObjectComponent::Draw()
    {
        shaderProgram_->Use();

        auto worldMatrix = Math3D::Matrix4f::Identity();
        worldMatrix.m[0][0] = .5f;
        worldMatrix.m[1][1] = .5f;
        worldMatrix.m[2][2] = .5f;

        shaderProgram_->UpdateUniform("gWorld", worldMatrix);

        GL::EnableVertexAttribArray(0);

        GL::BindBuffer(GL::BufferType::ARRAY_BUFFER, vertexBufferObject_);

        GL::VertexAttribPointer(0, 3, GL::Type::FLOAT, false, 0, 0);

        GL::DrawArrays(GL::DataType::TRIANGLES, 0, vertices_.size());

        GL::DisableVertexAttribArray(0);

        Base::SceneObjectComponent::Draw();
    }
    
    void RootSceneObjectComponent::Update(float dt)
    {
        scale_ += 1.8f * dt;
    }
}