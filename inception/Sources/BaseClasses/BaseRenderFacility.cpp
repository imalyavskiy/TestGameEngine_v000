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

    void RenderFacility::Draw(const std::vector<SceneObject::sptr>& objectsList)
    {
        for(const auto object : objectsList)
            object->Draw(((*static_cast<Generic::VideoRenderer*>(this))));
    }

    bool RenderFacility::AddCamera(Generic::Camera& camera)
    {
        if(const auto it = cameraList_.find(&camera); it != cameraList_.end())
            return false;

        cameraList_.insert(&camera);
        return true;
    }

    bool RenderFacility::RemoveCamera(Generic::Camera& camera)
    {
        if (const auto it = cameraList_.find(&camera); it == cameraList_.end())
            return false;

        cameraList_.erase(&camera);
        return true;
    }
}
