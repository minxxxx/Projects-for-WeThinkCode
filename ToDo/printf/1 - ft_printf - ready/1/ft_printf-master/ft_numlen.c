#include "libft.h"

int	ft_numlen(int a)
{
	int i;

	i = 0;
	if (!a)
		return (1);
	while (a > 0)
	{
		a = (a - (a % 10)) / 10;
		i++;
	}
	return (i);
}
