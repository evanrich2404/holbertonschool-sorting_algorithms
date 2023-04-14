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
 * l_partition - partitions the array
 * @array: array to partition
 * @low: low index
 * @high: high index
 * @size: size of array
 * Return: partition index
 */
int l_partition(int arr[], int low, int high, size_t size)
{
	int *pivot;
	int i, j;

	pivot = &arr[high];
	for (i = j = low; j < high; j++)
	{
		if (arr[j] < *pivot)
		{
			if (i < j)
			{
				swpints(&arr[i], &arr[j]);
				print_array(arr, size);
			}
			i++;
		}
	}
	if (arr[i] > *pivot)
	{
		swpints(&arr[i], pivot);
		print_array(arr, size);
	}
	return (i);
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int x = 0, y = size - 1;

	if (array == NULL || size < 2)
		return;
	l_cycler(array, size, x, y);
}

/**
 * l_cycler - cycles through the array
 * @array: array to cycle through
 * @size: size of array
 * @x: low index
 * @y: high index
 */
void l_cycler(int *array, size_t size, int x, int y)
{
	int p;

	if ((y - x) > 0)
	{
		p = l_partition(array, x, y, size);
		l_cycler(array, size, x, p - 1);
		l_cycler(array, size, p + 1, y);
	}
}
