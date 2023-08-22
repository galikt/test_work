#pragma once

#include "../core/core.h"

class TWClient : public TWPlatformClientBase
{
public:
	TWClient();
	virtual ~TWClient() = default;
	
	void Run() override;

};
