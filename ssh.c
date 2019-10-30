#include <stdio.h>
/**
 * itos - integer to string
 * @str: char array
 * @n: number
 *
 * Return: char array
 */
char *itos(char str[], long int n)
{
	int i, temp, div, length, last;

	last = n % 10;
	i = 0;
	if (last < 0)
	{
		last *= -1;
		str[i] = '-';
		i++;
	}
	n = (n / 10);
	if (n < 0)
	{
		n *= -1;
	}

	length = 0;
	div = 1;
	temp = n;

	while (temp > 0)
	{
		length += 1;
		div *= 10;
		temp = temp / 10;
	}

	div = div / 10;
	while (div >= 1)
	{
		str[i] = ((n / div) + '0');
		n = n % div;
		div /= 10;
		i++;
	}
	str[i] = last + '0';
	return (str);
}

/**
 * utos - uint to string
 * @str: string
 * @num: num
 *
 * Return: char array
 */
char *utos(char str[], unsigned int num)
{
	int i, rem, len = 0, n;

	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	i = 0;

	while (i < len)
	{
		rem = num % 10;
		num = num / 10;

		str[len - (i + 1)] = rem + '0';
		i++;
	}

	str[len] = '\0';
	return (str);
}
/**
 * num_len - getting the length of a number
 * @num: the number
 *
 * Return: int
 */
int num_len(int num)
{
	int n, len;

	n = num;
	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
/**
 * _strlen - count the length of a string
 *  @s: char pointer
 *
 * Return: integer
 */
int _strlen(char *s)
{
	int i, count;

	count = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		count++;
	}
	return (i);
}
