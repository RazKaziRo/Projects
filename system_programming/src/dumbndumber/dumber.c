#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *new_file;
	int a = 100;
	void *ptr_to_a;

	new_file = fopen("dumb.txt", "r");
	fscanf(new_file, "%p", &ptr_to_a);

	printf("ptr_to_a after: %d\n", *(int*)ptr_to_a);

	fclose(new_file);

	return 0;
}