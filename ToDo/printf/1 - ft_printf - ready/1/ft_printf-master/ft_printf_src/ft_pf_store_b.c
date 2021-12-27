#include "../libft.h"
#include "../ft_printf.h"

int		ft_pf_store_type(char **str, char *type)
{
	*type = (*str)[0];
	*str = ft_memmove(*str, *str + 1, ft_strlen(*str));
	return (1);
}
