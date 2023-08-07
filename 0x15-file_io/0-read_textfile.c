#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file name being read
 * @letters: The number of letters on the file get readed
 * Return: 1 = success, 0 = failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t FD;
	ssize_t k;
	ssize_t b;

	FD = open(filename, O_RDONLY);
	if (FD == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	b = read(FD, buf, letters);
	k = write(STDOUT_FILENO, buf, b);

	free(buf);
	close(FD);
	return (k);
}

