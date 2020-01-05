#include <time.h> /*clock()*/
#include <stdio.h> /*printf()*/
#include <stdlib.h> /*malloc()*/

#include "sorts.h"

#define UNUSED(x) (void)(x)
#define FREE(ptr) free(ptr); ptr=NULL;
#define MAX_ARRAY_NUM 50000
#define MIN_ARRAY_NUM (MAX_ARRAY_NUM/2)

static clock_t start, end;
static double cpu_time_used;

int g_arr[MAX_ARRAY_NUM];

static void InitArray()
{
    int i = 0;

    srand(0);
    for (i = 0; i < MAX_ARRAY_NUM; ++i) 
    {
        g_arr[i] = rand() % MAX_ARRAY_NUM - MIN_ARRAY_NUM;
    }
}

void TestBubbleSort()
{
    InitArray();
    start = clock(); 
    BubbleSort(g_arr, MAX_ARRAY_NUM);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    /*printf("BubbleSort() Sorted array: \n");
    PrintArray(g_arr, MAX_ARRAY_NUM);*/

    printf("BubbleSort() took %f seconds to execute \n", cpu_time_used); 

    printf("\n"); 

}

void TestBubbleSortBreak()
{
    InitArray();   
    start = clock(); 
    BubbleSortBreak(g_arr, MAX_ARRAY_NUM);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    /*printf("BubbleSortBreak() Sorted array: \n");
    PrintArray(g_arr, MAX_ARRAY_NUM);*/

    printf("BubbleSortBreak() took %f seconds to execute \n", cpu_time_used); 

    printf("\n"); 

}

void TestInsertionSort()
{

    InitArray();   
    start = clock(); 
    InsertionSort(g_arr, MAX_ARRAY_NUM);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    /*
    printf("InsertionSort() Sorted array: \n");
    PrintArray(arr, n);*/

    printf("InsertionSort() took %f seconds to execute \n", cpu_time_used); 
    printf("\n"); 
}

void  TestSelectionSort()
{

    InitArray();   

    start = clock(); 
    SelectionSort(g_arr, MAX_ARRAY_NUM);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    /*
    printf("SelectionSort() Sorted array: \n");
    PrintArray(arr, n);
    */

    printf("SelectionSort() took %f seconds to execute \n", cpu_time_used); 

    printf("\n"); 
}

void  TestCountingSort()
{
    int *res_arr = (int *) malloc(MAX_ARRAY_NUM * sizeof(int));

    InitArray();  

    start = clock(); 
    CountingSort(g_arr, MAX_ARRAY_NUM, -MIN_ARRAY_NUM, MAX_ARRAY_NUM, res_arr);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
/*
    printf("CountingSort() Sorted array: \n");
    PrintArray(res_arr, MAX_ARRAY_NUM);
*/
    printf("CountingSort() took %f seconds to execute \n", cpu_time_used); 

    printf("\n"); 
    FREE(res_arr);
}

int main(int argc, char const *argv[])
{

    TestBubbleSort();
   
    TestBubbleSortBreak();
  
    TestInsertionSort();

    TestSelectionSort();

    TestCountingSort();

    UNUSED(argv);
    UNUSED(argc);
	return 0;
}