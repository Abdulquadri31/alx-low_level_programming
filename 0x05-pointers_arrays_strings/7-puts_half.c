#include "main.h"

/**
 * puts2 - prints every other character of a string, starting with the first character
 * @str: pointer to the string to be printed
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
