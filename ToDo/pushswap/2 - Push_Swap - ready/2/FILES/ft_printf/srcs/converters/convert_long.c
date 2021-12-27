#include "ft_printf.h"

int		convert_long(t_tag *tag, va_list *args)
{
	tag->length = 3;
	if (tag->specifier == 'D')
		return (convert_int(tag, args));
	else if (tag->specifier == 'O')
		return (convert_octal(tag, args));
	else if (tag->specifier == 'U')
		return (convert_unsigned_int(tag, args));
	else
		return (-1);
}
