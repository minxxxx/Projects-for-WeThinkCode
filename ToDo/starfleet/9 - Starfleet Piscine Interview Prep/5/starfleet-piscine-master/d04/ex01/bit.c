
#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void handleNegation(char *s)
{
	int	i = 0;

	while (++i < 5)
	{
		s[i] = (s[i] == '1') ? '0' : '1';
	}
}

char *getAnd(char *a, char *b)
{
	char	*c;
	int		i, j, r;

	i = j = r = 0;
	c = calloc(5, sizeof(char));
	if (a[0] == '~')
	{
		handleNegation(a);
		i++;
	}
	if (b[0] == '~')
	{
		handleNegation(b);
		j++;
	}
	while (a[i])
	{
		c[r] = (a[i] == '1' && b[j] == '1') ? '1' : '0';
		r++;
		i++;
		j++;
	}
	c[4] = '\0';
	return (c);
}

char *getOr(char *a, char *b)
{
	char	*c;
	int		i, j, r;

	i = j = r = 0;
	c = calloc(5, sizeof(char));
	if (a[0] == '~')
	{
		handleNegation(a);
		i++;
	}
	if (b[0] == '~')
	{
		handleNegation(b);
		j++;
	}
	while (a[i])
	{
		c[r] = (a[i] == '1' || b[j] == '1') ? '1' : '0';
		r++;
		i++;
		j++;
	}
	c[4] = '\0';
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
