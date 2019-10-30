#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * format_u - specificer for u
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_u(va_list valist, char *buffer, int *index)
{
	unsigned int i;
	int j, numlen;
	char *num_str;

	i = va_arg(valist, int);
	numlen = num_len(i);
	num_str = malloc(numlen * sizeof(char));
	if (num_str == NULL)
		return;
	utos(num_str, i);
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
/**
 * format_h - specificer for h
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_h(va_list valist, char *buffer, int *index)
{
	unsigned int n;
	int i;
	char *hexvalues;
	char *hex;

	n = va_arg(valist, int);
	hexvalues = "0123456789abcdef";
	hex = malloc(9 * sizeof(char));
	if (hex == NULL)
		return;
	for (i = 0; n != 0; i++)
	{
		hex[i] = hexvalues[n % 16];
		n /= 16;
	}
	for (i--; i >= 0; *index += 1, i--)
	{
		buffer[*index] = hex[i];
	}
	free(hex);
}
/**
 * format_ch - specificer for ch
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_ch(va_list valist, char *buffer, int *index)
{
	unsigned int n;
	int i;
	char *hexvalues;
	char *hex;

	n = va_arg(valist, int);
	hexvalues = "0123456789ABCDEF";
	hex = malloc(9 * sizeof(char));
	if (hex == NULL)
		return;
	for (i = 0; n != 0; i++)
	{
		hex[i] = hexvalues[n % 16];
		n /= 16;
	}
	for (i--; i >= 0; *index += 1, i--)
	{
		buffer[*index] = hex[i];
	}
	free(hex);
}
/**
 * format_o - specificer for o
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_o(va_list valist, char *buffer, int *index)
{
	unsigned int n;
	int i;
	char *octvalues;
	char *oct;

	n = va_arg(valist, int);
	octvalues = "0123456789ABCDEF";

	oct = malloc(12 * sizeof(char));
	if (oct == NULL)
		return;
	for (i = 0; n != 0; i++)
	{
		oct[i] = octvalues[n % 8];
		n /= 8;
	}
	for (i--; i >= 0; *index += 1, i--)
	{
		buffer[*index] = oct[i];
	}
	free(oct);
}
