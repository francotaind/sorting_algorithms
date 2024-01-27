#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in an array.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 *
 * Return: Nothing.
 */
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme for quicksort.
 * @arr: The array to be sorted.
 * @low: Starting index of the partition.
 * @high: Last index of the partition.
 * @size: Size of the array.
 *
 * Return: Index of the pivot element.
 */
int lomuto_partition(int *arr, int low, int high, size_t size)
{
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap(&arr[i], &arr[j]);
                print_array(arr, size);
            }
        }
    }
    
    if (arr[i + 1] != arr[high])
    {
        swap(&arr[i + 1], &arr[high]);
        print_array(arr, size);
    }

    return (i + 1);
}

/**
 * quicksort_recursion - Recursive function to perform quicksort.
 * @arr: The array to be sorted.
 * @low: Starting index of the partition.
 * @high: Last index of the partition.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void quicksort_recursion(int *arr, int low, int high, size_t size)
{
    int pivot_index;

    if (low < high)
    {
        pivot_index = lomuto_partition(arr, low, high, size);
        quicksort_recursion(arr, low, pivot_index - 1, size);
        quicksort_recursion(arr, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - Sorts integers using the quicksort algorithm.
 * @arr: Array to be sorted.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void quick_sort(int *arr, size_t size)
{
    if (arr == NULL || size < 2)
    {
        return;
    }

    quicksort_recursion(arr, 0, size - 1, size);
}

