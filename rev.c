#include "holberton.h"
/**
 * format_r - reverse a string passed in
 * @valist: argument passed in
 * @buffer: values stored
 * @index: returns pointer to index
 */
void format_r(va_list valist, char *buffer, int *index)
{
	int i, strlen;
	char *s;

	s = va_arg(valist, char *);
	strlen = _strlen(s) - 1;

	for (i = strlen; i >= 0; i--, *index += 1)
	{
		buffer[*index] = s[i];
	}
}
