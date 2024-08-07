#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array using a comparison function
 * @array: the array of integers
 * @size: the number of elements in the array
 * @cmp: a pointer to the comparison function to be used
 *
 * Return: the index of the first element for which the cmp return 0
 *         If no element matches, return -1
 *         If size <= 0, return -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp)
	{
		if (size <= 0)
			return (-1);

		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
				return (i);
		}
	}
	return (-1);
}
