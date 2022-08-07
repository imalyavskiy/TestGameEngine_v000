#ifndef __BASE_SCENE_HPP__
#define __BASE_SCENE_HPP__
namespace Base {
	class Scene : public Object, public Updatable, public Drawable
	{
	public:
		using ptr = std::shared_ptr<Scene>;

		explicit Scene(const std::string& name);

		void AddObject(SceneObject::ptr sceneObject);

	protected:
		std::vector<SceneObject::ptr> objects_;
	};
}
#endif // __BASE_SCENE_HPP__