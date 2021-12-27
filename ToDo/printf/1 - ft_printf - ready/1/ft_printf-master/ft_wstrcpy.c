#include "libft.h"

wchar_t	*ft_wstrcpy(wchar_t *dst, const wchar_t *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = L'\0';
	return (dst);
}
