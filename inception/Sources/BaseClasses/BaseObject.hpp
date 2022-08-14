#ifndef __BASE_OBJECT_HPP__
#define __BASE_OBJECT_HPP__
namespace Base {
	class Object : public std::enable_shared_from_this<Object>
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

