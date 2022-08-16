#ifndef __RENDER_FACILITY_HPP__
#define __RENDER_FACILITY_HPP__
namespace Engine
{
	/**
	* @brief This class is responsible for camera switching. Each camera object
	*		 within scene tree must register in the object of this class.
	*/
	class RenderFacility : public Base::RenderFacility
	{
	public:
		using sptr = std::shared_ptr<RenderFacility>;
		using wptr = std::weak_ptr<RenderFacility>;

		RenderFacility(const Base::Settings& settings, const std::string& name = "renderer");

		void Draw(const std::vector<Base::SceneObject::sptr>& sceneTree_) override;
	};
}
#endif // __RENDER_FACILITY_HPP__