//
//	memory
//	DCPPMemory
//
//	Created by Jorge López González on 15/08/2017 11:24:44.
//

#include "memory.h"

const std::size_t AlignUp(const size_t n, const size_t alignment)
{
	const size_t align = alignment - 1;
	return ~align & (n + align);
}

void* operator new(std::size_t size)
{
	printf("New\n");
	return malloc(size * sizeof(char));
}

void* operator new[](std::size_t size)
{
	printf("New[]\n");
	return malloc(size * sizeof(char));
}

void operator delete(void* mem) noexcept
{
	printf("Delete\n");
	free(mem);
}

void operator delete[](void* mem) noexcept
{
	printf("Delete[]\n");
	free(mem);
}
