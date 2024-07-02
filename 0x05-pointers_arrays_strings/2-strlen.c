#include "main.h"

/**
 * _strlen - returns the length
 * @s: pointer to a string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}
