//
//	lineartests
//	DCPPMemoryTest
//
//	Created by Jorge López González on 15/08/2017 15:50:18.
//

#ifndef LINEARTESTS_H
#define LINEARTESTS_H

#include "memory/linearallocator.h"
#include <cassert>

inline void TestLinearAssigningMemory()
{
	dc::CLinearAllocator allocator(1024);
	TBytePtr memPtr = allocator.Allocate(64);
	
	assert(memPtr && allocator.Size() == 64 && allocator.Capacity() == 1024);
	
	allocator.Clear();
	
	assert(allocator.Size() == 0 && allocator.Capacity() == 1024);
}

inline void TestLinearAssigningAllMemory()
{
	dc::CLinearAllocator allocator(1024);
	
	int i=1;
	while(!allocator.Full())
	{
		TBytePtr memPtr = allocator.Allocate(64);
		
		const size_t allocatedSize = 64 * i;
		assert(memPtr && allocator.Size() == allocatedSize && allocator.Capacity() == 1024);
		++i;
	}
	
	allocator.Clear();
	
	assert(allocator.Empty() && allocator.Capacity() == 1024);
}

inline void LinearTests()
{
	printf("LINEARALLOCATOR TESTS\n");
	TestLinearAssigningMemory();
	TestLinearAssigningAllMemory();
}

#endif /* LINEARTESTS_H */
