#include <pch.hpp>
#include <BaseClasses/BaseClasses.hpp>
namespace Learning
{
	class SceneObject : public BaseSceneObject
	{
	public:
		SceneObject(const std::string& name);

		void Update(float dt) override;

		void Draw() override;
	};
}