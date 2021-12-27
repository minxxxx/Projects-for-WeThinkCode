#include "libft.h"

/*
** Deletes the first character of a string, by moving all chars to the left
** by one space.
*/

int	ft_stroneleft(char **str)
{
	*str = ft_memmove(*str, *str + 1, ft_strlen(*str));
	return (1);
}
