#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>  // For ssize_t

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void close_file(int fd, char *filename);

#endif /* MAIN_H */
