#pragma once

#include "../core/core.h"
#include "monkey.h"

class TWServer : public TWPlatformServerBase
{
public:
	TWServer();
	virtual ~TWServer() = default;
	virtual void Run() override;

protected:
	TWMonkey Monkey;
};
