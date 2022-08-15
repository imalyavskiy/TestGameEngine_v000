#ifndef __BASE_OBJECT_HPP__
#define __BASE_OBJECT_HPP__
namespace Base {
	class Object
	{
	public:
		using sptr = std::shared_ptr<Object>;

		Object(const std::string& name);

		virtual ~Object() = default;

		const std::string& GetName() const;

	private:
		const std::string name_;

	};
}
#endif // __BASE_OBJECT_HPP__

