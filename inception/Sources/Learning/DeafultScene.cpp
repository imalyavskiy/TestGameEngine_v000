#include <pch.hpp>
#include <BaseClasses/BaseClasses.hpp>
#include "Learning.hpp"

namespace Learning
{
	DefaultScene::DefaultScene(const std::string& name)
		: BaseScene(name)
	{
	}

	void DefaultScene::Update(float dt)
	{
		for (auto sceneObject : objects_)
			sceneObject->Update(dt);
	}

	void DefaultScene::Draw()
	{
		for (auto sceneObject : objects_)
			sceneObject->Draw();
	}
}
