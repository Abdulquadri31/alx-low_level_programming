#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: pointer to the string to be modified
 *
 * Return: pointer to the resulting string
 */
char *cap_string(char *str)
{
	int i;
	int cap_next = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (cap_next && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] -= 'a' - 'A';
		}

		cap_next = 0;

		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == ',' || str[i] == ';' || str[i] == '.' ||
			str[i] == '!' || str[i] == '?' || str[i] == '"' ||
			str[i] == '(' || str[i] == ')' || str[i] == '{' ||
			str[i] == '}')
		{
        		cap_next = 1;
		}
	}

	return (str);
}
