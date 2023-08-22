#include "string.h"

TWString::TWString(std::string str) :
	TWSerialization(ObjectType::OBJ_STRING), std::string(str)
{
}

void TWString::Serialize(std::iostream& stream)
{
	size_t size_str = length();

	stream.write(reinterpret_cast<char*>(&size_str), sizeof(size_str));
	stream.write(data(), size_str);
}

void TWString::Deserialize(std::iostream& stream)
{
	size_t size_str{ 0 };
	stream.read(reinterpret_cast<char*>(&size_str), sizeof(size_str));

	std::vector<char> arr(size_str);
	stream.read(arr.data(), size_str);

	append(arr.data(), size_str);
}
