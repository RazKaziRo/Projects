#include <time.h> /*clock()*/
#include <stdio.h> /*printf()*/
#include <stdlib.h> /*malloc()*/

#include "sorts.h"

#define UNUSED(x) (void)(x)
#define FREE(ptr) free(ptr); ptr=NULL;
#define MAX_ARRAY_NUM 100
#define MIN_ARRAY_NUM (MAX_ARRAY_NUM/2)
#define BUCKET 4

static clock_t start, end;
static double cpu_time_used;

int g_arr[MAX_ARRAY_NUM];

static void InitArray()
{
    int i = 0;

    srand(time(0));
    for (i = 0; i < MAX_ARRAY_NUM; ++i) 
    {
        g_arr[i] = rand() % MAX_ARRAY_NUM;
    }
}

static int CompareFunction(const void *data1, const void *data2)
{
    return(*(int *)data1 - *(int*)data2);
}

static int CompareWithParamFunction(const void *data1, const void *data2, void *param)
{
    return(*(int *)data1 - *(int*)data2);
}


void TestBubbleSort()
{
    InitArray();
    start = clock(); 
    BubbleSort(g_arr, MAX_ARRAY_NUM);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

/*
    printf("BubbleSort() Sorted array: \n");
    PrintArray(g_arr, MAX_ARRAY_NUM);
*/
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

void TestRadixSort()
{   

    InitArray();   
    
    start = clock(); 
    RadixSort((unsigned int *)g_arr, MAX_ARRAY_NUM, BUCKET);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    /*
    printf("RadixSort() Sorted array: \n");
    PrintArray(g_arr, MAX_ARRAY_NUM);
    */
    printf("RadixSort() took %f seconds to execute \n", cpu_time_used); 

    printf("\n"); 
}

void TestMergeSort()
{
    int a[] = {6, 4, 1};
    size_t arr_size = sizeof(a)/sizeof(a[0]);
    int b[3];

    PrintArray(a, arr_size);
    MergeSort(a,b, arr_size);
    PrintArray(a, arr_size);

}

void TestQuickSort()
{
    InitArray(); 

    printf("qsort() array BEFORE:\n"); 
    PrintArray(g_arr, MAX_ARRAY_NUM);
    start = clock(); 
    qsort(g_arr, MAX_ARRAY_NUM, sizeof(g_arr[0]), &CompareFunction);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nqsort() array AFTER:\n"); 
    PrintArray(g_arr, MAX_ARRAY_NUM);
    printf("qsort() took %f seconds to execute \n", cpu_time_used); 
    printf("\n"); 

    sleep(5);
    InitArray(); 

    printf("QuickSort() array BEFORE:\n"); 
    PrintArray(g_arr, MAX_ARRAY_NUM);
    printf("\n"); 

    start = clock(); 
    QuickSort(g_arr, MAX_ARRAY_NUM, sizeof(g_arr[0]), &CompareFunction);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("QuickSort() array AFTER:\n"); 
    PrintArray(g_arr, MAX_ARRAY_NUM);
    printf("QuickSort() took %f seconds to execute \n", cpu_time_used);  
}

void TestBinarySearch()
{
    int num = 1;
    int *res = NULL;

    InitArray(); 
    printf("Serching: %d \n", num);

    qsort(g_arr, MAX_ARRAY_NUM, sizeof(g_arr[0]), &CompareFunction);
    PrintArray(g_arr, MAX_ARRAY_NUM);

    res = BinarySearch(g_arr, MAX_ARRAY_NUM, sizeof(g_arr[0]), &CompareWithParamFunction, &num, NULL);
    printf("Result: %d ", *res);
}

void TestJumpSerach()
{
    int a[] = {0,1,1,2,3,5,8,13,21,34,55,77,89,91,95,110};
    int *res = NULL;
    int num = 98;

    InitArray(); 
    printf("Serching: %d \n", num);

    qsort(g_arr, MAX_ARRAY_NUM, sizeof(g_arr[0]), &CompareFunction);

    PrintArray(g_arr, MAX_ARRAY_NUM);
    res = JumpSerach(g_arr, MAX_ARRAY_NUM,sizeof(g_arr[0]),&CompareWithParamFunction, &num, NULL);

    printf("num: %d", *res);
}


int main(int argc, char const *argv[])
{

/*
    TestBubbleSort();
   
    TestBubbleSortBreak();

    TestSelectionSort();

    TestInsertionSort();

    TestCountingSort();

    TestRadixSort();

    TestMergeSort();

    TestQuickSort();

    TestBinarySearch();
*/
    TestJumpSerach();

    UNUSED(argv);
    UNUSED(argc);
	return 0;
}