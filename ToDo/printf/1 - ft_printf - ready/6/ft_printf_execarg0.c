#include "ft_printf.h"

int		ft_printf_execarg(t_args *a, va_list ap)
{
	int	r;

	if (a->type == 'p' || a->type == 'b' || a->type == 'd'
		|| a->type == 'i' || a->type == 'o' || a->type == 'u' || a->type == 'x'
		|| a->type == 'X')
		r = ft_printf_execarg_pbdioux(a, ap);
	else if (a->type == 's')
		r = ft_printf_execarg_s(a, ap);
	else if (a->type == 'r')
		r = ft_printf_execarg_r(a, ap);
	else if (a->type == '%')
		r = ft_printf_execarg_percent(a);
	else if (a->type == 'c')
		r = ft_printf_execarg_c(a, ap);
	else
		r = ft_printf_execarg_undefineds(a);
	return (r);
}
