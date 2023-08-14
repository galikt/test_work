#pragma one

#include <list>
#include <memory>
#include "column.h"

class Table
{
public:
	Table() = default;
	~Table() = default;

	void InsertColumn(COLUMN column);

protected:
	std::list<COLUMN> ColumnList;
};