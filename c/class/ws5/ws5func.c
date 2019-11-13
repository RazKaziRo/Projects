#include <stdio.h>
#include <string.h> 		/*Import strlen() */
#include <stdlib.h>         /*Inport realloc()*/
#include "ws5head.h"
#define NUM_OF_OPERATIONS 5 /*Number of total Operations */


void *StartLogger()

{	char *file_name = NULL;
	printf("Enter File Name: ");
	file_name = getInput();

	Logger(file_name);
}

void Logger(const char *file_name)
{

	char *user_input = NULL;
	int Logger_Status = SUSCESS, i = 0;
	struct operations op[NUM_OF_OPERATIONS];
	Initialize(op);
	

	while (EXIT != Logger_Status)
	{
		printf("Enter String: ");
		user_input = getInput();


		for (i = 0 ; i < 5; i++)
		{
			if(SUSCESS ==  op[i].ptr_cmp(op[i].string, user_input))
			{
				Logger_Status = op[i].ptr_opr(file_name,user_input);
				break;
			}
		}
		
		free(user_input);
		user_input = NULL;
	}
		free(user_input);
		user_input = NULL;
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

	op[3].string = "<";
	op[3].ptr_cmp = &CharCompare;
	op[3].ptr_opr = &AddLineToStart;

	op[4].string = "All The Rest";
	op[4].ptr_cmp = &AllTheRest;
	op[4].ptr_opr = &AddLineToEnd;

}

LoggerReturnStatus AllTheRest(const char *string, const char *user_input)
{
		return SUSCESS;
}

LoggerReturnStatus CharCompare(const char *string, const char *user_input)
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

LoggerReturnStatus StringCompare(const char *string, const char *user_input)
{
	if(0 == strcmp(user_input,string))
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
	fputs("\n",tmp_file);
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


LoggerReturnStatus AddLineToStart(const char *file_name, const char *intput_string)
{
	FILE *tmp_file;
	char *tmp_file_name = "tmp_file.txt";

	char c = 0;
	
	tmp_file = CreateNewFile(tmp_file_name);	/*Creat new Temp file */
	tmp_file = MergeTmpFile(file_name, tmp_file_name, intput_string+1);
	RemoveFile(file_name, file_name);
	rename(tmp_file_name,file_name);			/*rename tmp file with old name */
	free((char *)intput_string);	
	intput_string = NULL;		

	return SUSCESS;
}

LoggerReturnStatus AddLineToEnd(const char *file_name, const char *intput_string)
{	
	FILE *file;
	char c=0;
	file = fopen(file_name,"a");
	fputs(intput_string, file);		/*fputs() to insert string data type */
	fputs("\n",file);
	fclose(file);

	return SUSCESS;
	
}

LoggerReturnStatus CountLines(const char *file_name, const char *intput_string)
{	
	FILE *file;
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
    printf("Numer of lines in \"%s\" File: %d \n", file_name, lines);

  	return SUSCESS;
}



LoggerReturnStatus RemoveFile(const char *file_name, const char *intput_string)
{
	remove(file_name);

return SUSCESS;

}

LoggerReturnStatus ExitPrograme()
{
	return EXIT;
}

char *getInput()
{
	unsigned int len_max = 128;
    unsigned int current_size = 0;
    
    char *input_str = malloc(len_max);
    current_size = len_max;

    if(input_str != NULL)
    {
	int c = EOF;
	unsigned int i =0;

	while (( c = getchar() ) != '\n' && c != EOF)
	{
		input_str[i++]=(char)c;

		if(i == current_size)
		{
            current_size = i+len_max;
			input_str = realloc(input_str, current_size);
		}
	}

	input_str[i] = '\0';

    }
    return input_str;
}

