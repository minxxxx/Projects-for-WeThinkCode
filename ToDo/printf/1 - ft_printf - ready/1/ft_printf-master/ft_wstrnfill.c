/*
** Fills wide string with n specified characters.
*/

#include "libft.h"

wchar_t	*ft_wstrnfill(wchar_t *str, wchar_t c, int n)
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
