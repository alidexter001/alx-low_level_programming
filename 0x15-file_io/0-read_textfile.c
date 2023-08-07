#include "main.h"
#include <stdlib.h>

/**
 * read_and_print_text - Read text from a file and write to STDOUT.
 * @filename: The name of the text file to be read.
 * @max_characters: The maximum number of characters to be read.
 * Return: The number of characters written to STDOUT, or 0 on failure.
 */
ssize_t read_and_print_text(const char *filename, size_t max_characters)
{
    char *buffer;
    ssize_t file_descriptor;
    ssize_t bytes_read;
    ssize_t bytes_written;

    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1)
        return (0);

    buffer = malloc(sizeof(char) * max_characters);
    if (!buffer) {
        close(file_descriptor);
        return (0);
    }

    bytes_read = read(file_descriptor, buffer, max_characters);
    if (bytes_read == -1) {
        free(buffer);
        close(file_descriptor);
        return (0);
    }

    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

    free(buffer);
    close(file_descriptor);

    return (bytes_written);
}

