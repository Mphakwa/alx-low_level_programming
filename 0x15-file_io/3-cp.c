#include "main.h"

#define BUFFER_SIZE 1024

/**
 * print_usage_and_exit - Print usage message and exit with a specific code.
 * @program_name: The name of the program.
 */
void print_usage_and_exit(const char *program_name)
{
	dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", program_name);
	exit(97);
}

/**
 * print_error_and_exit - Print an error message and exit with a specific code.
 * @error_message: The error message.
 * @file_name: The name of the file.
 * @exit_code: The exit code.
 */
void print_error_and_exit(const char *error_message, const char *file_name, int exit_code)
{
	dprintf(STDERR_FILENO, "Error: %s %s\n", error_message, file_name);
	exit(exit_code);
}

/**
 * copy_file - Copy the content of one file to another.
 * @from_file: The source file name.
 * @to_file: The destination file name.
 */
void copy_file(const char *from_file, const char *to_file)
{
	int from_fd, to_fd;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	from_fd = open(from_file, O_RDONLY);
	if (from_fd == -1)
	{
		print_error_and_exit("Can't read from file", from_file, 98);
	}

	to_fd = open(to_file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to_fd == -1)
	{
		close(from_fd);
		print_error_and_exit("Can't write to", to_file, 99);
	}

	while ((bytes_read = read(from_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(to_fd, buffer, bytes_read);

	if (bytes_written == -1)
	{
		close(from_fd);
		close(to_fd);
		print_error_and_exit("Can't write to", to_file, 99);
		}
	}

	if (bytes_read == -1)
	{
		close(from_fd);
		close(to_fd);
		print_error_and_exit("Can't read from file", from_file, 98);
	}

	if (close(from_fd) == -1)
	{
		print_error_and_exit("Can't close fd", from_file, 100);
	}

	if (close(to_fd) == -1)
	{
		print_error_and_exit("Can't close fd", to_file, 100);
	}
}

/**
 * main - Entry point of the program.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success, or an appropriate error code on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		print_usage_and_exit(argv[0]);
	}

	copy_file(argv[1], argv[2]);

	return (0);
}
