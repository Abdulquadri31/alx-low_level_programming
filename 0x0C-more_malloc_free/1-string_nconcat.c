#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of bytes of s2 to concatenate to s1.
 *
 * Return: A pointer to a newly allocated space in memory contain  s1
 *         followed by the first n bytes of s2, and null terminated.
 *         If the function fails, it should return NULL.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat_str;
	unsigned int i, j, len1 = 0, len2 = 0;

	if (s1 != NULL)
	{
		while (s1[len1])
			len1++;
	}

	if (s2 != NULL)
	{
		while (s2[len2])
			len2++;
	}

	if (n >= len2)
		n = len2;

	concat_str = malloc((len1 + n + 1) * sizeof(char));
	if (concat_str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
	{
		concat_str[i] = s1[i];
	}

	for (j = 0; j < n; j++, i++)
	{
		concat_str[i] = s2[j];
	}

	concat_str[i] = '\0';

	return (concat_str);
}
