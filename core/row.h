#pragma once

#include "object.h"
#include <vector>

class TWRow : public TWObjectBase
{
public:
	TWRow(size_t size = 0);
	~TWRow() = default;

	virtual void Serialize(std::iostream& stream);
	virtual void Deserialize(std::iostream& stream);

	std::vector<char> Data;
};