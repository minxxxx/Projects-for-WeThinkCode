#include "ft_printf.h"

void	print_char(t_tag *tag, char c)
{
	if (tag->has_width && !tag->flag_minus && !tag->flag_zero)
		print_width_pad(1, tag->width, ' ');
	else if (tag->has_width && tag->flag_zero)
		print_width_pad(1, tag->width, '0');
	ft_putchar(c);
	if (tag->has_width && tag->flag_minus)
		print_width_pad(1, tag->width, ' ');
}

int		convert_char(t_tag *tag, va_list *args)
{
	char	output_arg;

	if (tag->length == 3)
		return (convert_wchar(tag, args));
	output_arg = va_arg(*args, int);
	print_char(tag, output_arg);
	if (tag->width)
		return (tag->width);
	else
		return (1);
}
