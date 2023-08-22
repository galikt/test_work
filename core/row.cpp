#include "row.h"

TWRow::TWRow(size_t size) :
	TWObjectBase(ObjectType::OBJ_ROW)
{
	Data.resize(size);
}

void TWRow::Serialize(std::iostream& stream)
{
	TWObjectBase::Serialize(stream);

	size_t size = Data.size();
	stream.write(reinterpret_cast<char*>(size), sizeof(size));
	stream.write(reinterpret_cast<char*>(Data.data()), size);
}

void TWRow::Deserialize(std::iostream& stream)
{
	TWObjectBase::Deserialize(stream);

	size_t size{ 0 };
	stream.read(reinterpret_cast<char*>(size), sizeof(size));

	Data.resize(size);
	stream.write(reinterpret_cast<char*>(Data.data()), size);
}
