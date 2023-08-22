#pragma once

#include "message.h"
#include <stdint.h>
#include "memory"
#include "serialization.h"

class TWMessenger;

class TWObjectBase : public TWSerialization
{
public:
	uint32_t Parent{ 0 };
	uint32_t Id{ 0 };
	bool Replica{ false };

	TWObjectBase(ObjectType type = ObjectType::NONE);
	~TWObjectBase() = default;

	void SendMsg(std::unique_ptr<TWMessage>&& msg);
	virtual void ProcessingMsg(std::unique_ptr<TWMessage>&& msg);

	static void SetMessanger(TWMessenger* messanger);

	virtual void Serialize(std::iostream& stream) override;
	virtual void Deserialize(std::iostream& stream) override;

protected:
	static uint32_t CounterId;
	static TWMessenger* Messanger;
};