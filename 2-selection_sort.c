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
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int i = 0, swapped = 1, j, cmp = 0;

	if (array == NULL || size < 2)
		return;
	j = size - 1;
	while (i < j)
	{
		if (swapped == j + 1)
		{
			if (i != cmp)
			{
				swpints(&array[i], &array[cmp]);
				print_array(array, size);
			}
			i++;
			cmp = i;
			swapped = i + 1;
			continue;
		}
		if (array[cmp] > array[swapped])
			cmp = swapped;
		swapped++;
	}
}
