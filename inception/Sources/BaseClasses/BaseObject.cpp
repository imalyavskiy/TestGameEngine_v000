#include <pch.hpp>
#include "BaseObject.hpp"

BaseObject::BaseObject(const std::string& name)
	: name_(name)
{
}

const std::string& BaseObject::GetName() const
{
	return name_;
}
