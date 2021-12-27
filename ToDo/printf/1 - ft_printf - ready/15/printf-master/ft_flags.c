/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemiy <artemiy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:19:13 by artemiy           #+#    #+#             */
/*   Updated: 2019/01/04 00:43:04 by artemiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

t_flags		*init_flags(void)
{
	t_flags *flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->plus = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->cage = 0;
	flags->minus = 0;
	return (flags);
}
