#include "libft.h"

int		ft_addtoa(char **num)
{
	int i;

	i = ft_strlen(*num) - 1;
	while (i)
	{
		if ((*num)[i] < '9')
		{
			((*num)[i])++;
			break ;
		}
		(*num)[i] = '0';
		i++;
	}
	return (1);
}
