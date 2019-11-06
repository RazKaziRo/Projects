#include <stdio.h>
#ifndef _ws3func_h
#define _ws3func_h


void *StringToLower(char **);
void *PrintEnv(const char **envp);
char *CopyEnv(const char **envp);
void CleanEnvCopy(char *);

#endif