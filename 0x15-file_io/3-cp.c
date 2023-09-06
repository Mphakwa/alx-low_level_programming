#include "main.h"

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, or exit with an error code on failure.
 */

int main(int argc, char *argv[])
{
	int from, to;
	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (EXIT_FAILURE);
	}
	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(from);
		return (EXIT_FAILURE);
	}
	while ((bytes_read = read(from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(to, buffer, bytes_read);
		if (bytes_written == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(from);
		close(to);
		return (EXIT_FAILURE);
	}
	}
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(from);
		close(to);
		return (EXIT_FAILURE);
	}
	close(from);
	close(to);
	return (EXIT_SUCCESS);
}
