#include <stdio.h> /*printf()*/
#include <stdlib.h>/*malloc()*/
#include <assert.h>/*assert()*/

#include "sorts.h"

#define FREE(ptr) free(ptr); ptr=NULL;
#define BITS_IN_BYTE 8
#define INT_NUM_OF_BITS sizeof(unsigned int)*BITS_IN_BYTE

static void Swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

static void SwapArrayPtr(unsigned int **src_arr, unsigned int **dest_arr)
{
  unsigned int *address_holder = *src_arr;
  *src_arr = *dest_arr;
  *dest_arr = address_holder;
}

void PrintArray(int arr[], size_t size) 
{ 
    size_t i = 0; 

    assert(NULL != arr);

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]); 
    }

    printf("\n"); 
} 

void BubbleSort(int arr[], size_t n) 
{ 	
  size_t i, j; 

  assert(NULL != arr);

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

   assert(NULL != arr);

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

    assert(NULL != arr);

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

    assert(NULL != arr);
  
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

    assert(NULL != arr);
    assert(NULL != res_arr);

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

      for (i = (size - 1); i > 0; --i)  
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

static void RadixCountingSort(unsigned int *src_arr, size_t src_arr_size, 
  unsigned int mask, unsigned int shift, 
  size_t *count_arr,unsigned int *dest_arr)
{
  size_t i = 0;

  assert(NULL != src_arr);
  assert(NULL != count_arr);
  assert(NULL != dest_arr);

  for (i = 0; i <= mask; ++i) /*reset count array*/
  {
    count_arr[i] = 0;
  }

  for (i = 0; i < src_arr_size; ++i)
  {
    ++count_arr[(src_arr[i] >> shift) & mask];
  }

  for (i = 1; i <= mask; ++i)
  {
    count_arr[i] += count_arr[i - 1];
  }

  for (i = (src_arr_size - 1); (long)i >= 0; --i)
  {
    dest_arr[count_arr[(src_arr[i] >> shift) & mask] - 1] = src_arr[i];
    --count_arr[(src_arr[i] >> shift) & mask];
  }
}

int RadixSort(unsigned int *src_arr, size_t src_arr_size, unsigned int num_of_bits)
{
  unsigned int i = 0;
  unsigned int mask = (1 << num_of_bits) - 1;

  unsigned int *dest_arr = 
  (unsigned int *)malloc(src_arr_size * sizeof(unsigned int));

  size_t *count_arr = (size_t *)malloc((mask + 1) * sizeof(size_t));

  assert(NULL != src_arr);

  if(NULL != dest_arr)
  {
    if(NULL != count_arr)
    {
      for(i = 0; i < INT_NUM_OF_BITS/num_of_bits; ++i)
      {
        RadixCountingSort(src_arr, src_arr_size, mask,
         (i * num_of_bits), count_arr, dest_arr);
        SwapArrayPtr(&src_arr, &dest_arr);
      }

      FREE(count_arr);
      FREE(dest_arr);
      return 0;
    }
    else
    {
      FREE(dest_arr);
    }
  }
  return 1;
}