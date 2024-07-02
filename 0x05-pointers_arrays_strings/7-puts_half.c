#include "main.h"

/**
 * puts2 - prints half of a string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (i >= 5)
		{
			_putchar(str[i]);
		}
		i++;
	}
	_putchar('\n');
}
