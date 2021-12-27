/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 19:24:32 by artemiy           #+#    #+#             */
/*   Updated: 2019/01/08 18:49:46 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int		is_flag(char c)
{
	if (ft_strchr("#-+ 0", c))
		return (1);
	return (0);
}

int		get_length_len(char *fmt)
{
	int	l_len;

	l_len = 0;
	if (ft_strchr("hlLzj", *fmt))
		l_len++;
	if ((*fmt == 'h' && *(fmt + 1) == 'h') || (*fmt == 'l' && *(fmt + 1) == 'l'))
		l_len++;
	return (l_len);
}

void	spec_del(t_specifier **sp)
{
	if ((*sp)->length)
		free((*sp)->length);
	if ((*sp)->flags)
		free((*sp)->flags);
	free(*sp);
	*sp = NULL;
}
