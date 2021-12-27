#include "header.h"

char *getSum(char *a, char *b)
{
	int carry;
	int sum;

	carry = 0;
	for (int i = 5; i >= 0; i--)
	{
		sum = (a[i] - '0') + (b[i] - '0') + carry;
		carry = (sum > 1);
		a[i] = '0' + (sum % 2);
	}
	return (a);
}

int toInt(char *bits)
{
	int n = 0;
	for (int i = 0; i < 6; i++)
		n += (bits[5 - i] - '0') * (1 << i);
	return n;
}
