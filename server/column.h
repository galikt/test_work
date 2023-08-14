#pragma once

#include <memory>
#include <string>

class ColumnBase;
using COLUMN = std::unique_ptr<ColumnBase>;

class ColumnBase
{
public:
	ColumnBase(std::string& label);
	virtual ~ColumnBase() = default;

protected:
	std::string Head;
};

template <typename T>
class Column : public ColumnBase
{
public:
	Column(std::string& label);
	virtual ~Column() = default;

protected:
	T Data;
};

template<typename T>
inline Column<T>::Column(std::string& label) :
	ColumnBase(label)
{
}
