#include <stdio.h>

/**
 * add - returns the sum of two integers
 * @a: first integer
 * @b: second integer
 * Return: the sum of a and b
 */
int add(int a, int b) {
	return a + b;
}

/**
 * sub - returns the difference of two integers
 * @a: first integer
 * @b: second integer
 * Return: the difference of a and b
 */
int sub(int a, int b) {
	return a - b;
}

/**
 * mul - returns the product of two integers
 * @a: first integer
 * @b: second integer
 * Return: the product of a and b
 */
int mul(int a, int b) {
	return a * b;
}

/**
 * div - returns the integer division of two integers
 * @a: first integer
 * @b: second integer
 * Return: the integer division of a by b
 */
int div(int a, int b) {
	if (b != 0)
		return a / b;
	return 0; // Return 0 for division by zero
}

/**
 * mod - returns the remainder of the division of two integers
 * @a: first integer
 * @b: second integer
 * Return: the remainder of a divided by b
 */
int mod(int a, int b) {
	if (b != 0)
		return a % b;
	return 0; // Return 0 for modulo by zero
}
