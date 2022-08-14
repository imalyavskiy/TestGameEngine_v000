#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include <BaseClasses/BaseClasses.hpp>
#include "RenderFacility.hpp"

namespace Engine
{
    RenderFacility::RenderFacility(const std::string& name)
        : Base::RenderFacility(name)
    {
    }

    void RenderFacility::Render(const std::vector<Base::SceneObject::sptr>& sceneTree_)
    {
        GL::Clear({ GL::AttribMask::COLOR_BUFFER_BIT });

        // todo: draw 

        GLUT::SwapBuffers();
    }
}
