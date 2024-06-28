#include <stdio.h>
#include <math.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long number = 612852475143;
	long max_prime = -1;
	long i;

	while (number % 2 == 0)
	{
		max_prime = 2;
		number /= 2;
	}

	for (i = 3; i <= sqrt(number); i += 2)
	{
		while (number % i == 0)
		{
			max_prime = i;
			number = number / i;
		}
	}

	if (number > 2)
	{
		max_prime = number;
	}

	printf("%ld\n", max_prime);

	return (0);
}
