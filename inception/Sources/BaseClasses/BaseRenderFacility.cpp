#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include "BaseClasses.hpp"
namespace Base
{
    RenderFacility::RenderFacility(const Base::Settings& settings, const std::string& name)
      : Object(name)
      , settings_(settings)
    {
    }

    void RenderFacility::Draw(const std::vector<SceneObject::sptr>& objectsList)
    {
      const auto proj = 
        Math3D::Pipeline::Projection(
          camera_->FoV(), 
          settings_.viewportWidth, 
          settings_.viewportHeight, 
          camera_->Near(), 
          camera_->Far()
        );

      const auto camView = 
        Math3D::Pipeline::ViewRotation(
          camera_->LookAt(), 
          camera_->Up());

      const auto camPos = 
        Math3D::Pipeline::Create(
          camera_->Position()
        );

      const auto matViewProjection = proj * camView * camPos;
      for (const auto& object : objectsList)
        object->Draw(matViewProjection);
    }

    bool RenderFacility::AddCamera(Generic::Camera& camera)
    {
#if 0 
        if(const auto it = cameraList_.find(&camera); it != cameraList_.end())
            return false;

        cameraList_.insert(&camera);
#else
        camera_ = &camera;
#endif
        return true;
    }

    bool RenderFacility::RemoveCamera(Generic::Camera& camera)
    {
#if 0
        if (const auto it = cameraList_.find(&camera); it == cameraList_.end())
            return false;

        cameraList_.erase(&camera);
#else
        camera_ = &camera;
#endif
        return true;
    }
}
