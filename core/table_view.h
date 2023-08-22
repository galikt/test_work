#pragma once

#include "object.h"

class TWTableView : public TWObjectBase
{
public:
	TWTableView();
	~TWTableView() = default;

	void SetTable(std::shared_ptr<TWObjectBase> obj);

protected:
	std::shared_ptr<TWObjectBase> Table{ nullptr };
};
