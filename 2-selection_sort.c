#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Function that sorts an array of integers using selection
 * sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp, swapped;

	/* Check if the array is valid or if it's already sorted */
	if (size < 2 || array == NULL)
		return;

	/* Iterate through the array */
	for (i = 0; i < size - 1; i++)
	{
		/* Assume the current index is the minimum */
		min_idx = i;
		swapped = 0;

		/* Find the index of the minimum element in the unsorted part of the array */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				/* Update the index of the minimum element */
				min_idx = j;
				swapped = 1; /* Set flag if a swap occurs */
			}
		}

		/* Swap the found minimum element with the first element */
		if (swapped)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size); /* Print the current state of the array */
		}
	}
}
