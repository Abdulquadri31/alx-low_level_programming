#include "main.h"
#include <unistd.h>

/**
 * print_most_numbers - Prints the numbers from 0 to 9, followed by a new line,
 *                      excluding 2 and 4.
 *
 * Return: void
 */
void print_most_numbers(void)
{
	char num;

	for (num = '0'; num <= '9'; num++)
	{
		if (num != '2' && num != '4')
		{
			write(1, &num, 1);
		}
	}
	write(1, "\n", 1);
}
