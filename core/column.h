#pragma once

#include <memory>
#include <string>
#include "string.h"
#include "serialization.h"
#include "row.h"

class TWColumnBase : public TWSerialization
{
public:
	TWColumnBase(ObjectType type = ObjectType::NONE, std::string label = std::string());
	virtual ~TWColumnBase() = default;

	virtual void Serialize(std::iostream& stream);
	virtual void Deserialize(std::iostream& stream);

	virtual size_t GetDataSize();
	virtual std::string GetData(std::shared_ptr<TWRow>& row);

	TWString Head;
	size_t Offset{ 0 };
};

template<typename DataType>
class TWColumn : public TWColumnBase
{
public:
	TWColumn(std::string label, DataType data);
	virtual ~TWColumn() = default;

	virtual void Serialize(std::iostream& stream);
	virtual void Deserialize(std::iostream& stream);

	virtual size_t GetDataSize() override;
	virtual std::string GetData(std::shared_ptr<TWRow>& row) override;

	DataType Data;
};
