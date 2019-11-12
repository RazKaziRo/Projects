#include <stdio.h>
#include <string.h>
#include "ws5head.h"

int main()
{
	FILE *file;
	int lines = 0;

	char *file_name = "raz.txt";
	char *input_string = "New Line 22";

	addLineToStart(file,file_name,input_string);

/*
	addLineToEnd(file,file_name,input_string);

	lines = CountLines(file,file_name);
	printf("Number Of Lines: %d \n" ,lines);


	CreatNewFile(file_name);

	RemoveFile(file_name);

	addLineToEnd(file,file_name,input_string);
	

	lines = CountLines(file,file_name);
	printf("Number Of Lines: %d \n" ,lines);
*/
}