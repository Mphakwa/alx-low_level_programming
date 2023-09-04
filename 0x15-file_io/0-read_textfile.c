#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_textfile - Read and print a text file
 * @filename: Name of the file to read
 * @letters: Number of letters to read and print
 *
 * Return: The actual number of letters read and printed, or 0 on failure
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char *buffer;
	ssize_t bytesRead, bytesWritten;

	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	buffer = (char *)malloc(letters + 1);
	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}

	bytesRead = fread(buffer, sizeof(char), letters, file);

	if (bytesRead <= 0)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	buffer[bytesRead] = '\0';

	bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);

	fclose(file);
	free(buffer);

	if (bytesWritten != bytesRead)
		return (0);

	return (bytesRead);
}
