namespace Learning
{
	class SceneObject : public Base::SceneObject
	{
	public:
		SceneObject(const std::string& name);

		void Update(float dt) override;

		void Draw() override;
	};
}