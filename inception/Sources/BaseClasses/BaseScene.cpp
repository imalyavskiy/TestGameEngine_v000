#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include "BaseClasses.hpp"

namespace Base {
	Scene::Scene(const std::string& name)
		: Object(name)
	{
	}

	void Scene::AddObject(SceneObject::sptr sceneObject)
	{
		objectTree_.push_back(sceneObject);
	}

    void Scene::Update(float dt)
    {
        for (const auto& object : objectTree_)
            object->Update(dt);
    }

    const Scene::ObjectTree& Scene::GetObjectTree() const
    {
        return objectTree_;
    }
}
