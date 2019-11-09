#ifndef _ws3func_h
#define _ws3func_h

void *StringToLower(char *);
void *PrintEnv(const char **);
char **CopyEnv(const char **);
void CleanEnvCopy(char **envp);
long int EnvpSize(const char **envp); /*return Envp size - Num of pointers */
char *MyStrDup(const char *s);
void printSizeOfType(char *type);
void *Jospehus(const char *soldierlist, char *sw_ptr);
int LiveCounter(const char *soldierlist);
void *killsoldier(const char *soldierlist, char *sw_ptr);

#endif