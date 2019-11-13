#include <stdio.h>
#include <string.h> 		/* Import strlen() */
#include <stdlib.h>         /* Inport realloc()*/
#include <assert.h>			/* import assert() */
#include "ws5head.h"
#define NUM_OF_OPERATIONS 5 /*Number of total Operations */


void StartLoggerInfrastructure()

{	char *file_name = NULL;
	printf("Enter File Name: ");
	file_name = getInput();

	LoggerInfrastructure(file_name);

	free(file_name);
	file_name = NULL;
}

void LoggerInfrastructure(const char *file_name)
{

	char *user_input = NULL;
	int Logger_Status = SUCCESS, i = 0;
	struct operations op[NUM_OF_OPERATIONS];

	assert( 0 != file_name);

	Initialize(op);
	
	while (EXIT != Logger_Status)
	{
		printf("Enter String: ");
		user_input = getInput();

		for (i = 0 ; i < 5; i++)
		{
			if(SUCCESS ==  op[i].ptr_cmp(op[i].string, user_input))
			{
				Logger_Status = op[i].ptr_opr(file_name,user_input);
				break;
			}
		}

		free(user_input);
		user_input = NULL;
	}
}


void Initialize(Operations op[])
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
		UNUSED(string);
		UNUSED(user_input);

		assert( 0 != string);
		assert( 0 != user_input);

		return SUCCESS;
}

LoggerReturnStatus CharCompare(const char *string, const char *user_input)
{
	assert( 0 != string);
	assert( 0 != user_input);

	if(*string == *user_input)  	/*check for the first char */
	{
		return SUCCESS;
	}

	else
	{
		return FAIL;
	}
}

LoggerReturnStatus StringCompare(const char *string, const char *user_input)
{
	assert( 0 != string);
	assert( 0 != user_input);

	if(0 == strcmp(user_input,string))
	{
		return SUCCESS;
	}

	else
	{
		return FAIL;
	}
}

FILE *CreateNewFile(const char *file_name) /* Creat New File */
{
	FILE *new_file;

	assert( 0 != file_name);

	new_file =fopen(file_name,"w");
	fclose(new_file);

	return new_file;
}


FILE *MergeTmpFile(const char *file_name,const char *tmp_file_name, const char *intput_string) 
{	
	FILE *exist_file;
	FILE *tmp_file;

	char c = 0;

	assert( 0 != file_name);
	assert( 0 != intput_string);

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
	UNUSED(tmp_file);

	assert( 0 != file_name);
	assert( 0 != intput_string);

	tmp_file = CreateNewFile(tmp_file_name);	/*Creat new Temp file */
	tmp_file = MergeTmpFile(file_name, tmp_file_name, intput_string+1);
	RemoveFile(file_name, file_name);
	rename(tmp_file_name,file_name);			/*rename tmp file with old name */
	free((char *)intput_string);	
	intput_string = NULL;		

	return SUCCESS;
}

LoggerReturnStatus AddLineToEnd(const char *file_name, const char *intput_string)
{	
	FILE *file;

	assert( 0 != file_name);
	assert( 0 != intput_string);

	file = fopen(file_name,"a");
	fputs(intput_string, file);		/*fputs() to insert string data type */
	fputs("\n",file);
	fclose(file);

	return SUCCESS;
	
}

LoggerReturnStatus CountLines(const char *file_name, const char *intput_string)
{	

	FILE *file;
	int lines = 0;			/*Line counter */
	char c; 				/*store characters from file*/

	UNUSED(intput_string);

	assert( 0 != file_name);
	assert( 0 != intput_string);

	file = fopen(file_name, "r");
	if(NULL != file)
	{
		for (c = fgetc(file); c != EOF; c = fgetc(file)) 	/*fgetc() = getc() */
		{
			if (c == '\n')
			{
			 ++lines;
			}
		}

    fclose(file); 
    printf("Number of lines in \"%s\" File: %d \n", file_name, lines);

	return SUCCESS;
	}
	printf("No File Found \n");
	return FILE_NOT_FOUND;
}



LoggerReturnStatus RemoveFile(const char *file_name, const char *intput_string)
{
	UNUSED(file_name);
	UNUSED(intput_string);

	assert( 0 != file_name);
	assert( 0 != intput_string);

	if(0 == remove(file_name))
	{
	return SUCCESS;
	}
	else
	{
	printf("No File To Remove \n");
	return NO_FILE_TO_REMOVE;
	}


}

LoggerReturnStatus ExitPrograme()
{
	return EXIT;
}

char *getInput()
{
    size_t len_max = 128;
    size_t current_size = 0;
    
    char *str_input = malloc(len_max);
    current_size = len_max;

    if(str_input != NULL)
    {
	int c = EOF;
	unsigned int i =0;

		while (( c = getchar() ) != '\n' && c != EOF)
		{
			str_input[i++]=(char)c;

			if(i == current_size)
			{
	            current_size = i+len_max;
				str_input = realloc(str_input, current_size);
			}
		}

	str_input[i] = '\0';
	}

	return str_input;
}

