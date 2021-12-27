#include "header.h"

char *getXor(char *a, char *b)
{
	char *xor;

	xor = (char*)calloc(7, sizeof(char));
	for (int i = 0; i < 6; i++)
		xor[i] = '0' + (a[i] + b[i] == '0' + '1');
	return (xor);
}

int toInt(char *bits)
{
	int total;
	int power;

	total = 0;
	power = 1;
	for (int i = 5; i >= 0; i--)
	{
		total += (bits[i] == '1') * power;
		power *= 2;
	}
	return (total);
}
