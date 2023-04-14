#include "sort.h"

/**
 * swpints - swaps two integers
 * @num1: first integer
 * @num2: second integer
 */
void swpints(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int swapped = 1, i, j;

	if (array == NULL || size < 2)
		return;

	j = size - 1;
	while (swapped)
	{
		swapped = 0;
		for (i = 0; i < j; i++)
		{
			if (array[i] > array[i + 1])
			{
				swpints(&array[i], &array[i + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}
		j--;
	}
}
