#ifndef __WD_API_FUNC_H__
#define __WD_API_FUNC_H__

#include "wd.h"

#define WD_APP_PATH "./wd"
/*	
*	The function recives a pointer to a thread created by the user 
* 	which will hold the tread to be joined in WDStop(). the first argument is the excute filename by path 
* 	this function guards the process from failing postcall. if the process fails, it will be revived. 
* 	Return value: 0 for success, 1 for fail. 
*/

wd_t *WDStart(const char *path_to_app, wd_status_t *status);

/*
*	the function ends the reviving effect.
*	it recievs the pointer to the tread created in WDStart() 
*/

wd_status_t WDStop(wd_t *wd_pack);

#endif