#include "holberton.h"
/**
 * format_perc - percent
 * @valist: valist
 * @buffer: write to buffer
 * @index: the index
 * Return: void
 */
void format_perc(
__attribute__((unused))va_list valist, char *buffer, int *index)
{
	buffer[*index] = '%';
	*index += 1;
}
