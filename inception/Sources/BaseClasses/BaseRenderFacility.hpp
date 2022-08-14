#ifndef __BASE_RENDER_FACIITY_HPP__
#define __BASE_RENDER_FACIITY_HPP__
namespace Base
{
	class RenderFacility : public Object
	{
	public:
		using ptr = std::shared_ptr<RenderFacility>;

		RenderFacility(const std::string& name);

		void Draw(const std::vector<SceneObject::sptr>& objects);
	};

}
#endif // __BASE_RENDER_FACIITY_HPP__