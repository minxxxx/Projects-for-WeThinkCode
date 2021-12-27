#include "header.h"
#include <stdlib.h>
#include <strings.h>

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

char *getSum(char *a, char *b)
{
	char ret[7];
	int i = 5;
	int carry = 0;
	int first, second;

	ret[6] = 0;
	while(i > -1)
	{
		first = 0;
		second = 0;
		if (a[i] == '1')
			first = 1;
		if (b[i] == '1')
			second = 1;
		carry = first + second + carry;
		ret[i] = (carry % 2) + 48;
		carry = carry / 2;
		i--;
	}
	return strdup(ret);
}
