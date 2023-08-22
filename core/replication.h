#pragma once

#include "messenger.h"

class TWReplication : public TWMessenger
{
public:
	TWReplication() = default;
	virtual ~TWReplication() = default;

	virtual void ReceiveBuffer(uint32_t id, std::unique_ptr<TWBuffer>&& buf) override;
	virtual void ProcessingReplication() = 0;
};

class TWReplicationServer : public TWReplication
{
public:
	TWReplicationServer() = default;
	virtual ~TWReplicationServer() = default;

	virtual void ProcessingReplication() override;
	virtual void Connected(uint32_t id) override;
};

class TWReplicationClient : public TWReplication
{
public:
	TWReplicationClient() = default;
	virtual ~TWReplicationClient() = default;

	virtual void ProcessingReplication() override;
	virtual void Connected(uint32_t id) override;
	virtual void RegisterObject(std::shared_ptr<TWObjectBase> obj) override;

};