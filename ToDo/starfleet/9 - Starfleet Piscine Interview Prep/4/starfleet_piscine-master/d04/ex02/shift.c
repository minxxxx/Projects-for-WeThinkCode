#include <stdlib.h> //malloc, free, exit...

#include "header.h"

char *rightShift(char *bin, int k)
{
	char *res = calloc(7, sizeof(char));
	for (int i = 5; i >= 0; i--)
		res[i] = (i - k > 0 ? bin[i - k] : bin[0]);
	return(res);
}

char *leftShift(char *bin, int k)
{
	char *res = calloc(7, sizeof(char));
	for (int i = 0; i < 6; i++)
		res[i] = (i + k < 6 ? bin[i + k] : '0');
	return(res);
}

int toInt(char *bits)
{
	int n = 0;
	int is_neg = (bits[0] - '0');
	for (int i = 1; i < 6; i++)
		n += ((bits[i] - '0')  ^ is_neg) * (1 << (5 - i));
	n += is_neg;
	return is_neg ? -n : n;
}
