#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - prints the opcodes of the main function
 * @num_bytes: number of bytes to print
 *
 * Return: Nothing.
 */
void print_opcodes(int num_bytes)
{
	unsigned char *opcode;
	int i;

	opcode = (unsigned char *)print_opcodes;
    
	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x", opcode[i]);
		if (i < num_bytes - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
}

/**
 * main - prints the opcodes of its own main function
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0 on success, 1 on error, 2 on negative input.
 */
int main(int argc, char *argv[])
{
	int num_bytes;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num_bytes = atoi(argv[1]);
    
	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	print_opcodes(num_bytes);
	return (0);
}
