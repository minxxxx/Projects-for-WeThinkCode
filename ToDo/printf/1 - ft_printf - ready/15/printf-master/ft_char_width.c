#include "ft_printf.h"

char 	*ft_make_str(t_specifier *spec)
{
	char 	*str;

	if (spec->width && !spec->flags->zero)
		str = ft_fillstr(spec->width, ' ');
	else if (spec->width && spec->flags->zero)
		str = ft_fillstr(spec->width, '0');
	else
		str = ft_strnew(1);
	return (str);
}
