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

		~SceneObjectComponent() override;

        void AddChild(sptr child);

		ChildList& GetChildList();

		virtual void Update(float dt);

		virtual void Draw(Generic::VideoRenderer& renderer);

		virtual void Init();

		Math3D::Matrix4f GetWorldTransformMatrix() const;

        Math3D::Matrix4f GetWorldTransformMatrix(const Math3D::Matrix4f& local) const;

        Math3D::Direction GetWorldForwardVector() const;

        Math3D::Direction GetWorldBackwardVector() const;

        Math3D::Direction GetWorldUpVector() const;

        Math3D::Direction GetWorldDownVector() const;

        Math3D::Direction GetWorldRightVector() const;

        Math3D::Direction GetWorldLeftVector() const;

		Math3D::Position GetWorldPosition() const;

	private:
		wptr parent_;

		Math3D::Transform transform_;

		ChildList childList_;
	};
}
#endif // __BASE_SCENE_OBJECT_COMPONENT_HPP__