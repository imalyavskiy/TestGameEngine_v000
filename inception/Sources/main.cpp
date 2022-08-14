#include "main.hpp"
#include "Engine/Engine.hpp"

Base::Scene::sptr scene;

int InitEngine(const uint32_t width, const uint32_t height)
{
    Engine::Settings settings;
    settings.viewportWidth = width;
    settings.viewportHeight = height;

    // @todo Refactor this. Abstraction levels mix-up: render API and application structure.
    // Render API must be under Engine and hidden under abstract some 'Render Device'
    // interface
    GLUT::InitDisplayMode({ GLUT::DisplayMode::DOUBLE, GLUT::DisplayMode::RGBA });
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

    // @todo Refactor this. Abstraction levels mix-up: render API and application structure.
    // Render API must be under Engine and hidden under abstract some 'Render Device'
    // interface
    GL::ClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    Engine::Load();

    return 0;
}

void RunEngine()
{
    // @todo Refactor this. Abstraction levels mix-up: render API and application structure.
    // Render API must be under Engine and hidden under abstract some 'Render Device'
    // interface
    GLUT::MainLoop();
}

int main(int argc, char** argv)
{
    constexpr int32_t WINDOW_WIDTH = 1024;
    constexpr int32_t WINDOW_HEIGHT = 768;

    // @todo Refactor this. Abstraction levels mix-up: render API and application structure.
    // Render API must be under Engine and hidden under abstract some 'Render Device'
    // interface
    GLUT::Init(argc, argv);

    InitEngine(WINDOW_WIDTH, WINDOW_HEIGHT);

    RunEngine();

    return 0;
}