#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include <Learning/Learning.hpp>

namespace Learning
{
    RootSceneObjectComponent::RootSceneObjectComponent(const std::string& name)
        : Base::SceneObjectComponent(name)
    {
        // TODO: move all this stuff to Init function

        vertices_ = {
            /* 0*/	Math3D::Vector3f{ -0.2500f, -0.2500f, -0.2500f },	/* 1*/	Math3D::Vector3f{ -0.0000f, -0.1001f, -0.1001f },	/* 2*/	Math3D::Vector3f{  0.2500f, -0.2500f, -0.2500f },
            /* 3*/	Math3D::Vector3f{ -0.1001f, -0.0000f, -0.1001f },	/* 4*/	Math3D::Vector3f{  0.0000f,  0.0000f, -0.3247f },	/* 5*/	Math3D::Vector3f{  0.1001f, -0.0000f, -0.1001f },
            /* 6*/	Math3D::Vector3f{ -0.2500f,  0.2500f, -0.2500f },	/* 7*/	Math3D::Vector3f{ -0.0000f,  0.1001f, -0.1001f },	/* 8*/	Math3D::Vector3f{  0.2500f,  0.2500f, -0.2500f },
            /* 9*/	Math3D::Vector3f{ -0.2500f, -0.2500f,  0.2500f },	/*10*/	Math3D::Vector3f{ -0.0000f, -0.1001f,  0.1001f },	/*11*/	Math3D::Vector3f{  0.2500f, -0.2500f,  0.2500f },
            /*12*/	Math3D::Vector3f{ -0.1001f, -0.0000f,  0.1001f },	/*13*/	Math3D::Vector3f{  0.0000f,  0.0000f,  0.3248f },	/*14*/	Math3D::Vector3f{  0.1001f, -0.0000f,  0.1001f },
            /*15*/	Math3D::Vector3f{ -0.2500f,  0.2500f,  0.2500f },	/*16*/	Math3D::Vector3f{ -0.0000f,  0.1001f,  0.1001f },	/*17*/	Math3D::Vector3f{  0.2500f,  0.2500f,  0.2500f },
            /*18*/	Math3D::Vector3f{ -0.1001f, -0.1001f,  0.0000f },	/*19*/	Math3D::Vector3f{  0.0000f, -0.3248f, -0.0000f },	/*20*/	Math3D::Vector3f{  0.1001f, -0.1001f,  0.0000f },
            /*21*/	Math3D::Vector3f{  0.3248f,  0.0000f, -0.0000f },	/*22*/	Math3D::Vector3f{  0.1001f,  0.1001f,  0.0000f },	/*23*/	Math3D::Vector3f{  0.0000f,  0.3248f, -0.0000f },
            /*24*/	Math3D::Vector3f{ -0.1001f,  0.1001f,  0.0000f },	/*25*/	Math3D::Vector3f{ -0.3248f,  0.0000f, -0.0000f },
        };

        GL::GenBuffer(vertexBufferObject_);

        GL::BindBuffer(GL::BufferType::ARRAY_BUFFER, vertexBufferObject_);

        GL::BufferData(GL::BufferType::ARRAY_BUFFER, vertices_.size() * sizeof vertices_[0] , vertices_.data(), GL::Action::STATIC_DRAW);

        indices_ = {
            /* 0*/  0,  3,  1,	/* 1*/  1,  5,  2,	/* 2*/  3,  6,  7,	/* 3*/  7,  8,  5,	/* 4*/ 10, 13, 12,	/* 5*/ 10, 14, 13,	/* 6*/ 12, 13, 16,	/* 7*/ 13, 14, 16,
            /* 8*/  0,  1, 18,	/* 9*/  1,  2, 20,	/*10*/ 18, 10,  9,	/*11*/ 20, 11, 10,	/*12*/  2,  5, 20,	/*13*/  5,  8, 22,	/*14*/ 20, 14, 11,	/*15*/ 22, 17, 14,
            /*16*/  8,  7, 22,	/*17*/  7,  6, 24,	/*18*/ 22, 16, 17,	/*19*/ 24, 15, 16,	/*20*/  3, 25, 24,	/*21*/  3, 18, 25,	/*22*/ 24, 25, 12,	/*23*/ 25, 18, 12,
            /*24*/ 12, 15, 24,	/*25*/ 24,  6,  3,	/*26*/  3,  0, 18,	/*27*/ 18,  9, 12,	/*28*/ 18, 19, 10,	/*29*/ 10, 19, 20,	/*30*/ 20, 19,  1,	/*31*/  1, 19, 18,
            /*32*/ 12,  9, 10,	/*33*/ 10, 11, 14,	/*34*/ 14, 17, 16,	/*35*/ 16, 15, 12,	/*36*/ 20, 21, 14,	/*37*/ 14, 21, 22,	/*38*/ 22, 21,  5,	/*39*/  5, 21, 20,
            /*40*/ 22, 23, 16,	/*41*/ 16, 23, 24,	/*42*/ 24, 23,  7,	/*43*/  7, 23, 22,	/*44*/  1,  4,  5,	/*45*/  5,  4,  7,	/*46*/  7,  4,  3,	/*47*/  3,  4,  1,
        };

        GL::GenBuffer(indexBufferObject_);

        GL::BindBuffer(GL::BufferType::ELEMENT_ARRAY_BUFFER, indexBufferObject_);

        GL::BufferData(GL::BufferType::ELEMENT_ARRAY_BUFFER, indices_.size() * sizeof(indices_[0]), indices_.data(), GL::Action::STATIC_DRAW);

        //
        shaderProgram_ = std::make_shared<Base::ShaderProgram>(
            "shader program",
            std::make_shared<Base::VertexShader>(
                                "#version 330                                      \n"
                                "layout (location = 0) in vec3 Position;           \n"
                                "uniform mat4 gWorld;                              \n"
                                "out vec4 Color;                                   \n"
                                "void main()                                       \n"
                                "{                                                 \n"
                                "    gl_Position = gWorld * vec4(Position, 1.0);   \n"
                                "    Color = vec4(clamp(Position, 0.1, 1.0), 1.0); \n"
                                "}                                                 \n"),
            nullptr, nullptr, nullptr,
            std::make_shared<Base::FragmentShader>(
                                "#version 330                                      \n"
                                "in vec4 Color;                                    \n"
                                "out vec4 FragColor;                               \n"
                                "void main()                                       \n"
                                "{                                                 \n"
                                "    FragColor = Color;                            \n"
                                "}                                                 \n") 
            );

    	if (!shaderProgram_->Build())
        {
            std::cerr << "Failed to build shader program\n";
            assert(0);
        }

        const std::string gWorldName("gWorld"); // uniform variable from vertex shader
        if(!shaderProgram_->AttachToUniform(gWorldName))
        {
            std::cerr << "Failed to attach to uniform variable(" << gWorldName << ")\n";
            assert(0);
        }
    }

    void RootSceneObjectComponent::Draw()
    {
        shaderProgram_->Use();

        Math3D::Transform pipeline;
        pipeline.SetTransform(
            Math3D::Position(0.f, 0.f, 5.f), 
            Math3D::Rotation(roll_, pitch_, yaw_), 
            Math3D::Scale(2.f)
        );
        pipeline.SetCamera(
            Math3D::Position{ 0.f, 0.f, -3.f * std::sinf(scale_) }, 
            Math3D::Direction{ 0.f,0.f,2.f }, 
            Math3D::Direction{ 0.f, 1.f, 0.f }
        );
        pipeline.SetProjection(60.f, 1024, 768, 1.f, 100.f);
        const auto matrixMVP = pipeline.GetMVPMatrix();

        shaderProgram_->UpdateUniform("gWorld", matrixMVP);

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