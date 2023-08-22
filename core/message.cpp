#include "message.h"

TWMessage::TWMessage(ObjectType type) :
	TWSerialization(type)
{
}

void TWMessage::Serialize(std::iostream& stream)
{
	TWSerialization::Serialize(stream);
	stream.write(reinterpret_cast<char*>(&Receiver), sizeof(Receiver));
	stream.write(reinterpret_cast<char*>(&Sender), sizeof(Sender));
}

void TWMessage::Deserialize(std::iostream& stream)
{
	TWSerialization::Deserialize(stream);
	stream.read(reinterpret_cast<char*>(&Receiver), sizeof(Receiver));
	stream.read(reinterpret_cast<char*>(&Sender), sizeof(Sender));
}

MsgReplication::MsgReplication(std::shared_ptr<TWSerialization> obj) :
	TWMessage(ObjectType::MSG_REPLICATION), Object(obj)
{
}

void MsgReplication::Serialize(std::iostream& stream)
{
	TWMessage::Serialize(stream);
	Object->Serialize(stream);
}

void MsgReplication::Deserialize(std::iostream& stream)
{
	TWMessage::Deserialize(stream);
	//обьект будет извлечен в модуле репликации
}

MsgReplicationNeedData::MsgReplicationNeedData(uint32_t id) :
	TWMessage(ObjectType::MSG_REPLICATION_NEED_DATA), Id(id)
{
}

void MsgReplicationNeedData::Serialize(std::iostream& stream)
{
	TWMessage::Serialize(stream);
	stream.write(reinterpret_cast<char*>(&Id), sizeof(Id));
}

void MsgReplicationNeedData::Deserialize(std::iostream& stream)
{
	TWMessage::Deserialize(stream);
	stream.read(reinterpret_cast<char*>(&Id), sizeof(Id));
}
