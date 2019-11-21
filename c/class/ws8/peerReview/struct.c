/*********************************/
/*                               */
/*    Work Sheet 8               */       
/*    Author :Guy Cohen Zedek    */
/*    Reviewed By: Raz           */
/*    Date:   20/11/2019         */
/*                               */
/*********************************/

#include "struct.h"

#define MAX_SIZE 3
#define ADD_VALUE 0
#define UNUSED(x) (void)(x)

/* Main function of the program */
int InfraStructure()
{
    int i = 0, status = 0;
    object_t obj[MAX_SIZE];
    
    Initialize(obj);
    
    for ( ; i < MAX_SIZE; ++i)
    {
        obj[i].print_type(obj[i].data);
        status += obj[i].add_val(ADD_VALUE, &obj[i].data);
        obj[i].print_type(obj[i].data);
        status += obj[i].clean_memory(obj[i].data);
        if (status > 0)
        {
            return 1;
        }
    }
   
    return 0;
}

/* Initiallize the struct array */
void Initialize(object_t obj[])
{
    obj[0].print_type = PrintInt;
    obj[0].add_val = AddValueToInt;
    obj[0].clean_memory = DemoClean;
    *((int *)(&(obj[0].data))) = 10;
    
    obj[1].print_type = PrintFloat;
    obj[1].add_val = AddValueToFloat;
    obj[1].clean_memory = DemoClean;
    *((float *)(&(obj[1].data))) = 2.25;
    
    obj[2].print_type = PrintString;
    obj[2].add_val = AddValueToString;
    obj[2].clean_memory = CleanUp;
    obj[2].data = (char *)malloc(6);
    if (NULL == obj[2].data)
    {
        printf("memory not allocated...");
        return;
    }
    strcpy(obj[2].data,"Hello");
}

/* This function add value n to data */
int AddValueToInt(int n, void *data_address)
{ 
    if(NULL == ((int *)(data_address)))
    {
        return 1;
    }
    
    *((int*)(data_address)) += n;
    
    return 0;
}

/* This function add value n to data */
int AddValueToFloat(int n, void *data_address)
{
    if(NULL == ((float *)(data_address)))
    {
        return 1;
    }
    
    *((float *)(data_address)) += n;

    return 0;
}

/* This function concate value n to data */
int AddValueToString(int n, void *data_address)
{
    char *run;
    int size = 0;
    
    size = NumLength(n);

    *((char **)(data_address)) = (char *)realloc(*((char **)data_address), strlen(*(char **)(data_address)) + size + 1);
    if (NULL == *((char **)(data_address)))
    {
        return 1;
    }
    
    run = *((char **)(data_address));
    
    while ('\0' != *run)
    {
        ++run;
    }
    
    run += size;
    *run = '\0';
    --run;
    
    while (size > 0)
    {
        *run = (char)((n % 10) + 48);
        --size;
        n = n/10;
        --run;
    }
    
    return 0;   
}

/* This function prints data of integer type */
void PrintInt(void *data)
{
    printf("%d\n", *((int *)(&data)));
}

/* This function prints data of float type */
void PrintFloat(void *data)
{
    printf("%.2f\n", *((float *)(&data)));
}

/* This function prints data of string type */
void PrintString(void *data)
{
    printf("%s\n", (char *)data);
}

/* This function clean the memmory in the heap */
int CleanUp(void *data)
{
    if (NULL == *((char **)(data)))
    {
        return 1;
    }
    
    free(data);
    data = NULL;
    
    return 0;
}

/* This is demo function - does nothing*/
int DemoClean(void *data)
{   
    UNUSED(data);
    
    return 0;
}

/* This function return the length of number*/
size_t NumLength(size_t n)
{
    size_t count = 0;
    
    while (n > 0)
    {
        n /= 10;
        ++count;
    }
    
    return count;
}



