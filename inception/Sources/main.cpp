#include "main.hpp"
#include "Engine/Engine.hpp"

Base::Scene::sptr scene;

[[nodiscard]]
int EngineInit(const Base::Settings& settings)
{
    // @todo Refactor this. Abstraction levels mix-up: render API and application structure.
    // Render API must be under Engine and hidden under abstract some 'Render Device'
    // interface
    GLUT::InitDisplayMode({ GLUT::DisplayMode::DOUBLE, GLUT::DisplayMode::DEPTH, GLUT::DisplayMode::RGBA });
    GLUT::InitWindowSize(settings.viewportWidth, settings.viewportHeight);
    GLUT::InitWindowPosition(100, 100);
    GLUT::CreateWindow("Inception");

    Engine::Initialize(settings);

    // @todo Refactor this. Abstraction levels mix-up: render API and application structure.
    // Render API must be under Engine and hidden under abstract some 'Render Device'
    // interface
    const GLEW::Error res = GLEW::Init();
    if (res != GLEW::Error::OK) {
        std::cerr << "Error: '" << GLEW::GetErrorString(res) << "'\n";
        return 1;
    }

    // @todo Refactor this. Abstraction levels mix-up: render API and application structure.
    // Render API must be under Engine and hidden under abstract some 'Render Device'
    // interface
    GLUT::DisplayFunc(Engine::RenderProc);
    GLUT::IdleFunc(Engine::RenderProc);
    GLUT::SpecialFunc(Engine::SpecialKeyboardProc);
    GLUT::SpecialUpFunc(Engine::SpecialKeyboardUpProc);
    GLUT::KeyboardFunc(Engine::KeyboardProc);
    GLUT::KeyboardUpFunc(Engine::KeyboardUpProc);
    GLUT::MouseFunc(Engine::MouseProc);
    GLUT::MotionFunc(Engine::MotionProc);
    GLUT::PassiveMotionFunc(Engine::PassiveMotionProc);
    GLUT::EntryFunc(Engine::EntryProc);

    // @todo Refactor this. Abstraction levels mix-up: render API and application structure.
    // Render API must be under Engine and hidden under abstract some 'Render Device'
    // interface
    GL::ClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    return 0;
}

[[nodiscard]]
int EngineLoad(const Base::Settings& settings)
{
    Engine::Load(settings);

    return 0;
}

[[nodiscard]]
int EngineRun()
{
    // @todo Refactor this. Abstraction levels mix-up: render API and application structure.
    // Render API must be under Engine and hidden under abstract some 'Render Device'
    // interface
    GLUT::MainLoop();

    return 0;
}

int main(int argc, char** argv)
{
  const Base::Settings settings;

  // @todo Refactor this. Abstraction levels mix-up: render API and application structure.
  // Render API must be under Engine and hidden under abstract some 'Render Device'
  // interface
  GLUT::Init(argc, argv);

  int result = 0;

  result = EngineInit(settings);

  result = EngineLoad(settings);

  result = EngineRun();

  return result;
}