#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>

/**
 * main - Entry point of the program
 *
 * This function is the entry point for the program, which copies the content of one file
 * to another file. It accepts command-line arguments for specifying source and destination files.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, other values on error.
 */

int main(int argc, char *argv[])
{
	const char *file_from;
	const char *file_to;
	int fd_from;
	int fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	ssize_t bytes_written;

	if (argc != 3)
	{
		error_exit("Usage: cp file_from file_to", 97);
	}

	file_from = argv[1];
	file_to = argv[2];

	fd_from = open(file_from, O_RDONLY);

	if (fd_from == -1)
	{
	error_exit("Error: Can't read from file", 98);
	}

	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		close(fd_from);
		error_exit("Error: Can't write to", 99);
	}

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);

		if (bytes_written == -1)
	       	{
			close(fd_from);
			close(fd_to);
			error_exit("Error: Can't write to", 99);
		}
	}

	if (bytes_read == -1)
       	{
		close(fd_from);
		close(fd_to);
		error_exit("Error: Can't read from file", 98);
	}
	if (close(fd_from) == -1 || close(fd_to) == -1)
       	{
		error_exit("Error: Can't close fd", 100);
	}

	return (0);
}
