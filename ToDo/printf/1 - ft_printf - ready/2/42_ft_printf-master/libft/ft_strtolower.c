#include "libft.h"

/*
** Makes every letter in the string lowercase.
*/

char	*ft_str_to_lowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i++])
		if (str[i - 1] >= 'A' && 'Z' >= str[i - 1])
			str[i - 1] += 32;
	return (str);
}
