#include "table.h"
#include "meta_object.h"

TWTable::TWTable() :
	TWObjectBase(ObjectType::OBJ_TABLE)
{
}

void TWTable::InsertColumn(std::unique_ptr<TWColumnBase> column)
{
	column->Offset = Offset;
	Offset += column->GetDataSize();

	SizeRow += column->GetDataSize();

	ColumnList.push_back(std::move(column));
}

void TWTable::InsertRow(std::shared_ptr<TWRow> row)
{
	RowMap.insert(std::pair(row->Id, row));
}

void TWTable::Serialize(std::iostream& stream)
{
	TWObjectBase::Serialize(stream);

	stream.write(reinterpret_cast<char*>(&SizeRow), sizeof(SizeRow));

	size_t size = ColumnList.size();
	stream.write(reinterpret_cast<char*>(&size), sizeof(size));
	for (auto& iter : ColumnList)
	{
		iter->Serialize(stream);
	}
}

void TWTable::Deserialize(std::iostream& stream)
{
	TWObjectBase::Deserialize(stream);

	stream.read(reinterpret_cast<char*>(&SizeRow), sizeof(SizeRow));

	size_t size{ 0 };
	stream.read(reinterpret_cast<char*>(&size), sizeof(size));
	for (size_t count = 0; count < size; ++count)
	{
		TWSerialization head;
		head.Deserialize(stream);
		stream.seekg(-sizeof(head.Type), std::ios::cur);

		std::unique_ptr<TWColumnBase> column(TWMetaObject::CreateColumn(head.Type));
		column->Deserialize(stream);

		ColumnList.push_back(std::move(column));
	}
}
