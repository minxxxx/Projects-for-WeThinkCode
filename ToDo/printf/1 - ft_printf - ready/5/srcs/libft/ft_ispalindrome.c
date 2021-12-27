#include "libft.h"

int		ft_ispalindrome(char *str)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!str)
		return (0);
	while (str[j])
		j++;
	while (i < j)
	{
		if (str[++i] != str[--j])
			return (0);
	}
	return (1);
}
