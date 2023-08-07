#ifndef MAIN_H
#define MAIN_H


/* Includes*/
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>



/*Code*/
ssize_t read_my_text_file(const char *filename, size_t letters);
int file_create(const char *filename, char *text_content);
int append_my_text_to_file(const char *filename, char *text_content);

/*
* ssize_t: Used for a count of bytes or an error indication.
* int: initialisation
*/


#endif

