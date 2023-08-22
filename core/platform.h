#pragma once

#include <list>
#include <memory>

class TWPlatform
{
public:
	TWPlatform() = default;
	virtual ~TWPlatform() = default;
	virtual void Run() = 0;
};
