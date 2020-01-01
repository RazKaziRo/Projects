#include <stdio.h> /*printf()*/
#include <stdlib.h> /*malloc()*/

static void StaticFunction()
{
	printf("Static Function\n");
}

extern void ExternFuntion()
{
	printf("Extern Function\n");
}

/*const global*/
const char const_global_ch = 'A';

/*global*/
char global_ch = 'B';

/*static global*/
static char global_static_ch = 'C';

int main(int argc, char const *argv[], char const *envp[])
{	
	/*heap var*/
	char *heap_char_var = malloc(sizeof(int));
	
	/*string literal*/
	char *string_literal = "Hello";

	/* env variable*/
	char *envp_var = (char *)envp[1];

	/*command variable*/
	char *argv_var = (char *)argv[1];

	/*const local*/
	const char const_local_ch = 'a';

	/*local*/
	char local_ch = 'b';

	/*static local*/
	static char local_static_ch = 'c';

	StaticFunction();
	ExternFuntion();

	return 0;
}