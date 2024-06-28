#include "main.h"
#include <unistd.h>

/**
 * print_numbers - Prints the numbers from 0 to 9, followed by a new line
 *
 * Return: void
 */
void print_numbers(void)
{
	char num;

	for (num = '0'; num <= '9'; num++)
	{
		write(1, &num, 1);
	}
	write(1, "\n", 1);
}
