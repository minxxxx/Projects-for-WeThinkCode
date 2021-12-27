
#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *leftShift(char *bin, int k)
{
	char	*shifted;
	int		len;

	len = strlen(bin);
	shifted = calloc(len + 1, sizeof(char));
	for (int i = 1; i < len; i++)
	{
		if ((i + (k % len)) < len)
			shifted[i] = bin[i + k];
		else
			shifted[i] = bin[0];
	}
	shifted[0] = bin[0];
	return (shifted);
}

char *rightShift(char *bin, int k)
{
	char	*shifted;
	int		len;

	len = strlen(bin);
	shifted = calloc(len + 1, sizeof(char));
	for (int i = 1; i < len; i++)
	{
		if ((i - (k % len)) > 0)
			shifted[i] = bin[i - k];
		else
			shifted[i] = bin[0];
	}
	shifted[0] = bin[0];
	return (shifted);
}

int		power(int x, int y)
{
	int	value;

	value = 1;
	while (y-- > 0)
		value *= x;
	return (value);
}

int     toInt(char *bits)
{
	int	result, j, i, neg, total;

	result = j = total = 0;
	neg = (bits[0] == '1');
	i = strlen(bits);
	for (i -= 1; i >= 0; i--)
		result += power(((bits[i] == '1') ^ neg) ? 2 : 0, j++);
	result -= (neg) ? 0 : 1;
	return ((neg) ? result * -1 : result);
}