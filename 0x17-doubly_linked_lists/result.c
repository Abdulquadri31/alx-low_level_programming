#include <stdio.h>
#include <stdbool.h>

/**
 * is_palindrome - Checks if a number is a palindrome.
 * @num: The number to check.
 *
 * Return: true if num is a palindrome, otherwise false.
 */
bool is_palindrome(int num)
{
    int original = num;
    int reversed = 0;

    while (num > 0)
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return (original == reversed);
}

/**
 * main - Finds and prints the largest palindromic product of two 3-digit numbers.
 *
 * Return: Always 0.
 */
int main(void)
{
    int i, j;
    int largest_palindrome = 0;

    for (i = 100; i <= 999; i++)
    {
        for (j = i; j <= 999; j++)
        {
            int product = i * j;

            if (is_palindrome(product) && product > largest_palindrome)
            {
                largest_palindrome = product;
            }
        }
    }

    printf("%d\n", largest_palindrome);
    return (0);
}
