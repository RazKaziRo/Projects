#ifndef _ws3func_h
#define _ws3func_h

#include <stdlib.h> /*Import size_y */

void *MyMalloc(size_t size, int flag);
void *PrintEnv(const char **);
char **CopyEnv(const char **);
void CleanEnvCopy(char **envp_copy);
long int EnvpSize(const char **envp); /*return Envp size - Num of pointers */
char *MyStrDup(const char *s);
void printSizeOfType(char *type);
void *Jospehus(const char *soldierlist, char *sw_ptr);
int LiveCounter(const char *soldierlist);
void *Killlive(const char *soldierlist, char *sw_ptr);
char *NextAlive(const char *soldierlist, char *sw_ptr);

#endif