#include "main.h"

/**
 * find_sqrt - Recursively calculates the square root of a no.
 * @n: The number to find the square root of.
 * @i: The current number to test as the square root.
 *
 * Return: The natural square root, or -1 
 */
int find_sqrt(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (find_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a no.
 * @n: The number to find the square root of.
 *
 * Return: The natural square root, or -1 
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (find_sqrt(n, 0));
}
