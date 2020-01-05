#include <stdio.h> /*printf()*/
#include <stdlib.h>/*malloc()*/

#define FREE(ptr) free(ptr); ptr=NULL;

static void Swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void PrintArray(int arr[], size_t size) 
{ 
    size_t i = 0; 

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]); 
    }

    printf("\n"); 
} 

void BubbleSort(int arr[], size_t n) 
{ 	
  size_t i, j; 

	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				Swap(&arr[j], &arr[j+1]);
			} 
		}    
	}          
} 

void BubbleSortBreak(int arr[], size_t n) 
{ 
   size_t i = 0, j = 0; 
   int swapped = 1; 

   for (i = 0; i < n-1; ++i) 
   { 

     swapped = 0; 

     for (j = 0; j < n-i-1; ++j) 
     { 
        if (arr[j] > arr[j+1]) 
        { 
           Swap(&arr[j], &arr[j+1]); 
           swapped = 1; 
        } 
     }
     if(0 == swapped)
     {
        break;
     } 
   } 
} 

void InsertionSort(int arr[], size_t n) 
{ 
    size_t i = 0, key = 0, j = 0; 
    for (i = 1; i < n; i++) 
    { 
        key = arr[i]; 
        j = i - 1; 
  
        while (j > 0 && arr[j] > (int)key) 
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 

        arr[j + 1] = key; 
    } 
} 

void SelectionSort(int arr[], size_t n) 
{ 
    size_t i = 0, j = 0, min_idx = 0; 
  
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 

        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                 min_idx = j;
            } 
        } 

     Swap(&arr[min_idx], &arr[i]); 
    } 
} 

int CountingSort(const int *arr, size_t size, int min, int max, int *res_arr)
{
    size_t range = max - min + 1;
    size_t i = 0;

    int *count_arr = (int *) calloc(range, sizeof(arr[0]));
    if(NULL != count_arr)
    {
      for(i = 0; i < size ; ++i)
      {
        ++count_arr[arr[i] - min];
      }

      for(i = 1; i < range; ++i)
      {
        count_arr[i] += count_arr[i-1];
      }

      for (i = size - 1; i > 0; --i)  
      {  
          res_arr[count_arr[arr[i] - min] - 1] = arr[i];  
          --count_arr[arr[i] - min];  
      }  

      res_arr[count_arr[arr[i] - min] - 1] = arr[i];  
      --count_arr[arr[i] - min]; 

      FREE(count_arr);
      return 0;
    }

return 1;

}   