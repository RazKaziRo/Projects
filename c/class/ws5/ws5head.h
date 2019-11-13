#ifndef _ws5func_h
#define _ws5func_h
#include <stdio.h>

typedef enum 
{
	FAIL,				/*1*/
	SUSCESS, 			/*0*/			
	EXIT				/*2*/
	
}Return;

typedef struct operations 
{
      char *string;
      Return (*ptr_cmp)(const char *string, const char *user_input);
      Return (*ptr_opr)(const char *file_name,const char *user_input);

} Operations;

char *getInput();

void *Initialize(Operations op[]);

void Logger(const char *file_name);

FILE *CreateNewFile(const char *file_name); 

int StrToOperation(const char *user_input);

void StrComparison(FILE *file,const char *file_name,const char *user_input);

Return AddLineToStart(const char *file_name, const char *intput_string);

Return AddLineToEnd(const char *file_name, const char *intput_string);

Return CountLines(const char *file_name, const char *intput_string);

Return StringCompare(const char *string, const char *user_input);

Return CharCompare(const char *string, const char *user_input);

FILE *MergeTmpFile(const char *file_name,const char *tmp_file_name, const char *intput_string);

Return RemoveFile(const char *file_name, const char *intput_string);

Return ExitPrograme();


#endif