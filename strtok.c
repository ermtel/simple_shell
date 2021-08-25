#include "holberton.h"

/**
 * _strtok - breaks a string into series of 0 or more elements.
 * @str: pointer to the string to be broken.
 * @delim: pointer to the string that is delimeting the elements.
 * Return: pointer to the next element or NULL if none left.
 */

char *_strtok(char *str, const char *delim)
{
static char *next;
char *buffer;
char *current;
int i = 0;

if (str != NULL)
current = str;
else if (*next != '\0')
current = next;
else if (*next == '\0')
return (NULL);
buffer = (char *)malloc(sizeof(char) * 1024);
if (!buffer)
{
free(buffer);
perror("Error: ");
return (NULL);
}
while (*current != *delim && *current != '\0')
{
buffer[i] = *current;
i++;
current++;
}
buffer[i] = '\0';
if (*current != '\0')
next = ++current;
else
next = current;
return (buffer);
}
