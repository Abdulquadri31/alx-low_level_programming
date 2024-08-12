#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

#define BUFFER_SIZE 1024

void close_file(int fd, char *filename);

/**
 * main - Copies the content of a file to another file
 * @argc: The number of command-line arguments
 * @argv: The array of command-line argument strings
 *
 * Return: 0 on success, exits with various codes on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, n_read, n_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_file(fd_from, argv[1]);
		exit(99);
	}

	while ((n_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		n_written = write(fd_to, buffer, n_read);
		if (n_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close_file(fd_from, argv[1]);
			close_file(fd_to, argv[2]);
			exit(99);
		}
	}

	if (n_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close_file(fd_from, argv[1]);
		close_file(fd_to, argv[2]);
		exit(98);
	}

	close_file(fd_from, argv[1]);
	close_file(fd_to, argv[2]);

	return (0);
}

/**
 * close_file - Closes a file descriptor and handles errors
 * @fd: The file descriptor to close
 * @filename: The name of the file associated with the file descriptor
 *
 * If the file descriptor cannot be closed, the function exits with code 100.
 */
void close_file(int fd, char *filename)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
