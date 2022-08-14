#ifndef __BASE_SCENE_OBJECT_COMPONENT_HPP__
#define __BASE_SCENE_OBJECT_COMPONENT_HPP__ 
namespace Base {
	class SceneObjectComponent : public Object
	{
	public:
		using sptr = std::shared_ptr<SceneObjectComponent>;
		using wptr = std::weak_ptr<SceneObjectComponent>;
		using ChildList = std::vector<SceneObjectComponent::sptr>;

		explicit SceneObjectComponent(wptr parent, const std::string& name);

		void AddChild(sptr child);

		ChildList& GetChildList();

		virtual void Update(float dt);

		virtual void Draw();

		Math3D::Direction GetForwardVector() const
		{
			return {};
		}

		Math3D::Direction GetBackwardVector() const
		{
			return {};
		}

	    Math3D::Direction GetUpVector() const
		{
			return {};
		}

	    Math3D::Direction GetDownVector() const
		{
			return {};
		}

	    Math3D::Direction GetRightVector() const
		{
			return {};
		}

	    Math3D::Direction GetLeftVector() const
		{
			return {};
		}

	private:
		wptr parent_;

		Math3D::Transform transform_;

		ChildList childList_;
	};
}
#endif // __BASE_SCENE_OBJECT_COMPONENT_HPP__