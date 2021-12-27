#include "libft.h"
#include <stdlib.h>
#include <string.h>

wchar_t		*ft_wstrnew(int size)
{
	wchar_t	*new;
	int		i;

	i = 0;
	new = (wchar_t *)malloc(sizeof(*new) * (size + 1));
	if (!new)
		return (NULL);
	while (i < size + 1)
	{
		new[i] = L'\0';
		i++;
	}
	return (new);
}
