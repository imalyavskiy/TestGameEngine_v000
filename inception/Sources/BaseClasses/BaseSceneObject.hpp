#ifndef __SCENE_OBJECT_H__
#define __SCENE_OBJECT_H__
namespace Base {
	class SceneObject : public Object, public Updatable, public Drawable
	{
	public:
		using ptr = std::shared_ptr<SceneObject>;

		explicit SceneObject(const std::string name);

		void SetRootComponent(SceneObjectComponent::ptr p);

		SceneObjectComponent::ptr GetRootComponent();

	private:
		SceneObjectComponent::ptr root_;
	};
}
#endif // __SCENE_OBJECT_H__