#include <stdlib.h> //malloc, free, exit...
#include "header.h"

char *getXor(char *a, char *b)
{
	char *res = calloc(7, sizeof(char));
	for (int i = 0; i < 6; i++)
		res[i] = '0' + ((a[i] - '0') ^ (b[i] - '0'));
	return res;
}

int toInt(char *bits)
{
	int n = 0;
	for (int i = 0; i < 6; i++)
		n += (bits[5 - i] - '0') * (1 << i);
	return n;
}
