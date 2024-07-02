#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 1 (Error code)
 */
int main(void)
{
	char mes[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
	write(2, mes, sizeof(mes) - 1);

	return (1);
}
