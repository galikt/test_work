#include "serialization.h"

TWSerialization::TWSerialization(ObjectType type) :
	Type(type)
{
}

void TWSerialization::Serialize(std::iostream& stream)
{
	stream.write(reinterpret_cast<char*>(&Type), sizeof(Type));
}

void TWSerialization::Deserialize(std::iostream& stream)
{
	stream.read(reinterpret_cast<char*>(&Type), sizeof(Type));
}
