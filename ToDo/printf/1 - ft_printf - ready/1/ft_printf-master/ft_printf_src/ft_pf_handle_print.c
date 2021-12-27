#include "../libft.h"
#include "../ft_printf.h"

int		ft_pf_format_print_num
	(char **new, char **str, t_print *features, int *ret)
{
	char *spaces;

	if (!(ft_pf_num_mod(new, str, &spaces, features)))
		return (0);
	ft_putstr(*new);
	*ret = *ret + ft_strlen(*new);
	free(*new);
	free(*str);
	return (1);
}
