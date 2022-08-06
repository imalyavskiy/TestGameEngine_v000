#ifndef __BASE_OBJECT_HPP__
#define __BASE_OBJECT_HPP__

class BaseObject
{
public:
	using ptr = std::shared_ptr<BaseObject>;

	BaseObject(const std::string& name);

	const std::string& GetName() const;

private:
	const std::string name_;

};

#endif // __BASE_OBJECT_HPP__

