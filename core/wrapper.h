#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <stdint.h>

class TWWsaData
{
public:
	TWWsaData();
	~TWWsaData();

	operator bool() const;

	WSADATA WsaData;
protected:
	bool Initilised{ false };
};

class TWSocket
{
public:
	TWSocket(SOCKET socket);
	~TWSocket();

	operator bool() const;

	SOCKET Socket;
};

class TWAddress
{
public:
	TWAddress(std::string ip, uint16_t port);
	~TWAddress() = default;

	sockaddr_in Address;
};
