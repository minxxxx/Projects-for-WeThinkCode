/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isint2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 15:52:11 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/09 16:42:13 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**	DON'T check if there is anything at end of number (!= ft_str_isint)
*/

#define MIN_INT_STR "-2147483648"
#define MAX_INT_STR	"2147483647"

int		ft_str_isint2(const char *s)
{
	int				len;

	len = (*s == '-') ? 1 : 0;
	while (ft_isdigit(s[len]))
		len++;
	if (len == 1 && *s == '-')
		return (FALSE);
	if (*s == '-' && len == 11 && ft_memcmp(s, MIN_INT_STR, 11) <= 0)
		return (TRUE);
	if (len > 10)
		return (FALSE);
	if (*s != '-' && len == 10 && ft_memcmp(s, MAX_INT_STR, 10) > 0)
		return (FALSE);
	return (TRUE);
}
