#pragma once
class BaseScene : public BaseObject, public Updatable, public Drawable
{
public:
	using ptr = std::shared_ptr<BaseScene>;

	explicit BaseScene(const std::string& name);

	void AddObject(BaseSceneObject::ptr sceneObject);

protected:
	std::vector<BaseSceneObject::ptr> objects_;
};

