#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * format_d - function that returns an int to signed decimal
 * @valist: arguments passed
 * @buffer: values stored
 * @index: tracks index position
 */
void format_d(va_list valist, char *buffer, int *index)
{
	int i, j, numlen;
	char *num_str;

	i = va_arg(valist, int);

	numlen = num_len(i);
	if (i < 0)
	{
		numlen += 1;
	}
	num_str = malloc(numlen * sizeof(char));
	if (num_str == NULL)
		return;
	itos(num_str, i);
	for (i = *index, j = 0; j < numlen; *index += 1, i++, j++)
	{
		if (*index == 1024)
		{
			_write_buffer(buffer, index);
			reset_buffer(buffer);
			*index = 0;
		}
		buffer[*index] = num_str[j];
	}
	free(num_str);
}
