#include <stdio.h>
#include "trie.h"

#define RUN_TEST(test, errmsg)\
							{\
								if(test)\
								{\
									printf("SUCCESS\n");\
								}\
								else\
								{\
									printf("\033[1;31m");\
									printf("%s \n", errmsg);\
									printf("\033[0m");\
								}\
							}

#define UNUSED(x) (void)(x)

void TestTrieDestroy()
{	
	trie_t *new_trie = TrieCreate();

	printf("TestTrieDestroy(): \n");

	RUN_TEST(TRUE == TrieIsEmpty(new_trie), "FAIL: TRIE IS EMPTY");
	RUN_TEST(0 == TrieSize(new_trie), "FAIL: WRONG TRIE SIZE (0)");
	RUN_TEST(0 == TrieCountLeafs(new_trie), "FAIL: WRONG LEAFS COUNT (0)");
	
	TrieDestroy(new_trie);

	printf("\n");
}

int main(int argc, char const *argv[])
{

	TestTrieDestroy();

	UNUSED(argv);
	UNUSED(argc);
	return 0;
}