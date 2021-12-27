#include <stdlib.h>

static int	ft_find_length(long int value, int base)
{
	int l;

	l = 0;
	if (!value)
		return (1);
	while (value > 0)
	{
		value = (value - (value % base)) / base;
		l++;
	}
	return (l);
}

char		*ft_sizettohexa(size_t value)
{
	char		*ans;
	size_t		tmp;
	int			l;

	l = 0;
	tmp = value;
	l = ft_find_length(tmp, 16);
	ans = (char *)malloc(sizeof(*ans) * (l + 1));
	ans[l] = '\0';
	l--;
	while (l >= 0)
	{
		ans[l] = (tmp % 16 < 10) ? (tmp % 16 + '0') : (tmp % 16 + 'W');
		tmp = (tmp - (tmp % 16)) / 16;
		l--;
	}
	return (ans);
}
