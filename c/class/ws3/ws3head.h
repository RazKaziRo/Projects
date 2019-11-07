#include <stdio.h>
#ifndef _ws3func_h
#define _ws3func_h


void *StringToLower(char *);
void *PrintEnv(const char **);
char *CopyEnv(const char **);
void CleanEnvCopy(char *);

#endif