//
//	linearallocator
//	DCPPMemory
//
//	Created by Jorge López González on 15/08/2017 15:26:21.
//

#include "linearallocator.h"

#include <cassert>

namespace dc
{
	CLinearAllocator::CLinearAllocator(const size_t capacity):
		m_capacity(capacity),
		m_size(0)
	{
		mp_buffer = static_cast<TBytePtr>(malloc(m_capacity * sizeof(char)));
	}
	
	CLinearAllocator::~CLinearAllocator()
	{
		m_size = 0;
		m_capacity = 0;
		mp_buffer = 0;
	}
	
	TBytePtr CLinearAllocator::Allocate(const size_t size)
	{
		assert(m_size + size <= m_capacity);
		
		TBytePtr memAddress = mp_buffer + m_size;
		m_size += size;
		
		return memAddress;
	}
	
	void CLinearAllocator::Clear()
	{
		assert(mp_buffer);
		free(mp_buffer);
		mp_buffer = 0;
		m_size = 0;
	}
}
