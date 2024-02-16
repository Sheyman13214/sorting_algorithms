#include "sort.h"

/**
 * swap_int - Function that swaps two integer in an array.
 * @m: First int to swap.
 * @n: Second int to swap.
 */

void swap_int(int *m, int *n)
{
	int temp;

	temp = *m;
	*m = *n;
	*n = temp;
}

/**
 * shell_sort - Function that sorts an array of ints in ascending order
 * using the shell sort alogrithm
 * @array: Array of ints to sort.
 * @size: size of array.
 * Description: Uses the Knuth Interval Sequence.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, a, b;

	/* Check if array is empty and size is less han 2 */
	if (array == NULL || size < 2)
		return;

	/* Calculate initial gap */
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	/* Perform Shell Sort */
	for (; gap >= 1; gap /= 3)
	{
		for (a = gap; a < size; a++)
		{
			a = b;
			while (b >= gap && array[b - gap] > array[b])
			{
				swap_int(array + b, array + (b - gap));
				b -= gap;
			}
		}
		print_array(array, size);
	}
}
