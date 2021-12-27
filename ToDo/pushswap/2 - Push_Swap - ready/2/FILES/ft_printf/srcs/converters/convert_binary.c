#include "ft_printf.h"

int		convert_binary(t_tag *tag, va_list *args)
{
	uintmax_t	nbr;

	nbr = va_arg(*args, int);
	nbr = get_unsigned_length(nbr, tag);
	return (print_uint(tag, nbr, "01", "0b"));
}
