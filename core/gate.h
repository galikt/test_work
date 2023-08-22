#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <map>
#include <memory>
#include <thread>
#include "wrapper.h"
#include "buffer.h"

struct TWClientContext
{
	uint32_t Id{ 0 };
	std::shared_ptr<TWSocket> Socket{ nullptr };
};

class TWGate
{
public:
	TWGate() = default;
	virtual ~TWGate() = default;

	virtual void DeInit() = 0;

	virtual void TransmitBuffer(uint32_t id, std::unique_ptr<TWBuffer>&& buf);
	virtual void ReceiveBuffer(uint32_t id, std::unique_ptr<TWBuffer>&& buf);
	virtual void Connected(uint32_t id);

	virtual void Processing() = 0;

protected:
	struct
	{
		std::unique_ptr<TWWsaData> WsaData;
		std::unique_ptr<TWSocket> Socket;
	} Context;

	bool Initialized{ false };
	std::string Address{ "127.0.0.1" };
	uint16_t Port{ 8080 };
};

class TWGateServer : virtual public TWGate
{
public:
	TWGateServer();
	virtual ~TWGateServer();

	virtual void DeInit() override;
	virtual void TransmitBuffer(uint32_t id, std::unique_ptr<TWBuffer>&& buf) override;

protected:
	std::map<uint32_t, TWClientContext> ClientMap;

private:
	virtual void Processing() override;
};

class TWGateClient : virtual public TWGate
{
public:
	TWGateClient();
	virtual ~TWGateClient();

	virtual void DeInit() override;
	virtual void TransmitBuffer(uint32_t id, std::unique_ptr<TWBuffer>&& buf) override;
	virtual void Processing() override;
};