// test_work.cpp : Defines the entry point for the application.
//

#include "server.h"
#include "table.h"
#include "column.h"
#include <stdint.h>
#include <memory>
#include <string>

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");

	auto table = std::make_unique<Table>();

	auto first_name = std::make_unique<Column<std::string>>(std::string("Имя"));
	table->InsertColumn(std::move(first_name));

	auto last_name = std::make_unique<Column<std::string>>(std::string("Фамилия"));
	table->InsertColumn(std::move(last_name));

	auto age = std::make_unique<Column<uint8_t>>(std::string("Возраст"));
	table->InsertColumn(std::move(age));

	auto online = std::make_unique<Column<bool>>(std::string("В сети"));
	table->InsertColumn(std::move(online));

	return 0;
}
