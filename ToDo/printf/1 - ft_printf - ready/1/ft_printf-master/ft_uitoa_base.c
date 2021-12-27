#include <stdlib.h>

static int	ft_find_length(unsigned long long value, int base)
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

char		*ft_uitoa_base(unsigned long long value, int base)
{
	char				*ans;
	unsigned long long	tmp;
	int					l;

	l = 0;
	if (base < 2 || base > 16)
		return (NULL);
	tmp = value;
	l = ft_find_length(tmp, base);
	ans = (char *)malloc(sizeof(*ans) * (l + 1));
	ans[l] = '\0';
	l--;
	while (l >= 0)
	{
		ans[l] = (tmp % base < 10) ? (tmp % base + '0') : (tmp % base + '7');
		tmp = (tmp - (tmp % base)) / base;
		l--;
	}
	return (ans);
}
