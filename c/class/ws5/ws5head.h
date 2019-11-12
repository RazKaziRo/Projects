#ifndef _ws5func_h
#define _ws5func_h

void Logger(FILE *file_name);

FILE *CreatNewFile(const char *file_name); 

void StrOperation(FILE *file_name, char *intput_string);

int StrComparison(FILE *file_name, char *intput_string);

void addLineToStart(FILE *file,const char *file_name, const char *intput_string);

void addLineToEnd(FILE *file,const char *file_name, const char *intput_string);

int CountLines(FILE *file,const char *file_name);

void RemoveFile(const char *file_name);

int ExitPrograme();

#endif