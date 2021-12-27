#include "header.h"

char *getSum(char *a, char *b)
{
	int carry;
	int sum;

	carry = 0;
	for (int i = 5; i >= 0; i--)
	{
		sum = (a[i] == '1') + (b[i] == '1') + carry;
		carry = (sum > 1);
		a[i] = '0' + (sum % 2);
	}
	return (a);
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
