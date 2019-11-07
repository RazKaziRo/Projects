#include <stdio.h>
#ifndef _ws3func_h
#define _ws3func_h


void *StringToLower(char *);
void *PrintEnv(const char **);
char **CopyEnv(const char **);
void CleanEnvCopy(char **envp);
long int EnvpSize(const char **envp); /*return Envp size - Num of pointers */
char *MyStrDup(const char *s);

#endif