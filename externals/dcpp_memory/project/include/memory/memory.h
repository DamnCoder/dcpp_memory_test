//
//	memory
//	DCPPMemory
//
//	Created by Jorge López González on 15/08/2017 11:24:44.
//

#ifndef MEMORY_H
#define MEMORY_H

#include <cstdio>
#include <cstdlib>
#include <new>

typedef void* TRawPtr;
typedef char* TBytePtr;

class CAlign
{
public:
	const int Value() const { return m_value; }
public:
	explicit CAlign(int value): m_value(value){}
private:
	int	m_value;
};

constexpr std::size_t align_up(std::size_t n, const CAlign& alignment)
{
	return (n + (alignment.Value()-1)) & ~(alignment.Value()-1);
}

extern void* operator new(size_t size, const std::nothrow_t &) throw();
extern void* operator new(std::size_t size) throw(std::bad_alloc);

extern void* operator new[](size_t size, const std::nothrow_t &) throw();
extern void* operator new[](std::size_t size) throw(std::bad_alloc);

extern void operator delete(void *p, const std::nothrow_t &) throw();
extern void operator delete(void* mem) throw();

extern void operator delete[](void *p, const std::nothrow_t &) throw();
extern void operator delete[](void* mem) throw();

#endif /* MEMORY_H */
