#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 * @str: The string to be copied.
 *
 * Return: A pointer to the duplicated string, or NULL if str is NULL
 *         or if insufficient memory was available.
 */
char *_strdup(char *str)
{
	char *dup_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len]; len++)
		;

	dup_str = malloc((len + 1) * sizeof(char));
	if (dup_str == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		dup_str[i] = str[i];
	}
	dup_str[i] = '\0';

	return (dup_str);
}
