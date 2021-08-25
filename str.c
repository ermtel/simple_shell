#include "holberton.h"
#include <stdlib.h>

/**
 * _strlen - measure the length of a string.
 *
 * @s: the string to be measured.
 *
 * Return: the length of the string.
 */

int _strlen(const char *s)
{
	int l;

	for (l = 0; s[l]; l++)
		;
	return (l);
}

/**
 * _strcpy - copy a string from source to destination.
 *
 * @dest: the destination of the string to be copied to.
 * @src: the source of the string to be copied.
 *
 * Return: the pointer to the destination.
 */

char *_strcpy(char *dest, char *src)
{
	int i;
	char *buff = dest;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = src[i];
	return (buff);
}

/**
 * _strcmp - compares two strings.
 *
 * @s1: the first string.
 * @s2: the second string.
 *
 * Return: 0 if they are equal, positive if s1 is greater and negative if less.
 */

int _strcmp(char *s1, char *s2)
{

	int i, j;

	for (i = 0, j = 0; (s1[i] != '\0') && (s2[i] != '\0'); i++)
	{
		j = s1[i] - s2[i];
		if (j != 0)
			break;
	}

	return (j);
}

/**
 * _strncmp - Compare two strings.
 * @s1: Pointer to first string.
 * @s2: Pointer to second string.
 * @n: The first n bytes of the strings to compare.
 *
 * Return: negative number if s1 is shorter than s2, 0 if they
 *         match, positive number if s1 is longer than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-1);
}

/**
 * _strdup - duplicates a string in memory.
 *
 *  @s: string to be duplicated.
 *
 * Return: duplicated string.
 */

char *_strdup(char *s)
{

	char *buff;
	unsigned int len;

	len = _strlen(s);
	buff = malloc(sizeof(char) * (len + 1));
	if (buff == NULL)
		return (NULL);
	_memcpy(buff, s, len + 1);
	return (buff);
}
