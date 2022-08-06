#pragma once
class BaseSceneObjectComponent : public BaseObject, public Updatable, public Drawable
{
public: 
	using ptr = std::shared_ptr<BaseSceneObjectComponent>;
	using ChildList = std::vector<BaseSceneObjectComponent::ptr>;

	explicit BaseSceneObjectComponent(const std::string& name);

	void AddChild(ptr child);

	ChildList& GetChildList();

	void Update(float dt) override;

	void Draw() override;

private:
	ChildList childList_;
};

