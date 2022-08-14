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

		Math3D::Matrix4f GetWorldTransformMatrix() const;

        Math3D::Matrix4f GetWorldTransformMatrix(const Math3D::Matrix4f& local) const;

        Math3D::Direction GetForwardVector() const;

        Math3D::Direction GetBackwardVector() const;

        Math3D::Direction GetUpVector() const;

        Math3D::Direction GetDownVector() const;

        Math3D::Direction GetRightVector() const;

        Math3D::Direction GetLeftVector() const;

        /**
		 * @brief Called when object being added to a scene.
		 */
		virtual void OnAddToScene();

	private:
		wptr parent_;

		Math3D::Transform transform_;

		ChildList childList_;
	};
}
#endif // __BASE_SCENE_OBJECT_COMPONENT_HPP__