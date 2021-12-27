#include <stdlib.h>
#include "libft.h"

/*
** Takes a double, and rounds it up or down depending on the value after the
** dot.
*/

double	ft_round(double n)
{
	return (((n - ((long long)(n + 1e-9))) * 10) > 5) ? n + 1 : n;
}
