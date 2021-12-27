#include <stdlib.h> //malloc, free, exit...

#include "header.h"

char *getAnd(char *a, char *b)
{
	int a_neg = (a[0] == '~');
	int b_neg = (b[0] == '~');
	int b_bit;
	int	a_bit;
	char *res = calloc(5, sizeof(char));
	for(int i = 0; i < 4; i++)
	{
		a_bit = ((a[i + a_neg] - '0') ^ a_neg);
		b_bit = ((b[i + b_neg] - '0') ^ b_neg);
		res[i] = (a_bit & b_bit) + '0';
	}
	return res;
}

char *getOr(char *a, char *b)
{
	int a_neg = (a[0] == '~');
	int b_neg = (b[0] == '~');
	int b_bit;
	int	a_bit;
	char *res = calloc(5, sizeof(char));
	for(int i = 0; i < 4; i++)
	{
		a_bit = ((a[i + a_neg] - '0') ^ a_neg);
		b_bit = ((b[i + b_neg] - '0') ^ b_neg);
		res[i] = (a_bit | b_bit) + '0';
	}
	return res;
}

int toInt(char *bits)
{
	int n = 0;
	for (int i = 0; i < 4; i++)
		n += (bits[3 - i] - '0') * (1 << i);
	return n;
}