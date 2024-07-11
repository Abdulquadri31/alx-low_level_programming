#include "main.h"

/**
 * check_prime - Checks if a number is prime.
 * @n: The number to be checked.
 * @i: The divisor to check.
 *
 * Return: 1 if the number is prime, otherwise 0.
 */
int check_prime(int n, int i)
{
	if (n <= 1)
		return (0);
	if (n == i)
		return (1);
	if (n % i == 0)
		return (0);
	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - Returns 1 if the input integer is prime
 * otherwise return 0.
 * @n: The number to be checked.
 *
 * Return: 1 if the number is prime, otherwise 0.
 */
int is_prime_number(int n)
{
	return (check_prime(n, 2));
}
