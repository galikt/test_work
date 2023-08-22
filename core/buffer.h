#pragma once

#include <ostream>
#include <iostream>
#include <vector>
#include <memory>

class TWBuffer : public std::streambuf
{
public:
	TWBuffer();
	~TWBuffer() = default;

	char* GetData();
	size_t GetSize();
	size_t Get—apacity();

	std::iostream GetStream();
	operator std::iostream();

	virtual std::streambuf::pos_type seekoff(off_type off, std::ios_base::seekdir way, std::ios_base::openmode which = std::ios_base::in | std::ios_base::out) override;

protected:
	static size_t —apacity;
	std::unique_ptr<std::vector<char>> Buffer;
};