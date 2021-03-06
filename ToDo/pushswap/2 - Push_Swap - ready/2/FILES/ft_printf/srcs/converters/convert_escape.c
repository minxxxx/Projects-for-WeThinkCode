#include "ft_printf.h"

int		convert_escape(t_tag *tag, va_list *args)
{
	(void)args;
	if (tag->has_width && !tag->flag_minus)
		print_width_pad(1, tag->width, tag->flag_zero ? '0' : ' ');
	ft_putchar('%');
	if (tag->has_width && tag->flag_minus)
		print_width_pad(1, tag->width, ' ');
	return (tag->has_width ? ft_max(tag->width, 1) : 1);
}
