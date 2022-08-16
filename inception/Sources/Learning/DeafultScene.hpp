#ifndef __LEARNING_DEAFULT_SCENE_H__
#define __LEARNING_DEAFULT_SCENE_H__
namespace Learning
{
	class DefaultScene final : public Base::Scene
	{
	public:
		explicit DefaultScene(const std::string& name = "DefaultScene");

		void Update(float dt) override;

		bool Load(const Base::RenderFacility::sptr& renderer) override;
	};
}
#endif // __LEARNING_DEAFULT_SCENE_H__