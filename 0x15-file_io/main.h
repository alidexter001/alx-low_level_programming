#ifndef HEADER
#define HEADER
/*
 * main.h icnludes read_textfile.c + create_file.c + append_text_to_file.c
*/



#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>




//Code for main function
int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);




#endif /* MAIN_H */
