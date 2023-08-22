#include "object_container.h"
#include "object_container.h"

std::shared_ptr<TWObjectBase> TWObjectContainer::FindObject(ObjectType type)
{
	for (auto& pair : ObjectMap)
	{
		if (pair.second->Type == type)
		{
			return pair.second;
		}
	}

	return std::shared_ptr<TWObjectBase>();
}

void TWObjectContainer::RegisterObject(std::shared_ptr<TWObjectBase> obj)
{
	ObjectMap.insert(std::make_pair(obj->Id, obj));
}
