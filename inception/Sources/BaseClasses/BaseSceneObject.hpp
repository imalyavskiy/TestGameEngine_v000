#ifndef __SCENE_OBJECT_H__
#define __SCENE_OBJECT_H__
class BaseSceneObject : public BaseObject, public Updatable, public Drawable
{
public:
	using ptr = std::shared_ptr<BaseSceneObject>;

	explicit BaseSceneObject(const std::string name);

	void SetRootComponent(BaseSceneObjectComponent::ptr p);

	BaseSceneObjectComponent::ptr GetRootComponent();

private:
	BaseSceneObjectComponent::ptr root_;
};
#endif // __SCENE_OBJECT_H__