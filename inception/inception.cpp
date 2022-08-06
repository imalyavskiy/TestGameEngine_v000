#include <iostream>
#include "glut_wrapper.h"
#include "gl_wrapper.h"

static void RenderSceneCB()
{
    gl::Clear({ gl::AttribMask::COLOR_BUFFER_BIT });

    /* TODO: Производим отрисовку */

    glut::SwapBuffers();
}

static void InitializeGlutCallbacks()
{
    glut::DisplayFunc(RenderSceneCB);
}

int main(int argc, char** argv)
{
    glut::Init(argc, argv);

    glut::InitDisplayMode({ glut::DisplayMode::DOUBLE, glut::DisplayMode::RGBA });

    glut::InitWindowSize(1024, 768);

    glut::InitWindowPosition(100, 100);

    glut::CreateWindow("Inception");

    InitializeGlutCallbacks();

    gl::ClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glut::MainLoop();

    return 0;
}