#include "meta_object.h"
#include "column.h"
#include "message.h"
#include "object.h"
#include "table.h"
#include "table_view.h"
#include "row.h"

std::shared_ptr<TWObjectBase> TWMetaObject::CreateObject(ObjectType type)
{
	std::shared_ptr<TWObjectBase> obj;

	switch (type)
	{
	case ObjectType::OBJ_TABLE:
		obj = std::make_shared<TWTable>();
		break;

	case ObjectType::OBJ_ROW:
		obj = std::make_shared<TWRow>();
		break;

	case ObjectType::OBJ_TABLE_VIEW:
		obj = std::make_shared<TWTableView>();
		break;

	//case ObjectType::OBJ_STRING:
	//	obj = std::make_shared<TWString>();
	//	break;

	default:
		obj = std::make_shared<TWObjectBase>();
		break;
	}

	return obj;
}

std::unique_ptr<TWMessage> TWMetaObject::CreateMessage(ObjectType type)
{
	std::unique_ptr<TWMessage> obj;

	switch (type)
	{
	case ObjectType::MSG_REPLICATION:
		obj = std::make_unique<MsgReplication>();
		break;
	default:
		obj = std::make_unique<TWMessage>();
		break;
	}

	return obj;
}

std::unique_ptr<TWColumnBase> TWMetaObject::CreateColumn(ObjectType type)
{
	std::unique_ptr<TWColumnBase> obj;

	switch (type)
	{
	case ObjectType::OBJ_COLUMN_BOOL:
			obj = std::make_unique<TWColumn<bool>>("", false);
		break;

		case ObjectType::OBJ_COLUMN_INT:
			obj = std::make_unique<TWColumn<int32_t>>("", 0);
			break;

		case ObjectType::OBJ_COLUMN_STRING:
			obj = std::make_unique<TWColumn<TWString>>("", TWString());
			break;

	default:
		obj = std::make_unique<TWColumnBase>();
		break;
	}

	return obj;
}
