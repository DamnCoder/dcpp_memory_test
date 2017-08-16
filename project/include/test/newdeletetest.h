//
//	newdeletetest
//	DCPPMemoryTest
//
//	Created by Jorge López González on 16/08/2017 11:16:28.
//

#ifndef NEWDELETE_H
#define NEWDELETE_H

#include "memory/memory.h"

class CFoo
{
public:
	CFoo() {}
};

inline void GlobalNewDeleteTest()
{
	CFoo* foo = new CFoo;
	delete foo;
	
	int* ia = new int[10];
	delete[] ia;
}

inline void NewDeleteTests()
{
	printf("GLOBAL NEW/DELETE TESTS\n");
	GlobalNewDeleteTest();
}

#endif /* NEWDELETE_H */
