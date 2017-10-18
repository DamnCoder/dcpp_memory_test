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

class CAlign
{
public:
	const int Value() const { return m_value; }
public:
	explicit CAlign(int value): m_value(value){}
private:
	int	m_value;
};

extern const std::size_t AlignUp(const size_t n, const size_t alignment);

template <class Allocator>
inline
TRawPtr operator new(const size_t size, Allocator& allocator, const char* file, int line)
{
	//printf("%s\n %d\n", file, line);
	return allocator.Allocate(size);
}

template <class Allocator, class T>
void destroy(T* ptr, Allocator& allocator, const char* file, int line)
{
	//printf("%s\n %d\n", file, line);
	ptr->~T();
	allocator.Deallocate((TBytePtr)ptr, sizeof(T));
}

extern void* operator new(std::size_t size);
extern void* operator new[](std::size_t size);

extern void operator delete(void* mem) noexcept;
extern void operator delete[](void* mem) noexcept;

#endif /* MEMORY_H */
