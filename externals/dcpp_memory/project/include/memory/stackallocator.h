//
//	stackallocator
//	DCPPMemory
//
//	Created by Jorge López González on 15/08/2017 11:23:23.
//

#ifndef CSTACKALLOCATOR_H
#define CSTACKALLOCATOR_H

#include "memory.h"

namespace dc
{
	// ===========================================================
	// External Enums / Typedefs for global usage
	// ===========================================================
	/**
	 * \class CStackAllocator
	 * \brief
	 * \author Jorge López González
	 *
	 * Description.
	 */
class CStackAllocator
{
	// ===========================================================
	// Constant / Enums / Typedefs internal usage
	// ===========================================================
	
	// ===========================================================
	// Static fields / methods
	// ===========================================================

	// ===========================================================
	// Inner and Anonymous Classes
	// ===========================================================

	// ===========================================================
	// Getter & Setter
	// ===========================================================
public:
	const bool		Full()		const { return m_capacity <= m_size; }
	const bool		Empty()		const { return m_size == 0; }
	const size_t	Capacity()	const { return m_capacity; }
	const size_t	Size()		const { return m_size; }
	
private:
	const bool		InsideBuffer(const TBytePtr memPtr, const size_t size) const
	{
		return mp_buffer <= memPtr && (memPtr + size) <= (mp_buffer + m_capacity);
	}
	
	const TBytePtr	StackHeadPtr() const { return mp_buffer + m_size; }

	// ===========================================================
	// Constructors
	// ===========================================================
public:
	explicit CStackAllocator(const size_t size, const size_t alignment);

	~CStackAllocator();
	
	// ===========================================================
	// Methods for/from SuperClass/Interfaces
	// ===========================================================

	// ===========================================================
	// Methods
	// ===========================================================
public:
	// Allocates on top of the stack
	TBytePtr Allocate(const size_t capacity);
	
	// Deallocates the top of the stack
	void Deallocate(TBytePtr memPtr, const size_t size);
	
	// Clears all memory
	void Clear();

	// ===========================================================
	// Fields
	// ===========================================================
private:
	TBytePtr	mp_buffer;
	
	size_t		m_alignment;
	size_t		m_size;
	size_t		m_capacity;
};

	// ===========================================================
	// Class typedefs
	// ===========================================================
	
	// ===========================================================
	// Template/Inline implementation
	// ===========================================================
}

#endif /* CSTACKALLOCATOR_H */
