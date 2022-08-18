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
      struct
      {
        float fov = 60.f;
        float width = 1024;
        float height = 768;
        float near = 1.f;
        float far = 100.f;
      } const projSettings;
      const Math3D::Position  cameraPos{ 0.f, 0.f, -3.f };
      const Math3D::Direction cameraForward{ 0.f, 0.f, -1.f };
      const Math3D::Direction cameraUp{ 0.f, 1.f, 0.f };

//      const auto viewProjection =
//        Math3D::Pipeline::Projection(projSettings.fov, projSettings.width, projSettings.height, projSettings.near, projSettings.far);
//      const auto viewRotation = 
//        Math3D::Pipeline::ViewRotation(cameraForward, cameraUp);
//      const auto viewPosition =
//        Math3D::Pipeline::Create(cameraPos);
//      const auto trans1 = viewProjection * viewRotation * viewPosition;

      Math3D::Pipeline pipeline;
      //      pipeline.SetProjection(projSettings.fov, projSettings.width, projSettings.height, projSettings.near, projSettings.far);
      pipeline.SetProjection(camera_->FoV(), settings_.viewportWidth, settings_.viewportHeight, settings_.nearClipPlane, settings_.farClipPlane);

      //      pipeline.SetCamera( cameraPos, cameraForward, cameraUp);
      auto pos = camera_->Position(); // HERE IS THE ERROR - INVALID POSITION
      pipeline.SetCamera({0.f, 0.f, -3.f}/*pos*/, camera_->LookAt(), camera_->Up());

      pipeline.SetTransform({ 0.f, 0.f, 0.f }, { 0.f, 0.f, 0.f }, { 1.f, 1.f, 1.f });
      const auto trans2 =
        pipeline.GetMVPMatrix();

      for (const auto& object : objectsList)
        object->Draw(trans2/*matViewProjection*/);

//      const auto cameraProjection = 
//        Math3D::Pipeline::Projection(camera_->FoV(), settings_.viewportWidth, settings_.viewportHeight, settings_.nearClipPlane, settings_.farClipPlane );
//      const auto cameraRotation = 
//        Math3D::Pipeline::ViewRotation(camera_->LookAt(), camera_->Up());
//      const auto cameraPosition = 
//        Math3D::Pipeline::Create(camera_->Position());
//      const auto matViewProjection = cameraProjection * cameraRotation * cameraPosition;
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
