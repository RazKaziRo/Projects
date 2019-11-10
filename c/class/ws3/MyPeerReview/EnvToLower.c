#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

size_t envpLen(const char **envp);
char **CopyEnvp(const char **envp, int *allocFailure);
char *Strdup(const char *s, int *allocFailure);
char *MyMalloc(size_t size, int *allocFailure);
char *Strcpy(char *dest, const char *src);
void CleanEnvCopy(char **copyEnvp);
void PrintEnv(const char **envp);


int main(int argc, char *argv[], const char **envp)
{

int size = 50;
int *ptr = &size;

char **envp_copy = CopyEnvp(envp,ptr);
/*PrintEnv((const char **)envp_copy);*/
/*CleanEnvCopy(envp_copy);*/
/*
   char *flag = "-f";

   if (argv[1])
   {
      if (strcmp(argv[1], flag) == 0)
      {
         allocFailure = envpLen(envp) - 10;
      }
   }

   copyEnvp = CopyEnvp(envp, &allocFailure);

   if (copyEnvp == NULL)
   {
      printf("Failure, the program failed to allocate\n");
      return 0;
   }

   PrintEnv((const char **)copyEnvp);

   CleanEnvCopy(copyEnvp);
*/
   return 0;
}


char **CopyEnvp(const char **envp, int *allocFailure)
{
   /* Get envp copy its strings and lowercase them.
      envp is pointer to pointers */

   const char **runnerEnvp = envp;
   char **copyEnvp, **runnerCopy;

   copyEnvp = (char **) calloc((envpLen(envp) + 1), sizeof(char *));
   runnerCopy = copyEnvp;
   
   while (*runnerEnvp != NULL)
   {
      *runnerCopy = (char *) Strdup(*runnerEnvp, allocFailure);
      if (*runnerCopy == NULL)
      {
         CleanEnvCopy(copyEnvp);
         return NULL;
      }

      ++runnerCopy;
      ++runnerEnvp;
   }
   
   return copyEnvp;
}


size_t envpLen(const char **envp)
{
   const char **runner = envp;
   size_t l = 0;
   
   while (*runner != NULL)
   {
      ++l;
      ++runner;
   }

   return l;
}


char *Strdup(const char *s, int *allocFailure)
{
   /* Duplicates string to a different location in the memory.
      Gets a pointer to string. */

   char *ptr;
   int len = strlen(s);

   ptr = (char *) MyMalloc(len + 1 * sizeof(char), allocFailure);
   if (ptr == NULL)
   {
      return NULL;
   }
   Strcpy(ptr, s);

   return ptr;
}


char *MyMalloc(size_t size, int *allocFailure)
{
   char *str;

   if (*allocFailure > 0)
   {
      if (*allocFailure == 1)
      {
         return NULL;
      }

      --(*allocFailure);
   }

   str = (char *) calloc(size, 1);
   
   return str;
}
   
         
char *Strcpy(char *dest, const char *src)
{
   /* Copy string to a specific destination.
      Gets two pointers, one of the string and one for the destination */

   char *runner_d = dest;
   const  char *runner_s = src;

   while ('\0' != *runner_s)
   {
      *runner_d = tolower(*runner_s);
      ++runner_d;
      ++runner_s;
   }

    *runner_d = '\0';
   
   return dest;
}


void CleanEnvCopy(char **copyEnvp)
{
   char **runner = copyEnvp;

   while (*runner != NULL)
   {
      free(*runner);
      *runner = NULL;
      ++runner;
   }

   free(copyEnvp);
   copyEnvp = NULL;
}


void PrintEnv(const char **envp)
{
   const char **runner = envp;

   while (*runner != NULL)
   {
      printf("%s\n", *runner);
      ++runner;
   }
}



















