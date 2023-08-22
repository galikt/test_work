#include "object.h"
#include "messenger.h"

uint32_t TWObjectBase::CounterId { 0 };
TWMessenger* TWObjectBase::Messanger{ nullptr };

TWObjectBase::TWObjectBase(ObjectType type) :
	TWSerialization(type)
{
	++CounterId;
	Id = CounterId;
}

void TWObjectBase::SendMsg(std::unique_ptr<TWMessage>&& msg)
{
	Messanger->SendMsg(std::move(msg));
}

void TWObjectBase::ProcessingMsg(std::unique_ptr<TWMessage>&& msg)
{

}

void TWObjectBase::SetMessanger(TWMessenger* messanger)
{
	Messanger = messanger;
}

void TWObjectBase::Serialize(std::iostream& stream)
{
	TWSerialization::Serialize(stream);
	stream.write(reinterpret_cast<char*>(&Id), sizeof(Id));
	stream.write(reinterpret_cast<char*>(&Parent), sizeof(Parent));
}

void TWObjectBase::Deserialize(std::iostream& stream)
{
	TWSerialization::Deserialize(stream);
	stream.read(reinterpret_cast<char*>(&Id), sizeof(Id));
	stream.read(reinterpret_cast<char*>(&Parent), sizeof(Parent));
}
