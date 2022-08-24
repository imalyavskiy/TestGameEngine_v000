namespace Learning
{
	class RotatingObject : public Base::SceneObject
	{
	public:
		RotatingObject(const std::string& name);

		void Update(float dt) override;

	protected:
//		const Math3D::Rotation rotationSpeed_ = { 5.f, 5.f, 5.f };
		const Math3D::Rotation rotationSpeed_ = { 0.f, 0.f, 0.f };
	};

}