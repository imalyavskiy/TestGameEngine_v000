#include <pch.hpp>
#include "BaseObject.hpp"
namespace Base {
	Object::Object(const std::string& name)
		: name_(name)
	{
	}

	const std::string& Object::GetName() const
	{
		return name_;
	}
}
