#include "libft.h"

static void		ft_display(int color, int format)
{
	ft_putstr("\033[");
	ft_putnbr(color);
	ft_putchar(';');
	ft_putnbr(format);
	ft_putchar('m');
}

void			ft_putrainbow(char *str)
{
	int			i;
	int			color;
	int			format;

	i = 0;
	color = 31;
	format = 5;
	while (str[i])
	{
		ft_display(color, format);
		ft_putchar(str[i]);
		if (color == 37)
			color = 90;
		else if (color == 97)
			color = 31;
		else
			color++;
		i++;
	}
}
