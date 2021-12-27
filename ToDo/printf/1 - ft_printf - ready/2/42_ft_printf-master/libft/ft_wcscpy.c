#include "libft.h"

/*
** Copy the wide string src to dst (including the terminating `\0' character).
*/

wchar_t		*ft_wcscpy(wchar_t *dst, const wchar_t *src)
{
	size_t	i;

	i = 0;
	while ((dst[i] = src[i]) != L'\0')
		i += 1;
	return (dst);
}
