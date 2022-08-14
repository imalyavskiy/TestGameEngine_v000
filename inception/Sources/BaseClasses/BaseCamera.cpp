#include <pch.hpp>
#include <Math3D/Math3D.hpp>
#include <Utilities/Utilities.hpp>
#include "BaseClasses.hpp"

namespace Base
{
	Camera::Camera(SceneObjectComponent::wptr parent, const std::string& name)
	    : SceneObjectComponent(parent, name)
    {
	}
}
