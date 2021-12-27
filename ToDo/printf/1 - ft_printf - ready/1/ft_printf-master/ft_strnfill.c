/*
** Fills string with n specified characters.
*/

#include "libft.h"

char	*ft_strnfill(char *str, char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
