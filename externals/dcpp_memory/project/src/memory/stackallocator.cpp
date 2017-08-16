//
//	stackallocator
//	DCPPMemory
//
//	Created by Jorge López González on 15/08/2017 11:23:23.
//

#include "stackallocator.h"
#include <cassert>

namespace dc
{
	CStackAllocator::CStackAllocator(size_t capacity, const size_t alignment):
		m_alignment(alignment),
		m_size(0),
		m_capacity(capacity)
	{
		mp_buffer = static_cast<TBytePtr>(malloc(capacity * sizeof(char)));
	}
	
	CStackAllocator::~CStackAllocator()
	{
		m_capacity = 0;
		free(mp_buffer);
	}

	TBytePtr CStackAllocator::Allocate(const size_t size)
	{
		assert(m_size + size <= m_capacity);
		
		TBytePtr memAddress = mp_buffer + m_size;
		m_size += size;
		
		assert(InsideBuffer(memAddress, size));
		
		return memAddress;
	}
	
	void CStackAllocator::Deallocate(TBytePtr memPtr, const size_t size)
	{
		assert(InsideBuffer(memPtr, size));
		m_size -= size;
	}
	
	void CStackAllocator::Clear()
	{
		assert(mp_buffer);
		free(mp_buffer);
		mp_buffer = 0;
		m_size = 0;
	}
}
