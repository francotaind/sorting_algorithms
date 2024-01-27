#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps the values of two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    size_t pass, min, i;

    for (pass = 0; pass < size - 1; pass++)
    {
        min = pass;

        for (i = pass + 1; i < size; i++)
        {
            if (array[i] < array[min])
                min = i;
        }

        if (min != pass)
        {
            swap(&array[pass], &array[min]);
            print_array(array, size);
        }
    }
}

