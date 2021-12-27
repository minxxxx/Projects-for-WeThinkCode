#include <stdlib.h>
#include "libft.h"

static	int		ft_determine_len(long n, int len)
{
	while (n > 0)
	{
		n = (n - (n % 10)) / 10;
		len++;
	}
	return (len);
}

char			*ft_longtoa(long n)
{
	int		min;
	int		neg;
	int		len;
	char	*ans;

	len = 0;
	min = 0;
	if (n == LONG_MIN)
	{
		min = 1;
		n++;
	}
	neg = (n < 0) ? 1 : 0;
	n = neg ? -n : n;
	len = ft_determine_len(n, len);
	len = (n == 0 || neg) ? len + 1 : len;
	if (!(ans = (char *)malloc(sizeof(*ans) * (len + 1))))
		return (NULL);
	ans[len] = '\0';
	while (len > 0)
	{
		ans[len - 1] = (n % 10) + '0';
		n = (n - (n % 10)) / 10;
		len--;
	}
	ans[0] = (neg) ? '-' : ans[0];
	if (min)
		ft_addtoa(&ans);
	return (ans);
}
