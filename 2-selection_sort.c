#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                  the Selection Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t current_pass = 0;
	size_t min_index;
	size_t i;
	int temporary;

	/* Check if the array is valid for sorting */
	if (array == NULL || size < 2)
		return;

	/* Iterate through the array */
	while (current_pass < size - 1)
	{
		min_index = current_pass;
		i = current_pass + 1;

		/* Find the index of the minimum element in the unsorted part */
		while (i < size)
		{
			if (array[i] < array[min_index])
				min_index = i;
			i++;
		}

		/* Swap the minimum element with the first element of the unsorted part */
		if (min_index != current_pass)
		{
			temporary = array[current_pass];
			array[current_pass] = array[min_index];
			array[min_index] = temporary;
			print_array(array, size);
		}

		current_pass++;
	}
}

