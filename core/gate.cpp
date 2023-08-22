#include "gate.h"

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include "buffer.h"

#pragma comment (lib, "Ws2_32.lib")

void TWGate::TransmitBuffer(uint32_t id, std::unique_ptr<TWBuffer>&& buf)
{
}

void TWGate::ReceiveBuffer(uint32_t id, std::unique_ptr<TWBuffer>&& buf)
{
}

void TWGate::Connected(uint32_t id)
{
}

TWGateServer::TWGateServer()
{
	auto wsa_data_tmp = std::make_unique<TWWsaData>();
	if (wsa_data_tmp == false)
		return;

	auto socket_tmp = std::make_unique<TWSocket>(socket(AF_INET, SOCK_STREAM, 0));
	if (socket_tmp == false)
		return;

	auto address_tmp = std::make_unique<TWAddress>(Address, Port);

	if (bind(socket_tmp->Socket, (sockaddr*)&address_tmp->Address, sizeof(address_tmp->Address)) != 0)
		return;

	if (listen(socket_tmp->Socket, SOMAXCONN) != 0)
		return;

	Context.WsaData = std::move(wsa_data_tmp);
	Context.Socket = std::move(socket_tmp);

	Initialized = true;

	std::thread thread = std::thread(&TWGateServer::Processing, this);
	thread.detach();
}

TWGateServer::~TWGateServer()
{
	DeInit();
}

void TWGateServer::DeInit()
{
	if (Initialized == false)
		return;

	Initialized = false;

	shutdown(Context.Socket->Socket, SD_BOTH);
	ClientMap.clear();
	Context.Socket.reset();
	Context.WsaData.reset();
}

void TWGateServer::TransmitBuffer(uint32_t id, std::unique_ptr<TWBuffer>&& buf)
{
	auto client = ClientMap.find(id);
	if (client == ClientMap.end())
		return;

	send(client->second.Socket->Socket, buf->GetData(), buf->GetSize(), 0);
}

void TWGateServer::Processing()
{
	if (Initialized == false)
		return;

	TWAddress address_tmp(Address, Port);
	int size = sizeof(address_tmp.Address);

	auto socket_tmp = std::make_shared<TWSocket>(accept(Context.Socket->Socket, (sockaddr*)&(address_tmp.Address), &size));
	if (*socket_tmp == false)
	{
		DeInit();
		return;
	}

	static uint32_t id = 0;
	++id;

	TWClientContext client;
	client.Id = id;
	client.Socket = socket_tmp;
	ClientMap.insert(std::make_pair(client.Id, client));

	Connected(id);

	while (Initialized)
	{
		auto buf = std::make_unique<TWBuffer>();
		auto packet_size = recv(socket_tmp->Socket, (char*)buf->GetData(), buf->GetSize(), 0);
		if (packet_size == SOCKET_ERROR)
		{
			DeInit();
			return;
		}

		ReceiveBuffer(id, std::move(buf));
	}
}

TWGateClient::TWGateClient()
{
	auto wsa_data_tmp = std::make_unique<TWWsaData>();
	if (wsa_data_tmp == false)
		return;

	auto socket_tmp = std::make_unique<TWSocket>(socket(AF_INET, SOCK_STREAM, 0));
	if (socket_tmp == false)
		return;

	auto address_tmp = std::make_unique<TWAddress>(Address, Port);

	if (connect(socket_tmp->Socket, (sockaddr*)&address_tmp->Address, sizeof(address_tmp->Address)) != 0)
		return;

	Context.WsaData = std::move(wsa_data_tmp);
	Context.Socket = std::move(socket_tmp);

	Initialized = true;

	std::thread thread = std::thread(&TWGateClient::Processing, this);
	thread.detach();

	Connected(0);
}
TWGateClient::~TWGateClient()
{
	DeInit();
}

void TWGateClient::DeInit()
{
	Context.Socket.reset();
	Context.WsaData.reset();
}

void TWGateClient::TransmitBuffer(uint32_t id, std::unique_ptr<TWBuffer>&& buf)
{
	send(Context.Socket->Socket, buf->GetData(), buf->GetSize(), 0);
}

void TWGateClient::Processing()
{
	if (Initialized == false)
		return;

	while (Initialized)
	{
		auto buf = std::make_unique<TWBuffer>();
		auto packet_size = recv(Context.Socket->Socket, (char*)buf->GetData(), buf->GetSize(), 0);

		if (packet_size == SOCKET_ERROR)
		{
			DeInit();
			return;
		}

		ReceiveBuffer(0, std::move(buf));
	}
}
