/*********************************/
/*                               */
/*    Work Sheet 8               */       
/*    Author :Guy Cohen Zedek    */
/*    Reviewed By: Raz           */
/*    Date:   20/11/2019         */
/*                               */
/*********************************/

#ifndef __STRUCT_H__
#define __STRUCT_H__

#include <stdio.h>  /* use for printf */
#include <stdlib.h> /* use for malloc and free */
#include <string.h> /* use for strcat, strlen */

typedef void (*p_print)(void *data);
typedef int (*p_add)(int n, void *data);
typedef int (*p_clean)(void *data);

typedef struct 
{
    p_print print_type;
    p_add add_val;
    p_clean clean_memory;
    void *data;    
    
}object_t;

/* General functions */
int InfraStructure();
void Initialize(object_t obj[]);

/* Add functions */
int AddValueToInt(int n, void *data);
int AddValueToFloat(int n, void *data);
int AddValueToString(int n, void *data);

/* Print function */
void PrintInt(void *data);
void PrintFloat(void *data);
void PrintString(void *data);

/* Clean up functions */
int CleanUp(void *data);
int DemoClean(void *data);

/* Help function */
size_t NumLength(size_t n);

#endif
