#include <stdio.h>

/**
 * print_alphabet - prints the alphabet in lowercase, followed by a new line
 */
void print_alphabet(void)
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz\n";
    int i;

    for (i = 0; alphabet[i] != '\0'; i++)
    {
        putchar(alphabet[i]);
    }
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    print_alphabet();
    return (0);
}

