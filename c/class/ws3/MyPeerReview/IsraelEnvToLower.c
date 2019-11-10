#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

char **CopyEnvp(char **envp);
size_t envpLen(char **envp);
void StringToLower(char *str);
void PrintEnv(char **envp);
char *Strdup(const char *s);
void CleanEnvCopy(char **copyEnvp);


int main(int argc, char *argv[], char **envp)
{
  char *arr[5] = {"abcd",
                     "efgh",
                     "1234",
                     "5678",
                     "\0"
                    };
   

   char **copyEnvp;
   copyEnvp = CopyEnvp(envp);

   PrintEnv(copyEnvp);
   
   CleanEnvCopy(copyEnvp);

   return 0;
}


char **CopyEnvp(char **envp)
{
   /* Get envp copy its strings and lowercase them.
      envp is pointer to pointers */

   char **runnerEnvp = envp, **copyEnvp, **runnerCopy;

   copyEnvp = (char **) calloc((envpLen(envp) + 1), sizeof(char *));
   runnerCopy = copyEnvp;

   while (*runnerEnvp != NULL)
   {
      *runnerCopy = Strdup(*runnerEnvp);

      StringToLower(*runnerCopy);

      ++runnerCopy;
      ++runnerEnvp;
   }

   *runnerCopy = '\0';
   
   return copyEnvp;
}


size_t envpLen(char **envp)
{
   char **runner = envp;
   size_t l = 0;
   
   while (*runner != NULL)
   {
      ++l;
      ++runner;
   }

   return l;
}


char *Strdup(const char *s)
{
   /* Duplicates string to a different location in the memory.
      Gets a pointer to string. */

   char *ptr;
   int len = strlen(s);
   
   assert( NULL != s);    /* Asserts that pointer don't point to zero location */

   ptr = (char *) calloc(len, sizeof(char));  /* Beware! here place in the memory is allocated.
                                                  It should be free after using it. */
   strcpy(ptr, s);

   return ptr;
}


void StringToLower(char *str)
{
   char *runner = str;

   while ('\0' != *runner)
   {
      *runner = tolower(*runner);
      ++runner;
   }
}


void PrintEnv(char **envp)
{
   char **runner = envp;

   while (*runner != NULL)
   {
      printf("%s\n", *runner);
      ++runner;
   }
}


void CleanEnvCopy(char **copyEnvp)
{
   char **runner = copyEnvp;

   while (*runner != NULL)
   {
      free(*runner);
      ++runner;
   }

   free(copyEnvp);
}



















