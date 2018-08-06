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
		assert((m_size % m_alignment) == 0 && "Size needs to be a multiple of alignment!");
		assert(m_alignment && !(m_alignment & (m_alignment - 1)) && "Alignment needs to be a power of 2!");
		mp_buffer = static_cast<TBytePtr>(malloc(capacity * sizeof(char)));
	}
	
	CStackAllocator::~CStackAllocator()
	{
		m_capacity = 0;
		free(mp_buffer);
	}

	TBytePtr CStackAllocator::Allocate(const size_t size)
	{
		TBytePtr memAddress = StackHeadPtr();
		const size_t aligned_size = AlignUp(size, m_alignment);
		assert(InsideBuffer(memAddress, aligned_size) && "The allocated memory would be out of bounds!");
		m_size += aligned_size;
		return memAddress;
	}
	
	void CStackAllocator::Deallocate(TBytePtr memPtr, const size_t size)
	{
		const size_t aligned_size = AlignUp(size, m_alignment);
		assert(InsideBuffer(memPtr, aligned_size));
		TBytePtr memLocation = StackHeadPtr() - aligned_size;
		assert(memLocation == memPtr && "Deallocate memory in the reverse order you allocated it!");
		m_size -= aligned_size;
	}
	
	void CStackAllocator::Clear()
	{
		assert(mp_buffer);
		free(mp_buffer);
		mp_buffer = 0;
		m_size = 0;
	}
}
