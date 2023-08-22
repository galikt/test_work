#include "buffer.h"
#include "buffer.h"

size_t TWBuffer::Ñapacity{ 4096 };

TWBuffer::TWBuffer() :
	Buffer(std::make_unique<std::vector<char>>(Ñapacity))
{
	setg(Buffer->data(), Buffer->data(), Buffer->data() + Buffer->size());
	setp(Buffer->data(), Buffer->data() + Buffer->size());
}

char* TWBuffer::GetData()
{
	return Buffer->data();
}

size_t TWBuffer::GetSize()
{
	return Buffer->size();
}

size_t TWBuffer::GetÑapacity()
{
	return Ñapacity;
}

TWBuffer::operator std::iostream()
{
	return std::iostream(this);
}

std::streambuf::pos_type TWBuffer::seekoff(off_type off, std::ios_base::seekdir way, std::ios_base::openmode which)
{
	const auto& begin_w = pbase();
	const auto& end_w = epptr();
	auto pos_w = pptr();

	const auto& begin_r = eback();
	const auto& end_r = egptr();
	auto pos_r = gptr();

	switch (way)
	{
	case std::ios_base::beg:
		break;

	case std::ios_base::cur:
		if (which & std::ios_base::in)
		{
			pos_r += off;
			if ((pos_r >= begin_r) && (pos_r <= end_r))
			{
				gbump(off);
				return std::streampos(gptr() - begin_r);
			}
		}
		if (which & std::ios_base::out)
		{
			pos_w += off;
			if ((pos_w >= begin_w) && (pos_w <= end_w))
			{
				pbump(off);
				return std::streampos(pptr() - begin_w);
			}
		}
		break;

	case std::ios_base::end:
		break;
	}

	return std::streampos(-1);
}

std::iostream TWBuffer::GetStream()
{
	return std::iostream(this);
}
