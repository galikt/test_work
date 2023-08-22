#include "messenger.h"
#include "meta_object.h"
#include "object.h"

TWMessenger::TWMessenger()
{
	TWObjectBase::SetMessanger(this);
}

void TWMessenger::SendMsg(std::unique_ptr<TWMessage>&& msg)
{
	MessageList.push_back(std::move(msg));
}

void TWMessenger::CleanMessages()
{
	MessageList.clear();
}

void TWMessenger::ReceiveBuffer(uint32_t id, std::unique_ptr<TWBuffer>&& buf)
{
	TWSerialization obj;
	obj.Deserialize(buf->GetStream());

	auto msg = TWMetaObject::CreateMessage(obj.Type);
	msg->Deserialize(buf->GetStream());

	SendMsg(std::move(msg));
}

void TWMessenger::ProcessingMsg()
{
	std::list<std::unique_ptr<TWMessage>> message_list;
	std::swap(message_list, MessageList);

	for (auto& msg : message_list)
	{
		auto obj_iter = ObjectMap.find(msg->Receiver);
		if (obj_iter == ObjectMap.end())
			continue;
		
		obj_iter->second->ProcessingMsg(std::move(msg));
	}

	message_list.clear();
}
