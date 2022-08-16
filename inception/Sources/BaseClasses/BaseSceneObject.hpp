#ifndef __SCENE_OBJECT_H__
#define __SCENE_OBJECT_H__
namespace Base {
	/**
	 * @todo describe this
	 */
	class SceneObject : public Object
	{
	public:
		/**
		 * @todo describe this
		 */
		using sptr = std::shared_ptr<SceneObject>;

		/**
		 * @todo describe this
		 */
		explicit SceneObject(const std::string name);

		/**
		 * @todo describe this
		 */
		void SetRootComponent(SceneObjectComponent::sptr p);

		/**
		 * @todo describe this
		 */
		SceneObjectComponent::sptr GetRootComponent();

		/**
		 * @todo describe this
		 */
		virtual void Update(float dt);

		/**
		 * @todo describe this
		 */
		virtual void Draw(const Math3D::Matrix4f& matViewProjection);

		/**
		 * @todo describe this
		 */
		virtual void Init();

		/**
		 * @todo describe this
		 */
		virtual void JoinScene();

		/**
		 * @todo describe this
		 */
		void Transform(const Math3D::Transform& transform);

		/**
		 * @todo describe this
		 */
		[[nodiscard]]
		const Math3D::Transform& Transform() const;

		/**
		 * @todo describe this
		 */
		[[nodiscard]]
		Math3D::Transform& Transform();

	protected:
    /**
    * @todo describe this
    */
		SceneObjectComponent::sptr root_;

    /**
    * @brief This transform structure is a stub object in used in case if no
    * root component is set otherwise transform of the root component is used.
    */
		Math3D::Transform transform_;

	};
}
#endif // __SCENE_OBJECT_H__