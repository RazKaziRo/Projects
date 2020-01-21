#include <stdio.h>

#include "hash.h"
#define UNUSED(x) (void)(x)

static size_t HashFunction(const void *data)
{
	return 0;
}

static int ActionFunction(void *data1, void *data2)
{

}

static int IsMatchFunction(const void *data1, const void *data2)
{	
	return(*(int *)data1 == *(int *)data2);
}

void TestHashCreate()
{
	hash_t *new_hash = HashCreate(10, &HashFunction, &IsMatchFunction);
}

int main(int argc, char const *argv[])
{

	TestHashCreate();

	UNUSED(argv);
	UNUSED(argc);
	return 0;
}