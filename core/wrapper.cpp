#include "wrapper.h"

TWWsaData::TWWsaData()
{
	Initilised = WSAStartup(MAKEWORD(2, 2), &WsaData) != 0 ? false : true;
}

TWWsaData::~TWWsaData()
{
	WSACleanup();
}

TWWsaData::operator bool() const
{
	return Initilised;
}

TWSocket::TWSocket(SOCKET socket) :
	Socket(socket)
{
}

TWSocket::~TWSocket()
{
	closesocket(Socket);
}

TWSocket::operator bool() const
{
	return Socket != INVALID_SOCKET;
}

TWAddress::TWAddress(std::string ip, uint16_t port)
{
	in_addr addr;
	inet_pton(AF_INET, ip.c_str(), &addr);

	ZeroMemory(&Address, sizeof(Address));
	Address.sin_family = AF_INET;
	Address.sin_addr = addr;
	Address.sin_port = htons(port);
}