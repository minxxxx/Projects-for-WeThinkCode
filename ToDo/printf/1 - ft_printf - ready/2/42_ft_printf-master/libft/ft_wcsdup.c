#include "libft.h"

/*
** Allocates sufficient memory for a copy of the wide string src, does the copy,
** and returns a pointer to it.
*/

wchar_t		*ft_wcsdup(wchar_t *src)
{
	int		len;
	wchar_t	*dst;

	len = ft_wcslen(src) + sizeof(wchar_t);
	dst = ft_memalloc(sizeof(wchar_t) * len);
	if (dst)
		ft_wcscpy(dst, src);
	return (dst);
}
