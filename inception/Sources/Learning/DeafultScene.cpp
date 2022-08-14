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
}
