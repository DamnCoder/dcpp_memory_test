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

#define DCNEW(allocator) new (allocator, __FILE__, __LINE__)

#define DCDELETE(allocator, ptr) destroy(ptr, allocator, __FILE__, __LINE__)


// Example:
// CFoo* foo = DCNEW(allocator) CFoo(i*2);
// the preprocessor expands the above into:
// CFoo* foo = new (sizeof(CFoo), allocator, "file.cpp", <line_where_called>) CFoo(i*2);

typedef void* TRawPtr;
typedef char* TBytePtr;

struct TMemPtr
{
	union
	{
		TRawPtr		rawPtr;
		TBytePtr	bytePtr;
	};
};

extern const std::size_t AlignUp(const size_t n, const size_t alignment);

// Overriden regular new / delete operators

extern void* operator new(std::size_t size);
extern void* operator new[](std::size_t size);

extern void operator delete(void* mem) noexcept;
extern void operator delete[](void* mem) noexcept;

template <class Allocator>
inline
TRawPtr operator new(const size_t size, Allocator& allocator, const char* file, int line)
{
	//printf("%s\n %d\n", file, line);
	return allocator.Allocate(size);
}

template <class Allocator>
inline
void operator delete(void* ptr, const size_t size, Allocator& allocator, const char* file, int line)
{
	allocator.Deallocate((TBytePtr)ptr, size);
}

template <class Allocator, class T>
void destroy(T* ptr, Allocator& allocator, const char* file, int line)
{
	ptr->~T();
	::operator delete(ptr, sizeof(T), allocator, file, line);
}

#endif /* MEMORY_H */
