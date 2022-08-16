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
        Math3D::Pipeline pipeline;
       
//        pipeline.SetCamera(
//            Math3D::Position{ 0.f, 0.f, -3.f * std::sinf(scale_) },
//            Math3D::Direction{ 0.f,0.f,2.f }, 
//            Math3D::Direction{ 0.f, 1.f, 0.f }
//        );

//        pipeline.SetProjection(60.f, 1024, 768, 1.f, 100.f);

        const auto cameraProjection = 
          Math3D::Pipeline::Projection(camera_->FoV(), settings_.viewportWidth
                                                     , settings_.viewportHeight
                                                     , settings_.nearClipPlane
                                                     , settings_.farClipPlane
                                      );
        const auto cameraRotation = 
          Math3D::Pipeline::ViewRotation(camera_->LookAt(), camera_->Up());
        const auto cameraPosition = 
          Math3D::Pipeline::Create(camera_->Position());

        const auto matViewProjection = cameraProjection * cameraRotation * cameraPosition;
  
        for(const auto& object : objectsList)
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
