#include "../libft.h"
#include "../ft_printf.h"

int		ft_pf_handle_f(va_list args, t_print *features, int *ret)
{
	long double		c;
	char			*str;
	char			*new;
	size_t			pr;

	pr = (features->is_precision) ? features->precision : 6;
	if (features->mod == 'L')
		c = (va_arg(args, long double));
	else
		c = (va_arg(args, double));
	str = ft_ftoa(c, pr);
	return (ft_pf_format_print_num(&new, &str, features, ret)) ? (1) : (0);
}
