#include "ft_printf.h"

int					ft_printf_execarg_percent(t_args *a)
{
	unsigned char	c;
	t_unicode		*s;

	c = '%';
	a->precision = -1;
	s = ft_wstrdup((unsigned char*)(&c), 1);
	if (!s)
		return (-1);
	ft_printf_wputstr(s, a, ft_putstr_ascii);
	free(s);
	return (1);
}
