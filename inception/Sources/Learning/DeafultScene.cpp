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
    LoadVectorTriple();

    LoadCamera(renderer, inputController);

    return true;
  }

  void DefaultScene::LoadVectorTriple()
  {
    const auto socRoot =
      std::make_shared<Base::SceneObjectComponent>(Base::SceneObjectComponent::wptr(), "Root");

    const auto socSphere =
      std::make_shared<Learning::VectorTripletOrigin>("VectorTripleOrigin");
    socSphere->SetColor({ 1.f, 1.f, 1.f });
    socSphere->Transform().scale.x = 0.35f;
    socSphere->Transform().scale.y = 0.35f;
    socSphere->Transform().scale.z = 0.35f;
    socRoot->AddChild(socSphere);

    const auto socVectorX =
      std::make_shared<Learning::VectorArrow>("Vector X");
    socVectorX->SetColor({ 1.f, 0.f, 0.f });
    socRoot->AddChild(socVectorX);

    const auto socVectorY=
      std::make_shared<Learning::VectorArrow>("Vector Y");
    socVectorY->SetColor({ 0.f, 0.f, 1.f });
    socVectorY->Transform().rotation.z = Math3D::DegToRad(90.f);
    socRoot->AddChild(socVectorY);

    const auto socVectorZ =
      std::make_shared<Learning::VectorArrow>("Vector Z");
    socVectorZ->SetColor({ 0.f, 1.f, 0.f });
    socVectorZ->Transform().rotation.y = Math3D::DegToRad(-90.f);
    socRoot->AddChild(socVectorZ);

    const auto vectorTriple =
      std::make_shared<Learning::RotatingObject>("VectorTriple");
    vectorTriple->SetRootComponent(socRoot);
    vectorTriple->Init();

    AddObject(vectorTriple);
  }

  void DefaultScene::LoadCamera(const Base::RenderFacility::sptr& renderer, Base::Controller::sptr inputController)
  {
    // Camera
    const auto soCamera =
      std::make_shared<Learning::Pawn>("FreeCamera");
    auto& genereicVideoRenderer =
      *(static_cast<Base::Generic::VideoRenderer*>(renderer.get()));
    const auto baseCamera =
      std::make_shared<Learning::CameraComponent>(genereicVideoRenderer, Base::SceneObjectComponent::wptr{}, "FreeCamera");
    soCamera->SetRootComponent(baseCamera);
    soCamera->Transform().position = Math3D::Position(3.f, 0.f, 0.f);
    soCamera->Init();

	  AddObject(soCamera);

	  inputController->SetPawn(soCamera);
  }
}
