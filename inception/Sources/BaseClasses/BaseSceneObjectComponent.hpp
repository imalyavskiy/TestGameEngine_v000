#ifndef __BASE_SCENE_OBJECT_COMPONENT_HPP__
#define __BASE_SCENE_OBJECT_COMPONENT_HPP__ 
namespace Base {
	class SceneObjectComponent : public Object, public Updatable, public Drawable
	{
	public:
		using ptr = std::shared_ptr<SceneObjectComponent>;
		using ChildList = std::vector<SceneObjectComponent::ptr>;

		explicit SceneObjectComponent(const std::string& name);

		void AddChild(ptr child);

		ChildList& GetChildList();

		void Update(float dt) override;

		void Draw() override;

	private:
		ChildList childList_;
	};
}
#endif // __BASE_SCENE_OBJECT_COMPONENT_HPP__