/* Defines*/
#ifndef MAIN_H
#define MAIN_H


/* Includes*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


/*
 * read_textfile: refers to the file 0-read_textfile.c
 * create_file: refers to the file 1-create_file.c
 * append_text_to_file: refers to the file 2-append_text_to_file.c
*/

ssize_t read_textfile(const char *filename, size_t letters);
int append_text_to_file(const char *filename, char *text_content);
int create_file(const char *filename, char *text_content);

#endif



