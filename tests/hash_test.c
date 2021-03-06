#include <stdio.h>
#include <string.h>

#include "hash.h"

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
#define TABLE_SIZE 10

static size_t HashFunction(const void *data)
{
	char *data_runner = (char *)data;
	size_t key = 0;

	while('\0' != *data_runner)
	{
		key += *data_runner;
		++data_runner;
	}
	
	return (key % TABLE_SIZE);
}

static int ActionFunction(void *data1, void *param)
{
	printf("%s \n", (char *)data1);

	UNUSED(param);
	return 0;
}	

static int IsMatchFunction(void *data1, void *data2)
{	
	return(0 == strcmp(data1, data2));
}

void TestHashCreate()
{
	hash_t *new_hash = HashCreate(TABLE_SIZE, &HashFunction, &IsMatchFunction);
	HashDestroy(new_hash);
}

void TestHashInstert()
{
	hash_t *new_hash = HashCreate(TABLE_SIZE, &HashFunction, &IsMatchFunction);
	char chair1 [] = "Eliya"; 	/*KEY 0*/
	char chair2 [] = "Raz";   	/*KEY 1*/
	char chair3 [] = "Yoav";  	/*KEY 5*/	
	char chair4 [] = "Daniel"; 	/*KEY 9*/ 
	char chair5 [] = "Yonatan"; /*KEY 0*/
	char chair6 [] = "Ben"; 	/*KEY 7*/
	char chair7 [] = "Guy"; 	/*KEY 9*/
	char chair8 [] = "Israel";  /*KEY 8*/
	char chair9 [] = "Itai"; 	/*KEY 1*/
	char chair10 [] = "Shye"; 	/*KEY 9*/


	HashInsert(new_hash, chair1);
	HashInsert(new_hash, chair2);
	HashInsert(new_hash, chair3);
	HashInsert(new_hash, chair4);
	HashInsert(new_hash, chair5);
	HashInsert(new_hash, chair6);
	HashInsert(new_hash, chair7);
	HashInsert(new_hash, chair8);
	HashInsert(new_hash, chair9);
	HashInsert(new_hash, chair10);

	HashDestroy(new_hash);

}

void TestHashRemove()
{
	hash_t *new_hash = HashCreate(TABLE_SIZE, &HashFunction, &IsMatchFunction);
	char chair1 [] = "Eliya"; 	/*KEY 0*/
	char chair2 [] = "Raz";   	/*KEY 1*/
	char chair3 [] = "Yoav";  	/*KEY 5*/	
	char chair4 [] = "Daniel"; 	/*KEY 9*/ 
	char chair5 [] = "Yonatan"; /*KEY 0*/
	char chair6 [] = "Ben"; 	/*KEY 7*/
	char chair7 [] = "Guy"; 	/*KEY 9*/
	char chair8 [] = "Israel";  /*KEY 8*/
	char chair9 [] = "Itai"; 	/*KEY 1*/
	char chair10 [] = "Shye"; 	/*KEY 9*/

	HashInsert(new_hash, chair1);
	HashInsert(new_hash, chair2);
	HashInsert(new_hash, chair3);
	HashInsert(new_hash, chair4);
	HashInsert(new_hash, chair5);
	HashInsert(new_hash, chair6);
	HashInsert(new_hash, chair7);
	HashInsert(new_hash, chair8);
	HashInsert(new_hash, chair9);
	HashInsert(new_hash, chair10);

	HashRemove(new_hash, &chair5);

	HashDestroy(new_hash);

}

void TestHashSize()
{
	hash_t *new_hash = HashCreate(TABLE_SIZE, &HashFunction, &IsMatchFunction);

	char chair1 [] = "Eliya"; 	/*KEY 0*/
	char chair2 [] = "Raz";   	/*KEY 1*/
	char chair3 [] = "Yoav";  	/*KEY 5*/	
	char chair4 [] = "Daniel"; 	/*KEY 9*/ 
	char chair5 [] = "Yonatan"; /*KEY 0*/
	char chair6 [] = "Ben"; 	/*KEY 7*/
	char chair7 [] = "Guy"; 	/*KEY 9*/
	char chair8 [] = "Israel";  /*KEY 8*/
	char chair9 [] = "Itai"; 	/*KEY 1*/
	char chair10 [] = "Shye"; 	/*KEY 9*/

	RUN_TEST(1 == HashIsEmpty(new_hash), "FAIL: IS EMPTY(1)");
	RUN_TEST(0 == HashSize(new_hash), "FAIL: WORONG SIZE (0)");

	HashInsert(new_hash, chair1);
	RUN_TEST(0 == HashIsEmpty(new_hash), "FAIL: IS EMPTY(1)");
	RUN_TEST(1 == HashSize(new_hash), "FAIL: WORONG SIZE (0)");

	HashInsert(new_hash, chair2);
	HashInsert(new_hash, chair3);
	HashInsert(new_hash, chair4);
	HashInsert(new_hash, chair5);
	HashInsert(new_hash, chair6);

	RUN_TEST(0 == HashIsEmpty(new_hash), "FAIL: IS EMPTY(1)");
	RUN_TEST(6 == HashSize(new_hash), "FAIL: WORONG SIZE (0)");

	HashInsert(new_hash, chair7);
	HashInsert(new_hash, chair8);
	HashInsert(new_hash, chair9);
	HashInsert(new_hash, chair10);

	HashForeach(new_hash, &ActionFunction, NULL);

	RUN_TEST(10 == HashSize(new_hash), "FAIL: WORONG SIZE (0)");

	RUN_TEST(0 == strcmp(HashFind(new_hash, &chair5), chair5), "FAIL: NO ONE TO REMOVE");

	HashRemove(new_hash, &chair5);

	RUN_TEST(NULL == HashFind(new_hash, &chair5), "FAIL: NO ONE TO REMOVE");

	HashForeach(new_hash, &ActionFunction, NULL);

	RUN_TEST(9 == HashSize(new_hash), "FAIL: WORONG SIZE (0)");
	
	HashFind(new_hash, &chair4);

	HashForeach(new_hash, &ActionFunction, NULL);

	HashDestroy(new_hash);

}

int main(int argc, char const *argv[])
{

	TestHashCreate();
	TestHashInstert();
	TestHashRemove();
	TestHashSize();

	UNUSED(argv);
	UNUSED(argc);
	return 0;
}