#pragma once

#include <memory>

class TWObjectBase;
class TWMessage;
class TWColumnBase;
enum class ObjectType;

class TWMetaObject
{
public:
	TWMetaObject() = default;
	~TWMetaObject() = default;

	static std::shared_ptr<TWObjectBase> CreateObject(ObjectType type);
	static std::unique_ptr<TWMessage> CreateMessage(ObjectType type);
	static std::unique_ptr<TWColumnBase> CreateColumn(ObjectType type);
};