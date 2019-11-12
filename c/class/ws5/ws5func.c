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

FILE *CreateNewFile(const char *file_name) /* Creat New File */
{
	FILE *new_file;
	new_file =fopen(file_name,"w");
	fclose(new_file);

return new_file;
}


FILE *MergeTmpFile(FILE *old_file,const char *old_file_name, FILE *tmp_file ,const char *tmp_file_name
 ,const char *intput_string) 
{	
	char c = 0;

	old_file = fopen(old_file_name, "r"); 				/*Open Exsiting File for reading*/
	tmp_file = fopen(tmp_file_name, "w");				/*Open Temp File for writing*/
	fputs(intput_string, tmp_file);						/* Insert New String */
	fputs("\n", tmp_file);						
	c = fgetc(old_file);

	while (c != EOF) 
    { 
        fputc(c, tmp_file); 
        c = fgetc(old_file); 
    } 

    fclose(tmp_file);
    fclose(old_file);

return tmp_file;
}

void RenameTmpFile(FILE *file_name,const char *new_name)
{

}

void StrOperation(FILE *file_name, char *intput_string)
{
	
}

int StrComparison(FILE *file_name,char *intput_string)
{

}

void AddLineToStart(FILE *file, const char *file_name, const char *intput_string)
{
	FILE *tmp_file;
	char *tmp_file_name = "tmp_file.txt";

	char c = 0;
	
	tmp_file = CreateNewFile(tmp_file_name);	/*Creat new Temp file */
	tmp_file = MergeTmpFile(file, file_name, tmp_file, tmp_file_name, intput_string );
	RemoveFile(file_name);
	rename(tmp_file_name,file_name);			/*rename tmp file with old name */

}

void AddLineToEnd(FILE *file, const char *file_name, const char *intput_string)
{
	char c=0;
	file = fopen(file_name,"a");
	fputs(intput_string, file);		/*fputs() to insert string data type */
	fputs("\n", file);				/*Insert New Line for the next input*/
	fclose(file);
	
}

int CountLines(FILE *file, const char *file_name)
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

