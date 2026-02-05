#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @a: pointer to first integer
 * @b: pointer to second integer
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
 * lomuto_partition - partitions an array using Lomuto scheme
 * @array: array to partition
 * @low: start index
 * @high: end index (pivot)
 * @size: size of the whole array (for printing)
 *
 * Return: pivot index
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot = array[high];
    size_t i = low - 1;
    size_t j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }

    i++;
    if (i != high)
    {
        swap(&array[i], &array[high]);
        print_array(array, size);
    }

    return i;
}

/**
 * quick_sort_recursive - recursively sorts array using Lomuto
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: size of the whole array (for printing)
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
    size_t pivot;

    if (low < high)
    {
        pivot = lomuto_partition(array, low, high, size);

        if (pivot > low)
            quick_sort_recursive(array, low, pivot - 1, size);

        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto scheme)
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
