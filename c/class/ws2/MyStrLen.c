#include <stdio.h>

size_t MyStrlen(const char *s)
{

	const char *runner = s;
	while ('\0'!=*runner){

		++runner;
	}


	return runner-s;

}