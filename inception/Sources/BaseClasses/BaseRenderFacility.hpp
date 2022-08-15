#ifndef __BASE_RENDER_FACIITY_HPP__
#define __BASE_RENDER_FACIITY_HPP__
namespace Base
{
    class RenderFacility : public Object, public Generic::VideoRenderer
    {
    public:
        using sptr = std::shared_ptr<RenderFacility>;

        RenderFacility(const std::string& name);

        virtual void Draw(const std::vector<SceneObject::sptr>& objectsList);

        bool AddCamera(Generic::Camera& camera) override;

        bool RemoveCamera(Generic::Camera& camera) override;
    protected:
        std::set<Generic::Camera*> cameraList_;
    };

}
#endif // __BASE_RENDER_FACIITY_HPP__