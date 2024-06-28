#include "main.h"
#include <unistd.h>

/**
 * more_numbers - Prints the numbers from 0 to 14 ten times,
 *                followed by a new line.
 *
 * Return: void
 */
void more_numbers(void)
{
	int i, num;

    	for (i = 0; i < 10; i++)
    	{
        	for (num = 0; num <= 14; num++)
        	{
            		if (num > 9)
            		{
                		char tens = (num / 10) + '0';
                		write(1, &tens, 1);
            		}
            		char ones = (num % 10) + '0';
            		write(1, &ones, 1);
        	}
        	write(1, "\n", 1);
    	}
}

