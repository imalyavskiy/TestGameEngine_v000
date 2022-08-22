#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include <BaseClasses/BaseClasses.hpp>
#include "Learning.hpp"

namespace Learning
{
	DefaultScene::DefaultScene(const std::string& name)
		: Base::Scene(name)
	{
	}

	void DefaultScene::Update(float dt)
	{
		for (auto sceneObject : objectTree_)
			sceneObject->Update(dt);
	}

  bool DefaultScene::Load(const Base::RenderFacility::sptr& renderer, Base::Controller::sptr inputController)
  {
    // Hedgehog
    const auto soHedgehog =
      std::make_shared<Learning::SceneObject>("Hedgehog");
    soHedgehog->SetRootComponent(std::make_shared<Learning::RootSceneObjectComponent>("dot component"));
    soHedgehog->Init();
    AddObject(soHedgehog);

    // Camera
    const auto soCamera =
      std::make_shared<Learning::Pawn>("FreeCamera");
    auto& genereicVideoRenderer =
      *(static_cast<Base::Generic::VideoRenderer*>(renderer.get()));
    const auto baseCamera =
      std::make_shared<Learning::CameraComponent>(genereicVideoRenderer, Base::SceneObjectComponent::wptr{}, "FreeCamera");
    soCamera->SetRootComponent(baseCamera);
    soCamera->Transform().position = Math3D::Position(3.f, 0.f, 0.f);
    //soCamera->Transform().rotation = Math3D::Rotation(0.f, Math3D::DegToRad(-90.f), Math3D::DegToRad(90.f));
    soCamera->Init();
    AddObject(soCamera);
    inputController->SetPawn(soCamera);

    return true;
  }
}
