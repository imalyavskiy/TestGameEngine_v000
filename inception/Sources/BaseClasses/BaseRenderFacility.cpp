#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include "BaseClasses.hpp"
namespace Base
{
    RenderFacility::RenderFacility(const std::string& name)
        : Object(name)
    {
    }

    void RenderFacility::Draw(const std::vector<SceneObject::sptr>& objects)
    {
        
    }
}