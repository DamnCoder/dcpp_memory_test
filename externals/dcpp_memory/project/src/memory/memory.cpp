//
//	memory
//	DCPPMemory
//
//	Created by Jorge López González on 15/08/2017 11:24:44.
//

#include "memory.h"

void* operator new(size_t size, const std::nothrow_t &) throw()
{
	printf("New\n");
	return malloc(size * sizeof(char));
}

void* operator new(std::size_t size) throw(std::bad_alloc)
{
	printf("New\n");
	return malloc(size * sizeof(char));
}

void* operator new[](size_t size, const std::nothrow_t &) throw()
{
	printf("New[]\n");
	return malloc(size);
}

void* operator new[](std::size_t size) throw(std::bad_alloc)
{
	printf("New[]\n");
	return malloc(size * sizeof(char));
}

void operator delete(void* p, const std::nothrow_t &) throw()
{
	printf("Delete\n");
	free(p);
}

void operator delete(void* mem) throw()
{
	printf("Delete\n");
	free(mem);
}

void operator delete[](void* p, const std::nothrow_t &) throw()
{
	printf("Delete[]\n");
	free(p);
}

void operator delete[](void* mem) throw()
{
	printf("Delete[]\n");
	free(mem);
}
