#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * word_len - Calculates the length of a word.
 * @str: The string containing the word.
 *
 * Return: The length of the word.
 */
int word_len(char *str)
{
	int len = 0;

	while (str[len] != ' ' && str[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to be counted.
 *
 * Return: The number of words in the string.
 */
int count_words(char *str)
{
	int i, words = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			words++;
		}
	}

	return (words);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to be split.
 *
 * Return: A pointer to an array of strings (words),
 *         or NULL if str is NULL or empty.
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len, num_words;

	if (str == NULL || *str == '\0')
		return (NULL);

	num_words = count_words(str);
	if (num_words == 0)
		return (NULL);

	words = malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, j = 0; j < num_words; j++)
	{
		while (str[i] == ' ')
			i++;

		len = word_len(str + i);

		words[j] = malloc((len + 1) * sizeof(char));
		if (words[j] == NULL)
		{
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}

		for (k = 0; k < len; k++, i++)
			words[j][k] = str[i];
		words[j][k] = '\0';
	}
	words[j] = NULL;

	return (words);
}
