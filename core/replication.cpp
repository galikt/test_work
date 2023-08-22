#include "replication.h"
#include <memory>
#include "message.h"
#include "meta_object.h"

void TWReplication::ReceiveBuffer(uint32_t id, std::unique_ptr<TWBuffer>&& buf)
{
	auto stream = buf->GetStream();
	TWSerialization head;

	head.Deserialize(buf->GetStream());
	stream.seekg(-sizeof(head.Type), std::ios::cur);

	if (head.Type != ObjectType::MSG_REPLICATION)
	{
		TWMessenger::ReceiveBuffer(id, std::move(buf));
		return;
	}

	auto msg = TWMetaObject::CreateMessage(head.Type);
	msg->Deserialize(stream);

	TWSerialization head_obj;
	
	head_obj.Deserialize(stream);
	stream.seekg(-sizeof(head_obj.Type), std::ios::cur);

	auto obj = TWMetaObject::CreateObject(head_obj.Type);
	obj->Deserialize(stream);

	RegisterObject(obj);
}

void TWReplicationServer::ProcessingReplication()
{

}

void TWReplicationServer::Connected(uint32_t id)
{
	for (auto& obj : ObjectMap)
	{
		auto msg = std::make_unique<MsgReplication>(obj.second);
		msg->Object = obj.second;

		auto buf = std::make_unique<TWBuffer>();
		msg->Serialize(buf->GetStream());

		TransmitBuffer(id, std::move(buf));
	}
}

void TWReplicationClient::ProcessingReplication()
{

}

void TWReplicationClient::Connected(uint32_t id)
{

}

void TWReplicationClient::RegisterObject(std::shared_ptr<TWObjectBase> obj)
{
	obj->Replica = true;
	TWReplication::RegisterObject(obj);

}