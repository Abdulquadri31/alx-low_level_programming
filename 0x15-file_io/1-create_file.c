#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file and writes a string to it
 * @filename: The name of the file to create
 * @text_content: The NULL-terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure (file cannot be created)
 *         The created file has the permissions rw-------.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len = 0, n_written;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
		len++;

		n_written = write(fd, text_content, len);
		if (n_written == -1 || n_written != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
