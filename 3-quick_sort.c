#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @a: pointer to first element
 * @b: pointer to second element
 */
void swap(int *a, int *b)
{
	int tmp;

	if (a == b)
		return;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array to partition
 * @low: starting index
 * @high: ending index (pivot)
 * @size: size of the array (for printing)
 *
 * Return: index of pivot after partition
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;

	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < array[high])
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return i;
}

/**
 * quick_sort_recursive - recursive quick sort function
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array (for printing)
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);

		if (pivot > 0)
			quick_sort_recursive(array, low, pivot - 1, size);

		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto)
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
