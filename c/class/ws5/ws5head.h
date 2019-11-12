#ifndef _ws5func_h
#define _ws5func_h

typedef enum 
{
	REMOVE_FILE, 			/*0*/
	COUNT_LINES,				/*1*/
	EXIT_PROG,				/*2*/
	ADD_LINE_TO_START,  /*3*/
	ADD_LINE_TO_END		/*4*/

}OPERATIONS;

char *getInput();

void Logger(const char *file_name);

FILE *CreateNewFile(const char *file_name); 

int StrToOperation(const char *user_input);

void StrComparison(FILE *file,const char *file_name,const char *user_input, OPERATIONS operation);

void AddLineToStart(FILE *file,const char *file_name, const char *intput_string);

void AddLineToEnd(FILE *file,const char *file_name, const char *intput_string);

void CountLines(FILE *file,const char *file_name);

FILE *MergeTmpFile(FILE *old_file,const char *old_file_name, FILE *tmp_file ,const char *tmp_file_name
 ,const char *intput_string) ;

void RemoveFile(const char *file_name);

int ExitPrograme();


#endif