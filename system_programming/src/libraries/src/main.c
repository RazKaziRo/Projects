#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "random.h"

int main() {

	void *handle;
	int (*cosine)();
    char *error;

	handle = dlopen ("./libs/librandom.so", RTLD_LAZY);
	if (!handle) 
	{
	    fputs (dlerror(), stderr);
	    exit(1);
    }

    *(void **) (&cosine) = dlsym(handle, "get_random_number");
	if ((error = dlerror()) != NULL)  
	{
		fputs(error, stderr);
		exit(1);
	}

	printf("%d \n", (*cosine)());
	dlclose(handle);
    return 0;
}