#include <pch.hpp>
#include <BaseClasses/BaseClasses.hpp>
namespace Learning
{
	class DotSceneObject : public BaseSceneObject
	{
	public:
		DotSceneObject(const std::string& name);

		void Update(float dt) override;

		void Draw() override;
	};
}