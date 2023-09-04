#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * append_text_to_file - Append text to the end of a file
 * @filename: Name of the file to append to
 * @text_content: NULL-terminated string to append to the file
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1); /* Nothing to add, return success */

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1); /* Unable to open or write the file */

	bytes_written = write(fd, text_content, strlen(text_content));

	if (bytes_written == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
