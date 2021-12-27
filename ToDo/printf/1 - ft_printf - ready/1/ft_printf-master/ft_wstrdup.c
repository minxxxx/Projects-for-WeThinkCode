#include "libft.h"
#include <stdlib.h>

wchar_t	*ft_wstrdup(wchar_t *s1)
{
	wchar_t *new;

	new = (wchar_t *)malloc(sizeof(*new) * ft_wstrlen(s1) + 1);
	if (!new)
		return (NULL);
	new = ft_wstrcpy(new, s1);
	return (new);
}
