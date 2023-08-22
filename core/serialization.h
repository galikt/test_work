#pragma once

#include <iostream>
#include "buffer.h"

enum class ObjectType
{
	NONE,
	MSG_REPLICATION,
	MSG_REPLICATION_NEED_DATA,
	OBJ_TABLE,
	OBJ_TABLE_VIEW,
	OBJ_STRING,
	OBJ_ROW,
	OBJ_COLUMN,
	OBJ_COLUMN_STRING,
	OBJ_COLUMN_INT,
	OBJ_COLUMN_BOOL
};

class TWSerialization
{
public:
	ObjectType Type{ ObjectType::NONE };

	TWSerialization(ObjectType type = ObjectType::NONE);
	virtual ~TWSerialization() = default;

	virtual void Serialize(std::iostream& stream);
	virtual void Deserialize(std::iostream& stream);
};