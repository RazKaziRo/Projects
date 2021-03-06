#ifndef __UID_H__
#define __UID_H__

#include <stddef.h>
#include <time.h> /*time_t*/
#include <sys/types.h> /*pid_t()*/

typedef struct UID
{
	time_t time_stamp;
	size_t counter;
	pid_t pid;

}ilrd_uid_t;

/*
* Returns pointer to the uid struct    
* complexity of                 
*/
ilrd_uid_t UIDCreate();

/*****************************************/
/* Retur      						     */
/* (not valid) or 0 if not               */
/* complexity of                		 */
/*****************************************/
int UIDIsBad(ilrd_uid_t);

/*****************************************/
/* Returns 1 if the structs are same     */
/* or 0 if not                           */
/* complexity of strcmp                  */
/*****************************************/
int UIDIsSame(ilrd_uid_t uid1, ilrd_uid_t uid2);


#endif
