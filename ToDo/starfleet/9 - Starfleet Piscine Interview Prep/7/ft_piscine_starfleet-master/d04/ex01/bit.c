#include "header.h"

char *getAnd(char *a, char *b)
{
	int		b_bit;
	int		a_bit;
	int		a_neg;
	int		b_neg;
	char	*add;

	a_neg = (a[0] == '~');
	b_neg = (b[0] == '~');
	add = (char*)calloc(5, sizeof(char));
	for (int i = 3; i >= 0; i--)
	{
		a_bit = ((a[i + a_neg] == '1') ^ a_neg);
		b_bit = ((b[i + b_neg] == '1') ^ b_neg);
		add[i] = '0' + (a_bit && b_bit);
	}	
	return (add);
}

char *getOr(char *a, char *b)
{
	int		b_bit;
	int		a_bit;
	int		a_neg;
	int		b_neg;
	char	*or;

	a_neg = (a[0] == '~');
	b_neg = (b[0] == '~');
	or = (char*)calloc(5, sizeof(char));
	for (int i = 3; i >= 0; i--)
	{	
		a_bit = ((a[i + a_neg] == '1') ^ a_neg);
		b_bit = ((b[i + b_neg] == '1') ^ b_neg);
		or[i] = '0' + (a_bit || b_bit);
	}	
	return (or);
}

int toInt(char *bits)
{
	int total;
	int power;

	total = 0;
	power = 1;
	for (int i = 3; i >= 0; i--)
	{
		total += (bits[i] == '1') * power;
		power *= 2;
	}
	return (total);
}
