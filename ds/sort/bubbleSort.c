#include <time.h>
#include <stdio.h> 

#define UNUSED(x) (void)(x)

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void bubbleSort(int arr[], int n) 
{ 	
   int i, j; 
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			} 
		}    
	}          
} 

void bubbleSortBreak(int arr[], int n) 
{ 
   int i, j; 
   int swapped; 

   for (i = 0; i < n-1; ++i) 
   { 
     swapped = 0; 

     for (j = 0; j < n-i-1; ++j) 
     { 
        if (arr[j] > arr[j+1]) 
        { 
           swap(&arr[j], &arr[j+1]); 
           swapped = 1; 
        } 
     } 

     if (swapped == 0) 
        break; 
   } 
} 

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int main(int argc, char const *argv[])
{
	clock_t start, end;
    double cpu_time_used;
    int arr1[] = {64, 34, 25, 12, 22, 11, 90,23,32,1,2,3,44,5,99,6,8,45,456,4,32,3,32,7,8,5,4,35,91}; 
    int arr2[] = {64, 34, 25, 12, 22, 11, 90,23,32,1,2,3,44,5,99,6,8,45,456,4,32,3,32,7,8,5,4,35,91}; 
    int n = sizeof(arr1)/sizeof(arr1[0]); 

    start = clock();
    bubbleSort(arr1, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("bubbleSort() took %f seconds to execute \n", cpu_time_used); 
    printf("Sorted array(2): \n"); 
    printArray(arr1, n); 

    start = clock();
    bubbleSortBreak(arr2, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("bubbleSortBreak() took %f seconds to execute \n", cpu_time_used); 
    printf("Sorted array(2): \n"); 
    printArray(arr2, n); 
    UNUSED(argv);
    UNUSED(argc);
	return 0;
}