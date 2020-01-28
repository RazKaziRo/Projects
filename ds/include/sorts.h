#ifndef __SORTS_H__
#define __SORTS_H__

#include <stddef.h> /*size_t*/

void PrintArray(int arr[], size_t size);

void BubbleSort(int arr[], size_t n);
void BubbleSortBreak(int arr[], size_t n);
void InsertionSort(int arr[], size_t n);
void SelectionSort(int arr[], size_t n);
int CountingSort(const int *arr, size_t size, int min, int max, int *res);
int RadixSort(unsigned int *src_arr, size_t size, unsigned int num_of_bits);
void MergeSort(int *src_arr,int *dest_arr, size_t size);
void QuickSort(void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *));
void *JumpSerach(void *arr, size_t nmemb, size_t size, int (*compare)(const void *, const void *, void *param), const void *data, void *param);
void *BinarySearch(void *arr, size_t nmemb, size_t size, int (*compare)(const void *, const void *, void *param), const void *data, void *param);

#endif