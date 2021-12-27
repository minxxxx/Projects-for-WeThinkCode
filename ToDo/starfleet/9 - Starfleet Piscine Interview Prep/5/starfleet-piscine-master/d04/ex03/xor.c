
#include "header.h"
#include <string.h>
#include <stdlib.h>

char	*getXor(char *a, char *b)
{
	int 	len;
	char	*c;

	len = strlen(a);
	c = malloc(sizeof(char) * len + 1);
	memset(c, '0', len);
	c[len] = '\0';
	for (int i = 0; i < len; i++)
	{
		if ((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0'))
			c[i] = '1';
	}
	return (c);
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
	int	result, j, i;

	result = j = 0;
	i = strlen(bits);
	for (i -= 1; i >= 0; i--)
	{
		if (bits[i] == '1')
			result += power(2, j);
		j++;
	}
	return (result);
}
