//
//	newdeletetest
//	DCPPMemoryTest
//
//	Created by Jorge López González on 16/08/2017 11:16:28.
//

#ifndef NEWDELETE_H
#define NEWDELETE_H

#include <assert.h>
#include "memory/memory.h"
#include "memory/stackallocator.h"

class CFoo
{
public:
	const int X() const { return x; }
	
public:
	CFoo() : x(0) {}
	CFoo(int x) : x(x) {}
	
private:
	int x;
};

inline void GlobalNewDeleteTest()
{
	CFoo* foo = new CFoo;
	delete foo;
	
	int* ia = new int[10];
	delete[] ia;
}

inline void AlignTest()
{
	const size_t alignment = AlignUp(5, 4);
	printf("%zu\n", alignment);
}

inline void StackAllocatorNewDeleteTest()
{
	const size_t alignment = 16;
	const size_t memBytes = 1024;
	const size_t fooSize = sizeof(CFoo);
	const size_t alignedFooSize = AlignUp(fooSize, alignment);
	const int num_elements = memBytes / alignedFooSize;
	
	printf("Size of CFoo: %zu bytes\n", fooSize);
	printf("Aligned size: %zu bytes\n", alignedFooSize);
	
	dc::CStackAllocator allocator(memBytes, alignment);
	
	CFoo* fooArray[num_elements];
	int i = 1;
	while (!allocator.Full())
	{
		CFoo* foo = DCNEW(allocator) CFoo(i*2);
		fooArray[i-1] = foo;
		printf("%d %p %d\n", i, foo, foo->X());
		const size_t allocatedSize = alignedFooSize * i;
		assert(foo && allocator.Size() == allocatedSize && allocator.Capacity() == 1024);
		++i;
	}
	
	for(i=num_elements-1; 0 <= i; --i)
	{
		CFoo* foo = fooArray[i];
		printf("%d\n", foo->X());
		DCDELETE(allocator, foo);
	}
	
	for(i=num_elements-1; 0 <= i; --i)
	{
		CFoo* foo = fooArray[i];
		printf("%d\n", foo->X());
	}
	
	allocator.Clear();
	
	assert(allocator.Size() == 0 && allocator.Capacity() == 1024);
}

inline void NewDeleteTests()
{
	printf("GLOBAL NEW/DELETE TESTS\n");
	GlobalNewDeleteTest();
	AlignTest();
	StackAllocatorNewDeleteTest();
}

#endif /* NEWDELETE_H */
