#ifndef __BASE_CAMERA_HPP__
#define __BASE_CAMERA_HPP__
namespace Base
{
	class Camera : public SceneObjectComponent
    {
	public:
		Camera(SceneObjectComponent::wptr parent, const std::string& name);
	};
}
#endif // __BASE_CAMERA_HPP__