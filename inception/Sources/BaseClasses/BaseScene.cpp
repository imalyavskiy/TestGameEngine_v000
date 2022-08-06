#include <pch.hpp>
#include "BaseClasses.hpp"
#include "BaseScene.hpp"

BaseScene::BaseScene(const std::string& name)
	: BaseObject(name)
{
}

void BaseScene::AddObject(BaseSceneObject::ptr sceneObject)
{
	objects_.push_back(sceneObject);
}
