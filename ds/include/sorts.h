#ifndef __SORTS_H__
#define __SORTS_H__

#include <stddef.h> /*size_t*/

void PrintArray(int arr[], size_t size);

void BubbleSort(int arr[], size_t n);
void BubbleSortBreak(int arr[], size_t n);
void InsertionSort(int arr[], size_t n);
void SelectionSort(int arr[], size_t n);
int CountingSort(const int *arr, size_t size, int min, int max, int *res);

#endif