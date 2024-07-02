#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random valid passwords for the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, sum, target_sum;
	char password[100];

	sum = 0;
	target_sum = 2772; /* This value is specific to 101-crackme */
    
	srand(time(NULL));

	for (i = 0; sum < target_sum - 127; i++)
	{
		password[i] = rand() % 94 + 33; /* Generates a random printable ASCII character */
		sum += password[i];
	}

	password[i] = target_sum - sum; /* Last character to complete the sum to target_sum */
	password[i + 1] = '\0';

	printf("%s", password);

	return (0);
}
