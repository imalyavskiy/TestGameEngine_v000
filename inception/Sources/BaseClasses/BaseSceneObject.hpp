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
		virtual void Draw(Generic::VideoRenderer& renderer);

		/**
		 * @todo describe this
		 */
		virtual void Init();

		/**
		 * @todo describe this
		 */
		virtual void JoinScene();

	private:
		/**
		 * @todo describe this
		 */
		SceneObjectComponent::sptr root_;
	};
}
#endif // __SCENE_OBJECT_H__