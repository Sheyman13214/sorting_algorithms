#include "sort.h"

/**
 * quick_partition - Function that partitions the array around a pivot for
 * quicksort.
 * @array: Pointer to the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 * Return: Index of the pivot after sorting.
 */

size_t quick_partition(int *array, size_t low, size_t high, size_t size)
{
	int aux;
	size_t idx_pivot, idx_small, idx_right;

	idx_pivot = high;
	idx_small = low - 1;

	for (idx_right = low; idx_right <= (high - 1); idx_right++)
	{
		if (array[idx_right] < array[idx_pivot])
		{
			idx_small++;

			if (idx_small != idx_right)
			{
				/* Swap elements at idx_small and idx_right */
				aux = array[idx_small];
				array[idx_small] = array[idx_right];
				array[idx_right] = aux;

				/* Print the current state of the array */
				print_array(array, size);
			}
		}
	}

	idx_small++;

	/* Swap elements at idx_small and pivot (high) */
	if (array[high] < array[idx_small])
	{
		aux = array[high];
		array[high] = array[idx_small];
		array[idx_small] = aux;

		/* Print the current state of the array */
		print_array(array, size);
	}

	return (idx_small);
}

/**
 * quick_recursion - Function that recursively performs quicksort on the array.
 * @array: Pointer to the array.
 * @low: Starting index of the sort.
 * @high: Ending index of the sort.
 * @size: Size of the entire array.
 */

void quick_recursion(int *array, size_t low, size_t high, size_t size)
{
	size_t idx_pivot;

	/* Check if there is more than one element in the array */
	if (low < high)
	{
		/* Partition the array and get the pivot index */
		idx_pivot = quick_partition(array, low, high, size);

		/* Recursively sort the sub-array on the left of the pivot */
		if (idx_pivot > 0)
			quick_recursion(array, low, (idx_pivot - 1), size);

		/* Recursively sort the sub-array on the right of the pivot */
		if (idx_pivot < high)
			quick_recursion(array, (idx_pivot + 1), high, size);
	}
}

/**
 * quick_sort - Function that sorts an array of integers using quicksort.
 * @array: Pointer to the array to sort.
 * @size: Size of the array.
 */

void quick_sort(int *array, size_t size)
{
	/* Check if the array is not NULL and has more than one element */
	if (array && size > 1)
		/* Start the quicksort algorithm */
		quick_recursion(array, 0, (size - 1), size);
}
