#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>
#include <string.h>

#define BUFFER_SIZE 1024

void error_exit(const char *message, int exit_code)
{
    dprintf(STDERR_FILENO, "%s\n", message);
    exit(exit_code);
}

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif
