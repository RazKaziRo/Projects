#include <stdio.h>
#include "trie.h"
#include "ip.h"

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

void TestTrieInsert()
{
	size_t height = 2;
	unsigned char subnet_mask[] = {255, 255, 255, 252};
	unsigned char broadcast_address[] = {255, 255, 255, 255};
	unsigned char ip253[] = {255, 255, 255, 253};
	unsigned char iptaked[] = {255, 255, 255, 253};

	trie_t *new_trie = TrieCreate(height);

	printf("TestTrieInsert(): \n");

	RUN_TEST(0 == TrieSize(new_trie), "FAIL: WRONG SIZE (0)");
	RUN_TEST(SUCCESS == TrieInsert(new_trie, subnet_mask), "FAIL: INSERT FAIL (SUCCESS)");
	RUN_TEST(1 == TrieSize(new_trie), "FAIL: WRONG SIZE (1)");
	RUN_TEST(SUCCESS == TrieInsert(new_trie, broadcast_address), "FAIL: INSERT FAIL (SUCCESS)");
	RUN_TEST(2 == TrieSize(new_trie), "FAIL: WRONG SIZE (2)");
	RUN_TEST(SUCCESS == TrieInsert(new_trie, ip253), "FAIL: INSERT FAIL (SUCCESS)");
	RUN_TEST(3 == TrieSize(new_trie), "FAIL: WRONG SIZE (3)");
	RUN_TEST(FAIL == TrieInsert(new_trie, ip253), "FAIL: INSERT FAIL (FAIL)");
	TrieNextAvilable(new_trie, subnet_mask);

	TrieDestroy(new_trie);

	printf("\n");

}

void TestTrieDestroy()
{	
	trie_t *new_trie = TrieCreate(2);

	printf("TestTrieDestroy(): \n");

	RUN_TEST(TRUE == TrieIsEmpty(new_trie), "FAIL: TRIE IS EMPTY");
	RUN_TEST(0 == TrieSize(new_trie), "FAIL: WRONG TRIE SIZE (0)");

	TrieDestroy(new_trie);

	printf("\n");
}

int main(int argc, char const *argv[])
{
	TestTrieInsert();
	TestTrieDestroy();

	UNUSED(argv);
	UNUSED(argc);
	return 0;
}