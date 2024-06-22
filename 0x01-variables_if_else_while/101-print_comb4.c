

#include <studio.h>

/**
 * main -Entry point
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	int num1;
	int num2;
	int num3;

	for (num1 = 0; num1 <= 9; num1++)
	{
		for (num2 = num1 + 1; num2 <= 9; num2++)
		{
			for (num3 = num2 + 1; num3 <= 9; num3++)
			{
				putchar(num1 + 48);
				putchar(',');
				putchar(' ');
				putchar(num2 + 48);
				putchar(',');
				putchar(num3 + 48);
				putchar(' ');
			}
		}
	}

	putchar('\n');

	return (0);
}
