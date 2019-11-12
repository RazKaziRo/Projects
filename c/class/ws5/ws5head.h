#ifndef _ws5func_h
#define _ws5func_h

void Logger(FILE *file_name);

FILE *CreateNewFile(const char *file_name); 

void StrOperation(FILE *file_name, char *intput_string);

int StrComparison(FILE *file_name, char *intput_string);

void AddLineToStart(FILE *file,const char *file_name, const char *intput_string);

void AddLineToEnd(FILE *file,const char *file_name, const char *intput_string);

int CountLines(FILE *file,const char *file_name);

FILE *MergeTmpFile(FILE *old_file,const char *old_file_name, FILE *tmp_file ,const char *tmp_file_name
 ,const char *intput_string) ;

void RemoveFile(const char *file_name);

int ExitPrograme();

#endif