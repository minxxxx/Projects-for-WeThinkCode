#include "ft_printf.h"

int		convert_address(t_tag *tag, va_list *args)
{
	uintmax_t	output_arg;
	char		*base;

	base = "0123456789abcdef";
	output_arg = va_arg(*args, uintmax_t);
	tag->length = 6;
	output_arg = get_unsigned_length(output_arg, tag);
	if (output_arg || tag->has_precision)
		return (print_uint(tag, output_arg, base, "0x"));
	else
	{
		if (tag->width && !tag->flag_minus)
			print_width_pad(3, tag->width, ' ');
		ft_putstr("0x0");
		if (tag->width && tag->flag_minus)
			print_width_pad(3, tag->width, ' ');
		tag->width = (tag->width ? tag->width : 3);
		return (tag->width);
	}
}
