#include "main.hpp"
#include "Learning/Learning.hpp"

BaseScene::ptr scene;


static void RenderSceneCB()
{
    GL::Clear({ GL::AttribMask::COLOR_BUFFER_BIT });

    scene->Draw();

    GLUT::SwapBuffers();
}

static void InitializeGlutCallbacks()
{
    GLUT::DisplayFunc(RenderSceneCB);
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
    GLUT::Init(argc, argv);

    GLUT::InitDisplayMode({ GLUT::DisplayMode::DOUBLE, GLUT::DisplayMode::RGBA });

    GLUT::InitWindowSize(1024, 768);

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