#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *file);
void close_descriptor(int fd);

/**
 * allocate_buffer - Allocates memory for a data buffer.
 * @file: The filename associated with the buffer.
 *
 * Return: A pointer to the newly allocated buffer.
 */
char *allocate_buffer(char *file)
{
    char *buffer;

    buffer = malloc(sizeof(char) * 1024);

    if (buffer == NULL)
    {
        dprintf(STDERR_FILENO,
                "Error: Unable to allocate buffer for %s\n", file);
        exit(99);
    }

    return (buffer);
}

/**
 * close_descriptor - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_descriptor(int fd)
{
    int result;

    result = close(fd);

    if (result == -1)
    {
        dprintf(STDERR_FILENO, "Error: Unable to close fd %d\n", fd);
        exit(100);
    }
}

/**
 * main - Copies the content from one file to another.
 * @argc: The number of arguments provided to the program.
 * @argv: An array of argument pointers.
 *
 * Return: 0 on successful execution.
 *
 * Description: Exit codes: 97 (incorrect argument count),
 * 98 (file_from inaccessible), 99 (file_to write failure),
 * 100 (file descriptors cannot be closed).
 */
int main(int argc, char *argv[])
{
    int src_file, dest_file, r, w;
    char *buffer;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp source_file dest_file\n");
        exit(97);
    }

    buffer = allocate_buffer(argv[2]);
    src_file = open(argv[1], O_RDONLY);
    r = read(src_file, buffer, 1024);
    dest_file = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

    do {
        if (src_file == -1 || r == -1)
        {
            dprintf(STDERR_FILENO,
                    "Error: Unable to read from %s\n", argv[1]);
            free(buffer);
            exit(98);
        }

        w = write(dest_file, buffer, r);
        if (dest_file == -1 || w == -1)
        {
            dprintf(STDERR_FILENO,
                    "Error: Unable to write to %s\n", argv[2]);
            free(buffer);
            exit(99);
        }

        r = read(src_file, buffer, 1024);
        dest_file = open(argv[2], O_WRONLY | O_APPEND);

    } while (r > 0);

    free(buffer);
    close_descriptor(src_file);
    close_descriptor(dest_file);

    return (0);
}

