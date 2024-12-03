#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

// Function to read the next line from a file descriptor
char *get_next_line(int fd);

// Utility function to find the length of a string
size_t ft_strlen(const char *str);

// Utility function to duplicate a string
char *ft_strdup(const char *s1);

// Utility function to join two strings
char *ft_strjoin(char const *s1, char const *s2);

// Utility function to find a character in a string
char *ft_strchr(const char *s, int c);

#endif // GET_NEXT_LINE_H