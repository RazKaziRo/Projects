#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int Joseph(int soldiers, int start);


int main()
{
   int soldiers, start;
   int survivor;

   printf("Enter number of soldiers: ");
   scanf("%d", &soldiers);
   printf("Who start? ");
   scanf("%d", &start);

   survivor = Joseph(soldiers, start);
   printf("%d\n", survivor);

   return survivor;
}


int Joseph(int soldiers, int start)
{
   int *solArr, *curSol, *rightSol;
   int solAlive = soldiers;

   solArr = calloc(soldiers, sizeof(int));
   curSol = solArr + start - 1, rightSol = solArr + soldiers - 1;

   while (solAlive > 1)
   {
      if (curSol == rightSol)
      {
         curSol = solArr;
      }
      else
      {
         ++curSol;
      }

      while (*curSol == 1)
      {
         ++curSol;
      }
         
      *curSol = 1;

      if (curSol == rightSol)
      {
         while (*curSol != 0)
         {
            --curSol;
         }
         rightSol = curSol;
         curSol = solArr;
      }
         
      while (*curSol == 1)
      {
         ++curSol;
      }
      
      --solAlive;
   }

   return curSol - solArr + 1;
}









