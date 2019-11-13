#include <stdio.h>
#include <string.h> 		/*Import strlen() */
#include <stdlib.h>         /*Inport realloc()*/
#include "ws5head.h"



void Logger(const char *file_name)
{
	/*
	FILE *file;

	
	char user_input[100];
	struct operations op[5];
	Initialize(op);

	printf("Enter String: ");
	scanf("%s", user_input);

	StrComparison(file, file_name, user_input);
*/


}


void *Initialize(Operations op[])
{
	op[0].string = "-remove";
	op[0].ptr_cmp = &StringCompare;
	op[0].ptr_opr = &RemoveFile;

	op[1].string = "-count";
	op[1].ptr_cmp = &StringCompare;
	op[1].ptr_opr = &CountLines;

	op[2].string = "-exit";
	op[2].ptr_cmp = &StringCompare;
	op[2].ptr_opr = &ExitPrograme;

	op[2].string = "<";
	op[2].ptr_cmp = &CharCompare;
	op[2].ptr_opr = &ExitPrograme;


}

Return CharCompare(const char *string, const char *user_input)
{
	if(*string == *user_input)  	/*check for the first char */
	{
		return SUSCESS;
	}
	else
	{
		return FAIL;
	}
}

Return StringCompare(const char *string, const char *user_input)
{
	if(strcmp(user_input,string))
	{
		return SUSCESS;
	}
	else
	{
		return FAIL;
	}
}

FILE *CreateNewFile(const char *file_name) /* Creat New File */
{
	FILE *new_file;
	new_file =fopen(file_name,"w");
	fclose(new_file);

return new_file;
}


FILE *MergeTmpFile(const char *file_name,const char *tmp_file_name, const char *intput_string) 
{	
	FILE *exist_file;
	FILE *tmp_file;

	char c = 0;

	exist_file = fopen(file_name, "r"); 				/*Open Exsiting File for reading*/
	tmp_file = fopen(tmp_file_name, "w");				/*Open Temp File for writing*/
	fputs(intput_string, tmp_file);						/* Insert New String */
	fputs("\n", tmp_file);						
	c = fgetc(exist_file);

	while (c != EOF) 
    { 
        fputc(c, tmp_file); 
        c = fgetc(exist_file); 
    } 

    fclose(tmp_file);
    fclose(exist_file);

	return tmp_file;
}


Return AddLineToStart(const char *file_name, const char *intput_string)
{
	FILE *tmp_file;
	char *tmp_file_name = "tmp_file.txt";

	char c = 0;
	
	tmp_file = CreateNewFile(tmp_file_name);	/*Creat new Temp file */
	tmp_file = MergeTmpFile(file_name, tmp_file_name, intput_string+1);
	RemoveFile(file_name, file_name);
	rename(tmp_file_name,file_name);			/*rename tmp file with old name */

	return SUSCESS;
}

Return AddLineToEnd(const char *file_name, const char *intput_string)
{	
	FILE *file;
	char c=0;
	file = fopen(file_name,"a");
	fputs(intput_string, file);		/*fputs() to insert string data type */
	fputs("\n", file);				/*Insert New Line for the next input*/
	fclose(file);

	return SUSCESS;
	
}

Return CountLines(const char *file_name, const char *intput_string)
{	
	FILE *file;
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

  	return SUSCESS;
}



Return RemoveFile(const char *file_name, const char *intput_string)
{
	remove(file_name);

return SUSCESS;

}

Return ExitPrograme()
{
	return EXIT;
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

