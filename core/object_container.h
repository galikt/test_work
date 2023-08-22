#pragma once

#include "object.h"
#include <memory>
#include <map>

class TWObjectContainer
{
public:
	TWObjectContainer() = default;
	virtual ~TWObjectContainer() = default;

	virtual void RegisterObject(std::shared_ptr<TWObjectBase> obj);
	std::shared_ptr<TWObjectBase> FindObject(ObjectType type);

protected:
	std::map<uint32_t, std::shared_ptr<TWObjectBase>> ObjectMap;
};
