#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char.
 * @s: The pointer to be updated.
 * @to: The value to be assigned.
 *
 * Return: void.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
