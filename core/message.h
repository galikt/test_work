#pragma once

#include <stdint.h>
#include <memory>
#include "serialization.h"

class TWObjectBase;

class TWMessage : public TWSerialization
{
public:
	TWMessage(ObjectType type = ObjectType::NONE);
	virtual ~TWMessage() = default;

	uint32_t Receiver{ 0 };
	uint32_t Sender{ 0 };

	virtual void Serialize(std::iostream& stream) override;
	virtual void Deserialize(std::iostream& stream) override;
};

class MsgReplication : public TWMessage
{
public:
	MsgReplication(std::shared_ptr<TWSerialization> obj = nullptr);
	virtual ~MsgReplication() = default;

	std::shared_ptr<TWSerialization> Object;

	virtual void Serialize(std::iostream& stream) override;
	virtual void Deserialize(std::iostream& stream) override;
};

class MsgReplicationNeedData : public TWMessage
{
public:
	MsgReplicationNeedData(uint32_t id = 0);
	virtual ~MsgReplicationNeedData() = default;

	uint32_t Id;

	virtual void Serialize(std::iostream& stream) override;
	virtual void Deserialize(std::iostream& stream) override;
};