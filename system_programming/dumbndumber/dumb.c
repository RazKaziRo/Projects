#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *new_file;
	int a = 200;

	new_file = fopen("dumb.txt", "w");
	fprintf(new_file, "%p", &a);
	fclose(new_file);

	return 0;
}