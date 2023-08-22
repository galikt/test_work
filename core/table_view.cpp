#include "table_view.h"
#include "table_view.h"

TWTableView::TWTableView() :
	TWObjectBase(ObjectType::OBJ_TABLE_VIEW)
{
}

void TWTableView::SetTable(std::shared_ptr<TWObjectBase> obj)
{
	Table = obj;
}
