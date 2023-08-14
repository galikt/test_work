#include "table.h"

void Table::InsertColumn(COLUMN column)
{
	ColumnList.push_back(std::move(column));
}
