#include <pch.hpp>
#include <Utilities/Utilities.hpp>
#include "BaseClasses.hpp"

namespace Base {
	Scene::Scene(const std::string& name)
		: Object(name)
	{
	}

	void Scene::AddObject(SceneObject::ptr sceneObject)
	{
		objects_.push_back(sceneObject);
	}
}