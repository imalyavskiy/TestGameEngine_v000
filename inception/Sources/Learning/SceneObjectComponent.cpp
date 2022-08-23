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

  VectorTripletOrigin::VectorTripletOrigin(const std::string& name)
    : Base::MeshComponent({}, name)
    , color_(.7f, .7f, .7f)
  {
  }

  void VectorTripletOrigin::Draw(const Math3D::Matrix4f& matViewProjection)
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

  void VectorTripletOrigin::Init()
  {
    vertices_ = {
      Math3D::Vector3f{  0.0000f, -0.2000f,	-0.0000f }, Math3D::Vector3f{ -0.0000f, -0.1848f,	 0.0765f }, Math3D::Vector3f{ -0.0293f, -0.1848f,	 0.0707f },
      Math3D::Vector3f{ -0.0541f, -0.1848f,	 0.0541f }, Math3D::Vector3f{ -0.0707f, -0.1848f,	 0.0293f }, Math3D::Vector3f{ -0.0765f, -0.1848f,	-0.0000f },
      Math3D::Vector3f{ -0.0707f, -0.1848f,	-0.0293f }, Math3D::Vector3f{ -0.0541f, -0.1848f,	-0.0541f }, Math3D::Vector3f{ -0.0293f, -0.1848f,	-0.0707f },
      Math3D::Vector3f{  0.0000f, -0.1848f,	-0.0765f }, Math3D::Vector3f{  0.0293f, -0.1848f,	-0.0707f }, Math3D::Vector3f{  0.0541f, -0.1848f,	-0.0541f },
      Math3D::Vector3f{  0.0707f, -0.1848f,	-0.0293f }, Math3D::Vector3f{  0.0765f, -0.1848f,	 0.0000f }, Math3D::Vector3f{  0.0707f, -0.1848f,	 0.0293f },
      Math3D::Vector3f{  0.0541f, -0.1848f,	 0.0541f }, Math3D::Vector3f{  0.0293f, -0.1848f,	 0.0707f }, Math3D::Vector3f{ -0.0000f, -0.1414f,	 0.1414f },
      Math3D::Vector3f{ -0.0541f, -0.1414f,	 0.1307f }, Math3D::Vector3f{ -0.1000f, -0.1414f,	 0.1000f }, Math3D::Vector3f{ -0.1307f, -0.1414f,	 0.0541f },
      Math3D::Vector3f{ -0.1414f, -0.1414f,	-0.0000f }, Math3D::Vector3f{ -0.1307f, -0.1414f,	-0.0541f }, Math3D::Vector3f{ -0.1000f, -0.1414f,	-0.1000f },
      Math3D::Vector3f{ -0.0541f, -0.1414f,	-0.1307f }, Math3D::Vector3f{  0.0000f, -0.1414f,	-0.1414f }, Math3D::Vector3f{  0.0541f, -0.1414f,	-0.1307f },
      Math3D::Vector3f{  0.1000f, -0.1414f,	-0.1000f }, Math3D::Vector3f{  0.1307f, -0.1414f,	-0.0541f }, Math3D::Vector3f{  0.1414f, -0.1414f,	 0.0000f },
      Math3D::Vector3f{  0.1307f, -0.1414f,	 0.0541f }, Math3D::Vector3f{  0.1000f, -0.1414f,	 0.1000f }, Math3D::Vector3f{  0.0541f, -0.1414f,	 0.1307f },
      Math3D::Vector3f{ -0.0000f, -0.0765f,	 0.1848f }, Math3D::Vector3f{ -0.0707f, -0.0765f,	 0.1707f }, Math3D::Vector3f{ -0.1307f, -0.0765f,	 0.1307f },
      Math3D::Vector3f{ -0.1707f, -0.0765f,	 0.0707f }, Math3D::Vector3f{ -0.1848f, -0.0765f,	 0.0000f }, Math3D::Vector3f{ -0.1707f, -0.0765f,	-0.0707f },
      Math3D::Vector3f{ -0.1307f, -0.0765f,	-0.1307f }, Math3D::Vector3f{ -0.0707f, -0.0765f,	-0.1707f }, Math3D::Vector3f{  0.0000f, -0.0765f,	-0.1848f },
      Math3D::Vector3f{  0.0707f, -0.0765f,	-0.1707f }, Math3D::Vector3f{  0.1307f, -0.0765f,	-0.1307f }, Math3D::Vector3f{  0.1707f, -0.0765f,	-0.0707f },
      Math3D::Vector3f{  0.1848f, -0.0765f,	 0.0000f }, Math3D::Vector3f{  0.1707f, -0.0765f,	 0.0707f }, Math3D::Vector3f{  0.1307f, -0.0765f,	 0.1307f },
      Math3D::Vector3f{  0.0707f, -0.0765f,	 0.1707f }, Math3D::Vector3f{ -0.0000f, -0.0000f,	 0.2000f }, Math3D::Vector3f{ -0.0765f, -0.0000f,	 0.1848f },
      Math3D::Vector3f{ -0.1414f, -0.0000f,	 0.1414f }, Math3D::Vector3f{ -0.1848f, -0.0000f,	 0.0765f }, Math3D::Vector3f{ -0.2000f,  0.0000f,	 0.0000f },
      Math3D::Vector3f{ -0.1848f,  0.0000f,	-0.0765f }, Math3D::Vector3f{ -0.1414f,  0.0000f,	-0.1414f }, Math3D::Vector3f{ -0.0765f,  0.0000f,	-0.1848f },
      Math3D::Vector3f{  0.0000f,  0.0000f,	-0.2000f }, Math3D::Vector3f{  0.0765f,  0.0000f,	-0.1848f }, Math3D::Vector3f{  0.1414f,  0.0000f,	-0.1414f },
      Math3D::Vector3f{  0.1848f,  0.0000f,	-0.0765f }, Math3D::Vector3f{  0.2000f,  0.0000f,	 0.0000f }, Math3D::Vector3f{  0.1848f, -0.0000f,	 0.0765f },
      Math3D::Vector3f{  0.1414f, -0.0000f,	 0.1414f }, Math3D::Vector3f{  0.0765f, -0.0000f,	 0.1848f }, Math3D::Vector3f{ -0.0000f,  0.0765f,	 0.1848f },
      Math3D::Vector3f{ -0.0707f,  0.0765f,	 0.1707f }, Math3D::Vector3f{ -0.1307f,  0.0765f,	 0.1307f }, Math3D::Vector3f{ -0.1707f,  0.0765f,	 0.0707f },
      Math3D::Vector3f{ -0.1848f,  0.0765f,	 0.0000f }, Math3D::Vector3f{ -0.1707f,  0.0765f,	-0.0707f }, Math3D::Vector3f{ -0.1307f,  0.0765f,	-0.1307f },
      Math3D::Vector3f{ -0.0707f,  0.0765f,	-0.1707f }, Math3D::Vector3f{  0.0000f,  0.0765f,	-0.1848f }, Math3D::Vector3f{  0.0707f,  0.0765f,	-0.1707f },
      Math3D::Vector3f{  0.1307f,  0.0765f,	-0.1307f }, Math3D::Vector3f{  0.1707f,  0.0765f,	-0.0707f }, Math3D::Vector3f{  0.1848f,  0.0765f,	 0.0000f },
      Math3D::Vector3f{  0.1707f,  0.0765f,	 0.0707f }, Math3D::Vector3f{  0.1307f,  0.0765f,	 0.1307f }, Math3D::Vector3f{  0.0707f,  0.0765f,	 0.1707f },
      Math3D::Vector3f{ -0.0000f,  0.1414f,	 0.1414f }, Math3D::Vector3f{ -0.0541f,  0.1414f,	 0.1307f }, Math3D::Vector3f{ -0.1000f,  0.1414f,	 0.1000f },
      Math3D::Vector3f{ -0.1307f,  0.1414f,	 0.0541f }, Math3D::Vector3f{ -0.1414f,  0.1414f,	 0.0000f }, Math3D::Vector3f{ -0.1307f,  0.1414f,	-0.0541f },
      Math3D::Vector3f{ -0.1000f,  0.1414f,	-0.1000f }, Math3D::Vector3f{ -0.0541f,  0.1414f,	-0.1307f }, Math3D::Vector3f{  0.0000f,  0.1414f,	-0.1414f },
      Math3D::Vector3f{  0.0541f,  0.1414f,	-0.1307f }, Math3D::Vector3f{  0.1000f,  0.1414f,	-0.1000f }, Math3D::Vector3f{  0.1307f,  0.1414f,	-0.0541f },
      Math3D::Vector3f{  0.1414f,  0.1414f,	 0.0000f }, Math3D::Vector3f{  0.1307f,  0.1414f,	 0.0541f }, Math3D::Vector3f{  0.1000f,  0.1414f,	 0.1000f },
      Math3D::Vector3f{  0.0541f,  0.1414f,	 0.1307f }, Math3D::Vector3f{ -0.0000f,  0.1848f,	 0.0765f }, Math3D::Vector3f{ -0.0293f,  0.1848f,	 0.0707f },
      Math3D::Vector3f{ -0.0541f,  0.1848f,	 0.0541f }, Math3D::Vector3f{ -0.0707f,  0.1848f,	 0.0293f }, Math3D::Vector3f{ -0.0765f,  0.1848f,	 0.0000f },
      Math3D::Vector3f{ -0.0707f,  0.1848f,	-0.0293f }, Math3D::Vector3f{ -0.0541f,  0.1848f,	-0.0541f }, Math3D::Vector3f{ -0.0293f,  0.1848f,	-0.0707f },
      Math3D::Vector3f{  0.0000f,  0.1848f,	-0.0765f }, Math3D::Vector3f{  0.0293f,  0.1848f,	-0.0707f }, Math3D::Vector3f{  0.0541f,  0.1848f,	-0.0541f },
      Math3D::Vector3f{  0.0707f,  0.1848f,	-0.0293f }, Math3D::Vector3f{  0.0765f,  0.1848f,	 0.0000f }, Math3D::Vector3f{  0.0707f,  0.1848f,	 0.0293f },
      Math3D::Vector3f{  0.0541f,  0.1848f,	 0.0541f }, Math3D::Vector3f{  0.0293f,  0.1848f,	 0.0707f }, Math3D::Vector3f{  0.0000f,  0.2000f,	 0.0000f },
    };

    indices_ = {
        0,   1,   2,    0,   2,   3,    0,   3,   4,    0,   4,   5,    0,   5,   6,    0,   6,   7,    0,   7,   8,    0,   8,   9,    0,   9,  10,    0,  10,  11,    0,  11,  12,
        0,  12,  13,    0,  13,  14,    0,  14,  15,    0,  15,  16,    0,  16,   1,    1,  17,  18,    1,  18,   2,    2,  18,  19,    2,  19,   3,    3,  19,  20,    3,  20,   4,
        4,  20,  21,    4,  21,   5,    5,  21,  22,    5,  22,   6,    6,  22,  23,    6,  23,   7,    7,  23,  24,    7,  24,   8,    8,  24,  25,    8,  25,   9,    9,  25,  26,
        9,  26,  10,   10,  26,  27,   10,  27,  11,   11,  27,  28,   11,  28,  12,   12,  28,  29,   12,  29,  13,   13,  29,  30,   13,  30,  14,   14,  30,  31,   14,  31,  15,
       15,  31,  32,   15,  32,  16,   16,  32,  17,   16,  17,   1,   17,  33,  34,   17,  34,  18,   18,  34,  35,   18,  35,  19,   19,  35,  36,   19,  36,  20,   20,  36,  37,
       20,  37,  21,   21,  37,  38,   21,  38,  22,   22,  38,  39,   22,  39,  23,   23,  39,  40,   23,  40,  24,   24,  40,  41,   24,  41,  25,   25,  41,  42,   25,  42,  26,
       26,  42,  43,   26,  43,  27,   27,  43,  44,   27,  44,  28,   28,  44,  45,   28,  45,  29,   29,  45,  46,   29,  46,  30,   30,  46,  47,   30,  47,  31,   31,  47,  48,
       31,  48,  32,   32,  48,  33,   32,  33,  17,   33,  49,  50,   33,  50,  34,   34,  50,  51,   34,  51,  35,   35,  51,  52,   35,  52,  36,   36,  52,  53,   36,  53,  37,
       37,  53,  54,   37,  54,  38,   38,  54,  55,   38,  55,  39,   39,  55,  56,   39,  56,  40,   40,  56,  57,   40,  57,  41,   41,  57,  58,   41,  58,  42,   42,  58,  59,
       42,  59,  43,   43,  59,  60,   43,  60,  44,   44,  60,  61,   44,  61,  45,   45,  61,  62,   45,  62,  46,   46,  62,  63,   46,  63,  47,   47,  63,  64,   47,  64,  48,
       48,  64,  49,   48,  49,  33,   49,  65,  66,   49,  66,  50,   50,  66,  67,   50,  67,  51,   51,  67,  68,   51,  68,  52,   52,  68,  69,   52,  69,  53,   53,  69,  70,
       53,  70,  54,   54,  70,  71,   54,  71,  55,   55,  71,  72,   55,  72,  56,   56,  72,  73,   56,  73,  57,   57,  73,  74,   57,  74,  58,   58,  74,  75,   58,  75,  59,
       59,  75,  76,   59,  76,  60,   60,  76,  77,   60,  77,  61,   61,  77,  78,   61,  78,  62,   62,  78,  79,   62,  79,  63,   63,  79,  80,   63,  80,  64,   64,  80,  65,
       64,  65,  49,   65,  81,  82,   65,  82,  66,   66,  82,  83,   66,  83,  67,   67,  83,  84,   67,  84,  68,   68,  84,  85,   68,  85,  69,   69,  85,  86,   69,  86,  70,
       70,  86,  87,   70,  87,  71,   71,  87,  88,   71,  88,  72,   72,  88,  89,   72,  89,  73,   73,  89,  90,   73,  90,  74,   74,  90,  91,   74,  91,  75,   75,  91,  92,
       75,  92,  76,   76,  92,  93,   76,  93,  77,   77,  93,  94,   77,  94,  78,   78,  94,  95,   78,  95,  79,   79,  95,  96,   79,  96,  80,   80,  96,  81,   80,  81,  65,
       81,  97,  98,   81,  98,  82,   82,  98,  99,   82,  99,  83,   83,  99, 100,   83, 100,  84,   84, 100, 101,   84, 101,  85,   85, 101, 102,   85, 102,  86,   86, 102, 103,
       86, 103,  87,   87, 103, 104,   87, 104,  88,   88, 104, 105,   88, 105,  89,   89, 105, 106,   89, 106,  90,   90, 106, 107,   90, 107,  91,   91, 107, 108,   91, 108,  92,
       92, 108, 109,   92, 109,  93,   93, 109, 110,   93, 110,  94,   94, 110, 111,   94, 111,  95,   95, 111, 112,   95, 112,  96,   96, 112,  97,   96,  97,  81,  113,  98,  97,
      113,  99,  98,  113, 100,  99,  113, 101, 100,  113, 102, 101,  113, 103, 102,  113, 104, 103,  113, 105, 104,  113, 106, 105,  113, 107, 106,  113, 108, 107,  113, 109, 108,
      113, 110, 109,  113, 111, 110,  113, 112, 111,  113,  97, 112,
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

  void VectorTripletOrigin::SetColor(const Math3D::Vector3f& color)
  {
    color_ = color;
  }

  const Math3D::Vector3f& VectorTripletOrigin::GetColor() const
  {
    return color_;
  }
}
