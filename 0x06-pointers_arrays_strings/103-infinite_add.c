#include "main.h"

/**
 * infinite_add - Adds two numbers stored as strings.
 * @n1: First number as a string.
 * @n2: Second number as a string.
 * @r: Buffer to store the result.
 * @size_r: Size of the buffer.
 *
 * Return: Pointer to the result or 0 if the result cannot be stored in r.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = 0, len2 = 0, len_r = size_r - 1;
    int carry = 0, sum, digit1, digit2;

    /* Calculate the length of both numbers */
    while (n1[len1] != '\0')
        len1++;
    while (n2[len2] != '\0')
        len2++;

    /* Null-terminate the result buffer */
    r[len_r] = '\0';
    len_r--;

    /* Add numbers from the end */
    while (len1 > 0 || len2 > 0 || carry)
    {
        if (len_r < 0)
            return (0);

        len1--;
        len2--;

        digit1 = len1 >= 0 ? n1[len1] - '0' : 0;
        digit2 = len2 >= 0 ? n2[len2] - '0' : 0;

        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        r[len_r] = (sum % 10) + '0';
        len_r--;
    }

    /* Move result to the beginning of the buffer */
    if (len_r >= 0)
    {
        int i = 0;
        len_r++;
        while (r[len_r] != '\0')
        {
            r[i] = r[len_r];
            i++;
            len_r++;
        }
        r[i] = '\0';
    }

    return (r);
}
