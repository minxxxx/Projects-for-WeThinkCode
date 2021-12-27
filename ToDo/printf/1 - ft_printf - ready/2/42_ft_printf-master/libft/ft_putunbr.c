#include "libft.h"

/*
** Outputs the unsigned integer n to the standard output.
*/

void	ft_putunbr(uintmax_t n)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		ft_putchar(c);
	}
	else
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
}
