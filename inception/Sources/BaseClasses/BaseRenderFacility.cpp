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

      const Math3D::Direction lookAt = 
        camera_->LookAt();
      const Math3D::Direction up = 
        camera_->Up();
      const Math3D::Matrix4f camView = 
        Math3D::Pipeline::ViewRotation( lookAt, up);

      const Math3D::Position pos = 
        camera_->Position();
      const Math3D::Matrix4f camPos = 
        Math3D::Pipeline::Create(-pos); // camera position must be negated

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
