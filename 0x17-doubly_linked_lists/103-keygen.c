#include <stdio.h>
#include <string.h>

/**
 * generate_key - Generates a key based on the given username.
 * @username: The username for which to generate the key.
 *
 * Return: The generated key as a string.
 */
char *generate_key(const char *username)
{
    static char key[32];
    int sum = 0;
    size_t i;

    // Simple example algorithm: Sum of ASCII values of characters in the username
    for (i = 0; i < strlen(username); i++)
    {
        sum += username[i];
    }

    // Convert sum to a hex string as a simple key
    snprintf(key, sizeof(key), "%X", sum);

    return key;
}

/**
 * main - Entry point for the keygen program.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s username\n", argv[0]);
        return 1;
    }

    char *username = argv[1];
    char *key = generate_key(username);

    printf("%s\n", key);

    return 0;
}
