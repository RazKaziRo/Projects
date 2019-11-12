#include <stdio.h>
#include <string.h> 		/*Import strlen() */
#include "ws5head.h"



void Logger(FILE *file_name)
{
	char user_input[25];
	FILE *new_file = file_name;

	/*
	struct file_input
	{

	};
	*/
}

FILE *CreatNewFile(const char *file_name) /* Creat New File */
{
	FILE *new_file;
	new_file =fopen(file_name,"w");
	fclose(new_file);

return new_file;
}


void StrOperation(FILE *file_name, char *intput_string)
{
	
}

int StrComparison(FILE *file_name,char *intput_string)
{

}

void addLineToStart(FILE *file,const char *file_name, const char *intput_string)
{
	file = fopen(file_name,"r+");
	fseek(file, 0, SEEK_SET);
	fputs(intput_string, file );		/*write the new line */

	fclose(file);
}

void addLineToEnd(FILE *file,const char *file_name, const char *intput_string)
{
	file = fopen(file_name,"a");
	fputs(intput_string, file);		/*fputs() to insert string data type */
	fputs("\n", file);				/*Insert New Line for the next input*/
	fclose(file);
}

int CountLines(FILE *file,const char *file_name)
{
	int lines = 0;			/*Line counter */
	char c; 				/*store characters from file*/

	file = fopen(file_name, "r");
	for (c = fgetc(file); c != EOF; c = fgetc(file)) 	/*fgetc() = getc() */
	{
		if (c == '\n')
		{
			 ++lines;
		}
	}
    fclose(file); 

return lines;
}

void RemoveFile(const char *file_name)
{
	remove(file_name);
}

int ExitPrograme()
{
	return 0;
}

