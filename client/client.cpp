#include "client.h"
#include <iostream>

TWClient::TWClient()
{
}

void TWClient::Run()
{
	std::shared_ptr<TWObjectBase> table;
	std::shared_ptr<TWObjectBase> table_view;
	while (true)
	{
		Sleep(1000);

		if (table == false)
		{
			auto obj = FindObject(ObjectType::OBJ_TABLE);
			if (obj)
			{
				table = obj;
				table_view = TWMetaObject::CreateObject(ObjectType::OBJ_TABLE_VIEW);
				dynamic_cast<TWTableView*>(table_view.get())->SetTable(table);


				auto table_ptr = static_cast<TWTable*>(table.get());

				std::cout << "Table id = " << table_ptr->Id << std::endl;
				for (auto& column : table_ptr->ColumnList)
				{

					std::cout << "Column name = " << column->Head << std::endl;
				}
			}
		}
	}
}

int main()
{
	auto client = std::make_unique<TWClient>();
	client->Run();

	return 0;
}
