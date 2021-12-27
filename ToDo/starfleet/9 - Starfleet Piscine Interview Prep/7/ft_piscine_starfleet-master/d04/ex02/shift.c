#include "header.h"

char *rightShift(char *bin, int k)
{
	char *shifted;

	shifted = (char*)calloc(7, sizeof(char));
	for (int i = 5; i > 0; i--)
		shifted[i] = (i - k > 0 ? bin[i - k] : bin[0]);
	shifted[0] = bin[0];
	return(shifted);
}

char *leftShift(char *bin, int k)
{
	char *shifted;

	shifted = (char*)calloc(7, sizeof(char));
	for (int i = 5; i > 0; i--)
		shifted[i] = (i + k < 6 ? bin[i + k] : '0');
	shifted[0] = bin[0];
	return(shifted);
}

int toInt(char *bits)
{
	int is_neg;
	int total;
	int power;

	is_neg = (bits[0] == '1');
	total = 0;
	power = 1;
	for (int i = 5; i > 0; i--)
	{
		total += ((bits[i] == '1') ^ is_neg) * power;
		power *= 2;
	}
	total += is_neg;
	return ((is_neg ? -total : total));
}
