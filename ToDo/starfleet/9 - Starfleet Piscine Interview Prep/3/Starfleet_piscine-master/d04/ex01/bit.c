#include <strings.h>
#include <stdlib.h>
#include "header.h"

char *tild(char *str)
{
	int i = 1;
	char *ret;
	ret = malloc(5);
	ret[4] = 0;

	while (str[i])
	{
		if (str[i] == '0')
			ret[i - 1] = '1';
		else
			ret[i - 1] = '0';
		i++;
	}
	return ret;
}

char *getAnd(char *a, char *b)
{
	int i = 0;
	char *ret;

	ret = malloc(5);
	ret[4] = 0;
	if (a[0] == '~')
		a = tild(a);
	if (b[0] == '~')
		b = tild(b);
	while (a[i] && b[i])
	{
		if (a[i] == '1' && b[i] == '1')
			ret[i] = '1';
		else
			ret[i] = '0';
		i++;
	}
	return ret;
}

char *getOr(char *a, char *b)
{
	int i = 0;
	char *ret;

	ret = malloc(5);
	ret[4] = 0;
	if (a[0] == '~')
		a = tild(a);
	if (b[0] == '~')
		b = tild(b);
	while (a[i] && b[i])
	{
		if (a[i] == '1' || b[i] == '1')
			ret[i] = '1';
		else
			ret[i] = '0';
		i++;
	}
	return ret;
}

int toInt(char *bits)
{
	int i = strlen(bits) - 1;
	int mult;
	int ret = 0;

	mult = 1;
	while (i > -1)
	{
		if (bits[i] == '1')
			ret = ret + mult;
		mult = mult * 2;
		i--;
	}
	return ret;
}
