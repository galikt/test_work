#include "server.h"

TWServer::TWServer()
{
	auto table = std::make_shared<TWTable>();

	auto first_name = TWMetaObject::CreateColumn(ObjectType::OBJ_COLUMN_STRING);
	first_name->Head = std::string("Name");
	table->InsertColumn(std::move(first_name));

	auto last_name = TWMetaObject::CreateColumn(ObjectType::OBJ_COLUMN_STRING);
	last_name->Head = std::string("Last Name");
	table->InsertColumn(std::move(last_name));

	auto age = TWMetaObject::CreateColumn(ObjectType::OBJ_COLUMN_INT);
	age->Head = std::string("age");
	table->InsertColumn(std::move(age));

	auto online = TWMetaObject::CreateColumn(ObjectType::OBJ_COLUMN_BOOL);
	online->Head = std::string("Online");
	table->InsertColumn(std::move(online));

	RegisterObject(table);
}

void TWServer::Run()
{
	while (true)
	{
		Sleep(1000);
	}
}

int main()
{
	auto server = std::make_unique<TWServer>();
	server->Run();

	return 0;
}
