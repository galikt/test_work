#include "column.h"

TWColumnBase::TWColumnBase(ObjectType type, std::string label) :
	TWSerialization(type), Head(label)
{
}

void TWColumnBase::Serialize(std::iostream& stream)
{
	TWSerialization::Serialize(stream);

	Head.Serialize(stream);

	stream.write(reinterpret_cast<char*>(&Offset), sizeof(Offset));
}

void TWColumnBase::Deserialize(std::iostream& stream)
{
	TWSerialization::Deserialize(stream);

	Head.Deserialize(stream);

	stream.read(reinterpret_cast<char*>(&Offset), sizeof(Offset));
}

size_t TWColumnBase::GetDataSize()
{
	return 0;
}

std::string TWColumnBase::GetData(std::shared_ptr<TWRow>& row)
{
	return std::string();
}

template<typename DataType>
TWColumn<DataType>::TWColumn(std::string label, DataType data) :
	TWColumnBase(ObjectType::OBJ_COLUMN, label), Data(data)
{
}

template<typename DataType>
void TWColumn<DataType>::Serialize(std::iostream& stream)
{
	TWColumnBase::Serialize(stream);
	stream.write(reinterpret_cast<char*>(&Data), sizeof(Data));
}

template<typename DataType>
void TWColumn<DataType>::Deserialize(std::iostream& stream)
{
	TWColumnBase::Deserialize(stream);
	stream.read(reinterpret_cast<char*>(&Data), sizeof(Data));
}

template<typename DataType>
size_t TWColumn<DataType>::GetDataSize()
{
	return sizeof(Data);
}

template<typename DataType>
std::string TWColumn<DataType>::GetData(std::shared_ptr<TWRow>& row)
{
	//return std::to_string(Data);
	return std::string();
}

template<>
TWColumn<TWString>::TWColumn(std::string label, TWString data) :
	TWColumnBase(ObjectType::OBJ_COLUMN_STRING, label), Data(data)
{
}

template<>
TWColumn<int32_t>::TWColumn(std::string label, int32_t data) :
	TWColumnBase(ObjectType::OBJ_COLUMN_INT, label), Data(data)
{
}

template<>
TWColumn<bool>::TWColumn(std::string label, bool data) :
	TWColumnBase(ObjectType::OBJ_COLUMN_BOOL, label), Data(data)
{
}

template<>
void TWColumn<TWString>::Serialize(std::iostream& stream)
{
	TWColumnBase::Serialize(stream);
	Data.Serialize(stream);
}

template<>
void TWColumn<TWString>::Deserialize(std::iostream& stream)
{
	TWColumnBase::Deserialize(stream);
	Data.Deserialize(stream);
}

template<>
size_t TWColumn<TWString>::GetDataSize()
{
	return Data.length();
}

template<>
std::string TWColumn<TWString>::GetData(std::shared_ptr<TWRow>& row)
{
	return Data;
}

//template<>
//std::string TWColumn<bool>::GetData()
//{
//	return Data == true ? "True" : "False";
//}
