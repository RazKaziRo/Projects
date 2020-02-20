#ifndef __WD_API_H__
#define __WD_API_H__

#include <pthread.h>

typedef struct WatchDog wd_t;

typedef enum STATUS
{
	SUCCESS,
	MEMORY_ALOC_FAIL
} wd_status_t;

/*	
*	The function recives a pointer to a thread created by the user 
* 	which will hold the tread to be joined in WDStop(). the first argument is the excute filename by path 
* 	this function guards the process from failing postcall. if the process fails, it will be revived. 
* 	Return value: 0 for success, 1 for fail. 
*/

wd_t *WDStart(const char *filename, wd_status_t status);

/*
*	the function ends the reviving effect.
*	it recievs the pointer to the tread created in WDStart() 
*/

void WDStop(pthread_t *thread);

#endif