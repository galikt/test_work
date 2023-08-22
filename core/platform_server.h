#pragma once

#include "platform.h"
#include "gate.h"
#include "replication.h"

class TWPlatformServerBase : public TWPlatform, public TWGateServer, public TWReplicationServer
{
public:
	TWPlatformServerBase() = default;
	virtual ~TWPlatformServerBase() = default;
};
