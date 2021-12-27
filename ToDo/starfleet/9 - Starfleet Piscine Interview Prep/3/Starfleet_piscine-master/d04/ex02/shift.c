#include "header.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

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

char *tild(char *str)
{
	int i = 1;
	char *ret;
	ret = malloc(5);
	ret[4] = 0;

	while (str[i])
	{
		if (str[i] == '0')
			ret[i - 1] = '1';
		else
			ret[i - 1] = '0';
		i++;
	}
	return ret;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		count;

	count = 0;
	tmp = malloc(strlen(s1) + strlen(s2));
	bzero(tmp, strlen(s1) + strlen(s2));
	if (!tmp)
		return (NULL);
	while (s1[0])
	{
		tmp[count] = s1[0];
		s1++;
		count++;
	}
	while (s2[0])
	{
		tmp[count] = s2[0];
		s2++;
		count++;
	}
	tmp[count] = '\0';
	return (tmp);
}

int toInt(char *bits)
{
	int i = strlen(bits) - 1;
	int mult;
	int ret = 0;
	int neg = 1;

	if (bits[0] == '1')
	{
		bits = tild(bits);
		bits = getSum(bits, "000001");
		neg = -1;
	}
	mult = 1;
	while (i > -1)
	{
		if (bits[i] == '1')
			ret = ret + mult;
		mult = mult * 2;
		i--;
	}
	return (ret * neg);
}

char *leftShift(char *bin, int k)
{
	char *ret;
	int i;

	i = k;
	while (i)
	{
		bin++;
		i--;
	}
	ret = malloc(strlen(bin) + k + 1);
	ret[strlen(bin) + k + 1] = 0;
	while (i < (int)(strlen(bin) + k))
	{
		if (i < (int)strlen(bin))
			ret[i] = bin[i];
		else
			ret[i] = '0';
		i++;
	}
	return ret;
}

char *rightShift(char *bin, int k)
{
	int i = k;
	int l = strlen(bin) - 1;
	char *join;

	while (i)
	{
		bin[l] = 0;
		l--;
		i--;
	}
	join = malloc(k + 1);
	join[k] = 0;
	while (i < k)
	{
		join[i] = '1';
		i++;
	}
	return ft_strjoin(join, bin);
}
