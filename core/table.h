#pragma once

#include <list>
#include <map>
#include <memory>
#include "object.h"
#include "column.h"
#include "row.h"

class TWTable : public TWObjectBase
{
public:
	TWTable();
	virtual ~TWTable() = default;

	void InsertColumn(std::unique_ptr<TWColumnBase> column);
	void InsertRow(std::shared_ptr<TWRow> row);

	virtual void Serialize(std::iostream& stream) override;
	virtual void Deserialize(std::iostream& stream) override;

//protected:
	size_t SizeRow{ 0 };
	size_t Offset{ 0 };
	std::list<std::unique_ptr<TWColumnBase>> ColumnList;

	std::map<uint32_t, std::shared_ptr<TWRow>> RowMap;
	std::map<uint32_t, std::shared_ptr<TWRow>> SortedMap;
};
