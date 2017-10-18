#include "test/newdeletetest.h"
#include "test/lineartests.h"
#include "test/stacktest.h"

int main( int argc, char* args[] )
{
	printf("Starting memory tests\n");
	//LinearTests();
	//StackTests();
	NewDeleteTests();
	printf("Finished memory tests\n");
	return 0;
}
