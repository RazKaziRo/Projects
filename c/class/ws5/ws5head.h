#ifndef _ws5func_h
#define _ws5func_h
#include <stdio.h>

typedef enum 
{
	FAIL,				/*0*/
	SUSCESS, 			/*1*/			
	EXIT				/*2*/
	
}LoggerReturnStatus;

typedef struct operations 
{
      char *string;
      LoggerReturnStatus (*ptr_cmp)(const char *string, const char *user_input);
      LoggerReturnStatus (*ptr_opr)(const char *file_name,const char *user_input);

} Operations;

void StartLogger();

char *getInput();

void Initialize(Operations op[]);

void Logger(const char *file_name);

FILE *CreateNewFile(const char *file_name); 

int StrToOperation(const char *user_input);

void StrComparison(FILE *file,const char *file_name,const char *user_input);

LoggerReturnStatus AllTheRest(const char *string, const char *user_input);

LoggerReturnStatus AddLineToStart(const char *file_name, const char *intput_string);

LoggerReturnStatus AddLineToEnd(const char *file_name, const char *intput_string);

LoggerReturnStatus CountLines(const char *file_name, const char *intput_string);

LoggerReturnStatus StringCompare(const char *string, const char *user_input);

LoggerReturnStatus CharCompare(const char *string, const char *user_input);

FILE *MergeTmpFile(const char *file_name,const char *tmp_file_name, const char *intput_string);

LoggerReturnStatus RemoveFile(const char *file_name, const char *intput_string);

LoggerReturnStatus ExitPrograme();


#endif