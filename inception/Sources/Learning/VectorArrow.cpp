#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include <Learning/Learning.hpp>

namespace Learning
{
  VectorArrow::VectorArrow(const std::string& name)
    : Base::MeshComponent({}, name)
    , color_(.7f, .7f, .7f)
  {
  }

  void VectorArrow::Draw(const Math3D::Matrix4f& matViewProjection)
  {
    shaderProgram_->Use();

    shaderProgram_->UpdateUniform("gWorld", matViewProjection * Math3D::Pipeline::Create(transform_));

    shaderProgram_->UpdateUniform("gColor", color_);

    GL::EnableVertexAttribArray(0);

    GL::BindBuffer(GL::BufferType::ARRAY_BUFFER, vertexBufferObject_);

    GL::VertexAttribPointer(0, 3, GL::Type::FLOAT, false, 0, 0);

    GL::BindBuffer(GL::BufferType::ELEMENT_ARRAY_BUFFER, indexBufferObject_);

    GL::DrawElements(GL::DataType::TRIANGLES, indices_.size(), GL::Type::UNSIGNED_INT);

    GL::DisableVertexAttribArray(0);

    Base::SceneObjectComponent::Draw(matViewProjection);

    MeshComponent::Draw(matViewProjection);
  }

  void VectorArrow::Init()
  {
    vertices_ = {
      Math3D::Vector3f{ 0.9736f, -0.0000f,  0.0000f }, Math3D::Vector3f{ 0.7294f, -0.0200f,  0.0000f }, Math3D::Vector3f{ 0.7294f, -0.0173f,  0.0100f },
      Math3D::Vector3f{ 0.7294f, -0.0100f,  0.0173f }, Math3D::Vector3f{ 0.7294f,  0.0000f,  0.0200f }, Math3D::Vector3f{ 0.7294f,  0.0100f,  0.0173f },
      Math3D::Vector3f{ 0.7294f,  0.0173f,  0.0100f }, Math3D::Vector3f{ 0.7294f,  0.0200f,  0.0000f }, Math3D::Vector3f{ 0.7294f,  0.0173f, -0.0100f },
      Math3D::Vector3f{ 0.7294f,  0.0100f, -0.0173f }, Math3D::Vector3f{ 0.7294f,  0.0000f, -0.0200f }, Math3D::Vector3f{ 0.7294f, -0.0100f, -0.0173f },
      Math3D::Vector3f{ 0.7294f, -0.0173f, -0.0100f }, Math3D::Vector3f{ 0.0000f, -0.0200f,  0.0000f }, Math3D::Vector3f{ 0.0000f, -0.0173f,  0.0100f },
      Math3D::Vector3f{ 0.0000f, -0.0100f,  0.0173f }, Math3D::Vector3f{ 0.0000f,  0.0000f,  0.0200f }, Math3D::Vector3f{ 0.0000f,  0.0100f,  0.0173f },
      Math3D::Vector3f{ 0.0000f,  0.0173f,  0.0100f }, Math3D::Vector3f{ 0.0000f,  0.0200f,  0.0000f }, Math3D::Vector3f{ 0.0000f,  0.0173f, -0.0100f },
      Math3D::Vector3f{ 0.0000f,  0.0100f, -0.0173f }, Math3D::Vector3f{ 0.0000f,  0.0000f, -0.0200f }, Math3D::Vector3f{ 0.0000f, -0.0100f, -0.0173f },
      Math3D::Vector3f{ 0.0000f, -0.0173f, -0.0100f }, Math3D::Vector3f{ 0.7018f, -0.0353f,  0.0204f }, Math3D::Vector3f{ 0.7018f, -0.0407f,  0.0000f },
      Math3D::Vector3f{ 0.7018f, -0.0353f, -0.0204f }, Math3D::Vector3f{ 0.7018f, -0.0204f, -0.0353f }, Math3D::Vector3f{ 0.7018f,  0.0000f, -0.0407f },
      Math3D::Vector3f{ 0.7018f,  0.0204f, -0.0353f }, Math3D::Vector3f{ 0.7018f,  0.0353f, -0.0204f }, Math3D::Vector3f{ 0.7018f,  0.0407f,  0.0000f },
      Math3D::Vector3f{ 0.7018f,  0.0353f,  0.0204f }, Math3D::Vector3f{ 0.7018f,  0.0204f,  0.0353f }, Math3D::Vector3f{ 0.7018f,  0.0000f,  0.0407f },
      Math3D::Vector3f{ 0.7018f, -0.0204f,  0.0353f },
    };

    indices_ = {
       0, 25, 26,   0, 36, 25,   0, 35, 36,   0, 34, 35,   0, 33, 34,   0, 32, 33,   0, 31, 32,   0, 30, 31,   0, 29, 30,   0, 28, 29,   0, 27, 28,   0, 26, 27,
       1,  2, 14,  14, 13,  1,   2,  3, 15,  15, 14,  2,   3,  4, 16,  16, 15,  3,   4,  5, 17,  17, 16,  4,   5,  6, 18,  18, 17,  5,   6,  7, 19,  19, 18,  6,
       7,  8, 20,  20, 19,  7,   8,  9, 21,  21, 20,  8,   9, 10, 22,  22, 21,  9,  10, 11, 23,  23, 22, 10,  11, 12, 24,  24, 23, 11,  12,  1, 13,  13, 24, 12,
      24, 13, 14,  24, 14, 15,  24, 15, 16,  24, 16, 17,  24, 17, 18,  24, 18, 19,  24, 19, 20,  24, 20, 21,  24, 21, 22,  24, 22, 23,   2,  1, 26,  26, 25,  2,
       1, 12, 27,  27, 26,  1,  12, 11, 28,  28, 27, 12,  11, 10, 29,  29, 28, 11,  10,  9, 30,  30, 29, 10,   9,  8, 31,  31, 30,  9,   8,  7, 32,  32, 31,  8,
       7,  6, 33,  33, 32,  7,   6,  5, 34,  34, 33,  6,   5,  4, 35,  35, 34,  5,   4,  3, 36,  36, 35,  4,   3,  2, 25,  25, 36,  3,
    };

    // Materialf
    shaderProgram_ = std::make_shared<Base::ShaderProgram>(
      "shader program",
      std::make_shared<Base::VertexShader>(
        "#version 330                                      \n"
        "layout (location = 0) in vec3 Position;           \n"
        "uniform mat4 gWorld;                              \n"
        "uniform vec3 gColor;                              \n"
        "out vec4 Color;                                   \n"
        "void main()                                       \n"
        "{                                                 \n"
        "    gl_Position = gWorld * vec4(Position, 1.0);   \n"
        "    Color = vec4(gColor, 1.0);                    \n"
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
    if (!shaderProgram_->AttachToUniform(gWorldName))
    {
      std::cerr << "Failed to attach to uniform variable(" << gWorldName << ")\n";
      assert(0);
    }

    const std::string gColorName("gColor");
    if (!shaderProgram_->AttachToUniform(gColorName))
    {
      std::cerr << "Failed to attach to uniform variable(" << gWorldName << ")\n";
      assert(0);
    }

    MeshComponent::Init();
  }

  void VectorArrow::SetColor(Math3D::Vector3f color) 
  {
    color_ = color;
  }

  const Math3D::Vector3f& VectorArrow::GetColor() const
  {
    return color_;
  }
}
