#include "holberton.h"

/**
 * _strcat - concatenate two strings.
 *
 * @dest: the destination.
 * @src: the source.
 *
 * Return: the pointer to the resulting string.
 */
char *_strcat(char *dest, char *src)
{
	int i, j, k, l;
	char *buff = dest;

	for (i = 0; dest[i] != '\0'; i++)
		l++;
	for (j = l, k = 0; src[k] != '\0'; j++, k++)
		dest[j] = src[k];
	dest[j] = '\0';
	return (buff);
}

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
