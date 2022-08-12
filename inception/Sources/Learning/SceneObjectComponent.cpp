#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include <Learning/Learning.hpp>

namespace Learning
{
    RootSceneObjectComponent::RootSceneObjectComponent(const std::string& name)
        : Base::SceneObjectComponent(name)
    {
        vertices_ = {
            Math3D::Vector3f{ -1.0f, -1.0f,  0.0f },
            Math3D::Vector3f{  0.0f, -1.0f,  1.0f },
            Math3D::Vector3f{  1.0f, -1.0f,  0.0f },
            Math3D::Vector3f{  0.0f,  1.0f,  0.0f }
        };

        GL::GenBuffer(vertexBufferObject_);

        GL::BindBuffer(GL::BufferType::ARRAY_BUFFER, vertexBufferObject_);

        GL::BufferData(GL::BufferType::ARRAY_BUFFER, vertices_.size() * sizeof vertices_[0] , vertices_.data(), GL::Action::STATIC_DRAW);

        indices_ = {
            0, 3, 1,
            1, 3, 2,
            2, 3, 0,
            0, 2, 1
        };

        GL::GenBuffer(indexBufferObject_);

        GL::BindBuffer(GL::BufferType::ELEMENT_ARRAY_BUFFER, indexBufferObject_);

        GL::BufferData(GL::BufferType::ELEMENT_ARRAY_BUFFER, indices_.size() * sizeof(indices_[0]), indices_.data(), GL::Action::STATIC_DRAW);

        //
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
                                "    Color = vec4(clamp(Position, 0.1, 1.0), 1.0);                                  \n"
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

        const auto projection =
            Math3D::Transform::Projection(Math3D::DegToRad(30.f), 1024, 768, 1.f, 100.f);
        const auto position = 
            Math3D::Transform::Create(Math3D::Position(0.f, 0.f, 5.f));
        const auto rotationMatrix = 
            Math3D::Transform::Create(Math3D::Rotation(roll_, pitch_, yaw_));
        const auto scale = 
            Math3D::Transform::Create(Math3D::Scale(0.25f, 0.25f, 0.25f));

        const auto worldMatrix = projection * position * rotationMatrix * scale;

        shaderProgram_->UpdateUniform("gWorld", worldMatrix);

        GL::EnableVertexAttribArray(0);

        GL::BindBuffer(GL::BufferType::ARRAY_BUFFER, vertexBufferObject_);

        GL::VertexAttribPointer(0, 3, GL::Type::FLOAT, false, 0, 0);

        GL::BindBuffer(GL::BufferType::ELEMENT_ARRAY_BUFFER, indexBufferObject_);

        GL::DrawElements(GL::DataType::TRIANGLES, indices_.size(), GL::Type::UNSIGNED_INT);

        GL::DisableVertexAttribArray(0);

        Base::SceneObjectComponent::Draw();
    }
    
    void RootSceneObjectComponent::Update(float dt)
    {
        scale_ += 0.5f * dt;

        roll_ += rollSpeed_ * dt;
        pitch_ += pitchSPeed_ * dt;
        yaw_ += yawSpeed_ * dt;
    }
}