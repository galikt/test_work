#pragma once

#include <string>
#include "serialization.h"

class TWString : public std::string, public TWSerialization
{
public:
	TWString(std::string str = std::string());
	~TWString() = default;

	virtual void Serialize(std::iostream& stream) override;
	virtual void Deserialize(std::iostream& stream) override;
};