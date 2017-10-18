//
//	linearallocator
//	DCPPMemory
//
//	Created by Jorge López González on 15/08/2017 15:26:21.
//

#ifndef CLINEARALLOCATOR_H
#define CLINEARALLOCATOR_H

#include "memory.h"

namespace dc
{
	// ===========================================================
	// External Enums / Typedefs for global usage
	// ===========================================================
	/**
	 * \class CLinearAllocator
	 * \brief
	 * \author Jorge López González
	 *
	 * Description.
	 */
class CLinearAllocator
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

	// ===========================================================
	// Constructors
	// ===========================================================
public:
	explicit CLinearAllocator(const size_t capacity);
	~CLinearAllocator();
	
	// ===========================================================
	// Methods for/from SuperClass/Interfaces
	// ===========================================================

	// ===========================================================
	// Methods
	// ===========================================================
public:
	TBytePtr Allocate(const size_t size);
	
	void Deallocate(TBytePtr memPtr, const size_t size);
	
	void Clear();

	// ===========================================================
	// Fields
	// ===========================================================
private:
	TBytePtr	mp_buffer;
	size_t		m_capacity;
	size_t		m_size;
};

	// ===========================================================
	// Class typedefs
	// ===========================================================
	
	// ===========================================================
	// Template/Inline implementation
	// ===========================================================
}

#endif /* CLINEARALLOCATOR_H */
