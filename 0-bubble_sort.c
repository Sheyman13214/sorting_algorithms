#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Function that sorts a list in ascending order using bubble
 * sort algorithm.
 * It goes comparing one element with the previous and swaps them
 * if neccesary, and then repeats the process until no changes are done.
 * @array: an array of integers
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t a;
	int temp, sorted = 0;

	if (array == NULL || size < 2)
		return;

	while (sorted == 0) /* Iterate through the array */
	{
		sorted = 1; /* Assume the array is already sorted */
		/* Traverse through the array */
		for (a = 1; a < size; a++)
		{
			/* Swap elements if the current element is greater than the next */
			if (array[a - 1] > array[a])
			{
				sorted = 0; /* Array is not sorted yet */
				temp = array[a];
				array[a] = array[a - 1];
				array[a - 1] = temp;
				print_array(array, size); /* Print the current state of the array */
			}
		}
	}
}
