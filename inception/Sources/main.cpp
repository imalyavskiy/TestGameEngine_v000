#include "main.hpp"
#include "Learning/Learning.hpp"

Base::Scene::ptr scene;


static void RenderSceneCB()
{
    GL::Clear({ GL::AttribMask::COLOR_BUFFER_BIT });

    scene->Draw();

    GLUT::SwapBuffers();
}

constexpr int oneThirtieth = 1000 / 30; // of a second in milliseconds
std::chrono::steady_clock::time_point prev = std::chrono::steady_clock::now() - std::chrono::milliseconds(oneThirtieth);
static void IdleCB()
{
    const auto now = std::chrono::steady_clock::now();
    const auto dtMS = std::chrono::duration_cast<std::chrono::milliseconds>(now - prev);
    prev = now;

    scene->Update(dtMS.count()/1000.f);

    RenderSceneCB();
}

static void InitializeGlutCallbacks()
{
    GLUT::DisplayFunc(RenderSceneCB);

    GLUT::IdleFunc(IdleCB);
}

static void InitializeScene()
{
    scene = std::make_shared<Learning::DefaultScene>("DefaultScene");

    auto sceneObject = std::make_shared<Learning::SceneObject>("dot scene object");
    sceneObject->SetRootComponent(std::make_shared<Learning::RootSceneObjectComponent>("dot component"));
    
    scene->AddObject(sceneObject);
}

int main(int argc, char** argv)
{
    const float WINDOW_WIDTH = 1024;
    const float WINDOW_HEIGHT = 768;

    GLUT::Init(argc, argv);

    GLUT::InitDisplayMode({ GLUT::DisplayMode::DOUBLE, GLUT::DisplayMode::RGBA });

    GLUT::InitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    GLUT::InitWindowPosition(100, 100);

    GLUT::CreateWindow("Inception");

    InitializeGlutCallbacks();

    GLEW::Error res = GLEW::Init();
    if (res != GLEW::Error::OK) {
        std::cerr << "Error: '" << GLEW::GetErrorString(res) << "'\n";
        return 1;
    }

    InitializeScene();

    GL::ClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    GLUT::MainLoop();

    return 0;
}