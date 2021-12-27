#include "header.h"
#include <strings.h>
#include <stdlib.h>

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

char *getXor(char *a, char *b)
{
	int i;
	char *ret;

	ret = malloc(7);
	ret[6] = 0;
	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] == '1' && b[i] == '1')
			ret[i] = '0';
		else if (a[i] == '1' || b[i] == '1')
			ret[i] = '1';
		else
			ret[i] = '0';
		i++;
	}
	return ret;
}
