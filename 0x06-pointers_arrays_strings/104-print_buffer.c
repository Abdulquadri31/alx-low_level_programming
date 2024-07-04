#include "main.h"
#include <stdio.h>

/**
 * print_buffer - Prints a buffer
 * @b: The buffer to print
 * @size: The size of the buffer
 *
 * Return: void
 */
void print_buffer(char *b, int size)
{
	int offset, byte_index, chunk;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (offset = 0; offset < size; offset += 10)
	{
		printf("%08x: ", offset);
		chunk = (size - offset) < 10 ? (size - offset) : 10;

		for (byte_index = 0; byte_index < 10; byte_index++)
		{
			if (byte_index < chunk)
				printf("%02x", *(b + offset + byte_index));
	    		else
				 printf("  ");
			if (byte_index % 2 != 0)
				printf(" ");
		}

		for (byte_index = 0; byte_index < chunk; byte_index++)
		{
			int c = *(b + offset + byte_index);
			if (c >= 32 && c <= 126)
				printf("%c", c);
			else
				printf(".");
		}
		printf("\n");
	}
}
