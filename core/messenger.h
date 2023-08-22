#pragma once

#include <memory>
#include <list>
#include "object_container.h"
#include "gate.h"
#include "message.h"

class TWMessenger : virtual public TWGate, public TWObjectContainer
{
public:
	TWMessenger();
	virtual ~TWMessenger() = default;

	void SendMsg(std::unique_ptr<TWMessage>&& msg);
	virtual void ReceiveBuffer(uint32_t id, std::unique_ptr<TWBuffer>&& buf) override;

protected:
	void CleanMessages();
	virtual void ProcessingMsg();
	std::list<std::unique_ptr<TWMessage>> MessageList;
};