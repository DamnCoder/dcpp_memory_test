//
//	stacktest
//	DCPPMemoryTest
//
//	Created by Jorge López González on 16/08/2017 11:16:09.
//

#ifndef STACKTESTS_H
#define STACKTESTS_H

#include "memory/stackallocator.h"
#include <cassert>

inline void TestStackAssigningMemory()
{
	dc::CStackAllocator allocator(1024, 16);
	TBytePtr memPtr = allocator.Allocate(64);
	
	assert(memPtr && allocator.Size() == 64 && allocator.Capacity() == 1024);
	
	allocator.Clear();
	
	assert(allocator.Size() == 0 && allocator.Capacity() == 1024);
}

inline void TestStackPushPopMemory()
{
	dc::CStackAllocator allocator(1024, 16);
	TBytePtr memPtr = allocator.Allocate(64);
	
	assert(memPtr && allocator.Size() == 64 && allocator.Capacity() == 1024);
	
	allocator.Deallocate(memPtr, 64);
	
	assert(allocator.Size() == 0 && allocator.Capacity() == 1024);
}

inline void TestStackPushPopAllMemory()
{
	dc::CStackAllocator allocator(1024, 16);
	
	TBytePtr ptrArray[1024 / 64];
	
	int i=0;
	while(!allocator.Full())
	{
		TBytePtr memPtr = allocator.Allocate(64);
		
		printf("%d Address %p\n", i, memPtr);
		ptrArray[i++] = memPtr;

		const size_t allocatedSize = 64 * i;
		assert(memPtr && allocator.Size() == allocatedSize && allocator.Capacity() == 1024);
	}
	
	while(!allocator.Empty())
	{
		--i;
		TBytePtr memPtr = ptrArray[i];
		printf("%d Address %p\n", i, memPtr);
		allocator.Deallocate(memPtr, 64);
	}
	
	assert(allocator.Size() == 0 && allocator.Capacity() == 1024);
}

inline void StackTests()
{
	printf("STACKALLOCATOR TESTS\n");
	TestStackAssigningMemory();
	TestStackPushPopMemory();
	TestStackPushPopAllMemory();
}

#endif /* STACKTESTS_H */
