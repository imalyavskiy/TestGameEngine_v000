#include <pch.hpp>
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
                                "uniform float gScale;                                                              \n"
                                "void main()                                                                        \n"
                                "{                                                                                  \n"
                                "    gl_Position = vec4(gScale * Position.x, gScale * Position.y, Position.z, 1.0); \n"
                                "}                                                                                  \n"),
            std::make_shared<Base::FragmentShader>(
                                "#version 330                                                                       \n"
                                "out vec4 FragColor;                                                                \n"
                                "void main()                                                                        \n"
                                "{                                                                                  \n"
                                "    FragColor = vec4(1.0, 0.0, 0.0, 1.0);                                          \n"
                                "}                                                                                  \n") );
        bool res = false;
        res = shaderProgram_->Build();
        assert(res);

        res = shaderProgram_->AttachToUniform("gScale");
        assert(res);
    }



    void RootSceneObjectComponent::Draw()
    {
        shaderProgram_->Use();

        shaderProgram_->UpdateUniform("gScale", std::sinf(scale_));

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