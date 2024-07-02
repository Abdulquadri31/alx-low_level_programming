#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string to be converted
 *
 * Return: the integer value of the string, or 0 if there are no numbers
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;
	int started = 0;

	while (*s != '\0')
	{
		if (*s == '-')
		{
			if (started)
			break;
			sign *= -1;
		}
		else if (*s == '+')
		{
			if (started)
			break;
		}
		else if (*s >= '0' && *s <= '9')
		{
			num = num * 10 + (*s - '0');
			started = 1;
		}
		else if (started)
		{
			break;
		}
		s++;
	}

	return (sign * num);
}
