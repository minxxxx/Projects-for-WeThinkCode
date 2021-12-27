
#include "header.h"
#include <stdlib.h>
#include <string.h>

char    *getSum(char *a, char *b)
{
    char    *c;
    int		extra;

    c = calloc(7, sizeof(char));
	extra = 0;
    for (int i = 5; i >= 0; i--)
    {
        if (a[i] == '0' && b[i] == '0')
		{
			if (extra > 0)
			{
				c[i] = '1';
				extra--;
			}
			else
            	c[i] = '0';
		}
        else if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1'))
		{
			if (extra > 0)
				c[i] = '0';
			else
            	c[i] = '1';
		}
        if (a[i] == '1' && b[i] == '1')
		{
			if (extra > 0)
				c[i] = '1';
			else
			{
            	c[i] = '0';
				extra++;
			}
		}
    }
	c[6] = '\0';
	return (c);
}

int		power(int x, int y)
{
	int	value;

	value = 1;
	while (y-- > 0)
		value *= x;
	return (value);
}

int     toInt(char *bits)
{
	int	result, j, i;

	result = j = 0;
	i = strlen(bits);
	for (i -= 1; i >= 0; i--)
	{
		if (bits[i] == '1')
			result += power(2, j);
		j++;
	}
	return (result);
}