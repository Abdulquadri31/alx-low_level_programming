#include "main.h"

/**
 * string_toupper - changes all lowercase to uppercase
 * @str: pointer to the string to be modified
 *
 * Return: pointer to the resulting string
 */
char *string_toupper(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 'a' + 'A';
		}
	}

	return (str);
}
