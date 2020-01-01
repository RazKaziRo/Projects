#include <stdio.h> /*printf()*/
#include <time.h> /*time_t*/
#include <unistd.h> /*getpid()*/

#include "uid.h"

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
#define FREE(ptr) free(ptr); ptr = NULL;

void TestUIDCreate()
{	
	ilrd_uid_t newPID1 = UIDCreate();
	ilrd_uid_t newPID2 = {0};
	
	RUN_TEST(1 == newPID1.counter, "FAIL: WRONG COUNTER (1)");
	RUN_TEST(getpid() == newPID1.pid, "FAIL: WRONG PID (getpid())");
	RUN_TEST(time(NULL) == newPID1.time_stamp, "FAIL: WRONG TIMESTAMP (time())");
	
	sleep(1);
	newPID2 = UIDCreate();

	RUN_TEST(2 == newPID2.counter, "FAIL: WRONG COUNTER (2)");
	RUN_TEST(getpid() == newPID2.pid, "FAIL: WRONG PID (getpid())");
	RUN_TEST(time(NULL) == newPID2.time_stamp, "FAIL: WRONG TIMESTAMP (time())");
	
	printf("\n");
}

void TestUIDIsBad()
{	
	ilrd_uid_t newPID1 = UIDCreate();
	ilrd_uid_t newPID2 = {0};

	newPID2 = UIDCreate();
	newPID2.pid = 0;

	RUN_TEST(0 == UIDIsBad(newPID1), "FAIL: PID NOT BAT");
	RUN_TEST(1 == UIDIsBad(newPID2), "FAIL: PID IS BAT");

	printf("\n");
}

void TestUIDIsSame()
{
	ilrd_uid_t newPID1 = UIDCreate();
	ilrd_uid_t newPID2 = {0};
	ilrd_uid_t newPID3 = UIDCreate();
	ilrd_uid_t newPID4;


	newPID2.pid = newPID1.pid;
	newPID2.time_stamp = newPID1.time_stamp;
	newPID2.counter = newPID1.counter;

	newPID4 = UIDCreate();
	newPID4.time_stamp = newPID1.counter;

	RUN_TEST((1 == UIDIsSame(newPID1, newPID2)), "FAIL: UID IS THE SAME");
	RUN_TEST((0 == UIDIsSame(newPID1, newPID3)), "FAIL: UID IS NOT THE SAME");
	RUN_TEST((0 == UIDIsSame(newPID1, newPID4)), "FAIL: UID IS NOT THE SAME");

}

int main(int argc, char const *argv[])
{	
	printf("TestUIDCreate()\n");
	TestUIDCreate();

	printf("TestUIDIsBad()\n");
	TestUIDIsBad();

	printf("TestUIDIsSame()\n");
	TestUIDIsSame();
	
	UNUSED(argv);
	UNUSED(argc);
	return 0;
}