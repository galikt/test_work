#pragma once

#include "platform.h"
#include "gate.h"
#include "replication.h"

class TWPlatformClientBase : public TWPlatform, public TWGateClient, public TWReplicationClient
{
public:
	TWPlatformClientBase() = default;
	virtual ~TWPlatformClientBase() = default;
	//virtual void Init() override;

protected:
	//TWGateClient* Gate{ nullptr };
	//TWReplicationClient* Replication{ nullptr };
};