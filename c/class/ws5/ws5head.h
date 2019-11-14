/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW5 - Logger Infrastructure.
 * Date: 13.11.2019
 * Language: C
 * Reviewer: Itai Marienberg 
 */

#ifndef _ws5func_h
#define _ws5func_h
#include <stdio.h>

#define UNUSED(var)  ((void)(var))

typedef enum 
{
	FAIL,				/*0*/
	SUCCESS, 			/*1*/			
	EXIT,				/*2*/
	FILE_NOT_FOUND,		/*3*/
	NO_FILE_TO_REMOVE	/*4*/
	
}LoggerReturnStatus;

typedef struct operations 
{
      char *string;
      LoggerReturnStatus (*ptr_cmp)(const char *string, const char *user_input);
      LoggerReturnStatus (*ptr_opr)(const char *file_name,const char *user_input);

} Operations;

void StartLoggerInfrastructure();

char *getInput();

void Initialize(Operations op[]);

void LoggerInfrastructure(const char *file_name);

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