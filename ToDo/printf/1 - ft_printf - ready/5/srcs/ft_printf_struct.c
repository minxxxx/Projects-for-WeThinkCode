/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:03:52 by thendric          #+#    #+#             */
/*   Updated: 2017/01/19 12:44:46 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_init(t_input *input)
{
	if (!(ft_strchr(input->form, '%')))
	{
		if (!input->str)
			input->str = ft_strdup(input->form);
		else if (*input->form)
			input->str = ft_strjoin(input->str, input->form);
	}
	else
		ft_percentsign(input);
	return (0);
}

t_input	*ft_init_tinput(const char *format)
{
	t_input	*new;

	new = (t_input *)ft_memalloc(sizeof(t_input));
	new->form = ft_strdup((char *)format);
	new->flags = NULL;
	new->str = NULL;
	new->size = 0;
	new->negative = 0;
	new->flagplus = 0;
	new->flagpound = 0;
	new->flagspace = 0;
	new->flagminus = 0;
	new->flagzero = 0;
	new->precision = -1;
	new->islong = 0;
	return (new);
}
