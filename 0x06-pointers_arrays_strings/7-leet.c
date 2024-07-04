#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: pointer to the string to be modified
 *
 * Return: pointer to the resulting string
 */
char *leet(char *str)
{
	int i, j;
	char leet_map[10] = {'a', 'A', 'e', 'E', 'o', 'O', 't', 'T', 'l', 'L'};
	char leet_replace[10] = {'4', '4', '3', '3', '0', '0', '7', '7', '1', '1'};

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (str[i] == leet_map[j])
			{
				str[i] = leet_replace[j];
				break;
			}
		}
	}

	return (str);
}
