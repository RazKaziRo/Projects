#include <stdio.h>
#include <string.h> 		/*Import strlen() */
#include <stdlib.h>         /*Inport realloc()*/
#include "ws5head.h"



void Logger(const char *file_name)
{
	FILE *file;

	int op = 0;
	char user_input[100];

	printf("Enter String: ");
	scanf("%s", user_input);

	op = StrToOperation(user_input);
	StrComparison(file, file_name, user_input, op);
/*
	typedef struct str 
	{
       char  *input ;
       void(*ptrcompare)(FILE *file,const char *file_name,const char *user_input);

	} STR;
*/
}


int StrToOperation(const char *user_input)
{

	if(user_input =="-remove")
	{
		return REMOVE_FILE;
	}

	if(user_input == "-count")
	{
		return COUNT_LINES;
	}
}


void StrComparison(FILE *file,const char *file_name,const char *user_input, OPERATIONS op)
{

	switch(op)
	{
		case (REMOVE_FILE):
		RemoveFile(file_name);
		break;

		case(COUNT_LINES):
		CountLines(file, file_name);
		break;

		case(EXIT_PROG):
		ExitPrograme();
		break;

		case(ADD_LINE_TO_START):
		AddLineToStart(file, file_name, user_input);
		break;

		/*
		default:
		AddLineToEnd(file, file_name, user_input);
		break;
		*/
	}


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

void CountLines(FILE *file, const char *file_name)
{
	int lines = 0;			/*Line counter */
	char c; 				/*store characters from file*/

	file = fopen(file_name, "r");
	for (c = getc(file); c != EOF; c = getc(file)) 	/*fgetc() = getc() */
	{
		if (c == '\n')
		{
			 ++lines;
		}
	}
    fclose(file); 
    printf("Numer of lines in \"%s\" File: %d \n", file_name, lines);
}



void RemoveFile(const char *file_name)
{
	remove(file_name);
}

int ExitPrograme()
{
	return 0;
}

char *getInput()
{
	int length = 100; 
	char *str = malloc(length * sizeof(char)); 
	int count = 0; 
	char c; 
	while((c = getchar()) != '\n')
	{ 
	   if(count >= length)
	   {
	     str = realloc(str, (length += 10) * sizeof(char));
	   }
	   str[count++] = c;
	}

return str;
}

